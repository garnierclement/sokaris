#include "Gaze.h"
namespace sokaris
{
	Gaze::Gaze(void)
	{
	}

	Gaze::Gaze(double posX, double posY, double posZ, 
		double angleX, double angleY, double angleZ, int idCamera)
	{
		this->position = Point3d(posX,posY,posZ);
		this->angles = Point3d(angleX,angleY,angleZ);
		this->idCamera = idCamera;
	}

	Gaze::~Gaze(void){
	}

	Point3d Gaze::getPosition(){
		return this->position;
	}

	Point3d Gaze::getAngles(){
		return this->angles;
	}

	void Gaze::setPosition(Point3d pos){
		this->position = pos;
	}

	void Gaze::setAngles(Point3d ang){
		this->angles = ang;
	}

	int Gaze::getCameraId(){
		return this->idCamera;
	}

	int Gaze::setFromString(string strSrc){
		const int nbElemGaze=7;
		stringstream ss(strSrc);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vStrings(begin, end);
		//copy(vStrings.begin(), vStrings.end(), ostream_iterator<string>(cout, "\n"));
		if(vStrings.size()!=nbElemGaze){
			return -1;
		}
		this->idCamera=atoi(vStrings[0].c_str());
		double posX=atof(vStrings[1].c_str());
		double posY=atof(vStrings[2].c_str());
		double posZ=atof(vStrings[3].c_str());
		double angleX=atof(vStrings[4].c_str());
		double angleY=atof(vStrings[5].c_str());
		double angleZ=atof(vStrings[6].c_str());
		this->position = Point3d(posX,posY,posZ);
		this->angles = Point3d(angleX,angleY,angleZ);
		return 0;
	}

}
