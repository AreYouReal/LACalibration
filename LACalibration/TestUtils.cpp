//
//  TestUtils.cpp
//  LACalibration
//
//  Created by Veronika on 02/07/14.
//  Copyright (c) 2014 Veronika. All rights reserved.
//

#include "TestUtils.h"

#pragma mark M4D tests
//____________________________________________________________________
bool TestUtils::testMVPMatrices(int numTests){
    return (scaleTest(numTests) && rotateTest(numTests) && translateTest(numTests) && inverseTest(numTests) && lookAtTest(numTests) && perspectiveTest(numTests));
}
//____________________________________________________________________
bool TestUtils::lookAtTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmEye , glmCenter, glmUp;
    V3D laEye, laCenter, laUp;
    for(int i = 0; i < numTests; ++i){
        glmEye       = glmrndvec();
        glmCenter    = glmrndvec();
        glmUp        = glmrndvec();
        
        laEye      = laVecFromglmVec(glmEye);
        laCenter   = laVecFromglmVec(glmCenter);
        laUp       = laVecFromglmVec(glmUp);
        
        if(!TestUtils::m4equality(glm::lookAt(glmEye, glmCenter, glmUp),
                                  LA::lookAt(laEye, laCenter, laUp))){
            failedTests++;
        }
    }
    printf("LA::loookAt(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::perspectiveTest(int numTests){
    int failedTests = 0;
    for(int i = 0; i < numTests; ++i){
        float fovy  = rnd(90);
        float width = rnd(1000);
        float height= rnd(1000);
        float near  = rnd(10);
        float far   = rnd(1000);
        while(far - near < SIGMA || width / height < SIGMA ){
            far     = rnd(1000);
            width   = rnd(1000);
            height  = rnd(1000);
        }
        if(!TestUtils::m4equality(glm::perspective(fovy, width/height, near, far), LA::perspective(fovy, width, height, near, far)))
            failedTests++;
    }
    printf("LA::perspective(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::translateTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmMove;
    V3D laMove;
    for(int i = 0; i < numTests; ++i){
        glmMove = glmrndvec();
        laMove  = laVecFromglmVec(glmMove);
        if(!TestUtils::m4equality(glm::translate(glmMove), LA::translate(laMove))){
            failedTests++;
        }
    }
    printf("LA::translate(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::rotateTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmAxis;
    V3D laAxis;
    float angle;
    for(int i = 0; i < numTests; ++i){
        glmAxis = glmrndvec();
        laAxis  = laVecFromglmVec(glmAxis);
        angle = rnd(1000);
        if(!TestUtils::m4equality(glm::rotate(angle, glmAxis), LA::rotate(angle, laAxis))){
            failedTests++;
        }
    }
    printf("LA::rotate(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::scaleTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmScale;
    V3D laScale;
    for(int i = 0; i < numTests; ++i){
        glmScale = glmrndvec();
        laScale  = laVecFromglmVec(glmScale);
        if(!TestUtils::m4equality(glm::scale(glmScale), LA::scale(laScale))){
            failedTests++;
        }
    }
    printf("LA::scale(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::inverseTest(int numTests){
    int failedTests = 0;
    glm::mat4   glmMat  = glmrndmat4();
    M4D    laMat   = laMatrix4FromglmMat4(glmMat);
    for(int i = 0; i < numTests; ++i){
        if(!TestUtils::m4equality(glm::inverse(glmMat), LA::inverse(laMat))){
            failedTests++;
        }
    }
    printf("LA::inverse(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________
#pragma mark V3D tests
//____________________________________________________________________
bool TestUtils::normalizeTest(int numTests){
    int failedTests = 0;
    glm::vec3   glmVec;
    V3D         laVec;
    for(int i = 0; i < numTests; ++i){
        glmVec  = glmrndvec();
        while(glmVec.x == 0 || glmVec.y == 0 || glmVec.z == 0)
            glmVec = glmrndvec();
        
        laVec   = laVecFromglmVec(glmVec);
        glmVec  = glm::normalize(glmVec);
        laVec   = LA::normalize(laVec);
        
        if(!TestUtils::v3equality(glmVec, laVec)){
            printf("\n[ %f, %f, %f ]   not equal to [ %f, %f, %f ]", glmVec.x, glmVec.y, glmVec.z, laVec[0], laVec[1], laVec[2]);
            failedTests++;
        }
    }
    printf("LA::normalize(...) test FINISHED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}
//____________________________________________________________________