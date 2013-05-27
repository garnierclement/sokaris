#ifndef __sokaris__Map__
#define __sokaris__Map__

#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include "Camera.h"

namespace sokaris
{
	struct MapPoint{
		Point3d point;							// Point pour définir la terre
		double height;							// Hauteur de la mur
												//  (longueur pour les structures plutôt horizontales)
		double width;							// Largeur jusqu'au plafond
	};

	class Map
	{
	private :
		vector<Camera*> listOfCameras;			// Liste des caméras dans le plan
		vector<MapPoint*> listOfCoordinates;	// Liste des points cruciaux pour le modèle 3D

	public :
		Map(void);
		~Map(void);

		int getCoordinates(string filename);	// Depuis un fichier xml
		int setCoordinates(vector<MapPoint*> listCoordinates, string filename);
												// Stocker dans un fichier xml
		int getCameras(string filename);		// Depuis un fichier xml
		int setCameras(vector<Camera*> listCoordinates, string filename);
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
		vector<double> calculIntersection(
			vector<double> planeVector, vector<double> planePoint, 
			vector<double> lineVector, vector<double> linePoint);

		/// <summary>
		/// Pour écrire le modèle final dans un fichier DAE(XML)
		/// </summary>
		/// <returns>0 si OK, sinon -1</returns>
		int drawMap();

	};

}

#endif /* defined(__sokaris__Map__) */