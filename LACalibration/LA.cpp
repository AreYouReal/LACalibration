// LA.cpp

#include "LA.h"

// For printing stuff - while debugging
#include <iostream>

// Attention! LA it is a ROW MAJOR linear algebra library

// Vector3D definition
Vector3D::Vector3D()
	: x(0.0f),y(0.0f),z(0.0f){}
Vector3D::Vector3D(float x, float y, float z)
	: x(x), y(y), z(z){}
Vector3D::Vector3D(const Vector4D& vec){
	x = vec.x / vec.w; y = vec.y / vec.w; z = vec.z / vec.w;
}
Vector3D::~Vector3D(){}
float& Vector3D::operator[](int i){
		switch(i){
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		}
    return x;
};

void Vector3D::operator=(const Vector3D& vec3){
	x = vec3.x;	y = vec3.y;	z = vec3.z;
}

// Global Vector3D operator definitions
void print(const Vector3D& vec3){
	std::cout << "[ " << vec3.x << ", " << vec3.y << ", " << vec3.z << " ]" << std::endl;	
}
Vector3D operator+(const Vector3D& v1, const Vector3D& v2){
	Vector3D rVec3;
	rVec3.x = v1.x + v2.x;	rVec3.y = v1.y + v2.y;	rVec3.z = v1.z + v2.z;
	return rVec3;
}
Vector3D operator-(const Vector3D& v2, const Vector3D& v1){
	Vector3D rVec3;
	rVec3.x = v2.x - v1.x;	rVec3.y = v2.y - v1.y;	rVec3.z = v2.z - v1.z;
	return rVec3;
}
Vector3D operator-(const Vector3D& vec){
	Vector3D rVec3;
	rVec3.x = -vec.x; rVec3.y = -vec.y; rVec3.z = -vec.z;
	return rVec3;
}
Vector3D operator*(const float scalar, const Vector3D& vec3){
	Vector3D rVec3;
	rVec3.x = scalar * vec3.x;	rVec3.y = scalar * vec3.y;	rVec3.z = scalar * vec3.z;
	return rVec3;
}
Vector3D operator*(const Vector3D& vec3, const float scalar){
	return operator*(scalar, vec3);
}
Vector3D operator/(const Vector3D& vec3, const float scalar){
	Vector3D rVec3;
	rVec3.x = vec3.x / scalar;	rVec3.y = vec3.y / scalar;	rVec3.z = vec3.z / scalar;
	return rVec3;
}

Vector4D::Vector4D()
:x(0.0f), y(0.0f), z(0.0f), w(0.0f){}
Vector4D::Vector4D(float x, float y, float z, float w)
:x(x),y(y),z(z),w(w){}
Vector4D::~Vector4D(){}
float& Vector4D::operator[](int i){
		switch(i){
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		case 3:
			return w;
			break;
		}
    return x;
}
void Vector4D::operator=(const Vector4D& vec){
	x = vec.x; y = vec.y; z = vec.z; w = vec.w;
}

void print(const Vector4D& vec4){
	std::cout << "[ " << vec4.x << ", " << vec4.y << ", " << vec4.z << ", " << vec4.w << " ]" << std::endl;
}

// Point3D definition
Point3D::Point3D()
:x(0.0f),y(0.0f),z(0.0f){}
Point3D::Point3D(float x, float y, float z)
:x(x),y(y),z(z){}
Point3D::~Point3D(){}
void Point3D::operator=(const Point3D& point){
	x = point.x;	y = point.y;	z = point.z;
}
void print(const Point3D& point){
	std::cout << "[ " << point.x << ", " << point.y << ", " << point.z << " ]" << std::endl;	
}

// Global Point3D operator definitions
Point3D operator+(const Point3D point, const Vector3D& vec3){
	Point3D rPoint3;
	rPoint3.x = point.x + vec3.x;	rPoint3.y = point.y + vec3.y;	rPoint3.z = point.z + vec3.z;
	return rPoint3;
}
Vector3D operator-(const Point3D& p2, const Point3D& p1){
	Vector3D rVec3;
	rVec3.x = p2.x - p1.x; rVec3.y = p2.y - p1.y; rVec3.z = p2.z - p1.z;
	return rVec3;
}

