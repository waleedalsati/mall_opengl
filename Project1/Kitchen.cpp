#include <windows.h>		// Header File For Windows
#include <texture.h>
#include <gl\GL.h>			// Header File For The OpenGL32 Library
#include <gl\GLU.h>			// Header File For The GLu32 Library 
#include "Point.h"
#include "Kitchen.h"
#include "TrainCar.h"





void Kitchen::drawStove (Point center , double width , double height,double depth){

  Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
  Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
  Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
  Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
                     glEnable(GL_TEXTURE_2D);
  
      
  int img15=LoadTexture("stove2top.bmp",255);
  int img16 =LoadTexture("wood.bmp",255);
  int img17 =  LoadTexture("storage2.bmp",255);  
  glBindTexture(GL_TEXTURE_2D,img17);
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
      
      // Front Face
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      
  // Bottom Face
      glBindTexture(GL_TEXTURE_2D,img16);
      glColor3f(1,1,1);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glEnd();
    // Back Face
    

  
       glBegin(GL_QUADS);
       glColor3f(1,1,1);
       glBindTexture(GL_TEXTURE_2D,img16);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glEnd();
      // Right face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img16);
       glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      // Left Face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img16);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
    glEnd();
    // upper Face

  glBindTexture(GL_TEXTURE_2D,img15);
 glBegin(GL_QUADS);
      
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glEnd();
	  glDisable(GL_TEXTURE_2D);
}



void Kitchen::drawref (Point center , double width , double height,double depth){


  Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
  Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
  Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
  Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
                     glEnable(GL_TEXTURE_2D);
  
      
  int img13=LoadTexture("ref13front.bmp",255);
  int img14 =LoadTexture("ref13back.bmp",255);
  glBindTexture(GL_TEXTURE_2D,img13);
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
      
      // Front Face
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      
  // Bottom Face
      glBindTexture(GL_TEXTURE_2D,img14);
      glColor3f(1,1,1);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glEnd();
    // Back Face
    

  
       glBegin(GL_QUADS);
       glColor3f(1,1,1);
       glBindTexture(GL_TEXTURE_2D,img14);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glEnd();
      // Right face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img14);
       glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      // Left Face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img14);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
    glEnd();
      // upper Face

  glBindTexture(GL_TEXTURE_2D,img14);
 glBegin(GL_QUADS);
      
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glEnd();

	  glDisable(GL_TEXTURE_2D);
}
void Kitchen::drawoven (Point center , double width , double height,double depth){


  Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
  Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
  Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
  Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
  glEnable(GL_TEXTURE_2D);
  
      
  int img11=LoadTexture("Oven5front.bmp",255);
  int img12 =LoadTexture("ref_back.bmp",255);
  glBindTexture(GL_TEXTURE_2D,img11);
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
      
      // Front Face
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      
  // Bottom Face
      glBindTexture(GL_TEXTURE_2D,img12);
      glColor3f(1,1,1);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glEnd();
    // Back Face
    

  
       glBegin(GL_QUADS);
       glColor3f(1,1,1);
       glBindTexture(GL_TEXTURE_2D,img12);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glEnd();
      // Right face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img12);
       glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      // Left Face
  
      glColor3f(1,1,1);
  glBindTexture(GL_TEXTURE_2D,img12);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
    glEnd();
      // upper Face

  glBindTexture(GL_TEXTURE_2D,img12);
 glBegin(GL_QUADS);
      
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glEnd();
	  glDisable(GL_TEXTURE_2D);
}

