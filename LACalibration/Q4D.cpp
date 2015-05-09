#include "Q4D.h"
#include "m4d.h"

Q4D::Q4D(){}
Q4D::Q4D(float x, float y, float z, float w){
    q[0] = x; q[1] = y; q[2] = z; q[3] = w;
    normalize();
}
Q4D::Q4D(const Q4D& quaternion){
    for(int i = 0; i < 4; ++i){
        q[i] = quaternion.q[i];
    }
    normalize();
}
float& Q4D::operator[](int i){
    return i > 3 ? q[0] : q[1];
}
void Q4D::operator=(const Q4D& quaternion){
    q[0] = quaternion.q[0]; q[1] = quaternion.q[1]; q[2] = quaternion.q[2]; q[3] = quaternion.q[3];
}
Q4D Q4D::operator*(const float scale){
    Q4D quaternion = Q4D(q[0] * scale, q[1] * scale, q[2] * scale, q[3] * scale);
    return quaternion;
}
float Q4D::magnitude(){
    return sqrtf( q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3] );
}
Q4D Q4D::conjugate(){
    return Q4D(-q[0], -q[1], -q[2], q[3]);
}

m4d Q4D::matrix(){
    m4d quatMatrix(1 - 2 * q[1] * q[1] - 2 * q[2] * q[2], 2 * q[0] * q[1] + 2 * q[3] * q[2], 2 * q[0] * q[2] + 2 * q[3] * q[1], 0,
                   2 * q[0] * q[1] - 2 * q[3] * q[2], 1 - 2 * q[0] * q[0] - 2 * q[2] * q[2], 2 * q[1] * q[2] + 2 * q[3] * q[0], 0,
                   2 * q[0] * q[2] + 2 * q[3] * q[1], 2 * q[1] * q[2] - 2 * q[3] * q[0], 1 - 2 * q[0] * q[0] - 2 * q[1] * q[1], 0,
                   0,                                   0,                                  0,                                  1);
    return quatMatrix;
}

void Q4D::normalize(){
    float length = magnitude();
    q[0] /= length; q[1] /= length; q[2] /= length; q[3] /= length;
}

Q4D Q4D::unit(){
    Q4D unitQuternion(*this);
    unitQuternion.normalize();
    return unitQuternion;
}

Q4D operator*(const Q4D& q1, const Q4D& q2){
    Q4D quaternion;
    quaternion.q[0] = q1.q[0] * q2.q[3] + q1.q[1] * q2.q[2] - q1.q[2] * q2.q[1] + q1.q[3] * q2.q[0];
    quaternion.q[1] = -q1.q[0] * q2.q[2] + q1.q[1] * q2.q[3] + q1.q[2] * q2.q[0] + q1.q[3] * q2.q[1];
    quaternion.q[2] = q1.q[0] * q2.q[1] - q1.q[1] * q2.q[0] + q1.q[2] * q2.q[3] + q1.q[3] * q2.q[2];
    quaternion.q[3] = -q1.q[0] * q2.q[0] - q1.q[1] * q2.q[1] - q1.q[2] * q2.q[2] + q1.q[3] * q2.q[3];
    return quaternion;
}

Q4D operator+(const Q4D& q1, const Q4D& q2){
    Q4D quaternion(q1.q[0] + q2.q[0], q1.q[1] + q2.q[1], q1.q[2] + q2.q[2], q1.q[3] + q2.q[3]);
    return quaternion;
}

