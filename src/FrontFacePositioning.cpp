//
//  FrontFacePositioning.cpp
//  
//
//  Created by Joel on 6/3/13.
//  Copyright (c) 2013 Joel. All rights reserved.
//
/*
 Cette fonction detecte -au plus une personne- -de face- et calcule ses coordonnees polaires par rapport a la camera
*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>

using namespace std;
using namespace cv;

int frontFacePositioning(int argc, const char** argv)
{
    //create the cascade classifier object used for the face detection
    CascadeClassifier face_cascade;
    //use the haarcascade_frontalface_alt.xml library
    const char* cascade_name1 =
    "/Users/joel/Documents/My Documents/sokaris/data/opencv/haarcascades/haarcascade_frontalface_alt.xml";
    
    face_cascade.load(cascade_name1);
    
    //setup video capture device and link it to the first capture device
    VideoCapture captureDevice;
    captureDevice.open(0);
    
    //Decomenter ses lignes pour changer la resolution
    //captureDevice.set(CV_CAP_PROP_FRAME_WIDTH,400);
    //captureDevice.set(CV_CAP_PROP_FRAME_HEIGHT,400);
    
    //CALIBRATION
    //Prendre la resolution
    const double H = captureDevice.get(CV_CAP_PROP_FRAME_HEIGHT);
    const double W = captureDevice.get(CV_CAP_PROP_FRAME_WIDTH);
    cout << "Starting capture..." << endl;
    cout << "Resolution is: " << endl;
    cout << "H= " << H << endl;
    cout << "W= " << W << endl;

    //Creer un point au centre de l'ecran
    Point2f screenCenter(W/2.0,H/2.0);
    
    //distance focale en mm
    const float f = 1000.0;
    
    //taille du diametre du visage
    const float D = 145.0;
    
    //FIN CALIBRATION
    
    //matrice d'images
    Mat captureFrame; //video de capture
    Mat grayscaleFrame; //video a traiter en gris et equalisee  

    
    //fenetre d'affichage
    namedWindow("outputCapture", 1);
    
    //Debut de l'algo
    while(true)
    {
        //redirige le flux
        captureDevice>>captureFrame;
        
        //convert captured image to gray scale and equalize
        cvtColor(captureFrame, grayscaleFrame, CV_BGR2GRAY);
        equalizeHist(grayscaleFrame, grayscaleFrame);
        
        //create a vector array to store the face found
        vector<Rect> faces;
        
        //find faces and store them in the vector array
        face_cascade.detectMultiScale(grayscaleFrame, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE, Size(30,30));
        
        //Param d: taille en pixels du visage
        //Param z: 
        vector<double> d(faces.size()),z(faces.size());

        //draw a rectangle for all found faces in the vector array on the original image
        for(int i = 0; i < faces.size(); i++)
        {
            Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            Point pt2(faces[i].x, faces[i].y);
            rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
            
            //Point 3 est le centre du rectangle qui fait le contour du visage
            Point pt3(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
            
            //ALGO DE CALCUL DE LA DISTANCE ////  f=d*Z/D
            d[i] = faces[i].width;
            z[i] = D*f/d[i];
            
            //CALCUL DE L'ANGLE AVEC DISTANCE FOCALE
            double xScreen = screenCenter.x-pt3.x;
            double xReel = xScreen*z[i]/f;
            
            double angle = asin(xReel/z[i])*180/3.141592;
            //cout << "l'angle est le suivant: " << angle << "\n";
            
            stringstream sstm;
            sstm << "Angle = " << angle << " degrees | " << "Depth = " << z[i]/10 << " cm";
            String outputText = sstm.str();
            
            //Positioner le texte sur l'ecran
            Point2f textPosition((W/12),7*H/8);
            //Mise du texte sur l'ecran
            putText(captureFrame, outputText, textPosition, FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255,255,255),1,8,false);
        }
        
        //print the output
        imshow("outputCapture", captureFrame);
        
        // Il y a un frame rate de 1/3 s = 33 ms
        waitKey(33);
        
        
    }
    
    return 0;
}