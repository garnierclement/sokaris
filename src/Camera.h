//
//  Camera.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Camera__
#define __sokaris__Camera__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace sokaris
{
    class Camera
    {
    private :
        Point3d coordinates;        // Coordonnées de la caméra, avec Hauteur de la caméra
        float angleX;               // Angle de vue de la caméra
		float angleY;
		float angleZ;
        int framerate;              // Nombre d'image par seconde
        
    public:
        Camera(void);
        Camera(Point3d coordinates);
        ~Camera(void);
        
        Point3d getCoordinates();
        void setCoordinates(Point3d point);
        

    };
}

#endif /* defined(__sokaris__Camera__) */
