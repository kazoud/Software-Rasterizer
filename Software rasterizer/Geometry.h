//
//  Geometry.h
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/15/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef Geometry_h
#define Geometry_h

#pragma once
#include <iostream>
#include <math.h>

template <typename t>class vec3 ;

template <typename t>class vec2 {
public:
    t x;
    t y;
    
public:
    vec2() : x(0), y(0) {}
    vec2(t u, t v) : x(u), y(v) {}
    vec2<int>(vec2<float> vec): x( (int) vec.x), y((int) vec.y) {}
    vec2(vec3<t> vec): x(vec.x), y(vec.y) {}
    
    void center(int width, int height) //appropriately scales the vertex according to the resolution
    {
        this->x = ((this->x) + 1.0) * width/2.0;
        this->y = ((this->y) + 1.0) * height/2.0;
    }
    
    void intify()
    {
        this->x = (int) x;
        this->y = (int) y;
    }
    
    vec2<t> operator +(float f)
    {
        return vec2<t>(this->x + f, this->y + f);
    }
    
    vec2<t> operator -(float f)
    {
        return vec2<t>(this->x - f, this->y - f);
    }
    
    vec2<t> operator*(float f)
    {
        return vec2<t>(this->x * f, this->y * f);
    }
    
    vec2<t> operator+(const vec2<t> vec)
    {
        return vec2<t>(this->x + vec.x, this->y + vec.y);
    }
    
    vec2<t> operator-(const vec2<t> vec)
    {
        return vec2<t>(this->x - vec.x, this->y - vec.y);
    }
    
    t operator*(vec2<t> vec) //dot product
    {
        return this->x*vec.x + this->y*vec.y;
    }
    
    float normalize()
    {
        return sqrt(this->x*this->x + this->y*this->y);
    }
    template <typename > friend std::ostream& operator<<(std::ostream& out, vec2<t>& vec);
    
};
    template <typename t> std::ostream& operator<<(std::ostream& out, vec2<t>& vec)
    {
        out << "(" << vec.x << "," << vec.y << ")\n";
        return out;
    }
    typedef vec2<float> vec2f;
    typedef vec2<int> vec2i;


template <typename t> class vec3 {
    public:
        t x;
        t y;
        t z;
    public:
        vec3() : x(0), y(0), z(0) {}
        vec3(t u, t v, t w): x(u), y(v), z(w) {}
    
        vec3<t> operator +(float f)
        {
            return vec3<t>(this->x + f, this->y + f, this->z + f);
        }
    
        vec3<t> operator -(float f)
        {
            return vec3<t>(this->x - f, this->y - f, this->z - f);
        }
    
        vec3<t> operator*(float f)
        {
            return vec3<t>(this->x * f, this->y * f, this->z * f);
        }
    
        vec3<t> operator +(vec3<t> const vec)
        {
            return vec3<t>(this->x + vec.x, this->y + vec.y, this->z + vec.z);
        }
    
        vec3<t> operator -(const vec3<t> vec)
        {
            return vec3<t>(this->x - vec.x, this->y - vec.y, this->z + vec.z);
        }
    
        vec3<t> operator*(const vec3<t> vec)
        {
            return vec3<t>(this->x * vec.x, this->y * vec.y, this->z * vec.z);
        }
    
        vec3<t> operator ^(const vec3<t> &v)
        {
            return vec3<t>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
        }
        
        template <typename > friend std::ostream& operator<<(std::ostream& out, vec3<t>& vec);
    };
    
    template <typename t> std::ostream& operator<<(std::ostream& out, vec3<t>& vec)
    {
        out << "(" << vec.x << "," << vec.y << "," << vec.z << ")\n";
        return out;
    }

typedef vec3<float> vec3f;
typedef vec3<int> vec3i;
    
#endif /* Geometry_h */
