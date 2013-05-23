//
//  Picture.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Picture__
#define __sokaris__Picture__

#include <iostream>
#include <ctime>

#include "Person.h"
#include "Flux.h"
#include "Camera.h"

namespace sokaris
{
    class Picture
    {
        
    private :
        tm timestamp;                       // Date de l'image
        Camera *camera;                     // Caméra d'origine
        Flux *video;                        // Flux vidéo
        vector<Person*> listOfPersons;      // Liste des personnes dans l'image
        
    public :
        Picture(void);
        ~Picture(void);
        
    };
}

#endif /* defined(__sokaris__Picture__) */
