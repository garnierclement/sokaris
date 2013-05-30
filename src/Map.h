#ifndef __sokaris__Map__
#define __sokaris__Map__

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include "Camera.h"
#include "Gaze.h"

namespace sokaris
{
	struct Plane{
		Point3d point;							// Point pour définir la terre
		Point3d angles;							// Angles de rotation
		double height;							// Hauteur de la mur
												//  (longueur pour les structures plutôt horizontales)
		double width;							// Largeur jusqu'au plafond
	};

	class Map
	{
	private :
		vector<Camera*> listCameras;			// Liste des caméras dans le plan
		vector<Plane*> listPlanes;			// Liste des plans pour le modèle 3D
		vector<Gaze*> listGazes;				// Liste des regards

	public :
		Map(void);
		~Map(void);

		int Map::getListCamerasSize();
		int Map::getListPlanesSize();
		int Map::getListGazesSize();

		int Map::readCamerasFromFile(string filename);	
												// fichier ==> vector
		int Map::readGazesFromFile(string filename);	
												// fichier ==> vector
		int Map::readPlanesFromFile(string filename);	
												// fichier ==> vector
		
		/// <summary>
		/// Pour écrire le modèle final dans un fichier DAE(XML)
		/// </summary>
		/// <returns>0 si OK, sinon -1</returns>
		int writeResultToFile(string filename, double angleX_observator, 
			double angleY_observator, double angleZ_observator);
												// Stocker dans un fichier xml

		/// <summary>
		/// Pour calculer le point d'intersection entre un plan et
		/// un rayon incident(d'un vecteur de regard).
		/// C'est-à-dire le point du regard projeté sur la mur.
		/// C'est pour harmoniser les zones de l'environnement
		/// afin de mieux représenter.
		/// </summary>
		/// <param name="planeVector">Ligne normale du plan</param>
		/// <param name="planePoint">Un point parcouru par le plan</param>
		/// <param name="lineVector">Vecteur qui représente l'orientation du rayon</param>
		/// <param name="linePoint">Un point parcouru par le rayon incident</param>
		/// <returns>Point d'intersection</returns>
		Point3d calculIntersection(
			Point3d planeVector, Point3d planePoint, 
			Point3d lineVector, Point3d linePoint);

	};

}

#endif /* defined(__sokaris__Map__) */