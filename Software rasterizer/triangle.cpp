//
//  triangle.cpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/17/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#include "triangle.hpp"

/*void triangle::draw(TGAImage& image)
{
    float a1, a2, a3, b1, b2, b3; //slopes and 0-crossings
    bool underl3 = false;
    vec2i p1 = t[0];
    vec2i p2 = t[1];
    vec2i p3 = t[2];
    if (p3.x < p1.x)
    {
        std::swap(p1, p3);
    }
    if (p3.x < p2.x)
    {
        std::swap(p3, p2);
    }
    if (p2.x < p1.x)
    {
        std::swap(p1, p2);
    }
    if (p3.y > p2.y && p3.y > p1.y)
    {
        underl3 = true;
    }
    if (p2.x != p1.x)
    {
        a1 = (float) (p2.y - p1.y) / (p2.x - p1.x);
        b1 = (float) (p1.y - a1*p1.x) ;
    }
    else
    {
        a1 = 0;
        b1 = underl3 ? 0:99999;
    }
    
    if (p3.x != p2.x)
    {
        a2 = (float) (p3.y - p2.y) / (p3.x - p2.x);
        b2 = (float) (p2.y - a2*p2.x) ;
    }
    else
    {
        a2 = 0;
        b2 = underl3 ? 0:99999;
    }
    
    if (p1.x != p3.x)
    {
        a3 = (float) (p1.y - p3.y) / (p1.x - p3.x);
        b3 = (float) (p3.y - a3*p3.x) ;
    }
    else
    {
        a3 = 0;
        b3 = underl3? 99999:0;
    }
    
    int minx = std::min(p1.x, p2.x);
    int miny = std::min(p1.y, std::min(p2.y, p3.y));
    int maxy = std::max(p1.y, std::max(p2.y, p3.y));
    
    for (int i = minx; i <= p3.x; i++)
    {
        for (int j = miny; j <= maxy; j++)
        {
            if (underl3)
            {
                if (j <= b3 +a3*i && j >= b1 + a1*i && j >= b2 + a2*i)
                {
                    image.set(i, j, this->color);
                }
            }
            else
            {
                if (j >= b3 +a3*i && j <= b1 + a1*i && j <= b2 + a2*i)
                {
                    image.set(i, j, this->color);
                }
            }
        }
    }
}*/

void triangle::draw(TGAImage& image)
{
    vec2i p1 = t[0];
    vec2i p2 = t[1];
    vec2i p3 = t[2];
    if (p3.x < p1.x)
    {
        std::swap(p1, p3);
    }
    if (p3.x < p2.x)
    {
        std::swap(p3, p2);
    }
    if (p2.x < p1.x)
    {
        std::swap(p1, p2);
    }
    float a1, a2, a3; //slopes
    
    if (p2.x != p1.x)
    {
        a1 = abs((float) (p2.y - p1.y) / (p2.x - p1.x));
    }
    if (p3.x != p1.x)
    {
        a2 = abs((float) (p3.y - p1.y) / (p3.x - p1.x));
    }
    bool neg1 = p1.y > p2.y ;
    bool neg2 = p1.y > p3.y;
    float error1 =0.0;
    float error2 =0.0;
    int first_y = p1.y;
    int second_y = p1.y;
    
    for(int x = p1.x; x <p2.x; x++)
    {
        line(x, first_y, x, second_y, image, color);

        error1 += a1;
        error2 += a2;
        
        if (error1 >= 1.0)
        {
            if (neg1)
            {
                first_y-= (a1 > 1.0)? a1 : 1.0;
            }
            else
            {
                first_y+= (a1 > 1.0)? a1 : 1.0;
            }
            error1 -= 1.0;
        }
        if (error2 >= 1.0)
        {
            if (neg2)
            {
                second_y -= (a2 > 1.0)? a2: 1.0;
            }
            else
            {
                second_y += (a2 > 1.0)? a2: 1.0;
            }
            error2 -=1.0;
        }
    }
    if (p3.x != p2.x)
    {
       a3 = abs((float) (p3.y - p2.y) / (p3.x - p2.x));
    }
    first_y = p2.y;
    bool neg3 = p2.y > p3.y;
    float error3 = 0.0;
    error2 = 0.0;
    
    for(int x = p2.x; x <=p3.x; x++)
    {
        line(x,first_y,x,second_y,image,color);
        
        error3 += a3;
        error2 += a2;
        
        if (error3 >= 1.0)
        {
            if (neg3)
            {
                first_y-= (a3 > 1.0)? a3 : 1.0;
            }
            else
            {
                first_y+= (a3 > 1.0)? a3 : 1.0;
            }
            error3 -= 1.0;
        }
        if (error2 >= 1.0)
        {
            if (neg2)
            {
                second_y -= (a2 > 1.0)? a2: 1.0;
            }
            else
            {
                second_y += (a2 > 1.0)? a2: 1.0;
            }
            error2 -=1.0;
        }
    }
}
