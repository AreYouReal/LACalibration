// LA.h

// "When your code has undefined behavior, you get a seg fault and corrupted data. 
// When Jeff Dean's code has undefined behavior, a unicorn rides in on a rainbow and gives everybody free ice cream."
// (c) Astounding 'Facts' About Google's Most Badass Engineer, Jeff Dean
 
#pragma once

#include <cmath>

#define PI atan(1.0f)*4.0f

struct V4D{
public:
	V4D();
	V4D(float x, float y, float z, float w);

	float& operator[](int i);
	void operator=(const V4D& vec);

    float v[4]{0.0, 0.0, 0.0, 1.0};
};

void print(const V4D& vec4);

struct V3D{
public:
	V3D();
    V3D(float a);
	V3D(float x, float y, float z);
	V3D(const V4D& vec);

	float& operator[](int i);
	void operator=(const V3D& vec);

    float v[3]{0.0, 0.0, 0.0};
};

void print(const V3D& vec3);
V3D operator*(const float scalar, const V3D& vec3);
V3D operator*(const V3D& vec3, const float scalar);
V3D operator+(const V3D& v1, const V3D& v2);
V3D operator-(const V3D& v1, const V3D& v2);
V3D operator-(const V3D& vec);
V3D operator/(V3D& vec3, const float scalar);




struct M4D{
public:
	M4D();
	M4D(const M4D& m4);
	M4D(const float arr[16]);
	M4D(float m11, float m12, float m13, float m14,
			 float m21, float m22, float m23, float m24,
			 float m31, float m32, float m33, float m34,
			 float m41, float m42, float m43, float m44);

	void operator=(const M4D& m4);

	float m[4][4];
};

void print(const M4D& m);
M4D operator*(const M4D& m1, const M4D& m2);
M4D operator*(const float scalar, const M4D& m4);
M4D operator*(const M4D& m4, const float scalar);
M4D operator/(const M4D& m4, const float scalar);
M4D operator+(const M4D& m1, const M4D& m2);
M4D operator-(const M4D& m1, const M4D& m2);


V4D operator*(const M4D& m, V4D& vec);

struct Q4D{
public:
    Q4D();
    Q4D(const Q4D& quaternion);
    Q4D(float x, float y, float z, float w);
    
    
    float& operator[](int i);
    void operator=(const Q4D& quat);
    void operator=(const V4D& vec);
    Q4D operator*(const float scale);
    
    
    float magnitude();
    Q4D conjugate();
    M4D matrix();
    void normalize();
    Q4D unit();
    
    float q[4]{0.0, 0.0, 0.0, 1.0};
};

Q4D operator*(const Q4D& q1, const Q4D& q2);
Q4D operator*(const Q4D& q1, const float scale);
Q4D operator+(const Q4D& q1, const Q4D& q2);


struct LA{
public:

	static float dot(const V3D& v1, const V3D& v2);
	static V3D cross(const V3D& v1, const V3D& v2);
	static float length(const V3D& vec3);
	static V3D normalize(const V3D& vec);

	static float determinant(const M4D& m4);
	static M4D transpose(const M4D& m4);
	static M4D inverse(const M4D& m4);
	static M4D inverseTranspose(const M4D& m4);
	static M4D lookAt(float eyeX, float eyeY, float eyeZ, float lookAtX, float lookAtY, float lookAtZ, float upX, float upY, float upZ);
	static M4D lookAt(V3D& eye, V3D& lookAt, V3D& up);
    static M4D ortho(float l, float r, float t, float b, float n, float f);
	static M4D perspective(float fovy, float w, float h, float n, float f);
	static M4D rotate(float angle, float x, float y, float z);
	static M4D rotate(float angle, V3D& axis);
	static M4D scale(float x, float y, float z);
	static M4D scale(V3D& scale);
	static M4D translate(float x, float y, float z);
	static M4D translate(V3D& translate);
    
	static float* getPointer(M4D& mat);
    static float* getPointer(V3D& vec);
};

