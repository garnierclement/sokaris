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
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>
#include "opencv2/contrib/contrib.hpp"

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
		String mouth_cascade_name;
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;
		CascadeClassifier mouth_cascade;
        string window_name;
		string main_window_name;
		string face_window_name;
        RNG rng;
        
    public :
        Test();
        ~Test();
        
        // test detection de visage + yeux
        // http://docs.opencv.org/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html#cascade-classifier
        int testCascadeClassifier();
        void detectAndDisplay(Mat frame);
		void trainedClassifier();
		void putSomeText(String text, Mat frame, Point point);
		void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';');
		void performFeatureDetection( std::vector<Rect> feature, 
										std::vector<Rect> faces, 
										cv::Mat faceROI, 
										cv::CascadeClassifier feature_cascade,
										cv::Mat frame,
										int i);
		void findEyes(cv::Mat frame_gray, cv::Rect face);
        
    };
}

#endif /* defined(__sokaris__Test__) */
