//
//  main.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Camera.h"
#include "Flux.h"
#include "Process.h"
#include "Interface.h"

using namespace std;
using namespace cv;
using namespace sokaris;


int main(int argc, const char * argv[])
{
    Interface::parseArguments(argc, argv);

#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#endif // _WIN32 || _WIN64
    
    return 0;
}

