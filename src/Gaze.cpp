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
