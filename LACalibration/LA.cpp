// LA.cpp

#include "LA.h"

// For printing stuff - while debugging
#include <iostream>

// Attention! LA it is a ROW MAJOR linear algebra library

// V3D definition
V3D::V3D(){}
V3D::V3D(float x, float y, float z){
    v[0] = x; v[1] = y; v[2] = z;
}
V3D::V3D(const V4D& vec){
	v[0] = vec.v[0] / vec.v[3]; v[1] = vec.v[1] / vec.v[3]; v[2] = vec.v[2] / vec.v[3];
}
V3D::~V3D(){}
float& V3D::operator[](int i){
    return i > 2 ? v[0] : v[i];
};

void V3D::operator=(const V3D& vec3){
	v[0] = vec3.v[0];	v[1] = vec3.v[1];	v[2] = vec3.v[2];
}

// Global V3D operator definitions
void print(const V3D& vec3){
	std::cout << "[ " << vec3.v[0] << ", " << vec3.v[1] << ", " << vec3.v[2] << " ]" << std::endl;
}
V3D operator+(const V3D& v1, const V3D& v2){
	V3D rVec3;
	rVec3.v[0] = v1.v[0] + v2.v[0];	rVec3.v[1] = v1.v[1] + v2.v[1];	rVec3.v[2] = v1.v[2] + v2.v[2];
	return rVec3;
}
V3D operator-(const V3D& v2, const V3D& v1){
	V3D rVec3;
	rVec3.v[0] = v2.v[0] - v1.v[0];	rVec3.v[1] = v2.v[1] - v1.v[1];	rVec3.v[2] = v2.v[2] - v1.v[2];
	return rVec3;
}
V3D operator-(const V3D& vec){
	V3D rVec3;
	rVec3.v[0] = -vec.v[0]; rVec3.v[1] = -vec.v[1]; rVec3.v[2] = -vec.v[2];
	return rVec3;
}
V3D operator*(const float scalar, const V3D& vec3){
	V3D rVec3;
	rVec3.v[0] = scalar * vec3.v[0];	rVec3.v[1] = scalar * vec3.v[1];	rVec3.v[2] = scalar * vec3.v[2];
	return rVec3;
}
V3D operator*(const V3D& vec3, const float scalar){
	return operator*(scalar, vec3);
}
V3D operator/(const V3D& vec3, const float scalar){
	V3D rVec3;
	rVec3.v[0] = vec3.v[0] / scalar;	rVec3.v[1] = vec3.v[1] / scalar;	rVec3.v[2] = vec3.v[2] / scalar;
	return rVec3;
}

V4D::V4D(){}
V4D::V4D(float x, float y, float z, float w){
    v[0] = x; v[1] = y; v[2] = z; v[3] = w;
}
V4D::~V4D(){}
float& V4D::operator[](int i){
    return i > 3 ? v[0] : v[i];
}
void V4D::operator=(const V4D& vec){
	v[0] = vec.v[0]; v[1] = vec.v[1]; v[2] = vec.v[2]; v[3] = vec.v[3];
}

void print(const V4D& vec4){
	std::cout << "[ " << vec4.v[0] << ", " << vec4.v[1] << ", " << vec4.v[2] << ", " << vec4.v[3] << " ]" << std::endl;
}

// M4D definition
M4D::M4D(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i == j)
				m[i][j] = 1.0f;
			else
				m[i][j] = 0.0f;
		}
	}
}
M4D::M4D(const M4D& m4){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = m4.m[i][j];
		}
	}
}
M4D::M4D(const float arr[16]){
	int offset = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = arr[offset++];
		}
	}
}

M4D::M4D(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23,
			 float m30, float m31, float m32, float m33){
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}
M4D::~M4D(){};

void M4D::operator=(const M4D& m4){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			m[i][j] = m4.m[i][j];
		}
	}
}

void print(const M4D& m){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cout << m.m[i][j] << "  "; 
		}
	std::cout << std::endl;
	}
	std::cout << std::endl;
}
M4D operator*(const M4D& m1, const M4D& m2){
	M4D rMat4;
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
M4D operator*(const float scalar, const M4D& m4){
	M4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = scalar * m4.m[i][j];
		}
	}
	return rMat4;
}
M4D operator*(const M4D& m4, const float scalar){
	return operator*(scalar, m4);
}
M4D operator/(const M4D& m4, const float scalar){
	return operator*(m4, (1.0f / scalar));
}
M4D operator+(const M4D& m1, const M4D& m2){
	M4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	return rMat4;
}

V4D operator*(const M4D& m, V4D& vec){
	V4D rVec4;
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
// static method to operate with V3D, Point3D, etc...
LA::LA(){}
LA::~LA(){}

// V3D operation definitions (dot product, cross product, length, normalize operation)
float LA::dot(const V3D& v1, const V3D& v2){
	return (v1.v[0] * v2.v[0]) + (v1.v[1] * v2.v[1]) + (v1.v[2] * v2.v[2]);
};
V3D LA::cross(const V3D& v1, const V3D& v2){
	V3D rVec3;
	rVec3.v[0] = v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1];
    rVec3.v[1] = v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2];
    rVec3.v[2] = v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0];
	return rVec3;
}
float LA::length(const V3D& vec3){
	return sqrtf(dot(vec3, vec3));
}
V3D LA::normalize(const V3D& vec3){
	V3D rVec3;
	float length = LA::length(vec3);
	rVec3.v[0] = vec3.v[0] / length;
    rVec3.v[1] = vec3.v[1] / length;
    rVec3.v[2] = vec3.v[2] / length;
	return rVec3;
}

