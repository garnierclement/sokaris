//
//  Interface.h
//  sokaris
//
//  Created by Clément Garnier on 28/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Interface__
#define __sokaris__Interface__

#include <iostream>
#include <sstream>
#include <map>

using namespace std;

namespace sokaris
{
    class Interface
    {
    public :
        static void parseArguments(int argc, const char ** argv);
        static void usage();
    };
}

#endif /* defined(__sokaris__Interface__) */
