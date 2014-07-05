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
#define MAX 100


#define SIGMA 0.000001

class TestUtils{
#warning declare private after debugging and testing
public:
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
    static V3D larndvec(){
        return V3D(rnd(MAX), rnd(MAX), rnd(MAX));
    }
    static V3D laVecFromglmVec(const glm::vec3 vec){
        return V3D(vec.x, vec.y, vec.z);
    }
    static M4D laMatrix4FromglmMat4(const glm::mat4 glmm4){
        glm::mat4 m4 = glm::transpose(glmm4);
        return M4D(m4[0][0], m4[0][1], m4[0][2], m4[0][3],
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
    static bool m4equality(const glm::mat4 glmM, const M4D origLAM){
        M4D laM = LA::transpose(origLAM);
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
    
    static bool v3equality(const glm::vec3 glmVec, const V3D laVec){
        bool equal = glmVec[0] == laVec.v[0] && glmVec[1] && laVec.v[1] && glmVec[2] && laVec.v[2];
        if(!equal)
            printf("v3equality failed");
        return equal;
    };

// M4D related tests
    static bool lookAtTest      (int numTests);
    static bool perspectiveTest (int numTests);
    static bool translateTest   (int numTests);
    static bool rotateTest      (int numTests);
    static bool scaleTest       (int numTests);
    static bool inverseTest     (int numTests);

// V3D related tests
    
public:
    static bool testMVPMatrices (int numTests);

};