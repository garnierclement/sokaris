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
		Point3d point;							// Point du centre pour définir la mur
		Point3d angles;							// Angles de rotation
		double height;							// Hauteur de la mur
												//  (longueur pour les structures plutôt horizontales)
		double width;							// Largeur jusqu'au plafond
	};

	struct Intersection{
		Point3d position;						// Intersection d'un regard sur un mur
		double time;							// à un moment
	};

	class Map
	{
	private :
		vector<Camera*> listCameras;			// Liste des caméras dans le plan
		vector<Plane*> listPlanes;				// Liste des plans pour le modèle 3D
		vector<Gaze*> listGazes;				// Liste des regards
		vector<Intersection*> listIntersection; // Liste des intersections calculées, à afficher

	public :
		Map(void);
		~Map(void);

		int getListCamerasSize();
		int getListPlanesSize();
		int getListGazesSize();

		/* Chargement des données depuis fichiers */
		int readCamerasFromFile(string filename);
		int readGazesFromFile(string filename);
		int readPlanesFromFile(string filename);
		


		/* Ecriture de fichier 3D */
		// Pour écrire le modèle final dans un fichier DAE(XML)
		int writeDAEResultToFile(string filename, double energy, double posX_observator, 
			double posY_observator, double posZ_observator, double angleX_observator, 
			double angleY_observator, double angleZ_observator);

		// Pour écrire les intersections des regards à représenter
		// "time posX posY posZ"
		int writeIntersectionsToFile(string filename);

		// Pour écrire les murs/terrains à représenter
		// "posX posY posZ angX angY angZ height width"
		int writePlanesToFile(string filename);




		/* Fonctions de calcul */
		// Pour calculer le point d'intersection entre un plan et
		// un rayon incident(d'un vecteur de regard).
		// C'est-à-dire le point du regard projeté sur la mur.
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