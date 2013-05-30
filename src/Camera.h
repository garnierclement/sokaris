#ifndef __sokaris__Camera__
#define __sokaris__Camera__

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace sokaris
{
	class Camera
    {
    private :
		int id;						// Identification unique pour chaque caméra
        Point3d position;			// Coordonnées de la caméra, avec Hauteur de la caméra
        Point3d angles;				// Angle de vue de la caméra
        int framerate;              // Nombre d'image par seconde
		string format;
		double timestamp;
        
    public:
        Camera(void);
        ~Camera(void);

		/* Création avec paramètres */
        Camera(int id, double posX, double posY, double posZ, double angleX, double angleY, 
			double angleZ, int framerate, string format, double timestamp);
        
		/* Récupération d'info */
        int getId();
		Point3d getPosition();
		Point3d getAngles();
		int getFramerate();
		string getFormat();
		double getTimestamp();

		/* Modification d'info */
        void setPosition(Point3d point);
		void setAngles(Point3d a);

		/* Conversion depuis string */
		int setFromString(string strSrc);
    };
}

#endif /* defined(__sokaris__Camera__) */