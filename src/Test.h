//
//  Test.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Test__
#define __sokaris__Test__

#include <iostream>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

namespace sokaris
{
    class Test
    {
        
    private :
        String path;
        String face_cascade_name;
        String eyes_cascade_name;
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;
        string window_name;
        RNG rng;
        
    public :
        Test();
        ~Test();
        int testCascadeClassifier();
        void detectAndDisplay(Mat frame);
        
    };
}

#endif /* defined(__sokaris__Test__) */
