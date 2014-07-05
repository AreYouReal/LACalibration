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

    TestUtils::testM4Dfunctionality(NUM_TESTS);
    
    TestUtils::testV3Dfunctionality(NUM_TESTS);
    
    return 0;
}




