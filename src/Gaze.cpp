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
