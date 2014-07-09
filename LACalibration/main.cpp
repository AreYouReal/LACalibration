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
    TestUtils::testM4Dfunctionality(10000);
    TestUtils::testV3Dfunctionality(10000);
    
    return 0;
}

