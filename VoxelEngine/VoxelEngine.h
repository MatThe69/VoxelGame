#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/* --- Graphic(s) --- */
#include "Graphics/Window/Window.h"
#include "Graphics/Asset/Asset.h"
#include "Graphics/Shader/Shader.h"
#include "Graphics/Texture/Texture.h"
#include "Graphics/Texture/TextureArray/TextureArray.h"
#include "Graphics/Mesh/Mesh.h"
#include "Graphics/Mesh/DynamicMesh.h"
#include "Graphics/Mesh/VERTEX.h"


/* --- Voxel Engine Function(s) --- */
namespace VoxelEngine
{
	static void Init(unsigned int Width, unsigned int Height, const char* Title)
	{
		Window::Init(Width, Height, Title);
	}
	static void Terminate()
	{
		Window::Terminate();
	}
}