#include "DynamicMesh.h"

void DynamicMesh::AddVertices(std::vector<Vertex> vertices)
{
	this->pVertices.insert(this->pVertices.end(), vertices.begin(), vertices.end());
}
void DynamicMesh::ClearVertices()
{
	this->pVertices.clear();
}

#include <iostream>
void DynamicMesh::CreateMesh()
{
	if (this->pVertices.empty()) {
		std::cout << "MESH-Vertices List: EMPTY!\n";
		return;
	}
	if (!this->pID)
		glGenVertexArrays(1, &this->pID);

	glBindVertexArray(this->pID);
	glGenBuffers(1, &pVBO);

	glBindBuffer(GL_ARRAY_BUFFER, pVBO);
	glBufferData(GL_ARRAY_BUFFER, this->pVertices.size() * sizeof(Vertex), &this->pVertices[0], GL_DYNAMIC_DRAW);

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
void DynamicMesh::ClearMesh()
{
	this->pVertices.clear();
	glDeleteBuffers(1, &this->pID);
	glDeleteVertexArrays(1, &this->pID);
}

void DynamicMesh::UpdateMesh()
{
	glBindVertexArray(this->pID);
	glBindBuffer(GL_ARRAY_BUFFER, pVBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, this->pVertices.size() * sizeof(Vertex), &this->pVertices);
}

void DynamicMesh::Draw()
{
	glBindVertexArray(this->pID);
	glDrawArrays(GL_TRIANGLES, 0, this->pVertices.size());
}