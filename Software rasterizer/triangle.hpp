//
//  triangle.hpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/17/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp

#pragma once
#include <stdio.h>
#include "Geometry.h"
#include "line.h" //just contains the line() function

class triangle{
public:
    vec2i t[3];
    TGAColor color;
    
public:
    triangle(vec2i pt1, vec2i pt2, vec2i pt3, TGAColor col) : t{pt1, pt2, pt3}, color(col) {}
    triangle(int x1, int x2, int y1, int y2, int z1, int z2, TGAColor col)
    {
        t[0] = vec2i(x1, x2);
        t[1] = vec2i(y1, y2);
        t[2] = vec2i(z1, z2);
        color = col;
    }
    triangle(vec2i vec[3], TGAColor col) : t{vec[0], vec[1], vec[2]}, color(col) {}
    triangle(const triangle& tri) : t{tri.t[0], tri.t[1], tri.t[2]}, color(tri.color) {}
    void draw(TGAImage& image);
};

#endif /* triangle_hpp */
