//
//  main.cpp
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/14/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#include "model.hpp"
#include "triangle.hpp"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor blue  = TGAColor( 0, 0, 255, 255);

const int width = 800;
const int height = 800;

void display(model model, TGAImage& image)
{
    for (int i = 0; i < model.nfaces(); i++)
    {
        std::vector<int> face = model.face(i);
        vec2i coords[3];
        for (int j = 0; j < 3; j++)
        {
            vec3f vec = model.vert(face[j]);
            int x = (vec.x + 1.0) * width /2.0;
            int y = (vec.y + 1.0) * width /2.0;
            vec2i vertex(x, y);
            coords[j] = vertex;
        }
        triangle tri(coords, TGAColor(rand()%255, rand()%255, rand()%255, 255));
        tri.draw(image);
    }
}

void wireframe(model model, TGAImage& image)
{
    for (int i = 0; i < model.nfaces(); i++)
    {
        std::vector<int> face = model.face(i);
        for (int j = 0; j < 3; j++)
        {
         vec3f v0 = model.vert(face[j]);
         vec3f v1 = model.vert(face[(j+1)%3]);
         
         int x0 = (v0.x + 1.0) * width/2.0 ;
         int y0 = (v0.y + 1.0) * height/2.0 ;
         int x1 = (v1.x + 1.0) * width/2.0 ;
         int y1 = (v1.y + 1.0) * height/2.0 ;
         line(x0, y0, x1, y1, image, white);
        }
    }
}

int main(int argc, char** argv) {
    TGAImage image(width, height, TGAImage::RGB);
    model head("/Users/KSD/Desktop/Software rasterizer/Software rasterizer/head.obj");
    display(head, image);
    //wireframe(head, image);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
