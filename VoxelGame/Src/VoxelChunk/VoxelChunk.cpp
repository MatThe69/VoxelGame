#include "VoxelChunk.h"
//#include "PerlinNoise.hpp"






void VoxelChunk::Swamp(unsigned int x1, unsigned int y1, unsigned z1, unsigned int x2, unsigned int y2, unsigned int z2)
{
	unsigned int index1 = GetVoxel(x1, y1, z1); unsigned int index2 = GetVoxel(x2, y2, z2);
	SetVoxel(x1, y1, z1, index2); SetVoxel(x2, y2, z2, index1);
}
void VoxelChunk::Move(unsigned int x, unsigned int y, unsigned z, unsigned int x2, unsigned int y2, unsigned int z2)
{ SetVoxel(x2, y2, z2, GetVoxel(x, y, z)); SetVoxel(x, y, z, VOXELID_AIR); }


bool VoxelChunk::CheckAirAndMove(unsigned int x, unsigned int y, unsigned int z, unsigned int x2, unsigned int y2, unsigned int z2)
{
	if (GetVoxel(x2, y2, z2) == VOXELID_AIR)
	{
		Move(x, y, z, x2, y2, z2);
		return true;
	}
	return false;
}





void VoxelChunk::Update(GLfloat delta)
{
	this->RenderUpdate = false;

	for(GLuint x = 0; x < CHUNK_SIZE; x++)
		for (GLuint z = 0; z < CHUNK_SIZE; z++)
			for (GLuint y = 0; y < CHUNK_SIZE; y++)
			{
				switch (GetVoxel(x, y, z))
				{
				case VOXELID_AIR:
					break;
				case VOXELID_SAND:
					if(UpdateSand(x, y, z)) this->RenderUpdate = true;
					break;
				case VOXELID_WATER:
					//UpdateWater(x, y, z);
					break;
				}
			}
}






/* --- Update Function(s) --- */
// Sand
bool VoxelChunk::UpdateSand(unsigned int x, unsigned int y, unsigned int z)
{
	// If Underneath is free, Move there! (Return)
	if (y != 0 && CheckAirAndMove(x, y, z, x, y-1, z))
		return true;
	// If Underneath right is free
	if ((y != 0 && x != CHUNK_SIZE-1) && CheckAirAndMove(x, y, z, x + 1, y - 1, z))
		return true;
	// If Underneath left is free
	if ((y != 0 && x != 0) && CheckAirAndMove(x, y, z, x - 1, y - 1, z))
		return true;
	// If Underneath front is free
	if ((y != 0 && z != CHUNK_SIZE - 1) && CheckAirAndMove(x, y, z, x, y - 1, z+1))
		return true;
	// If Underneath back is free
	if ((y != 0 && z != 0) && CheckAirAndMove(x, y, z, x, y - 1, z - 1))
		return true;

	return false;
}
// Water
bool VoxelChunk::UpdateWater(unsigned int x, unsigned int y, unsigned int z)
{
	return false;
}








void VoxelChunk::GenerateRandom()
{
	//const siv::PerlinNoise::seed_type seed = 123456u;
	//const siv::PerlinNoise perlin{ seed };

	for (GLuint x = 0; x < CHUNK_SIZE; x++)
		for (GLuint z = 0; z < CHUNK_SIZE; z++) {
			//double noise = perlin.octave2D_01((x * 0.01), (z * 0.01), 4);
			float noise = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			int amplify = CHUNK_SIZE-1;

			unsigned int noise_height = noise * amplify;
			for (GLuint y = 0; y < CHUNK_SIZE; y++)
			{
				/*if (y < noise_height)
					SetVoxel(x, y, z, rand()%4);
				else
					SetVoxel(x, y, z, 0);*/
				SetVoxel(x, y, z, VOXELID_AIR);

				/*SetVoxel(x, y, z, rand() % 2);
				if (y < CHUNK_SIZE / 2)
					SetVoxel(x, y, z, 1);*/
			}
		}
}

#include <iostream>
std::vector<Vertex> VoxelChunk::GenerateMesh()
{
	Mesh mesh;

	for (GLuint y = 0; y < CHUNK_SIZE; y++) {
		for (GLuint z = 0; z < CHUNK_SIZE; z++) {
			for (GLuint x = 0; x < CHUNK_SIZE; x++) {
				if (GetVoxel(x, y, z) == 0)
					continue;
				Vector3f Color;

				switch (GetVoxel(x, y, z))
				{
				case VOXELID_SOLID:
					Color = Vector3f(1.0f);
					break;
				case VOXELID_SAND:
					Color = Vector3f(1.f, 0.8f, 0.f);
					break;
				case VOXELID_WATER:
					Color = Vector3f(0.8f, 0.8f, 1.0f);
					break;
				}

				if (!FaceLeft(x, y, z))		mesh.AddVertices(VERTEX::Add_CUBE_Left(		Vector3f(x, y, z), Color));
				if (!FaceRight(x, y, z))	mesh.AddVertices(VERTEX::Add_CUBE_Right(		Vector3f(x, y, z), Color));
				if (!FaceFront(x, y, z))	mesh.AddVertices(VERTEX::Add_CUBE_Front(		Vector3f(x, y, z), Color));
				if (!FaceBack(x, y, z))		mesh.AddVertices(VERTEX::Add_CUBE_Back(		Vector3f(x, y, z), Color));
				if (!FaceTop(x, y, z))		mesh.AddVertices(VERTEX::Add_CUBE_Top(			Vector3f(x, y, z), Color));
				if (!FaceBottom(x, y, z))	mesh.AddVertices(VERTEX::Add_CUBE_Bottom(		Vector3f(x, y, z), Color));

				//std::cout << GetVoxel(x, y, z);
			}
			//std::cout << "\n";
		}
		//std::cout << "\n";
	}


	return mesh.GetVertices();
}

void VoxelChunk::SetVoxel(unsigned int x, unsigned int y, unsigned int z, unsigned int id) { this->pVoxel[x][y][z] = id; }
unsigned int VoxelChunk::GetVoxel(unsigned int x, unsigned int y, unsigned int z) { return this->pVoxel[x][y][z]; }






bool VoxelChunk::FaceLeft(unsigned int x, unsigned int y, unsigned int z) { 
	if (x == 0)
		return false;
	if (GetVoxel(x-1, y, z) != 0)
		return true;

	return false;
}
bool VoxelChunk::FaceRight(unsigned int x, unsigned int y, unsigned int z) { 
	if (x == CHUNK_SIZE-1)
		return false;
	if (GetVoxel(x + 1, y, z) != 0)
		return true;

	return false;
}
bool VoxelChunk::FaceFront(unsigned int x, unsigned int y, unsigned int z) { 
	if (z == CHUNK_SIZE-1)
		return false;
	if (GetVoxel(x, y, z+1) != 0)
		return true;

	return false;
}
bool VoxelChunk::FaceBack(unsigned int x, unsigned int y, unsigned int z) { 
	if (z == 0)
		return false;
	if (GetVoxel(x, y, z - 1) != 0)
		return true;

	return false;
}
bool VoxelChunk::FaceTop(unsigned int x, unsigned int y, unsigned int z) { 
	if (y == CHUNK_SIZE-1)
		return false;
	if (GetVoxel(x, y+1, z) != 0)
		return true;

	return false;
}
bool VoxelChunk::FaceBottom(unsigned int x, unsigned int y, unsigned int z) {
	if (y == 0)
		return false;
	if (GetVoxel(x, y - 1, z) != 0)
		return true;

	return false;
}