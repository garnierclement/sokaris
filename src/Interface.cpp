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
        cout << "\t-h or --help to display this message" << endl;
        cout << endl;
    }
    
    void Interface::parseArguments(int argc, const char ** argv)
    {
        if (argc == 1) {
            usage();
        }
        
        for (int i = 1; i < argc; i++)
        {
            if (!strcmp(argv[i], "-data")) {
                string data = argv[++i];
            }
            else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
                usage();
            }
        }
    }

}