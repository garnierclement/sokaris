//
//  Interface.cpp
//  sokaris
//
//  Created by Clément Garnier on 28/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Interface.h"

namespace sokaris
{
    void Interface::usage()
    {
        cout << "Welcome on Sokaris!" << endl;
        cout << "Usage: sokaris" << endl;
        cout << "\t-data <path_to_data>" << endl;
        cout << "\t-video <path_to_video>" << endl;
        cout << "\t-test <number_of_test> default is 0" << endl;
        cout << "\t-view" << " ('space' for a new image, 'p' to process, 'q' to quit, 's' to switch to video mode)" << endl;
        cout << "\t-o or --output <filename>" << endl;
        cout << "\t-h or --help to display help message" << endl;
        // cout << "\t-command <param>" << endl;
        cout << endl;
    }
    
    void Interface::parseArguments(int argc, const char ** argv)
    {
        string data = "", video = "", output = "";
        int test = 0;
        
        if (argc == 1)
            usage();
        
        for (int i = 1; i < argc; i++)
        {
            if (!strcmp(argv[i], "-data"))
            {
                if (i+1 < argc)
                    data = argv[++i];
                else
                    cout << "Argument -data needs a value" << endl;
            }
            else if (!strcmp(argv[i], "-video"))
            {
                if (i+1 < argc)
                    video = argv[++i];
                else
                    cout << "Argument -video needs a value" << endl;
            }
            else if (!strcmp(argv[i], "-test"))
            {
                if (i+1 < argc)
                    test = atoi(argv[++i]);
                
                if (test == 0)
                    testArthur();
                else if (test == 1)
                    testClement();
                else if (test == 2)
                    testJoel();
                else if (test == 3)
                    testMinwei();
                else
                    cout << "Unkown test : " << argv[i] << endl;
            }
            else if (!strcmp(argv[i], "-view"))
            {
                view(video);
            }
            else if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output"))
            {
                cout << "Not implemented yet" << endl;
            }
            else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
            {
                usage();
            }
            else {
                cout << "Unknown command : " << argv[i] << endl;
                usage();
            }
            /* Warning : crash if argv[++i] does not exist
            else if (!strcmp(argv[i], "-command")) {
                command = argv[++i]; 
            }
            */
        }
    }
    
    
    void Interface::testArthur()
    {
        Test* t = new Test();
        t->testCascadeClassifier();
        //t->trainedClassifier();
        delete t;
    }
    
    void Interface::testClement()
    {
        Flux fl("/Users/garnierclement/Desktop/","test.mp4");
        fl.display(true, Process::testCallback);
    }
    
    void Interface::testJoel()
    {
         MultiplePositions();
    }
    
    void Interface::testMapWriting(string filename)
    {
        
    }
    
    void Interface::testMinwei()
    {
        Map* m = new Map();
            
        if(m->readGazesFromFile("Gazes.ini")<0){
            cout << "error loading Gazes" << endl;
            exit(EXIT_FAILURE);
        }
        if(m->readCamerasFromFile("Cameras.ini")<0){
            cout << "error loading Cameras" << endl;
            exit(EXIT_FAILURE);
        }
        
        cout << m->getListCamerasSize() << endl;
        cout << m->getListGazesSize() << endl;
        m->writeDAEResultToFile("xsd.dae",0.1,5,5,5,135,45,0);
        
        Gaze* g = new Gaze();
        g->setAngles(Point3d(1,1,1));
        Point3d p1 = g->getAngles();
        Point3d p2 = p1;
        p1.x=100;
        cout << p2.x << endl;
        
        Camera* c = new Camera(999, 10, 10, 10, 0, 45, 0,
                               24, "AV", 135790);
        Gaze* gt=new Gaze(5, 5, 5, 0, 0, 0, 999);
        gt->changeCoordinates(c);
        cout << gt->getPosition().x << gt->getPosition().y << gt->getPosition().z <<endl;
        
        int temp;
        cin >> temp;
    }
    
    void Interface::view(string filename)
    {
        VideoCapture video;
        int c1;
        int waiting = 0;
        
        if (!filename.compare(""))
            video.open(0);
        else
            video.open(filename);
        
        if (!video.isOpened()) {
            cout << "Unable to open video" << endl;
            return;
        }
        
        namedWindow("view", CV_WINDOW_AUTOSIZE);
        
        Mat picture;
        
        while (1)
        {
            video >> picture;
            imshow("view", picture);
            
            c1 = waitKey(waiting);
            
            if (c1 == 'q') {
                // exit the loop
                break;
            }
            else if (c1 == 'p') {
                cout << "apply process" << endl;
            }
            else if (c1 == 's') {
                waiting = (waiting == 0) ? 10 : 0;
            }
        }
        
        destroyWindow("view");
    }

}