void Kitchen::drawSink (Point center , double width , double height,double depth){

  Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
  Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
  Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
  Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
                     glEnable(GL_TEXTURE_2D);
  
  int img20=LoadTexture("sinktop.bmp",255);    
  int img22 =LoadTexture("wood.bmp",255);
  int img21 =  LoadTexture("storage2.bmp",255);  
  glBindTexture(GL_TEXTURE_2D,img21);
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
      
      // Front Face
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      
  // Bottom Face
      glBindTexture(GL_TEXTURE_2D,img22);
      
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glEnd();
    // Back Face
    

  
       glBegin(GL_QUADS);
       
       glBindTexture(GL_TEXTURE_2D,img22);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 0.0f); glVertex3d( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glEnd();
      // Right face
  
      
  glBindTexture(GL_TEXTURE_2D,img22);
       glBegin(GL_QUADS);
      glTexCoord2f(1.0f, 0.0f); glVertex3d( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d( pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerRight.x, pLowerRight.y, pLowerRight.z);
      glEnd();
      // Left Face
  
      
  glBindTexture(GL_TEXTURE_2D,img22);
       glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
    glEnd();
    // upper Face

  glBindTexture(GL_TEXTURE_2D,img20);
 glBegin(GL_QUADS);
      
      glTexCoord2f(0.0f, 0.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z);
      glTexCoord2f(1.0f, 0.0f); glVertex3d(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
      glTexCoord2f(1.0f, 1.0f); glVertex3d( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
      glTexCoord2f(0.0f, 1.0f); glVertex3d(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
      glEnd();
}

















void Kitchen::initRoom() {
	this->addObject(Point(-1.1,0.35,1.5),0.8,0.8);//1

	this->addObject(Point(-1.1,0.35,2.4),0.8,0.8);//2

	this->addObject(Point(1.05,0.85,-2.6),0.9,0.8);//3

	this->addObject(Point(1.1,0.35,-0.5),0.8,0.8);//4

	this->addObject(Point(1.25,0.35,0.2),0.5,0.5);//5

	this->addObject(Point(1.25,0.35,0.72),0.5,0.5);//6

	this->addObject(Point(1.2,0.3,2),0.6,0.7);//7

	this->addObject(Point(-1.2,0.3,-1.8),0.6,0.9);//8

	this->addObject(Point(-1.2,0.3,0),0.6,0.9);//9

	this->addObject(Point(-1.2,0.3,-2.5),0.6,0.9);//10

	this->addObject(Point(-1.2,0.3,-1.2),0.6,0.9);//11

	this->addObject(Point(-1.2,0.3,-0.7),0.6,0.9);//12

	this->addObject(Point(-1.2,0.3,0.8),0.6,0.9);//13

	this->addObject(Point(1.2,0.3,2.6),0.6,0.7);//14

	this->addObject(Point(1.2,0.3,1.4),0.6,0.7);//15
	



}
void Kitchen::drawtable(Point center , double width , double height,double depth){

	glBegin(GL_QUADS);
	   glColor3f(0.8, 0.5, 0.3);
	    glVertex3d(center.x-width/2, center.y+height/2,center.z+depth/2);
    	glVertex3d(center.x-width/2, center.y+height/2,center.z-depth/2);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2);

		glVertex3d(center.x-width/2, center.y+height/2,center.z+depth/2);
    	glVertex3d(center.x-width/2, center.y+height/2,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2,center.z+depth/2);
    	

		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2);
    	glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2);
    

		glVertex3d(center.x+width/2, center.y+height/2,center.z+depth/2);
    	glVertex3d(center.x+width/2, center.y+height/2,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2);

		glVertex3d(center.x+width/2, center.y+height/2,center.z-depth/2);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d((center.x-width/2), center.y+height/2-0.05,center.z-depth/2);
		glVertex3d((center.x-width/2), center.y+height/2,center.z-depth/2);

		glVertex3d(center.x+width/2, center.y+height/2,(center.z+depth/2));
		glVertex3d(center.x+width/2, center.y+height/2-0.05,(center.z+depth/2));
		glVertex3d((center.x-width/2), center.y+height/2-0.05,(center.z+depth/2));
		glVertex3d((center.x-width/2), center.y+height/2,(center.z+depth/2));
	////////////////////////////////////////////////////////////////////////////

		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2-0.05);

		glVertex3d(center.x-width/2, 0,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2,0,center.z+depth/2-0.05);

		glColor3f(0.5,0.5,0.5);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x-width/2, 0,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2);

		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2, 0,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2-0.05);

		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z+depth/2);
		
		glVertex3d(center.x-width/2, 0,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x-width/2, 0,center.z+depth/2);




	//
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x+width/2, 0,center.z+depth/2);
		glVertex3d(center.x+width/2-0.05, 0,center.z+depth/2);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z+depth/2);

		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2, 0,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2-0.05, 0,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z+depth/2-0.05);


		glVertex3d(center.x+width/2, 0,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x+width/2, 0,center.z+depth/2);

		glVertex3d(center.x+width/2-0.05, 0,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z+depth/2-0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z+depth/2);
		glVertex3d(center.x+width/2-0.05, 0,center.z+depth/2);

		//


		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x-width/2, 0,center.z-depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z-depth/2);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z-depth/2);

		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2, 0,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2+0.05, 0,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z-depth/2+0.05);

		glVertex3d(center.x+width/2, 0,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2, 0,center.z-depth/2);

		glVertex3d(center.x+width/2-0.05, 0,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2-0.05, 0,center.z-depth/2);




		//4
		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x+width/2, 0,center.z-depth/2);
		glVertex3d(center.x+width/2-0.05, 0,center.z-depth/2);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z-depth/2);

		glVertex3d(center.x+width/2, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2, 0,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2-0.05, 0,center.z-depth/2+0.05);
		glVertex3d(center.x+width/2-0.05, center.y+height/2-0.05,center.z-depth/2+0.05);

		glVertex3d(center.x-width/2+0.05, 0,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2+0.05, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x-width/2+0.05, 0,center.z-depth/2);

		glVertex3d(center.x-width/2, 0,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2+0.05);
		glVertex3d(center.x-width/2, center.y+height/2-0.05,center.z-depth/2);
		glVertex3d(center.x-width/2, 0,center.z-depth/2);


	//	//4




    glEnd();





}



