//
//  Flux.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Flux.h"

namespace sokaris
{
    Flux::Flux(void)
    {
    }
    
    Flux::~Flux(void)
    {
    }
    
    Flux::Flux(String path, String filename)
    {
        this->path = path;
        this->filename = filename;
    }
    
    int Flux::read(void)
    {
        video.open(path+filename);
        if (!video.isOpened()) {
            return EXIT_FAILURE;
        }
        
        namedWindow(filename, CV_WINDOW_AUTOSIZE);
        
        Mat picture;
        
        while (1) {
            video >> picture;
            imshow(filename, picture);
            if (waitKey(10) >= 0)
                break;
        }
        
        waitKey();
        video.release();
        return EXIT_SUCCESS;
    }
}