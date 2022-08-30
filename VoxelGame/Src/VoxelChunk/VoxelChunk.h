#pragma once
#include <VoxelEngine.h>
#include "Voxel.h"

/* --- Voxel ID(s) */
#define VOXELID_AIR 0
#define VOXELID_SOLID 1
#define VOXELID_SAND 2
#define VOXELID_WATER 3

/* --- Chunk Const(s) --- */
const unsigned int CHUNK_SIZE = 16;

class VoxelChunk
{
protected:
	unsigned int pVoxel[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

public:
	void GenerateRandom();

	std::vector<Vertex> GenerateMesh();

	void SetVoxel(unsigned int x, unsigned int y, unsigned int z, unsigned int id);
	unsigned int GetVoxel(unsigned int x, unsigned int y, unsigned int z);


	void Update(GLfloat delta);
	bool RenderUpdate = false;

protected:
	bool FaceLeft(unsigned int x, unsigned int y, unsigned int z);
	bool FaceRight(unsigned int x, unsigned int y, unsigned int z);
	bool FaceFront(unsigned int x, unsigned int y, unsigned int z);
	bool FaceBack(unsigned int x, unsigned int y, unsigned int z);
	bool FaceTop(unsigned int x, unsigned int y, unsigned int z);
	bool FaceBottom(unsigned int x, unsigned int y, unsigned int z);



	void Swamp(unsigned int x1, unsigned int y1, unsigned z1, unsigned int x2, unsigned int y2, unsigned int z2);
	void Move(unsigned int x, unsigned int y, unsigned z, unsigned int x2, unsigned int y2, unsigned int z2);

	bool CheckAirAndMove(unsigned int x, unsigned int y, unsigned int z, unsigned int x2, unsigned int y2, unsigned int z2);


	bool UpdateSand(unsigned int x, unsigned int y, unsigned int z);
	bool UpdateWater(unsigned int x, unsigned int y, unsigned int z);
};