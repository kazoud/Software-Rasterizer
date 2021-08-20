//
//  model.hpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/15/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#pragma once
#include <stdio.h>
#include <vector>
#include "Geometry.h"
#include "tgaimage.hpp"

class model {
private:
    std::vector<vec3f> verts;
    std::vector<std::vector<int>> faces;
    
public:
    model(const char* filename);
    ~model();
    int nverts();
    int nfaces();
    vec3f vert(int i);
    std::vector<int> face(int idx);
};

#endif /* model_hpp */
