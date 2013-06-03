//
//  Test.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Test.h"
#include "constants.h"
#include "findEyeCorner.h"
#include "findEyeCenter.h"

#define w 400

namespace sokaris
{
    Test::Test()
    {
#ifdef __APPLE__
        this->path = "/usr/local/Cellar/opencv/2.4.5/share/OpenCV/haarcascades/";
#else
		this->path = "C:/Program Files (x86)/opencv/data/haarcascades/";
#endif
		this->face_cascade_name = "haarcascade_frontalface_alt.xml";
        this->eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
		this->mouth_cascade_name = "haarcascade_mcs_mouth.xml";
		//this->path = "C:/Program Files (x86)/opencv/data/lbpcascades/";
		//this->face_cascade_name = "lbpcascade_frontalface.xml";
        this->window_name = "Capture - Face detection";
		this->main_window_name = "Capture - Face detection";
		this->face_window_name = "Capture - Face";
		cv::namedWindow(main_window_name,CV_WINDOW_NORMAL);
		cv::moveWindow(main_window_name, 400, 100);
		cv::namedWindow(face_window_name,CV_WINDOW_NORMAL);
		cv::moveWindow(face_window_name, 10, 100);
		cv::namedWindow("Right Eye",CV_WINDOW_NORMAL);
		cv::moveWindow("Right Eye", 10, 600);
		cv::namedWindow("Left Eye",CV_WINDOW_NORMAL);
		cv::moveWindow("Left Eye", 10, 800);
        this->rng(1234);
    }
    
    Test::~Test()
    {
    }
    
