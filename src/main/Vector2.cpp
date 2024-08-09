#include "Vector2.hpp"
#include "math.h"

Vector2 VECTOR2_ZERO = Vector2(0, 0);
Vector2 VECTOR2_RIGHT = Vector2(1, 0);
Vector2 VECTOR2_LEFT = Vector2(-1, 0);
Vector2 VECTOR2_UP = Vector2(0, -1);
Vector2 VECTOR2_DOWN = Vector2(0, 1);

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vector2::lenght() {
	return sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() {
	float len = this->lenght();
	if(len == 0) {
		return Vector2();
	}
	return Vector2(this->x/len, this->y/len);
}

float Vector2::distanceTo(Vector2 &v) {
	return sqrt(
		(this->x - v.x) * (this->x - v.x) +
		(this->y - v.y) * (this->y - v.y)
	);
}

Vector2 Vector2::operator+=(const Vector2 & p){   
	x += p.x;
	y += p.y;
	return *this;
}

Vector2 Vector2::operator*=(const Vector2 &p){
	x *= p.x;
	y *= p.y;
	return * this;
}

Vector2 Vector2::operator*=(const float f){
	x *= f;
	y *= f;
	return * this;
}

Vector2 Vector2::operator-=(const Vector2 &p){
	x -= p.x;
	y -= p.y;
	return * this;
}

Vector2 Vector2::operator/=(const Vector2 &p){
	x /= p.x;
	y /= p.y;
	return * this;
}

Vector2 Vector2::operator+(const Vector2 &p){
	Vector2 v = Vector2(this->x, this->y);
	v.x += p.x;
	v.y += p.y;
	return v;
}

Vector2 Vector2::operator*(const Vector2 &p){
	Vector2 v = Vector2(this->x, this->y);
	v.x *= p.x;
	v.y *= p.y;
	return v;
}

Vector2 Vector2::operator*(const float f){
	Vector2 v = Vector2(this->x, this->y);
	v.x *= f;
	v.y *= f;
	return v;
}

Vector2 Vector2::operator-(const Vector2 &p){
	Vector2 v = Vector2(this->x, this->y);
	v.x -= p.x;
	v.y -= p.y;
	return v;
}

Vector2 Vector2::operator/(const Vector2 &p){
	Vector2 v = Vector2(this->x, this->y);
	v.x /= p.x;
	v.y /= p.y;
	return v;
	
}

