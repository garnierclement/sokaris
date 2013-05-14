//
//  Flux.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Flux__
#define __sokaris__Flux__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace sokaris
{
    class Flux
    {
    private :
        VideoCapture video;
        String path;
        String filename;    
        
    
    public :
        Flux(void);
        Flux(String path, String filename);
        ~Flux(void);
        int read(void);
        
        
    };
}

#endif /* defined(__sokaris__Flux__) */
