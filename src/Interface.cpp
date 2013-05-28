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
        cout << "\t-o or --output <filename>" << endl;
        cout << "\t-h or --help to display this message" << endl;
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
                if (++i < argc)
                    data = argv[++i];
            }
            else if (!strcmp(argv[i], "-video"))
            {
                if (++i < argc)
                    video = argv[++i];
            }
            else if (!strcmp(argv[i], "-test"))
            {
                if (++i < argc)
                    test = atoi(argv[++i]);
                
                if (test == 0)
                    testArthur();
                
                else if (test == 1)
                    testClement();
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

}