// Matrix4D definition
Matrix4D::Matrix4D(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i == j)
				m[i][j] = 1.0f;
			else
				m[i][j] = 0.0f;
		}
	}
}
Matrix4D::Matrix4D(const Matrix4D& m4){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = m4.m[i][j];
		}
	}
}
Matrix4D::Matrix4D(const float arr[16]){
	int offset = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = arr[offset++];
		}
	}
}

Matrix4D::Matrix4D(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23,
			 float m30, float m31, float m32, float m33){
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}
Matrix4D::~Matrix4D(){};

void Matrix4D::operator=(const Matrix4D& m4){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = m4.m[i][j];
		}
	}
}

void print(const Matrix4D& m){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cout << m.m[i][j] << "  "; 
		}
	std::cout << std::endl;
	}
	std::cout << std::endl;
}
Matrix4D operator*(const Matrix4D& m1, const Matrix4D& m2){
	Matrix4D rMat4;
	for(int row = 0; row < 4; row++){
		for(int col = 0; col < 4; col++){
			float temp = 0;
			for(int i = 0; i < 4; i++){
				temp += m1.m[row][i] * m2.m[i][col];
			}
			rMat4.m[row][col] = temp;		
		}
	}
	return rMat4;
}
Matrix4D operator*(const float scalar, const Matrix4D& m4){
	Matrix4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = scalar * m4.m[i][j];
		}
	}
	return rMat4;
}
Matrix4D operator*(const Matrix4D& m4, const float scalar){
	return operator*(scalar, m4);
}
Matrix4D operator/(const Matrix4D& m4, const float scalar){
	return operator*(m4, (1.0f / scalar));
}
Matrix4D operator+(const Matrix4D& m1, const Matrix4D& m2){
	Matrix4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	return rMat4;
}

Vector4D operator*(const Matrix4D& m, Vector4D& vec){
	Vector4D rVec4;
	for(int row = 0; row < 4; row++){
		float result = 0;
		for(int col = 0; col < 4; col++){
			result += m.m[row][col] * vec[col];
		}
		rVec4[row] = result;
	}
	return rVec4;
}

// LA - Linear Algebra class definition
// static method to operate with Vector3D, Point3D, etc...
LA::LA(){}
LA::~LA(){}

// Vector3D operation definitions (dot product, cross product, length, normalize operation)
float LA::dot(const Vector3D& v1, const Vector3D& v2){
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
};
Vector3D LA::cross(const Vector3D& v1, const Vector3D& v2){
	Vector3D rVec3;
	rVec3.x = v1.y * v2.z - v1.z * v2.y;	rVec3.y = v1.z * v2.x - v1.x * v2.z;	rVec3.z = v1.x * v2.y - v1.y * v2.x;
	return rVec3;
}
float LA::length(const Vector3D& vec3){
	return sqrtf(dot(vec3, vec3));
}
Vector3D LA::normalize(const Vector3D& vec3){
	Vector3D rVec3;
	float length = LA::length(vec3);
	rVec3.x = vec3.x / length; rVec3.y = vec3.y / length; rVec3.z = vec3.z / length;
	return rVec3;
}

// Matrix4D operation definitions (all requared transformations)
float LA::determinant(const Matrix4D& m4){
	return 
		m4.m[0][0] * (m4.m[1][1] * (m4.m[2][2] * m4.m[3][3] - m4.m[3][2] * m4.m[2][3]) - m4.m[1][2] * (m4.m[2][1] * m4.m[3][3] - m4.m[3][1] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][1] * m4.m[3][2] - m4.m[3][1] * m4.m[2][2]) )
	  - m4.m[0][1] * (m4.m[1][0] * (m4.m[2][2] * m4.m[3][3] - m4.m[3][2] * m4.m[2][3]) - m4.m[1][2] * (m4.m[2][0] * m4.m[3][3] - m4.m[3][0] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][0] * m4.m[3][2] - m4.m[3][0] * m4.m[2][2]) )
	  + m4.m[0][2] * (m4.m[1][0] * (m4.m[2][1] * m4.m[3][3] - m4.m[3][1] * m4.m[2][3]) - m4.m[1][1] * (m4.m[2][0] * m4.m[3][3] - m4.m[3][0] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][0] * m4.m[3][1] - m4.m[3][0] * m4.m[2][1]) )
	  - m4.m[0][3] * (m4.m[1][0] * (m4.m[2][1] * m4.m[3][2] - m4.m[3][1] * m4.m[2][2]) - m4.m[1][1] * (m4.m[2][0] * m4.m[3][2] - m4.m[3][0] * m4.m[2][2]) + m4.m[1][2] * (m4.m[2][0] * m4.m[3][1] - m4.m[3][0] * m4.m[2][1]) );
}
Matrix4D LA::transpose(const Matrix4D& m4){
	Matrix4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = m4.m[j][i];
		}
	}
	return rMat4;
}

