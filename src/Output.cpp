//
//  Output.cpp
//  sokaris
//
//  Created by Joel on 6/3/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//
//
//  flag = 1 -> La fonction effacera tout le contenu de la trace avant d'ecrire ses informations
//  flag = 0 -> La fonction continuera d'ecrire ses infos a la suite du fichier 
//
//
//
//

#include "Output.h"

using namespace std;

int Output(int cameraId, double x, double y, double z, double aX, double aY, double aZ, int flag){

    // Arrondi x, y et z pour pas avoir mille decimaux
    float zRounded = truncf(z * 10) / 10;
    float yRounded = truncf(y * 10) / 10;
    float xRounded = truncf(x * 10) / 10;
    
    stringstream sstm;
    sstm << cameraId << " " << xRounded << " " << yRounded << " " << zRounded << " " << aX << " "<< aY << " " << aZ << " "<<endl;
    
    string outputText = sstm.str();
    
    //Changer le nom du fichier pour un fichier local
    string filename = "/Users/joel/Desktop/example";
    
    if (flag == 1) {
        //Erase all file contents
        ofstream(filename.c_str()).close();
    }
   
    
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