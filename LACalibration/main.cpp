//
//  main.cpp
//  LACalibration
//
//  Created by Alexander on 9/11/13.
//  Copyright (c) 2013 Alexander. All rights reserved.
//

#include "TestUtils.h"
#include <iostream>

int main(int argc, const char * argv[]){

    srand(time(0));    
//    TestUtils::testm4dfunctionality(10000);
//    TestUtils::testv3dfunctionality(10000);

    TestUtils::qaternionRotateVector(1000);
    

    return 0;
}

