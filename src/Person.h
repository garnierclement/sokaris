//
//  Person.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Person__
#define __sokaris__Person__

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Gaze.h"

using namespace cv;

namespace sokaris
{
    class Person
    {
        
    private :
        Point2d coordinates;    // Coordonnées de la personne dans l'espace
        Gaze *gaze;             // Regard de la personne
        Scalar colour;          // Couleur de la personne
        
    public :
        Person(void);
        Person(Point2d coordinates);
        ~Person(void);
        
        Point2d getCoordinates();
        void setCoordinates(Point2d point);
        
        
    };
}

#endif /* defined(__sokaris__Person__) */
