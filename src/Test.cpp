//
//  Test.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Test.h"

namespace sokaris
{
    Test::Test()
    {
        this->path = "/usr/local/Cellar/opencv/2.4.5/share/OpenCV/haarcascades/";
        this->face_cascade_name = "haarcascade_frontalface_alt.xml";
        this->eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
        this->window_name = "Capture - Face detection";
        this->rng(1234);
    }
    
    Test::~Test()
    {
    }
    
    int Test::testCascadeClassifier()
    {
        CvCapture* capture;
        Mat frame;
        
        //-- 1. Load the cascades
        if( !face_cascade.load( path+face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
        if( !eyes_cascade.load( path+eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
        
        //-- 2. Read the video stream
        capture = cvCaptureFromCAM( -1 );
        if( capture )
        {
            while( true )
            {
                frame = cvQueryFrame( capture );
                
                //-- 3. Apply the classifier to the frame
                if( !frame.empty() )
                { detectAndDisplay( frame ); }
                else
                { printf(" --(!) No captured frame -- Break!"); break; }
                
                int c = waitKey(10);
                if( (char)c == 'c' ) { break; }
            }
        }
        return 0;
    }
    
    void Test::detectAndDisplay(Mat frame)
    {
        std::vector<Rect> faces;
        Mat frame_gray;
        
        cvtColor( frame, frame_gray, CV_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );
        
        //-- Detect faces
        face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        
        for( int i = 0; i < faces.size(); i++ )
        {
            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
            
            Mat faceROI = frame_gray( faces[i] );
            std::vector<Rect> eyes;
            
            //-- In each face, detect eyes
            eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
            
            for( int j = 0; j < eyes.size(); j++ )
            {
                Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
            }
        }
        //-- Show what you got
        imshow( window_name, frame );
    }
}