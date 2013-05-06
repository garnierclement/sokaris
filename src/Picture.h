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

#include "Person.h"
#include "Flux.h"
#include "Camera.h"

namespace sokaris
{
    class Picture
    {
        
    private :
        Camera *camera;
        Flux *video;
        vector<Person*> listOfPersons;
        
    public :
        Picture(void);
        ~Picture(void);
        
    };
}

#endif /* defined(__sokaris__Picture__) */
