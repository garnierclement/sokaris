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
		Point3d angles;
		int idCamera;

	public :
		Gaze(void);
		~Gaze(void);

		/* Création avec paramètres */
		Gaze(double posX, double posY, double posZ, double angleX, double angleY, double angleZ, int idCamera);

		/* Récupération d'info */
		Point3d getPosition();
		Point3d getAngles();
		int getCameraId();

		/* Modification d'info */
		void setPosition(Point3d pos);
		void setAngles(Point3d ang);

		/* Conversion depuis string */
		int Gaze::setFromString(string strSrc);

	};
}

#endif /* defined(__sokaris__Gaze__) */
