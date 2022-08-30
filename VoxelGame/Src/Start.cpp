#include <VoxelEngine.h>
#include <iostream>

#include "VoxelChunk/VoxelChunk.h"

int main()
{
	// Initilizing!
	VoxelEngine::Init(1920, 1080, "Voxel Game");

	// Voxel Spawn Indicator
	unsigned int spawnX = CHUNK_SIZE/2, spawnY = CHUNK_SIZE - 1, spawnZ = CHUNK_SIZE/2;
	Mesh spawner_mesh;
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Back(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Front(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Left(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Right(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Top(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.AddVertices(VERTEX::Add_CUBE_Bottom(Vector3f(), Vector3f(1.0f)));
	spawner_mesh.CreateMesh();

	VoxelChunk* Chunk = new VoxelChunk();
	Chunk->GenerateRandom();

	Shader voxel_shader = SHADER::loadShaderFromFile("Res/Shader/voxel_v.glsl.txt", "Res/Shader/voxel_f.glsl.txt");
	Chunk->SetVoxel(CHUNK_SIZE - 1, CHUNK_SIZE - 1, CHUNK_SIZE - 1, VOXELID_SAND);
	DynamicMesh voxel_mesh;
	voxel_mesh.AddVertices(Chunk->GenerateMesh());
	voxel_mesh.CreateMesh();

	// Test Camera
	Vector3f Camera_Position = Vector3f(15.5f, 15.5f, 79.0f);
	Vector3f Camera_Rotation = Vector3f(0.f, 0.f, 0.f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Spawner Indicator
	bool keys[4];

	// Generate Again :D
	bool hasPressed = false;

	// deltaTime variables
	// -------------------
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	// Game-Loop
	while (!Window::ShouldClose())
	{
		// calculate delta time
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		// Update

		Chunk->Update(deltaTime);

		// Spawn Indicator
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS && !keys[0])
			if (spawnX != 0) { spawnX--; keys[0] = true; }
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_LEFT) == GLFW_RELEASE)
			keys[0] = false;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS && !keys[1])
			if (spawnX != CHUNK_SIZE-1) { spawnX++; keys[1] = true; }
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_RIGHT) == GLFW_RELEASE)
			keys[1] = false;

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_UP) == GLFW_PRESS && !keys[2])
			if (spawnZ != 0) { spawnZ--; keys[2] = true; }
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_UP) == GLFW_RELEASE)
			keys[2] = false;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS && !keys[3])
			if (spawnZ != CHUNK_SIZE - 1) { spawnZ++; keys[3] = true; }
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_DOWN) == GLFW_RELEASE)
			keys[3] = false;



		float speed = 5.f;

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
			Camera_Position.z -= speed * deltaTime;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
			Camera_Position.z += speed * deltaTime;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
			Camera_Position.x -= speed * deltaTime;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
			Camera_Position.x += speed * deltaTime;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
			Camera_Position.y += speed * deltaTime;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
			Camera_Position.y -= speed * deltaTime;

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_L) == GLFW_PRESS)
			Camera_Rotation.y = 180.f;
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_K) == GLFW_PRESS)
			Camera_Rotation.y = 0.f;

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_I) == GLFW_PRESS) {
			voxel_mesh.ClearMesh();
			voxel_mesh.AddVertices(Chunk->GenerateMesh());
		}

		if(glfwGetKey(Window::GetWindow(), GLFW_KEY_R))
			Chunk->SetVoxel(spawnX, spawnY, spawnZ, VOXELID_SAND);

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_Q) == GLFW_PRESS && !hasPressed) {
			//Chunk->GenerateRandom();
			Chunk->SetVoxel(4, CHUNK_SIZE-1, 4, VOXELID_SAND);
			voxel_mesh.CreateMesh();
			hasPressed = true;
		}
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_Q) == GLFW_RELEASE) {
			hasPressed = false;
		}

		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_B) == GLFW_PRESS)
			std::cout << "Camera Position: " << Camera_Position.x << ", " << Camera_Position.y << ", " << Camera_Position.z << "\n";



		// Add Voxel(s) to Voxel Chunk : Chunk
		



		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_O) == GLFW_PRESS)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		if (glfwGetKey(Window::GetWindow(), GLFW_KEY_P) == GLFW_PRESS)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render 3D
		if (Chunk->RenderUpdate)
		{
			//voxel_mesh.ClearVertices();
			voxel_mesh.AddVertices(Chunk->GenerateMesh());
			voxel_mesh.UpdateMesh();
		}
		voxel_shader.Bind();

		glm::mat4 model_matrix = glm::mat4(1.f);
		glm::mat4 matrix_view = glm::mat4(1.f);
		glm::mat4 matrix_proj = glm::mat4(1.f);
		matrix_view = glm::rotate(matrix_view, glm::radians(Camera_Rotation.x), glm::vec3(1, 0, 0));
		matrix_view = glm::rotate(matrix_view, glm::radians(Camera_Rotation.y), glm::vec3(0, 1, 0));
		matrix_view = glm::rotate(matrix_view, glm::radians(Camera_Rotation.z), glm::vec3(0, 0, 1));
		matrix_view = glm::translate(matrix_view, glm::vec3(-Camera_Position.x, -Camera_Position.y, -Camera_Position.z));
		matrix_proj = glm::perspective(glm::radians(45.f), 1920.f / 1080.f, 0.001f, 100.f);
		voxel_shader.SetMat4("model", model_matrix);
		voxel_shader.SetMat4("view", matrix_view);
		voxel_shader.SetMat4("proj", matrix_proj);

		voxel_mesh.Draw();

		// Spawn Indicator
		model_matrix = glm::mat4(1.f);
		model_matrix = glm::translate(model_matrix, glm::vec3(spawnX, spawnY, spawnZ));
		matrix_proj = glm::perspective(glm::radians(45.f), 1920.f / 1080.f, 0.001f, 100.f);
		voxel_shader.SetMat4("model", model_matrix);
		spawner_mesh.Draw();


		// Render 2D

		// Flush
		glfwSwapBuffers(Window::GetWindow());
		glfwSwapInterval(1);
	}

	//delete voxel_shader;
	//delete voxel_mesh;

	// Cleaning-Up and Terminating!
	VoxelEngine::Terminate();
}