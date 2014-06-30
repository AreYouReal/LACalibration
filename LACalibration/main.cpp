//
//  main.cpp
//  LACalibration
//
//  Created by Alexander on 9/11/13.
//  Copyright (c) 2013 Alexander. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "LA.h"
#include <iostream>

void print(const glm::vec3 vec){
    std::cout << vec.x << " " << vec.y << " " << vec.z << std::endl;
}

void print(const glm::mat4 m){
    for(int i = 0; i < m.length(); i++){
        for(int j = 0; j < m[0].length(); j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    glm::mat4 translateMatrix = glm::translate(glm::vec3(3.0, 3.0, 3.0));
    
    Vector3D scaleVector(3.0, 3.0, 3.0);
    Matrix4D translateLAMatrix = LA::translate(scaleVector);
    
    print(translateMatrix);
    
    
    print(translateLAMatrix);

    
    
    

    return 0;
}



