//
//  line.h
//  Software rasterizer
//
//  Created by Karim Dahrouge on 8/17/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef line_h
#define line_h

#pragma once
#include "tgaimage.hpp"

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color);

#endif /* line_h */
