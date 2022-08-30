#pragma once
#include "Mesh.h"

class DynamicMesh
{
protected:
	GLuint pID;
	GLuint pVBO;
	std::vector<Vertex> pVertices;

public:
	void AddVertices(std::vector<Vertex> vertices);
	void ClearVertices();

	void UpdateMesh();

	void CreateMesh();
	void ClearMesh();

	void Draw();
};