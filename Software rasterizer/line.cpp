//
//  line.cpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/17/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#include <iostream>
#include "line.h"

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    bool steep = false;
    if (std::abs(x0-x1)<std::abs(y0-y1))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    
    float dx = (float) (x1 - x0);
    float dy = (float) (y1 - y0);
    float slope = dy/dx;
    if (slope <0.0)
    {
        slope = -slope;
    }
    
    float error = 0.0;
    int y = y0;
    
    for (int x=x0; x<=x1; x++)
    {
        if (steep)
        {
            image.set(y, x, color);
        }
        else
        {
            image.set(x, y, color);
        }
        error += slope;
        if (error >= 0.5)
        {
            y += (y0 >y1)? -1.0:1.0;
            error -= 1.0;
        }
    }
}
