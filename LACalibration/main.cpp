//
//  main.cpp
//  LACalibration
//
//  Created by Alexander on 9/11/13.
//  Copyright (c) 2013 Alexander. All rights reserved.
//

#include "TestUtils.h"
#include "LA.h"
#include <iostream>

int main(int argc, const char * argv[]){

    srand(time(0));    
//    TestUtils::testM4Dfunctionality(10000);
//    TestUtils::testV3Dfunctionality(10000);
    
    
    glm::mat4 glmM4 = TestUtils::glmrndmat4();
    M4D lam4 = TestUtils::laMatrix4FromglmMat4(glmM4);
    M4D transposeLam4 = LA::transpose(lam4);
    float* lam4Pointer = LA::getPointer(transposeLam4);
    float*  glmPointer = glm::value_ptr(glmM4);
    
    
    
    
    
    for(int i = 0; i < 16; ++i)
        printf("%f   %f\n", *(lam4Pointer + i), *(glmPointer + i) );
    
    
    glm::vec3 glmVec = TestUtils::glmrndvec();
    V3D laVec = TestUtils::laVecFromglmVec(glmVec);
    float* laVecPointer = LA::getPointer(laVec);
    float* glmVecPointer = glm::value_ptr(glmVec);
    
    for(int i = 0; i < 3; ++i)
        printf("%f   %f\n", *(laVecPointer + i), *(glmVecPointer + i) );
    
    
    
    return 0;
}

