//
//  Map.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

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
	class Map
	{
	private :
		vector<Camera*> listOfCameras;			// Liste des caméras dans le plan
		vector<Point3d*> listOfCoordinates;		// Liste des points cruciaux pour le modèle 3D

	public :
		int getCoordinates(string filename);	// Depuis un fichier xml
		int setCoordinates(vector<Point3d*> listCoordinates, string filename);
												// Stocker dans un fichier xml
		int getCameras(string filename);		// Depuis un fichier xml
		int setCameras(vector<Camera*> listCoordinates, string filename);
												// Stocker dans un fichier xml
		void drawMap();
		Map(void);
		~Map(void);

	};

}

#endif /* defined(__sokaris__Map__) */
