<<<<<<< HEAD
//
//  Gaze.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Gaze.h"
=======
//
//  Gaze.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Gaze.h"
namespace sokaris
{
	Gaze::Gaze(void)
	{
	}

	Gaze::Gaze(Point3d position, double angleX, double angleY, double angleZ)
	{
		this->position = position;
		double angles[] = {angleX,angleY,angleZ};
		this->angles.assign (angles,angles+3);
	}

	Gaze::~Gaze(void){
	}

	Point3d Gaze::getPosition(){
		return this->position;
	}

	vector<double> Gaze::getAngles(){
		return this->angles;
	}

}
>>>>>>> Gaze et Camera
