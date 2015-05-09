#pragma once

#include "v3d.h"

struct Q4D{
public:
    Q4D();
    Q4D(const Q4D& quaternion);
    Q4D(float x, float y, float z, float w);
    
    
    float& operator[](int i);
    void operator=(const Q4D& quat);
    void operator=(const v4d& vec);
    Q4D operator*(const float scale);
    
    
    float magnitude();
    Q4D conjugate();
    m4d matrix();
    void normalize();
    Q4D unit();
    
    float q[4]{0.0, 0.0, 0.0, 1.0};
};

Q4D operator*(const Q4D& q1, const Q4D& q2);
Q4D operator*(const Q4D& q1, const float scale);
Q4D operator+(const Q4D& q1, const Q4D& q2);