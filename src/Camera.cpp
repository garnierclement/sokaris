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

}