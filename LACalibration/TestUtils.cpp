//
//  TestUtils.cpp
//  LACalibration
//
//  Created by Veronika on 02/07/14.
//  Copyright (c) 2014 Veronika. All rights reserved.
//

#include "TestUtils.h"

#pragma mark m4d tests
//____________________________________________________________________
bool TestUtils::testm4dfunctionality(int numTests){
    printf("m4d tests: \n");
    return (scaleTest(numTests) && rotateTest(numTests) && translateTest(numTests) && inverseTest(numTests) && lookAtTest(numTests) && orthoTest(numTests) && perspectiveTest(numTests) && m4daddTest(numTests) && m4dsubTest(numTests) && m4dmultTest(numTests));
}
//____________________________________________________________________
bool TestUtils::lookAtTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmEye , glmCenter, glmUp;
    v3d laEye, laCenter, laUp;
    for(int i = 0; i < numTests; ++i){
        glmEye       = glmrndvec();
        glmCenter    = glmrndvec();
        glmUp        = glmrndvec();
        while(glmCenter.x == glmEye.x && glmCenter.y == glmEye.y && glmCenter.z == glmEye.z){
            glmEye   = glmrndvec();
            glmCenter= glmrndvec();
        }
        while(glmUp.x == 0 && glmUp.y == 0 && glmUp.z == 0) {
            glmUp       = glmrndvec();
        }
        
        laEye      = laVecFromglmVec(glmEye);
        laCenter   = laVecFromglmVec(glmCenter);
        laUp       = laVecFromglmVec(glmUp);
        
        if(!TestUtils::m4equality(glm::lookAt(glmEye, glmCenter, glmUp),
                                  m4d::lookAt(laEye, laCenter, laUp))){
            failedTests++;
        }
    }
    printf("LA::loookAt(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::orthoTest(int numTests){
    int failedTests = 0;
    for(int i = 0; i < numTests; ++i){
        float left   = rnd(1000);
        float right  = rnd(1000);
        float top    = rnd(1000);
        float bottom = rnd(1000);
        float near   = rnd(10);
        float far    = rnd(1000);
        while(far - near < SIGMA || right - left < SIGMA || top - bottom < SIGMA){
            far     = rnd(1000);
            right   = rnd(1000);
            left    = rnd(1000);
            top     = rnd(1000);
            bottom  = rnd(1000);
        }
        if(!TestUtils::m4equality(glm::ortho(left, right, top, bottom, near, far), m4d::ortho(left, right, top, bottom, near, far)))
            failedTests++;
    }
    printf("LA::ortho(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
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
        if(!TestUtils::m4equality(glm::perspective(fovy, width/height, near, far), m4d::perspective(fovy, width, height, near, far)))
            failedTests++;
    }
    printf("LA::perspective(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::translateTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmMove;
    v3d laMove;
    for(int i = 0; i < numTests; ++i){
        glmMove = glmrndvec();
        laMove  = laVecFromglmVec(glmMove);
        if(!TestUtils::m4equality(glm::translate(glmMove), m4d::translate(laMove))){
            failedTests++;
        }
    }
    printf("LA::translate(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::rotateTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmAxis;
    v3d laAxis;
    float angle;
    for(int i = 0; i < numTests; ++i){
        glmAxis = glmrndvec();
        while(glmAxis.x == 0 && glmAxis.y == 0 && glmAxis.z == 0)
            glmAxis = glmrndvec();
        laAxis  = laVecFromglmVec(glmAxis);
        angle = rnd(1000);
        if(!TestUtils::m4equality(glm::rotate(angle, glmAxis), m4d::rotate(angle, laAxis))){
            failedTests++;
        }
    }
    printf("LA::rotate(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::scaleTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmScale;
    v3d laScale;
    for(int i = 0; i < numTests; ++i){
        glmScale = glmrndvec();
        laScale  = laVecFromglmVec(glmScale);
        if(!TestUtils::m4equality(glm::scale(glmScale), m4d::scale(laScale))){
            failedTests++;
        }
    }
    printf("LA::scale(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::inverseTest(int numTests){
    int failedTests = 0;
    glm::mat4   glmMat  = glmrndmat4();
    m4d    laMat   = laMatrix4FromglmMat4(glmMat);
    for(int i = 0; i < numTests; ++i){
        if(!TestUtils::m4equality(glm::inverse(glmMat), m4d::inverse(laMat))){
            failedTests++;
        }
    }
    printf("LA::inverse(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::m4dmultTest(int numTests){
    int failedTests = 0;
    glm::mat4   glmM_1  = glmrndmat4();
    glm::mat4   glmM_2  = glmrndmat4();
    m4d         laM_1   = laMatrix4FromglmMat4(glmM_1);
    m4d         laM_2   = laMatrix4FromglmMat4(glmM_2);
    
    for(int i = 0; i < numTests; ++i){
        if(!TestUtils::m4equality(glmM_1 * glmM_2, laM_1 * laM_2)){
            failedTests++;
        }
    }
    printf("LA::m4dmulti(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::m4daddTest(int numTests){
    int failedTests = 0;
    glm::mat4   glmM_1  = glmrndmat4();
    glm::mat4   glmM_2  = glmrndmat4();
    m4d         laM_1   = laMatrix4FromglmMat4(glmM_1);
    m4d         laM_2   = laMatrix4FromglmMat4(glmM_2);
    
    for(int i = 0; i < numTests; ++i){
        if(!TestUtils::m4equality(glmM_1 + glmM_2, laM_1 + laM_2)){
            failedTests++;
        }
    }
    printf("LA::m4dadd(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::m4dsubTest(int numTests){
    int failedTests = 0;
    glm::mat4   glmM_1  = glmrndmat4();
    glm::mat4   glmM_2  = glmrndmat4();
    m4d         laM_1   = laMatrix4FromglmMat4(glmM_1);
    m4d         laM_2   = laMatrix4FromglmMat4(glmM_2);
    
    for(int i = 0; i < numTests; ++i){
        if(!TestUtils::m4equality(glmM_1 - glmM_2, laM_1 - laM_2)){
            failedTests++;
        }
    }
    printf("LA::m4dsub(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
#pragma mark v3d tests
//____________________________________________________________________
bool TestUtils::testv3dfunctionality(int numTests){
    printf("v3d tests: \n");
    return (normalizeTest(numTests) && lengthTest(numTests) && dotProductTest(numTests) &&crossProductTest(numTests));
}
//____________________________________________________________________
bool TestUtils::normalizeTest(int numTests){
    int failedTests = 0;
    glm::vec3   glmVec;
    v3d         laVec;
    for(int i = 0; i < numTests; ++i){
        glmVec  = glmrndvec();
        while(glmVec.x == 0 || glmVec.y == 0 || glmVec.z == 0)
            glmVec = glmrndvec();
        
        laVec   = laVecFromglmVec(glmVec);
        glmVec  = glm::normalize(glmVec);
        laVec   = v3d::normalize(laVec);
        
        if(!TestUtils::v3equality(glmVec, laVec)){
            failedTests++;
        }
    }
    printf("LA::normalize(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::lengthTest(int numTests){
    int failedTests = 0;
    glm::vec3   glmVec;
    v3d         laVec;
    for(int i = 0; i < numTests; ++i){
        glmVec  = glmrndvec();
        while(glmVec.x == 0 && glmVec.y == 0 && glmVec.z == 0)
            glmVec = glmrndvec();
        
        laVec   = laVecFromglmVec(glmVec);
        if(!(glm::length(glmVec) - v3d::length(laVec) < SIGMA)){
            failedTests++;
        }
        
    }
    printf("LA::length(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::dotProductTest(int numTests){
    int failedTests = 0;
    glm::vec3   glmVec_1, glmVec_2;
    v3d         laVec_1, laVec_2;
    for(int i = 0; i < numTests; ++i){
        glmVec_1 = glmrndvec();
        glmVec_2 = glmrndvec();
        laVec_1  = laVecFromglmVec(glmVec_1);
        laVec_2  = laVecFromglmVec(glmVec_2);
        
        if(!(glm::dot(glmVec_1, glmVec_2) - v3d::dot(laVec_1, laVec_2) < SIGMA)){
            failedTests++;
        }
    }
    printf("LA::dot(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::crossProductTest(int numTests){
    int failedTests = 0;
    glm::vec3   glmVec_1, glmVec_2;
    v3d         laVec_1, laVec_2;
    for(int i = 0; i < numTests; ++i){
        glmVec_1 = glmrndvec();
        glmVec_2 = glmrndvec();
        laVec_1  = laVecFromglmVec(glmVec_1);
        laVec_2  = laVecFromglmVec(glmVec_2);
        
        if(!(v3equality(glm::cross(glmVec_1, glmVec_2), v3d::cross(laVec_1, laVec_2)))){
            failedTests++;
        }
    }
    printf("LA::cross(...) test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
//____________________________________________________________________
bool TestUtils::qaternionRotateVector(int numTests){
    int failedTests = 0;
    m4d     laRMatrix;
    q4d     rotQuaternion;
    float   randomAngle;
    v3d     randomAxis;
    for(int i = 0; i < numTests; ++i){
        randomAxis = larndvec();
        laRMatrix = m4d::rotate(randomAngle, randomAxis);
        rotQuaternion = q4d(randomAngle, randomAxis);
        if(!m4laEquality(laRMatrix, rotQuaternion.matrix())){
            failedTests++;
        }
    }
    printf("Quternion <-> Rotation matrix test FINISHED. %.2f percent matching.   (NUM_TESTS = %d)(SIGMA = %f)\n", (float)(numTests - failedTests) / numTests * 100, numTests, SIGMA);
    return true;
}