void Kitchen::drawChair() {

	// glTranslatef(0.0f, 0.0f, -14.0f);

	//glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	//glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	//glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(0.4f, 0.302f, 0.0f);
	glBegin(GL_QUADS);

	//Front
	//
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Left
	;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//

	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;

	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -3.0f, 1.6f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//back
	//;

	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);

	//right


	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//left
	;

	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;

	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);

	//back
	;

	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -3.0f, -1.6f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//right


	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.6f);

	//chair back
	//front





	//;
	//chair upper part 
	glColor3f(0.902, 0.902, 0);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	//chair upper side
	glColor3f(1, 1, 0.4);
	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 1.2f, -1.80f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	//chiar upper top 
	glColor3f(1, 1, 0);
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -1.8f);

	// chair top legs 

	glColor3f(0.2, 0.2, 0.0);
	//side walls
	glVertex3f(-1.2f, 1.2f, -1.20f);
	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-.8f, 1.2f, -1.20f);
	glVertex3f(-.8f, 1.2f, -0.6f);
	glVertex3f(-.8f, .2f, -0.6f);
	glVertex3f(-.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glVertex3f(-1.2f, 1.2f, -1.2f);
	glVertex3f(-0.8f, 1.2f, -1.2f);
	glVertex3f(-0.8f, .2f, -1.2f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-0.8f, 1.2f, -0.6f);
	glVertex3f(-0.8f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);

	//side walls
	glVertex3f(1.2f, 1.2f, -1.20f);
	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(.8f, 1.2f, -1.20f);
	glVertex3f(.8f, 1.2f, -0.6f);
	glVertex3f(.8f, .2f, -0.6f);
	glVertex3f(.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(1.2f, 1.2f, -1.2f);
	glVertex3f(0.8f, 1.2f, -1.2f);
	glVertex3f(0.8f, .2f, -1.2f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(0.8f, 1.2f, -0.6f);
	glVertex3f(0.8f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);

	//glVertex3f()

	glEnd();

}

void Kitchen::buildRoom() {	
	int img0= LoadTexture("wallkitchen.bmp",255);
	//drawroom(0.0);
	drawtraincar(img0,img0,img0,img0,img0,img0,0.0);
	//drawcartafal(img0,img0,img0,img0,img0,img0,0.0,flagg);
	//drawcarwith4window2door(img0,img0,img0,img0,img0,img0,0.0);
	glPushMatrix();
	glTranslatef(-1.1,0.35,1.5);
	glRotatef(90,0,1,0);
	drawoven(Point(0,0,0),0.8,0.7,0.8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.1,0.35,2.4);
	glRotatef(90,0,1,0);
	drawoven(Point(0,0,0),0.8,0.7,0.8);
	glPopMatrix();
	drawref(Point(1.05,0.85,-2.6),0.9,1.7,0.8);
	glPushMatrix();
	glTranslatef(1.1,0.35,-0.5);
	glRotatef(-90,0,1,0);
	drawStove(Point(0,0,0),0.8,0.7,0.8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25,0.35,0.2);
	glRotatef(-90,0,1,0);
	drawSink(Point(0,0,0),0.5,0.7,0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25,0.35,0.72);
	glRotatef(-90,0,1,0);
	drawSink(Point(0,0,0),0.5,0.7,0.5);
	glPopMatrix();
	drawtable(Point(1.2,0.3,2),0.6,0.6,0.7);//7
	drawtable(Point(-1.2,0.3,-1.8),0.6,0.6,0.9);//8
	drawtable(Point(-1.2,0.3,0),0.6,0.6,0.9);//9
		glPushMatrix();
		glTranslatef(-1.2,0.3,-2.5);//10
	glScalef(0.1,0.1,0.1);
	drawChair();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.2,0.3,-1.2);//11
	glScalef(0.1,0.1,0.1);
	glRotatef(180,0,1,0);
	drawChair();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.2,0.3,-0.7);//12
	glScalef(0.1,0.1,0.1);
	drawChair();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.2,0.3,0.8);//13
	glScalef(0.1,0.1,0.1);
	glRotatef(180,0,1,0);
	drawChair();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.2,0.3,2.6);//14
	glScalef(0.1,0.1,0.1);
	glRotatef(180,0,1,0);
	drawChair();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.2,0.3,1.4);//15
	glScalef(0.1,0.1,0.1);
	drawChair();
	glPopMatrix();
}