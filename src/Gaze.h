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
		vector<double> angles;

	public :
		Gaze(void);
		~Gaze(void);

		/* Création avec paramètres */
		Gaze::Gaze(double posX, double posY, double posZ, 
		double angleX, double angleY, double angleZ);

		/* Récupération d'info */
		Point3d getPosition();
		vector<double> getAngles();
	};
}

#endif /* defined(__sokaris__Gaze__) */
