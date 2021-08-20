//
//  model.cpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/15/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#include <string>
#include <sstream>
#include <fstream>
#include "model.hpp"

model::model(const char* filename) : verts(), faces()
{
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if (in.fail())
    {
        return ;
    }
    std::string line;
    while(!in.eof())
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (line.compare(0, 2, "v ") == 0)
        {
            iss >> trash;
            vec3f v;
            iss >> v.x;
            iss >> v.y;
            iss >> v.z;
            verts.push_back(v);
        }
        else if (line.compare(0, 2, "f ") == 0)
        {
            std::vector<int> f;
            int itrash, idx;
            iss >> trash;
            while (iss >> idx >> trash >> itrash >> trash >> itrash)
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
            }
            faces.push_back(f);
        }
    }
    std::cerr << "# v# " << verts.size() << " f# "  << faces.size() << std::endl;
}

model::~model()
{
    
}

int model::nverts()
{
    return verts.size();
}

int model::nfaces()
{
    return faces.size();
}

vec3f model::vert(int i)
{
    return verts[i];
}

std::vector<int> model::face(int idx)
{
    return faces[idx];
}
