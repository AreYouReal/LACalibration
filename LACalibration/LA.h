// LA.h

// "When your code has undefined behavior, you get a seg fault and corrupted data. 
// When Jeff Dean's code has undefined behavior, a unicorn rides in on a rainbow and gives everybody free ice cream."
// (c) Astounding 'Facts' About Google's Most Badass Engineer, Jeff Dean
 
#ifndef LA_H
#define LA_H

#include <cmath>

#define PI atan(1.0f)*4.0f

struct Vector4D{
public:
	Vector4D();
	Vector4D(float x, float y, float z, float w);
	~Vector4D();

	float& operator[](int i);
	void operator=(const Vector4D& vec);

	float x;
	float y;
	float z;
	float w;
};

void print(const Vector4D& vec4);

struct Vector3D{
public:
	Vector3D();
	Vector3D(float x, float y, float z);
	Vector3D(const Vector4D& vec);
	~Vector3D();

	float& operator[](int i);
	void operator=(const Vector3D& vec);

	float x;
	float y;
	float z;
};

void print(const Vector3D& vec3);
Vector3D operator*(const float scalar, const Vector3D& vec3);
Vector3D operator*(const Vector3D& vec3, const float scalar);
Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& vec);
Vector3D operator/(Vector3D& vec3, const float scalar);

struct Point3D{
public:
	Point3D();
	Point3D(float x, float y, float z);
	~Point3D();

	void operator=(const Point3D& point);

	float x;
	float y;
	float z;
};

void print(const Point3D& point);
Point3D operator+(const Point3D point, const Vector3D& vec3);
Vector3D operator-(const Point3D& p2, const Point3D& p1);

struct Matrix4D{
public:
	Matrix4D();
	Matrix4D(const Matrix4D& m4);
	Matrix4D(const float arr[16]);
	Matrix4D(float m11, float m12, float m13, float m14,
			 float m21, float m22, float m23, float m24,
			 float m31, float m32, float m33, float m34,
			 float m41, float m42, float m43, float m44);
	~Matrix4D();

	void operator=(const Matrix4D& m4);

	float m[4][4];
};

void print(const Matrix4D& m);
Matrix4D operator*(const Matrix4D& m1, const Matrix4D& m2);
Matrix4D operator*(const float scalar, const Matrix4D& m4);
Matrix4D operator*(const Matrix4D& m4, const float scalar);
Matrix4D operator/(const Matrix4D& m4, const float scalar);
Matrix4D operator+(const Matrix4D& m1, const Matrix4D& m2);

Vector4D operator*(const Matrix4D& m, Vector4D& vec);

struct LA{
public:
	LA();
	~LA();

	static float dot(const Vector3D& v1, const Vector3D& v2);
	static Vector3D cross(const Vector3D& v1, const Vector3D& v2);
	static float length(const Vector3D& vec3);
	static Vector3D normalize(const Vector3D& vec);

	static float determinant(const Matrix4D& m4);
	static Matrix4D transpose(const Matrix4D& m4);
	static Matrix4D inverse(const Matrix4D& m4);
	static Matrix4D inverseTranspose(const Matrix4D& m4);
	static Matrix4D lookAt(float eyeX, float eyeY, float eyeZ, float lookAtX, float lookAtY, float lookAtZ, float upX, float upY, float upZ);
	static Matrix4D lookAt(Vector3D& eye, Vector3D& lookAt, Vector3D& up);
	static Matrix4D perspective(float fovy, float w, float h, float n, float f);
	static Matrix4D rotate(float angle, float x, float y, float z);
	static Matrix4D rotate(float angle, Vector3D& axis);
	static Matrix4D scale(float x, float y, float z);
	static Matrix4D scale(Vector3D& scale);
	static Matrix4D translate(float x, float y, float z);
	static Matrix4D translate(Vector3D& translate);
	static float* getPointer(Matrix4D& mat);
};


#endif	//LA_H