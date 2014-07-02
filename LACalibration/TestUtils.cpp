//
//  TestUtils.cpp
//  LACalibration
//
//  Created by Veronika on 02/07/14.
//  Copyright (c) 2014 Veronika. All rights reserved.
//

#include "TestUtils.h"



bool TestUtils::lookAtTest(int numTests){
    int failedTests = 0;
    glm::vec3 glmEye , glmCenter, glmUp;
    Vector3D laEye, laCenter, laUp;
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
    printf("LA::loookAt(...) test PASSED on %d / %d tests.   (SIGMA = %f)\n", (numTests - failedTests), numTests, SIGMA);
    return true;
}