Matrix4D LA::inverse(const Matrix4D& m4){
	Matrix4D rMat4;
	rMat4.m[0][0] = m4.m[1][1] * m4.m[2][2] * m4.m[3][3] + m4.m[1][2] * m4.m[2][3] * m4.m[3][1] + m4.m[1][3] * m4.m[2][1] * m4.m[3][2] - m4.m[1][1] * m4.m[2][3] * m4.m[3][2] - m4.m[1][2] * m4.m[2][1] * m4.m[3][3] - m4.m[1][3] * m4.m[2][2] * m4.m[3][1];
	rMat4.m[0][1] = m4.m[0][1] * m4.m[2][3] * m4.m[3][2] + m4.m[0][2] * m4.m[2][1] * m4.m[3][3] + m4.m[0][3] * m4.m[2][2] * m4.m[3][1] - m4.m[0][1] * m4.m[2][2] * m4.m[3][3] - m4.m[0][2] * m4.m[2][3] * m4.m[3][1] - m4.m[0][3] * m4.m[2][1] * m4.m[3][2];
	rMat4.m[0][2] = m4.m[0][1] * m4.m[1][2] * m4.m[3][3] + m4.m[0][2] * m4.m[1][3] * m4.m[3][1] + m4.m[0][3] * m4.m[1][1] * m4.m[3][2] - m4.m[0][1] * m4.m[1][3] * m4.m[3][2] - m4.m[0][2] * m4.m[1][1] * m4.m[3][3] - m4.m[0][3] * m4.m[1][2] * m4.m[3][1];
	rMat4.m[0][3] = m4.m[0][1] * m4.m[1][3] * m4.m[2][2] + m4.m[0][2] * m4.m[1][1] * m4.m[2][3] + m4.m[0][3] * m4.m[1][2] * m4.m[2][1] - m4.m[0][1] * m4.m[1][2] * m4.m[2][3] - m4.m[0][2] * m4.m[1][3] * m4.m[2][1] - m4.m[0][3] * m4.m[1][1] * m4.m[2][2];
	
	rMat4.m[1][0] = m4.m[1][0] * m4.m[2][3] * m4.m[3][2] + m4.m[1][2] * m4.m[2][0] * m4.m[3][3] + m4.m[1][3] * m4.m[2][2] * m4.m[3][0] - m4.m[1][0] * m4.m[2][2] * m4.m[3][3] - m4.m[1][2] * m4.m[2][3] * m4.m[3][0] - m4.m[1][3] * m4.m[2][0] * m4.m[3][2];
	rMat4.m[1][1] = m4.m[0][0] * m4.m[2][2] * m4.m[3][3] + m4.m[0][2] * m4.m[2][3] * m4.m[3][0] + m4.m[0][3] * m4.m[2][0] * m4.m[3][2] - m4.m[0][0] * m4.m[2][3] * m4.m[3][2] - m4.m[0][2] * m4.m[2][0] * m4.m[3][3] - m4.m[0][3] * m4.m[2][2] * m4.m[3][0];	
	rMat4.m[1][2] = m4.m[0][0] * m4.m[1][3] * m4.m[3][2] + m4.m[0][2] * m4.m[1][0] * m4.m[3][3] + m4.m[0][3] * m4.m[1][2] * m4.m[3][0] - m4.m[0][0] * m4.m[1][2] * m4.m[3][3] - m4.m[0][2] * m4.m[1][3] * m4.m[3][0] - m4.m[0][3] * m4.m[1][0] * m4.m[3][2];	
	rMat4.m[1][3] = m4.m[0][0] * m4.m[1][2] * m4.m[2][3] + m4.m[0][2] * m4.m[1][3] * m4.m[2][0] + m4.m[0][3] * m4.m[1][0] * m4.m[2][2] - m4.m[0][0] * m4.m[1][3] * m4.m[2][2] - m4.m[0][2] * m4.m[1][0] * m4.m[2][3] - m4.m[0][3] * m4.m[1][2] * m4.m[2][0];	

	rMat4.m[2][0] = m4.m[1][0] * m4.m[2][1] * m4.m[3][3] + m4.m[1][1] * m4.m[2][3] * m4.m[3][0] + m4.m[1][3] * m4.m[2][0] * m4.m[3][1] - m4.m[1][0] * m4.m[2][3] * m4.m[3][1] - m4.m[1][1] * m4.m[2][0] * m4.m[3][3] - m4.m[1][3] * m4.m[2][1] * m4.m[3][0];	
	rMat4.m[2][1] = m4.m[0][0] * m4.m[2][3] * m4.m[3][1] + m4.m[0][1] * m4.m[2][0] * m4.m[3][3] + m4.m[0][3] * m4.m[2][1] * m4.m[3][0] - m4.m[0][0] * m4.m[2][1] * m4.m[3][3] - m4.m[0][1] * m4.m[2][3] * m4.m[3][0] - m4.m[0][3] * m4.m[2][0] * m4.m[3][1];
	rMat4.m[2][2] = m4.m[0][0] * m4.m[1][1] * m4.m[3][3] + m4.m[0][1] * m4.m[1][3] * m4.m[3][0] + m4.m[0][3] * m4.m[1][0] * m4.m[3][1] - m4.m[0][0] * m4.m[1][3] * m4.m[3][1] - m4.m[0][1] * m4.m[1][0] * m4.m[3][3] - m4.m[0][3] * m4.m[1][1] * m4.m[3][0];
	rMat4.m[2][3] = m4.m[0][0] * m4.m[1][3] * m4.m[2][1] + m4.m[0][1] * m4.m[1][0] * m4.m[2][3] + m4.m[0][3] * m4.m[1][1] * m4.m[2][0] - m4.m[0][0] * m4.m[1][1] * m4.m[2][3] - m4.m[0][1] * m4.m[1][3] * m4.m[2][0] - m4.m[0][3] * m4.m[1][0] * m4.m[2][1];

	rMat4.m[3][0] = m4.m[1][0] * m4.m[2][2] * m4.m[3][1] + m4.m[1][1] * m4.m[2][0] * m4.m[3][2] + m4.m[1][2] * m4.m[2][1] * m4.m[3][0] - m4.m[1][0] * m4.m[2][1] * m4.m[3][2] - m4.m[1][1] * m4.m[2][2] * m4.m[3][0] - m4.m[1][2] * m4.m[2][0] * m4.m[3][1];
	rMat4.m[3][1] = m4.m[0][0] * m4.m[2][1] * m4.m[3][2] + m4.m[0][1] * m4.m[2][2] * m4.m[3][0] + m4.m[0][2] * m4.m[2][0] * m4.m[3][1] - m4.m[0][0] * m4.m[2][2] * m4.m[3][1] - m4.m[0][1] * m4.m[2][0] * m4.m[3][2] - m4.m[0][2] * m4.m[2][1] * m4.m[3][0];
	rMat4.m[3][2] = m4.m[0][0] * m4.m[1][2] * m4.m[3][1] + m4.m[0][1] * m4.m[1][0] * m4.m[3][2] + m4.m[0][2] * m4.m[1][1] * m4.m[3][0] - m4.m[0][0] * m4.m[1][1] * m4.m[3][2] - m4.m[0][1] * m4.m[1][2] * m4.m[3][0] - m4.m[0][2] * m4.m[1][0] * m4.m[3][1];
	rMat4.m[3][3] = m4.m[0][0] * m4.m[1][1] * m4.m[2][2] + m4.m[0][1] * m4.m[1][2] * m4.m[2][0] + m4.m[0][2] * m4.m[1][0] * m4.m[2][1] - m4.m[0][0] * m4.m[1][2] * m4.m[2][1] - m4.m[0][1] * m4.m[1][0] * m4.m[2][2] - m4.m[0][2] * m4.m[1][1] * m4.m[2][0];

	rMat4 = rMat4 / determinant(m4);
	return rMat4;
}
Matrix4D LA::inverseTranspose(const Matrix4D& m4){
	return LA::transpose(LA::inverse(m4));
}
Matrix4D LA::lookAt(float eyeX, float eyeY, float eyeZ, float lookAtX, float lookAtY, float lookAtZ, float upX, float upY, float upZ){
	Matrix4D rMat4;
	Vector3D eye(eyeX, eyeY, eyeZ);
	Vector3D lookAt(lookAtX, lookAtY, lookAtZ);
	Vector3D up(upX, upY, upZ);
	return LA::lookAt(eye, lookAt, up);
}
Matrix4D LA::lookAt(Vector3D& eye, Vector3D& lookAt, Vector3D& up){
	Matrix4D rMat4;
	Vector3D w = LA::normalize(eye - lookAt);
	Vector3D u = LA::normalize(LA::cross(up, w));
	Vector3D v = LA::normalize(LA::cross(w, u));
	for(int i = 0; i < 3; i++){
		rMat4.m[0][i] = u[i];
		rMat4.m[1][i] = v[i];
		rMat4.m[2][i] = w[i];
	}
	rMat4.m[0][3] = dot(u, -eye); 
	rMat4.m[1][3] = dot(v, -eye);
	rMat4.m[2][3] = dot(w, -eye);
	return rMat4;
}
Matrix4D LA::perspective(float fovy, float w, float h, float n, float f){
	float aspect = w / h;
	float A = - (f + n)/(f - n);
	float B = -(2 * f * n)/(f - n);
	float angleOfView =  PI / 180 * fovy;
	float d = 1.0f / tanf(angleOfView/2);

	Matrix4D rMat4(d/aspect, 0, 0, 0,
				      0,     d, 0, 0,
					  0,     0, A, B,
					  0,     0, -1,0);

	return rMat4;
}
Matrix4D LA::rotate(float angle, float x, float y, float z){
	Vector3D axis(x, y, z);
	return LA::rotate(angle, axis);
}
Matrix4D LA::rotate(float angle, Vector3D& axis){
	float degree = PI / 180 * angle;
	Vector3D nAxis = LA::normalize(axis);
	float x = nAxis.x;
	float y = nAxis.y;
	float z = nAxis.z;
	float c = cos(degree);
	float s = sin(degree);

	Matrix4D rMat4(c + (1 - c)* x * x, (1 - c) * x * y - s * z, (1 - c) * x * z + s * y, 0,
				   (1 - c) * x * y + s * z, c + (1 - c) * y * y, (1 - c) * y * z - s * x, 0,
				   (1- c) * x * z - s * y, (1 - c) * y * z + s * x, c + (1 - c) * z * z, 0,
				   0, 0, 0, 1);

	return rMat4;
}
Matrix4D LA::scale(float x, float y, float z){
	Vector3D scale(x, y, z);
	return LA::scale(scale);
}
Matrix4D LA::scale(Vector3D& scale){
	Matrix4D rMat4(scale.x, 0, 0, 0,
					0, scale.y, 0, 0,
					0, 0, scale.z, 0,
					0,	  0,   0,  1);
	return rMat4;
}
Matrix4D LA::translate(float x, float y, float z){
	Vector3D translate(x, y, z);
	return LA::translate(translate);
}
Matrix4D LA::translate(Vector3D& translate){
	Matrix4D rMat4(1, 0, 0, translate.x,
				   0, 1, 0, translate.y,
				   0, 0, 1, translate.z,
				   0, 0, 0,      1);

	return rMat4;
}

float* LA::getPointer(Matrix4D &mat){
	return &(mat.m[0][0]);
}

