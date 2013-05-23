<<<<<<< HEAD
//
//  Gaze.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Gaze__
#define __sokaris__Gaze__

#include <iostream>

namespace sokaris
{
    class Gaze
    {
        public :
        
        
    };
}

#endif /* defined(__sokaris__Gaze__) */
=======
//
//  Gaze.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Gaze__
#define __sokaris__Gaze__

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace sokaris
{
	class Gaze
	{
	private : 
		Point3d position;
		vector<double> angles;

	public :
		Gaze(void);
		~Gaze(void);

		/* Création avec paramètres */
		Gaze(Point3d position, double angleX, double angleY, double angleZ);

		/* Récupération d'info */
		Point3d getPosition();
		vector<double> getAngles();
	};
}

#endif /* defined(__sokaris__Gaze__) */
>>>>>>> Gaze et Camera
