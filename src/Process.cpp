//
//  Process.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Process.h"

namespace sokaris
{
    int Process::testCallback(Mat& picture)
    {
        Mat tmp = picture.clone();
        Canny(tmp, picture, 3, 4);
        return 1;
    }
}