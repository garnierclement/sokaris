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
    
    Camera::Camera(Point3d coordinates)
    {
        this->coordinates = coordinates;
    }
    
    Camera::~Camera(void)
    {
    }
    
    Point3d Camera::getCoordinates()
    {
        return this->coordinates;
    }
    
    void Camera::setCoordinates(Point3d point)
    {
        this->coordinates = point;
    }
}