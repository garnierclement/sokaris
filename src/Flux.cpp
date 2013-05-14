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
    
    // read a video
    int Flux::read(bool legend)
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
            if (legend)
                addLegend(picture);
            imshow(filename, picture);
            
            if (waitKey(10) >= 0)
                break;  
        }
        
        destroyWindow(filename);
        return EXIT_SUCCESS;
    }
    
    // create and add a legend onto a picture
    string Flux::addLegend(Mat& picture)
    {
        stringstream legend("");
        legend << (int)video.get(CV_CAP_PROP_POS_MSEC) << " ms";
        putText(picture, legend.str(), Point(100,400), 1, 1.0, Scalar(50,50,50));
        return legend.str();
    }
}