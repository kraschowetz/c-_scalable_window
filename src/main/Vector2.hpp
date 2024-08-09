#pragma once

struct Vector2 {
	public:
		float x, y;
	public:
		Vector2() : x(0), y(0) {}
		Vector2(float x, float y);
		float lenght();
		float distanceTo(Vector2 &v);
		Vector2 normalized();
	public:
		Vector2 operator+=(const Vector2 &p);
		Vector2 operator*=(const Vector2 &p);
		Vector2 operator-=(const Vector2 &p);
		Vector2 operator/=(const Vector2 &p);
		Vector2 operator+(const Vector2 &p);
		Vector2 operator*(const Vector2 &p);
		Vector2 operator-(const Vector2 &p);
		Vector2 operator/(const Vector2 &p);

		Vector2 operator*=(const float f);
		Vector2 operator*(const float f);
	
};

extern Vector2 VECTOR2_ZERO;
extern Vector2 VECTOR2_RIGHT;
extern Vector2 VECTOR2_LEFT;
extern Vector2 VECTOR2_UP;
extern Vector2 VECTOR2_DOWN;
