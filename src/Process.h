//
//  Process.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Process__
#define __sokaris__Process__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace sokaris
{
    class Process
    {
    public :
        
        static int testCallback(Mat& picture);
        
    };
}

#endif /* defined(__sokaris__Process__) */
