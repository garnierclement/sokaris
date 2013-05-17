//
//  Test.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Test.h"

#define w 400

namespace sokaris
{
    Test::Test()
    {
        this->path = "/usr/local/Cellar/opencv/2.4.5/share/OpenCV/haarcascades/";
		this->path = "C:/Program Files (x86)/opencv/data/haarcascades/";
		this->face_cascade_name = "haarcascade_frontalface_alt.xml";
        this->eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
		//this->path = "C:/Program Files (x86)/opencv/data/lbpcascades/";
		//this->face_cascade_name = "lbpcascade_frontalface.xml";
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
            //rectangle(frame, center, Scalar(255, 0, 0), 1, 8, 0);
			rectangle( frame, center, center, Scalar( 0, 255, 255 ), 4, 8, 0 );
            Mat faceROI = frame_gray( faces[i] );
            std::vector<Rect> eyes;
            
            //-- In each face, detect eyes
            eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
            
            for( int j = 0; j < eyes.size(); j++ )
            {
                Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
				Point pt = center;
				int thickness = -1;
				int lineType = 8;
				circle( frame, center, w/32.0, Scalar( 0, 0, 255 ), thickness, lineType );
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
				/*stringstream textImage("");
				textImage << center;
				putText(frame, textImage.str(), center, 1, 4.0, Scalar(50,50,50));*/
                circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
				cout << center << endl;
            }
        }
        //-- Show what you got
        imshow( window_name, frame );
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

	void Test::read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
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
}