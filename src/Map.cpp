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

	int Map::setCoordinates(vector<Point3d*> listCoordinates, string filename)
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
}