//
//  Person.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//
//Rev 1.0 : The aim of this class is to create an object person that will allow us 
//          to track a person in consecutive images.
//

#include "Person.h"

namespace sokaris
{

    Person::Person(void)
    {
    }
    
    Person::Person(Point2d coordinates)
    {
        this->coordinates = coordinates;
    }
    
    Person::~Person(void)
    {
    }
    
    Point2d Person::getCoordinates()
    {
        return this->coordinates;
    }
    
    void Person::setCoordinates(Point2d point)
    {
        this->coordinates = point;
    }
}