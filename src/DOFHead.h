//
//  DOFHead.h
//  sokaris
//
//  Created by Clément Garnier on 06/06/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__DOFHead__
#define __sokaris__DOFHead__

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <math.h>


#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

#include "ehci.h"

#ifdef __APPLE__
//#include <GLUT/GLUT.h>    // GLUT Mac OS X 10.8 (deprecated)
#include <GL/glut.h>        // FreeGLUT from Homebrew
#include <OpenGL/gl.h>      // Header File For The OpenGL
#include <OpenGL/glu.h>     // Header File For The GLu
#else
#include <GL/glut.h>
#include <GL/gl.h>      // Header File For The OpenGL32 Library
#include <GL/glu.h>     // Header File For The GLu32 Library
#endif

using namespace std;

namespace sokaris
{
    struct triangle{
        float vert[3][3];
    };
    
	class DOFHead
	{
    public:
        GLuint	keyframeTexture;
        GLfloat LightAmbient[4]; /* white ambient light at half intensity (rgba) */
        GLfloat LightDiffuse[4]; /* super bright, full intensity diffuse light. */
        GLfloat LightSpecular[4];
        GLfloat LightPosition[4]; /* position of light (x, y, z, (position of light)) */
        GLuint	frameTexture; //openGl texture to store grabbed frame
        int window; /* The number of our GLUT window */
        
        double projectionMatrix[16];

        int initialGuess;
        int drawSine, drawHead, drawAxis, drawNormals, blending, drawLight, drawBackground;
        int aLastHeadW, aLastHeadH;
        int headRefX,headRefY;
        triangle triangles[3036];
        
        char *data;
        
        cv::Mat matrice;
        
        
        ///
        DOFHead(void);
        void drawHelpText();
        void drawCentralAxis();
        void drawReferenceAxis();
        void loadRaw(char* file);
        void drawSinusoidalHead(float scale, int headWidth, int headHeight, int myRefX,int myRefY);
        void drawHeadModel(float scale,int headWidth,int headHeight, int myRefX,int myRefY);
        void checkTransparency();
        void getFrameAsGLTexture();
        void drawGrabbedFrame();
        void keyframeRelated();
        void generateTexture(int width, int height);
        void DrawGLScene(void);
        void ReSizeGLScene(GLsizei Width, GLsizei Height);
        void keyPressed(unsigned char key, int x, int y);
        void InitGL(GLsizei Width, GLsizei Height);
        void openGLCustomInit(int argc, char** argv, double width, double height);
        
        // Point de départ
        int main(int argc, char** argv);
        
        
        // Ajout
        double fromRadianToDegre(double rad);
        void rotationMatrixToAngles(cv::Mat& source);
	};
}

#endif /* defined(__sokaris__DOFHead__) */
