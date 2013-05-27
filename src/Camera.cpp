#include "Camera.h"

namespace sokaris
{
	Camera::Camera(void)
	{
	}

	Camera::Camera(int id, double posX, double posY, double posZ, double angleX, double angleY, 
		double angleZ, int framerate, string format, double timestamp)
	{
		this->id = id;
		this->position = Point3d(posX,posY,posZ);
		this->angles = Point3d(angleX,angleY,angleZ);
		this->framerate = framerate;
		this->format.assign(format);
		this->timestamp = timestamp;
	}

	Camera::~Camera(void){
	}

	int Camera::getId(){
		return this->id;
	}

	Point3d Camera::getPosition(){
		return this->position;
	}

	Point3d Camera::getAngles(){
		return this->angles;
	}

	int Camera::getFramerate(){
		return this->framerate;
	}

	string Camera::getFormat(){
		return this->format;
	}

	double Camera::getTimestamp(){
		return this->timestamp;
	}

	void Camera::setPosition(Point3d point)
	{
		this->position = point;
	}

	void Camera::setAngles(Point3d a){
		this->angles = a;
	}
}