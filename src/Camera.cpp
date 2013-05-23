<<<<<<< HEAD
//
//  Camera.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Camera.h"

namespace sokaris
{
	Camera::Camera(void)
	{
	}

	Camera::Camera(int id, Point3d position, float angleX, float angleY, 
		float angleZ, int framerate, string format, float timestamp)
	{
		this->position = position;

	}

	Camera::~Camera(void){
	}

	/* Récupération d'info */
	int Camera::getId(){
		return this->id;
	}

	Point3d Camera::getPosition(){
		return this->position;
	}

	vector<float> Camera::getAngles(){
		return this->angles;
	}

	int Camera::getFramerate(){
		return this->framerate;
	}

	string Camera::getFormat(){
		return this->format;
	}

	float Camera::getTimestamp(){
		return this->timestamp;
	}

	/* Configuration de paramètres */
	void Camera::setPosition(Point3d point)
	{
		this->position = point;
	}

	void Camera::setAngles(vector<float> a){
		if(a.size()!=3)
			cout << "Invalid parameter";
		else if(this->angles.size()!=3)
			this->angles.resize(3);
		else this->angles.swap(a);
	}

=======
//
//  Camera.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

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
		double angles[] = {angleX,angleY,angleZ};
		this->angles.assign (angles,angles+3);
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

	vector<double> Camera::getAngles(){
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

	void Camera::setAngles(vector<double> a){
		if(a.size()!=3)
			cout << "Invalid parameter";
		else if(this->angles.size()!=3)
			this->angles.resize(3);
		else this->angles.swap(a);
	}

>>>>>>> Gaze et Camera
}