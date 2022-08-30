#pragma once
#include <vector>
#include "Mesh.h"

namespace VERTEX
{
	static std::vector<Vertex> Add_CUBE_Front(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 0.8f;

		Vector3f vert_pos1 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 1);
		Vector3f vert_pos2 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 1);
		Vector3f vert_pos3 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);

		Vector3f vert_pos4 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);
		Vector3f vert_pos5 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 1);
		Vector3f vert_pos6 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 1);
		
		vertices.push_back(Vertex{ vert_pos1, Color, Shade});
		vertices.push_back(Vertex{ vert_pos2, Color, Shade});
		vertices.push_back(Vertex{ vert_pos3, Color, Shade});
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});
		vertices.push_back(Vertex{ vert_pos5, Color, Shade});
		vertices.push_back(Vertex{ vert_pos6, Color, Shade});

		return vertices;
	}
	static std::vector<Vertex> Add_CUBE_Back(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 0.6;

		Vector3f vert_pos1 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);
		Vector3f vert_pos2 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 0);
		Vector3f vert_pos3 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 0);

		Vector3f vert_pos4 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 0);
		Vector3f vert_pos5 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 0);
		Vector3f vert_pos6 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);

		vertices.push_back(Vertex{ vert_pos3, Color, Shade});
		vertices.push_back(Vertex{ vert_pos2, Color, Shade});
		vertices.push_back(Vertex{ vert_pos1, Color, Shade});
		vertices.push_back(Vertex{ vert_pos6, Color, Shade});
		vertices.push_back(Vertex{ vert_pos5, Color, Shade});
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});

		return vertices;
	}
	static std::vector<Vertex> Add_CUBE_Left(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 0.5f;

		Vector3f vert_pos1 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 1);
		Vector3f vert_pos2 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 0);
		Vector3f vert_pos3 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);

		Vector3f vert_pos4 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);
		Vector3f vert_pos5 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 1);
		Vector3f vert_pos6 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 1);

		vertices.push_back(Vertex{ vert_pos1, Color, Shade});
		vertices.push_back(Vertex{ vert_pos2, Color, Shade});
		vertices.push_back(Vertex{ vert_pos3, Color, Shade});
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});
		vertices.push_back(Vertex{ vert_pos5, Color, Shade});
		vertices.push_back(Vertex{ vert_pos6, Color, Shade});

		return vertices;
	}
	static std::vector<Vertex> Add_CUBE_Right(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 0.4f;

		/*0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  */

		Vector3f vert_pos1 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);
		Vector3f vert_pos2 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 0);
		Vector3f vert_pos3 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 0);

		Vector3f vert_pos4 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 0);
		Vector3f vert_pos5 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 1);
		Vector3f vert_pos6 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);

		vertices.push_back(Vertex{ vert_pos3, Color, Shade });
		vertices.push_back(Vertex{ vert_pos2, Color, Shade });
		vertices.push_back(Vertex{ vert_pos1, Color, Shade });
		vertices.push_back(Vertex{ vert_pos6, Color, Shade });
		vertices.push_back(Vertex{ vert_pos5, Color, Shade });
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});

		return vertices;
	}
	static std::vector<Vertex> Add_CUBE_Top(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 1.0f;

		/*-0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, */

		Vector3f vert_pos1 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 0);
		Vector3f vert_pos2 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 0);
		Vector3f vert_pos3 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);

		Vector3f vert_pos4 = Vector3f(Position.x + 1, Position.y + 1, Position.z + 1);
		Vector3f vert_pos5 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 1);
		Vector3f vert_pos6 = Vector3f(Position.x + 0, Position.y + 1, Position.z + 0);

		vertices.push_back(Vertex{ vert_pos3, Color, Shade});
		vertices.push_back(Vertex{ vert_pos2, Color, Shade});
		vertices.push_back(Vertex{ vert_pos1, Color, Shade});
		vertices.push_back(Vertex{ vert_pos6, Color, Shade});
		vertices.push_back(Vertex{ vert_pos5, Color, Shade});
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});

		return vertices;
	}
	static std::vector<Vertex> Add_CUBE_Bottom(const Vector3f Position, const Vector3f Color)
	{
		std::vector<Vertex> vertices;
		float Shade = 0.3f;

		/*-0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f,*/

		Vector3f vert_pos1 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);
		Vector3f vert_pos2 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 0);
		Vector3f vert_pos3 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 1);

		Vector3f vert_pos4 = Vector3f(Position.x + 1, Position.y + 0, Position.z + 1);
		Vector3f vert_pos5 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 1);
		Vector3f vert_pos6 = Vector3f(Position.x + 0, Position.y + 0, Position.z + 0);

		vertices.push_back(Vertex{ vert_pos1, Color, Shade});
		vertices.push_back(Vertex{ vert_pos2, Color, Shade});
		vertices.push_back(Vertex{ vert_pos3, Color, Shade});
		vertices.push_back(Vertex{ vert_pos4, Color, Shade});
		vertices.push_back(Vertex{ vert_pos5, Color, Shade});
		vertices.push_back(Vertex{ vert_pos6, Color, Shade});

		return vertices;
	}
}