// M4D operation definitions (all requared transformations)
float LA::determinant(const M4D& m4){
	return 
		m4.m[0][0] * (m4.m[1][1] * (m4.m[2][2] * m4.m[3][3] - m4.m[3][2] * m4.m[2][3]) - m4.m[1][2] * (m4.m[2][1] * m4.m[3][3] - m4.m[3][1] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][1] * m4.m[3][2] - m4.m[3][1] * m4.m[2][2]) )
	  - m4.m[0][1] * (m4.m[1][0] * (m4.m[2][2] * m4.m[3][3] - m4.m[3][2] * m4.m[2][3]) - m4.m[1][2] * (m4.m[2][0] * m4.m[3][3] - m4.m[3][0] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][0] * m4.m[3][2] - m4.m[3][0] * m4.m[2][2]) )
	  + m4.m[0][2] * (m4.m[1][0] * (m4.m[2][1] * m4.m[3][3] - m4.m[3][1] * m4.m[2][3]) - m4.m[1][1] * (m4.m[2][0] * m4.m[3][3] - m4.m[3][0] * m4.m[2][3]) + m4.m[1][3] * (m4.m[2][0] * m4.m[3][1] - m4.m[3][0] * m4.m[2][1]) )
	  - m4.m[0][3] * (m4.m[1][0] * (m4.m[2][1] * m4.m[3][2] - m4.m[3][1] * m4.m[2][2]) - m4.m[1][1] * (m4.m[2][0] * m4.m[3][2] - m4.m[3][0] * m4.m[2][2]) + m4.m[1][2] * (m4.m[2][0] * m4.m[3][1] - m4.m[3][0] * m4.m[2][1]) );
}
M4D LA::transpose(const M4D& m4){
	M4D rMat4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			rMat4.m[i][j] = m4.m[j][i];
		}
	}
	return rMat4;
}

M4D LA::inverse(const M4D& m4){
	M4D rMat4;
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
M4D LA::inverseTranspose(const M4D& m4){
	return LA::transpose(LA::inverse(m4));
}
M4D LA::lookAt(float eyeX, float eyeY, float eyeZ, float lookAtX, float lookAtY, float lookAtZ, float upX, float upY, float upZ){
	M4D rMat4;
	V3D eye(eyeX, eyeY, eyeZ);
	V3D lookAt(lookAtX, lookAtY, lookAtZ);
	V3D up(upX, upY, upZ);
	return LA::lookAt(eye, lookAt, up);
}
M4D LA::lookAt(V3D& eye, V3D& lookAt, V3D& up){
	M4D rMat4;
	V3D w = LA::normalize(eye - lookAt);
	V3D u = LA::normalize(LA::cross(up, w));
	V3D v = LA::normalize(LA::cross(w, u));
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
M4D LA::perspective(float fovy, float w, float h, float n, float f){
	float aspect = w / h;
	float A = - (f + n)/(f - n);
	float B = -(2 * f * n)/(f - n);
	float angleOfView =  PI / 180 * fovy;
	float d = 1.0f / tanf(angleOfView/2);

	M4D rMat4(d/aspect, 0, 0, 0,
				      0,     d, 0, 0,
					  0,     0, A, B,
					  0,     0, -1,0);

	return rMat4;
}
M4D LA::rotate(float angle, float x, float y, float z){
	V3D axis(x, y, z);
	return LA::rotate(angle, axis);
}
M4D LA::rotate(float angle, V3D& axis){
	float degree = PI / 180 * angle;
	V3D nAxis = LA::normalize(axis);
	float x = nAxis.v[0];
	float y = nAxis.v[1];
	float z = nAxis.v[2];
	float c = cos(degree);
	float s = sin(degree);

	M4D rMat4(c + (1 - c)* x * x, (1 - c) * x * y - s * z, (1 - c) * x * z + s * y, 0,
				   (1 - c) * x * y + s * z, c + (1 - c) * y * y, (1 - c) * y * z - s * x, 0,
				   (1- c) * x * z - s * y, (1 - c) * y * z + s * x, c + (1 - c) * z * z, 0,
				   0, 0, 0, 1);

	return rMat4;
}
M4D LA::scale(float x, float y, float z){
	V3D scale(x, y, z);
	return LA::scale(scale);
}
M4D LA::scale(V3D& scale){
	M4D rMat4(scale.v[0], 0, 0, 0,
					0, scale.v[1], 0, 0,
					0, 0, scale.v[2], 0,
					0,	  0,   0,  1);
	return rMat4;
}
M4D LA::translate(float x, float y, float z){
	V3D translate(x, y, z);
	return LA::translate(translate);
}
M4D LA::translate(V3D& translate){
	M4D rMat4(1, 0, 0, translate.v[0],
				   0, 1, 0, translate.v[1],
				   0, 0, 1, translate.v[2],
				   0, 0, 0,      1);

	return rMat4;
}

float* LA::getPointer(M4D &mat){
	return &(mat.m[0][0]);
}

float* LA::getPointer(V3D &vec){
	return vec.v;
}

