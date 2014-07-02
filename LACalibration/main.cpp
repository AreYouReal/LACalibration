//
//  main.cpp
//  LACalibration
//
//  Created by Alexander on 9/11/13.
//  Copyright (c) 2013 Alexander. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "LA.h"
#include <iostream>

#define SIGMA 0.00001

void print(const glm::vec3 vec){
    std::cout << vec.x << " " << vec.y << " " << vec.z << std::endl;
}

void print(const glm::mat4 m){
    for(int i = 0; i < m.length(); i++){
        for(int j = 0; j < m[0].length(); j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool equal(const glm::mat4 glmM, const Matrix4D laM){
    for(int i = 0; i < glmM.length(); ++i){
        for(int j = 0; j < glmM[i].length(); ++j){
            if(glmM[i][j] - laM.m[i][j] > SIGMA){
                printf("\n%f != %f\n", glmM[i][j], laM.m[i][j]);
                return false;
            }
        }
    }
    return true;
}


int main(int argc, const char * argv[])
{
    glm::mat4 translateMatrix = glm::translate(glm::vec3(3.0, 3.0, 3.0));
    
    Vector3D scaleVector(3.0, 3.0, 3.0);
    Matrix4D translateLAMatrix = LA::translate(scaleVector);
    translateLAMatrix = LA::transpose(translateLAMatrix);

    Vector3D LAeye(0, 1, 1);
    Vector3D LAlookAt(-5, 0, 0);
    Vector3D LAup(0, 1, 0);
    Matrix4D LAlook = LA::transpose(LA::lookAt(LAeye, LAlookAt, LAup));
    
    glm::mat4 glmmat4 = glm::lookAt(glm::vec3(0, 1, 1), glm::vec3(-5, 0, 0), glm::vec3(0, 1, 0));
    
    printf("\nLookAtTest: %s", equal(glmmat4, LAlook) ? "PASS" : "FAIL" );
    printf("\nLookAtTest: %s", equal(translateMatrix, translateLAMatrix) ? "PASS" : "FAIL" );
    
    return 0;
}


// Check all matrix related operations
void Matrix4DTest(){
    
}

// Checks vector related operations
void Vector3DTest(){

}

void Vector4DTest(){

}

