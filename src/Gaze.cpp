#include "Gaze.h"
namespace sokaris
{
	Gaze::Gaze(void)
	{
	}

	Gaze::Gaze(double posX, double posY, double posZ, 
		double angleX, double angleY, double angleZ)
	{
		this->position = Point3d(posX,posY,posZ);
		this->angles = Point3d(angleX,angleY,angleZ);
	}

	Gaze::~Gaze(void){
	}

	Point3d Gaze::getPosition(){
		return this->position;
	}

	Point3d Gaze::getAngles(){
		return this->angles;
	}

}
