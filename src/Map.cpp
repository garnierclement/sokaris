<<<<<<< HEAD
//
//  Map.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Map.h"

using namespace std;
namespace sokaris
{
    Map::Map()
    {
    }
    
    Map::~Map()
    {
    }

	int Map::setCoordinates(vector<MapPoint*> listCoordinates, string filename)
	{
		FileStorage fs(filename, FileStorage::WRITE);
		fs << "Map";										// text - mapping
        fs << "[" << "Test1" << "Test2" << "]";     
		fs.release();
		return 0;
	}

	int Map::getCoordinates(string filename)
	{
		FileStorage fs;
        fs.open(filename, FileStorage::READ);
		FileNode n = fs["Map"];
		if (n.type() != FileNode::SEQ)
            return -1;										// Map n'est pas une séquence

		FileNodeIterator it = n.begin(), it_end = n.end();  // Itérateur pour lire la séquence
        for (; it != it_end; ++it)
            cout << (string)*it << endl;

		fs.release();										// énoncer la fermeture
		return 0;
	}

	int Map::setCameras(vector<Camera*> listCoordinates, string filename)
	{
		FileStorage fs(filename, FileStorage::WRITE);
		fs << "Camera";
        fs << "[" << "Test1" << "Test2" << "]";     
		fs.release();
		return 0;
	}

	int Map::getCameras(string filename)
	{
		FileStorage fs;
        fs.open(filename, FileStorage::READ);
		FileNode n = fs["Camera"];
		if (n.type() != FileNode::SEQ)
            return -1;										// Map n'est pas une séquence

		FileNodeIterator it = n.begin(), it_end = n.end();  // Itérateur pour lire la séquence
        for (; it != it_end; ++it)
            cout << (string)*it << endl;

		fs.release();										// énoncer la fermeture
		return 0;
	}


	/* Calculation pour la raprésentation */
	vector<float> Map::calculIntersection(
		vector<float> planeVector, vector<float> planePoint, 
		vector<float> lineVector, vector<float> linePoint){
			vector<float> returnResult(3);
			float vp1, vp2, vp3, n1, n2, n3, v1, v2, v3, m1, m2, m3, t,vpt;
			vp1 = planeVector[0];
			vp2 = planeVector[1];
			vp3 = planeVector[2];
			n1 = planePoint[0];
			n2 = planePoint[1];
			n3 = planePoint[2];
			v1 = lineVector[0];
			v2 = lineVector[1];
			v3 = lineVector[2];
			m1 = linePoint[0];
			m2 = linePoint[1];
			m3 = linePoint[2];
			vpt = v1 * vp1 + v2 * vp2 + v3 * vp3;
			if (vpt == 0){
				returnResult.resize(0); //si perpendiculaire, on retourne un verteur null
			}
			else{
				t = ((n1 - m1) * vp1 + (n2 - m2) * vp2 + (n3 - m3) * vp3) / vpt;
				returnResult[0] = m1 + v1 * t;
				returnResult[1] = m2 + v2 * t;
				returnResult[2] = m3 + v3 * t;
			}
			return returnResult;
	}

	/* Sortie du modèle 3D final */
	int drawMap(){
		return 0;
	}
=======
//
//  Map.cpp
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Map.h"

using namespace std;
namespace sokaris
{
    Map::Map()
    {
    }
    
    Map::~Map()
    {
    }

	int Map::setCoordinates(vector<MapPoint*> listCoordinates, string filename)
	{
		FileStorage fs(filename, FileStorage::WRITE);
		fs << "Map";										// text - mapping
        fs << "[" << "Test1" << "Test2" << "]";     
		fs.release();
		return 0;
	}

	int Map::getCoordinates(string filename)
	{
		FileStorage fs;
        fs.open(filename, FileStorage::READ);
		FileNode n = fs["Map"];
		if (n.type() != FileNode::SEQ)
            return -1;										// Map n'est pas une séquence

		FileNodeIterator it = n.begin(), it_end = n.end();  // Itérateur pour lire la séquence
        for (; it != it_end; ++it)
            cout << (string)*it << endl;

		fs.release();										// énoncer la fermeture
		return 0;
	}

	int Map::setCameras(vector<Camera*> listCoordinates, string filename)
	{
		FileStorage fs(filename, FileStorage::WRITE);
		fs << "Camera";
        fs << "[" << "Test1" << "Test2" << "]";     
		fs.release();
		return 0;
	}

	int Map::getCameras(string filename)
	{
		FileStorage fs;
        fs.open(filename, FileStorage::READ);
		FileNode n = fs["Camera"];
		if (n.type() != FileNode::SEQ)
            return -1;										// Map n'est pas une séquence

		FileNodeIterator it = n.begin(), it_end = n.end();  // Itérateur pour lire la séquence
        for (; it != it_end; ++it)
            cout << (string)*it << endl;

		fs.release();										// énoncer la fermeture
		return 0;
	}


	/* Calculation pour la raprésentation */
	vector<double> Map::calculIntersection(
		vector<double> planeVector, vector<double> planePoint, 
		vector<double> lineVector, vector<double> linePoint){
			vector<double> returnResult(3);
			double vp1, vp2, vp3, n1, n2, n3, v1, v2, v3, m1, m2, m3, t,vpt;
			vp1 = planeVector[0];
			vp2 = planeVector[1];
			vp3 = planeVector[2];
			n1 = planePoint[0];
			n2 = planePoint[1];
			n3 = planePoint[2];
			v1 = lineVector[0];
			v2 = lineVector[1];
			v3 = lineVector[2];
			m1 = linePoint[0];
			m2 = linePoint[1];
			m3 = linePoint[2];
			vpt = v1 * vp1 + v2 * vp2 + v3 * vp3;
			if (vpt == 0){
				returnResult.resize(0); //si perpendiculaire, on retourne un verteur null
			}
			else{
				t = ((n1 - m1) * vp1 + (n2 - m2) * vp2 + (n3 - m3) * vp3) / vpt;
				returnResult[0] = m1 + v1 * t;
				returnResult[1] = m2 + v2 * t;
				returnResult[2] = m3 + v3 * t;
			}
			return returnResult;
	}

	/* Sortie du modèle 3D final */
	int drawMap(){
		return 0;
	}
>>>>>>> Gaze et Camera
}