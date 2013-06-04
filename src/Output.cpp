//
//  Output.cpp
//  sokaris
//
//  Created by Joel on 6/3/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#include "Output.h"

using namespace std;

int Output(double cameraId, double x, double y, double z, double aX, double aY, double aZ){

    stringstream sstm;
//    float zRounded = truncf(z * 10) / 10;
//    float angleRounded = truncf(angle * 10) / 10;
//    
    sstm << cameraId << " " << x << " " << y << " " << z << " " << aX << " "<< aY << " " << aZ << " "<<endl;
    
    string outputText = sstm.str();
    
    //Changer le nom du fichier pour un fichier local
    string filename = "/Users/joel/Desktop/example";
    
    //Erase all file contents
    ofstream(filename.c_str()).close();
    
    //Reopen the file to write in it
    ofstream outputFile(filename.c_str(),ios::app);
    if (outputFile.is_open())
    {
        outputFile << outputText;
        outputFile.close();
    }else{
        return -1;
    }
    return 0;

}