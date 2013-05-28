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

#include "Process.h"
#include "Flux.h"
#include "Test.h"

using namespace std;

namespace sokaris
{
    class Interface
    {
    public :
        static void parseArguments(int argc, const char ** argv);
        static void usage();
        
        // Différents tests
        static void testArthur();
        static void testClement();
        static void view(string filename = "");
    };
}

#endif /* defined(__sokaris__Interface__) */
