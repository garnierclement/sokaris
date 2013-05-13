//
//  main.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Map.h"
#include "Camera.h"
#include "Flux.h"
#include "Picture.h"
#include "Person.h"
#include "Gaze.h"
#include "Process.h"
#include "Test.h"

using namespace std;
using namespace cv;
using namespace sokaris;

int main(int argc, const char * argv[])
{
    cout << "Welcome on Sokaris!\n";

#if defined(_WIN32) || defined(_WIN64)
	cout << "je m'appelle Arthur" << endl;
	system("pause");
#endif // _WIN32 || _WIN64
    
    Test *t = new Test();
    
    t->testCascadeClassifier();
    
    delete t;

    return 0;
}

