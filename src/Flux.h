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
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace sokaris
{
    class Flux
    {
    private :
        VideoCapture video;
        String path;
        String filename;
        int zero;
        
    
    public :
        Flux(void);
        Flux(String path, String filename);
        ~Flux(void);
        int display(bool legend = 0, int (*callback)(Mat& picture) = NULL);                         // display video on screen
        string addLegend(Mat& picture);         // create and add a legend onto a picture    
        
    };
}

#endif /* defined(__sokaris__Flux__) */
