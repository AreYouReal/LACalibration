//
//  TestUtils.h
//  LACalibration
//
//  Created by Veronika on 02/07/14.
//  Copyright (c) 2014 Veronika. All rights reserved.
//

#pragma once

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "LA.h"

#define rnd(max) (float)((float)(rand() % max - max/2)/ (MAX/10))
#define MAX 1000


#define SIGMA 0.00001

struct TestUtils{
    static glm::vec3 glmrndvec(){
        return glm::vec3(rnd(MAX), rnd(MAX), rnd(MAX));
    }
    static Vector3D larndvec(){
        return Vector3D(rnd(MAX), rnd(MAX), rnd(MAX));
    }
    static Vector3D laVecFromglmVec(glm::vec3 vec){
        return Vector3D(vec.x, vec.y, vec.z);
    }
    static void print(const glm::vec3 vec){
        std::cout << vec.x << " " << vec.y << " " << vec.z << std::endl;
    }
    static void print(const glm::mat4 m){
        for(int i = 0; i < m.length(); i++){
            for(int j = 0; j < m[0].length(); j++){
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    static bool m4equality(const glm::mat4 glmM, const Matrix4D origLAM){
        Matrix4D laM = LA::transpose(origLAM);
        for(int i = 0; i < glmM.length(); ++i){
            for(int j = 0; j < glmM[i].length(); ++j){
                if(glmM[i][j] - laM.m[i][j] > SIGMA){
                    //printf("\n%f != %f\n", glmM[i][j], laM.m[i][j]);
                    return false;
                }
            }
        }
        return true;
    }

    
    static bool testMVPMatrices();
    
    
    static bool lookAtTest(int numTests);
    static bool perspectiveTest(int numTests);
    static bool translateTest(int numTests);
};