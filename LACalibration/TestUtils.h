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
#include "v3d.h"
#include "m4d.h"

#define rnd(max) (float)((float)(rand() % max - max/2)/ (MAX/10))
#define MAX 100

#define SIGMA 0.000001

#define NUM_TESTS 1000000

#define DEBUG_MODE false

class TestUtils{
private:
// Supporting functions
    static glm::vec3 glmrndvec(){
        return glm::vec3(rnd(MAX), rnd(MAX), rnd(MAX));
    }
    static glm::mat4 glmrndmat4(){
        return glm::mat4(rnd(MAX), rnd(MAX), rnd(MAX), rnd(MAX),
                         rnd(MAX), rnd(MAX), rnd(MAX), rnd(MAX),
                         rnd(MAX), rnd(MAX), rnd(MAX), rnd(MAX),
                         rnd(MAX), rnd(MAX), rnd(MAX), rnd(MAX) );
    }
    static v3d larndvec(){
        return v3d(rnd(MAX), rnd(MAX), rnd(MAX));
    }
    static v3d laVecFromglmVec(const glm::vec3 vec){
        return v3d(vec.x, vec.y, vec.z);
    }
    static m4d laMatrix4FromglmMat4(const glm::mat4 glmm4){
        glm::mat4 m4 = glm::transpose(glmm4);
        return m4d(m4[0][0], m4[0][1], m4[0][2], m4[0][3],
                        m4[1][0], m4[1][1], m4[1][2], m4[1][3],
                        m4[2][0], m4[2][1], m4[2][2], m4[2][3],
                        m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
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
    static bool m4equality(const glm::mat4 glmM, const m4d origLAM){
        m4d laM = m4d::transpose(origLAM);
        for(int i = 0; i < glmM.length(); ++i){
            for(int j = 0; j < glmM[i].length(); ++j){
                if(glmM[i][j] - laM.m[i][j] > SIGMA){
                    if(DEBUG_MODE)
                        printf("\n%f != %f        [%d][%d]\n", glmM[i][j], laM.m[i][j], i, j);
                    return false;
                }
            }
        }
        return true;
    }
    
    static bool v3equality(const glm::vec3 glmVec, const v3d laVec){
        bool equal = (   glmVec[0] - laVec.v[0] < SIGMA
                      && glmVec[1] - laVec.v[1] < SIGMA
                      && glmVec[2] - laVec.v[2] < SIGMA );
        if(!equal && DEBUG_MODE){
            printf("v3equality failed [ %f, %f, %f ] & [ %f, %f, %f ]", glmVec[0], glmVec[1], glmVec[2], laVec.v[0], laVec.v[1], laVec.v[2]);
        }
        return equal;
    };

// m4d related tests
    static bool lookAtTest      (int numTests);
    static bool orthoTest       (int numTests);
    static bool perspectiveTest (int numTests);
    static bool translateTest   (int numTests);
    static bool rotateTest      (int numTests);
    static bool scaleTest       (int numTests);
    static bool inverseTest     (int numTests);
    static bool m4dmultTest     (int numTests);
    static bool m4daddTest      (int numTests);
    static bool m4dsubTest      (int numTests);

// v3d related tests
    static bool normalizeTest   (int numTests);
    static bool lengthTest      (int numTests);
    static bool dotProductTest  (int numTests);
    static bool crossProductTest(int numTests);
    
public:
    static bool testv3dfunctionality(int numTests);
    static bool testm4dfunctionality(int numTests);
};