#pragma once

struct Vector3f
{
	float x, y, z;
	Vector3f(float X, float Y, float Z) : x(X), y(Y), z(Z){}
	Vector3f(float value) : x(value), y(value), z(value) {}
	Vector3f() : x(0.f), y(0.f), z(0.f) {}
};

struct Vector2f
{
	float x, y;
	Vector2f(float X, float Y) : x(X), y(Y) {}
	Vector2f(float value) : x(value), y(value) {}
	Vector2f() : x(0.f), y(0.f) {}
};