    int Test::testCascadeClassifier()
    {
        CvCapture* capture;
        Mat frame;
		Mat frame_original;
        
        //-- 1. Load the cascades
        if( !face_cascade.load( path+face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
        if( !eyes_cascade.load( path+eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
        if( !mouth_cascade.load( path+mouth_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
        
        //-- 2. Read the video stream
        capture = cvCaptureFromCAM( -1 );
        if( capture )
        {
            while( true )
            {
                frame_original = cvQueryFrame( capture );
                frame = frame_original.clone();
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
        //Mat frame_gray;
        
		//@TODO : Understand what the lines below mean
		std::vector<cv::Mat> rgbChannels(3);
		cv::split(frame, rgbChannels);
		cv::Mat frame_gray = rgbChannels[2];
        
        // cvtColor( frame, frame_gray, CV_BGR2GRAY );
        //equalizeHist( frame_gray, frame_gray );
        //-- Detect faces
		//-- Calculate the face orientation and give it as a parameter to the new object person
		//-- Create a new person for each face detected
		//-- For each person detected, store information about that person in a database or something similar
        //face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
		//@TODO Understand what are the arguments used in detectMultiScale
        face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE|CV_HAAR_FIND_BIGGEST_OBJECT, cv::Size(150, 150) );
        
        for( int i = 0; i < faces.size(); i++ )
        {
            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );			rectangle( frame, center, center, CV_RGB(0, 255,0), 1);
            Mat faceROI = frame_gray( faces[i] );
            std::vector<Rect> eyes;
            std::vector<Rect> mouth;
            
            //-- In each face, detect eyes
            eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
            
            for( int j = 0; j < eyes.size(); j++ )
            {
                Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
				rectangle(frame,    cvPoint(faces[i].x + eyes[j].x, faces[i].y + eyes[j].y),
                          cvPoint(faces[i].x + eyes[j].x + eyes[j].width ,faces[i].y + eyes[j].y + eyes[j].height),
                          CV_RGB(0, 0, 255),
                          1, 8, 0
                          );
            }
            
			//-- In each face, detect mouth
			performFeatureDetection( mouth, faces, faceROI, mouth_cascade, frame, i);
        }
        //-- Show what you got
        imshow( window_name, frame );
    }
    
	void Test::putSomeText(String text, Mat frame, Point point) {
		stringstream textImage("");
		textImage << text;
		putText(frame, textImage.str(),Point(100,400), 1, 1.0, Scalar(50,50,50));
		cout << point << endl;
	}
    
	void Test::performFeatureDetection( std::vector<Rect> feature,
                                       std::vector<Rect> faces,
                                       cv::Mat faceROI,
                                       cv::CascadeClassifier feature_cascade,
                                       cv::Mat frame, int i){
        feature_cascade.detectMultiScale( faceROI, feature, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        
        for( int j = 0; j < 1 /*mouth.size()*/; j++ )
        {
            Point center( faces[i].x + feature[j].x + feature[j].width*0.5, faces[i].y + feature[j].y + feature[j].height*0.5 );
            Point corner = cvPoint(faces[i].x + feature[j].x + feature[j].width ,faces[i].y + feature[j].y + feature[j].height);
            rectangle(frame,    cvPoint(faces[i].x + feature[j].x, faces[i].y + feature[j].y),
                      cvPoint(faces[i].x + feature[j].x + feature[j].width ,faces[i].y + feature[j].y + feature[j].height),
                      CV_RGB(225, 228, 0), //225, 228, 0
                      1, 8, 0
                      );
            putSomeText("Mouth detected",frame, corner);
        }
    }
    
	void Test::trainedClassifier(){
		
		/* STEP 2. Opening the file */
		//1. Declare a structure to keep the data
		CvMLData cvml;
		//2. Read the file
		cvml.read_csv("samples.csv");
		//3. Indicate which column is the response
		cvml.set_response_idx(0);
        
		/* STEP 3. Splitting the samples */
		//1. Select 40 for the training
		CvTrainTestSplit cvtts(40, true);
		//2. Assign the division to the data
		cvml.set_train_test_split(&cvtts);
        
		printf("Training ... ");
		/* STEP 4. The training */
		//1. Declare the classifier
		CvBoost boost;
		//2. Train it with 100 features
		boost.train(&cvml, CvBoostParams(CvBoost::REAL, 100, 0, 1, false, 0), false);
        
		/* STEP 5. Calculating the testing and training error */
		// 1. Declare a couple of vectors to save the predictions of each sample
		std::vector<float> train_responses, test_responses;
		// 2. Calculate the training error
		float fl1 = boost.calc_error(&cvml,CV_TRAIN_ERROR,&train_responses);
		// 3. Calculate the test error
		float fl2 = boost.calc_error(&cvml,CV_TEST_ERROR,&test_responses);
		printf("Error train %f \n", fl1);
		printf("Error test %f \n", fl2);
        
		/* STEP 6. Save your classifier */
		// Save the trained classifier
		boost.save("./trained_boost.xml", "boost");
        
		//return EXIT_SUCCESS;
    }
    
	void Test::read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator) {
		std::ifstream file(filename.c_str(), ifstream::in);
		if (!file) {
			string error_message = "No valid input file was given, please check the given filename.";
			CV_Error(CV_StsBadArg, error_message);
		}
		string line, path, classlabel;
		while (getline(file, line)) {
			stringstream liness(line);
			getline(liness, path, separator);
			getline(liness, classlabel);
			if(!path.empty() && !classlabel.empty()) {
				images.push_back(imread(path, 0));
				labels.push_back(atoi(classlabel.c_str()));
			}
		}
    }
    
	void Test::findEyes(cv::Mat frame_gray, cv::Rect face) {
		
		cv::Mat faceROI = frame_gray(face);
        
		if (kSmoothFaceImage) {
            double sigma = kSmoothFaceFactor * face.width;
            GaussianBlur( faceROI, faceROI, cv::Size( 0, 0 ), sigma);
		}
		//-- Find eye regions and draw them
		int eye_region_width = face.width * (kEyePercentWidth/100.0);
		int eye_region_height = face.width * (kEyePercentHeight/100.0);
		int eye_region_top = face.height * (kEyePercentTop/100.0);
		cv::Rect leftEyeRegion(face.width*(kEyePercentSide/100.0),
                               eye_region_top,eye_region_width,eye_region_height);
		cv::Rect rightEyeRegion(face.width - eye_region_width - face.width*(kEyePercentSide/100.0),
                                eye_region_top,eye_region_width,eye_region_height);
        
		//-- Find Eye Centers
		cv::Point leftPupil = findEyeCenter(faceROI,leftEyeRegion,"Left Eye");
		cv::Point rightPupil = findEyeCenter(faceROI,rightEyeRegion,"Right Eye");
		// get corner regions
        cv::Rect leftRightCornerRegion(leftEyeRegion);
        leftRightCornerRegion.width -= leftPupil.x;
        leftRightCornerRegion.x += leftPupil.x;
        leftRightCornerRegion.height /= 2;
        leftRightCornerRegion.y += leftRightCornerRegion.height / 2;
        cv::Rect leftLeftCornerRegion(leftEyeRegion);
        leftLeftCornerRegion.width = leftPupil.x;
        leftLeftCornerRegion.height /= 2;
        leftLeftCornerRegion.y += leftLeftCornerRegion.height / 2;
        cv::Rect rightLeftCornerRegion(rightEyeRegion);
        rightLeftCornerRegion.width = rightPupil.x;
        rightLeftCornerRegion.height /= 2;
        rightLeftCornerRegion.y += rightLeftCornerRegion.height / 2;
        cv::Rect rightRightCornerRegion(rightEyeRegion);
        rightRightCornerRegion.width -= rightPupil.x;
        rightRightCornerRegion.x += rightPupil.x;
        rightRightCornerRegion.height /= 2;
        rightRightCornerRegion.y += rightRightCornerRegion.height / 2;
        rectangle(faceROI,leftRightCornerRegion,200);
        rectangle(faceROI,leftLeftCornerRegion,200);
        rectangle(faceROI,rightLeftCornerRegion,200);
        rectangle(faceROI,rightRightCornerRegion,200);
        // change eye centers to face coordinates
        rightPupil.x += rightEyeRegion.x;
        rightPupil.y += rightEyeRegion.y;
        leftPupil.x += leftEyeRegion.x;
        leftPupil.y += leftEyeRegion.y;
        // draw eye centers
        circle(faceROI, rightPupil, 3, 1234);
        circle(faceROI, leftPupil, 3, 1234);
        
        //-- Find Eye Corners
        if (kEnableEyeCorner) {
            cv::Point2f leftRightCorner = findEyeCorner(faceROI(leftRightCornerRegion), true, false);
            leftRightCorner.x += leftRightCornerRegion.x;
            leftRightCorner.y += leftRightCornerRegion.y;
            cv::Point2f leftLeftCorner = findEyeCorner(faceROI(leftLeftCornerRegion), true, true);
            leftLeftCorner.x += leftLeftCornerRegion.x;
            leftLeftCorner.y += leftLeftCornerRegion.y;
            cv::Point2f rightLeftCorner = findEyeCorner(faceROI(rightLeftCornerRegion), false, true);
            rightLeftCorner.x += rightLeftCornerRegion.x;
            rightLeftCorner.y += rightLeftCornerRegion.y;
            cv::Point2f rightRightCorner = findEyeCorner(faceROI(rightRightCornerRegion), false, false);
            rightRightCorner.x += rightRightCornerRegion.x;
            rightRightCorner.y += rightRightCornerRegion.y;
            circle(faceROI, leftRightCorner, 3, 200);
            circle(faceROI, leftLeftCorner, 3, 200);
            circle(faceROI, rightLeftCorner, 3, 200);
            circle(faceROI, rightRightCorner, 3, 200);
        }
        
        imshow(face_window_name, faceROI);
    }
}