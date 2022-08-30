#include "Mesh.h"

void Mesh::AddVertices(std::vector<Vertex> vertices)
	{ this->pVertices.insert(this->pVertices.end(), vertices.begin(), vertices.end()); }
void Mesh::ClearVertices()
	{ this->pVertices.clear(); }

#include <iostream>
void Mesh::CreateMesh()
{
	if (this->pVertices.empty()) {
		std::cout << "MESH-Vertices List: EMPTY!\n";
		return;
	}
	if (!this->pID)
		glGenVertexArrays(1, &this->pID);

	GLuint VBO;
	glBindVertexArray(this->pID);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, this->pVertices.size() * sizeof(Vertex), &this->pVertices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Shade));

	glBindVertexArray(0);
}
void Mesh::ClearMesh()
{
	this->pVertices.clear();
	glDeleteBuffers(1, &this->pID);
	glDeleteVertexArrays(1, &this->pID);
}

void Mesh::Draw()
{
	glBindVertexArray(this->pID);
	glDrawArrays(GL_TRIANGLES, 0, this->pVertices.size());
}



std::vector<Vertex>& Mesh::GetVertices() { return this->pVertices; }