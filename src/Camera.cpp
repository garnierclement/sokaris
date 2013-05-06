//
//  Camera.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Camera.h"

namespace sokaris
{
    Camera::Camera(void)
    {
    }
    
    Camera::Camera(Point2d coordinates)
    {
        this->coordinates = coordinates;
    }
    
    Camera::~Camera(void)
    {
    }
    
    Point2d Camera::getCoordinates()
    {
        return this->coordinates;
    }
    
    void Camera::setCoordinates(Point2d point)
    {
        this->coordinates = point;
    }
}