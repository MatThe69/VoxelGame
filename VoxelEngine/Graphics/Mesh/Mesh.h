#pragma once
#include <glad/glad.h>
#include <vector>

#include "Vector3f.h"

struct Vertex
{
	Vector3f Position;
	Vector3f Color;
	float Shade;
};


class Mesh
{
private:
	GLuint pID;
	std::vector<Vertex> pVertices;

public:
	void AddVertices(std::vector<Vertex> vertices);
	void ClearVertices();

	void CreateMesh();
	void ClearMesh();

	void Draw();

	std::vector<Vertex>& GetVertices();
};