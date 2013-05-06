//
//  Camera.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Camera__
#define __sokaris__Camera__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace sokaris
{
    class Camera
    {
    private :
        Point2d coordinates;
        
    public:
        Camera(void);
        Camera(Point2d coordinates);
        ~Camera(void);
        
        Point2d getCoordinates();
        void setCoordinates(Point2d point);
        

    };
}

#endif /* defined(__sokaris__Camera__) */
