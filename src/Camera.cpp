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

	int Camera::setFromString(string strSrc){
		const int nbElemCamera=10;
		stringstream ss(strSrc);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vStrings(begin, end);
		//copy(vStrings.begin(), vStrings.end(), ostream_iterator<string>(cout, "\n"));
		if(vStrings.size()!=nbElemCamera){
			return -1;
		}
		double posX=atof(vStrings[1].c_str());
		double posY=atof(vStrings[2].c_str());
		double posZ=atof(vStrings[3].c_str());
		double angleX=atof(vStrings[4].c_str());
		double angleY=atof(vStrings[5].c_str());
		double angleZ=atof(vStrings[6].c_str());
		this->id = atoi(vStrings[0].c_str());;
		this->position = Point3d(posX,posY,posZ);
		this->angles = Point3d(angleX,angleY,angleZ);
		this->framerate = atoi(vStrings[7].c_str());
		this->format.assign(vStrings[8]);
		this->timestamp = atof(vStrings[9].c_str());
		return 0;
	}

}