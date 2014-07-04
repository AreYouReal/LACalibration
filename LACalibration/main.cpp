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
    
    //TestUtils::scaleTest(10000000);
    
    //TestUtils::perspectiveTest(100000);
    
    //TestUtils::lookAtTest(9000000);
    
    for(int i = 0; i < 1000; i++){
        glm::mat4 glmMat4 = TestUtils::glmrndmat4();
        if(!TestUtils::m4equality(glmMat4, TestUtils::laMatrix4FromglmMat4(glmMat4))){
            printf("Generating equal matrices test FAILED!");
            return 0;
        }
    }
    
    printf("Generating equal matrices test PASSED!");
    return 0;
}




