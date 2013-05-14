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
            cout << "Unable to open video " << filename << " in " << path << endl;
            return EXIT_FAILURE;
        }
        
        namedWindow(filename, CV_WINDOW_AUTOSIZE);
        
        Mat picture;
        
        while (video.read(picture))
        {
            imshow(filename, picture);
            
            if (waitKey(10) >= 0)
                break;  
        }
        
        destroyWindow(filename);
        return EXIT_SUCCESS;
    }
}