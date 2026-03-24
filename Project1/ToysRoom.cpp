#include "ToysRoom.h"
#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "Point.h"
#include "TrainCar.h"
#include <texture.h>


void ToysRoom::drawboxpacman(Point center , double width , double height,double depth){
	int img2;
int img9;

		Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));

        glEnable(GL_TEXTURE_2D);
	
			
	img2 =LoadTexture("gamesmachinesfront.bmp",255);
	img9 =LoadTexture("gamesmachinesback.bmp",255);
	glBindTexture(GL_TEXTURE_2D,img9);
	glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
	// Bottom Face

	glBindTexture(GL_TEXTURE_2D,img9);
	glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glEnd();
		// Back Face
		

		glBindTexture(GL_TEXTURE_2D,img9);
		glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glEnd();
			// Right face
	

		glBindTexture(GL_TEXTURE_2D,img2);
		glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			// Left Face
	

		glBindTexture(GL_TEXTURE_2D,img9);
		glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face

	glBindTexture(GL_TEXTURE_2D,img9);
	glColor3ub(255, 255, 255);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
void ToysRoom::drawboxteddybear (Point center , double width , double height,double depth){
int img3;
int img8;

	Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));


								 		glEnable(GL_TEXTURE_2D);
	
			
	img3 =LoadTexture("teddybearbody.bmp",255);
	img8 =LoadTexture("teddybearbodyback.bmp",255);
	glBindTexture(GL_TEXTURE_2D,img3);
 glBegin(GL_QUADS);
			
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			
	// Bottom Face
			glBindTexture(GL_TEXTURE_2D,img8);
			 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glEnd();
		// Back Face
		

	
			 glBegin(GL_QUADS);
			 glBindTexture(GL_TEXTURE_2D,img8);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glEnd();
			// Right face
	

	glBindTexture(GL_TEXTURE_2D,img8);
			 glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			// Left Face
	

	glBindTexture(GL_TEXTURE_2D,img8);
			 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face

	glBindTexture(GL_TEXTURE_2D,img8);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
void ToysRoom::drawboxteddybearface (Point center , double width , double height,double depth){
	int img4;
int img10;

    Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
								 		glEnable(GL_TEXTURE_2D);
	
			
	img4 =LoadTexture("teddybearface1.bmp",255);
	img10 =LoadTexture("teddybearface1b.bmp",255);
	
	glBindTexture(GL_TEXTURE_2D,img4);
	
 glBegin(GL_QUADS);
			
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
	// Bottom Face

	glBindTexture(GL_TEXTURE_2D,img10);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glEnd();
		// Back Face
		

	glBindTexture(GL_TEXTURE_2D,img4);
			
 glBegin(GL_QUADS);
			
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glEnd();
			// Right face
	
	glBindTexture(GL_TEXTURE_2D,img4);

	
 glBegin(GL_QUADS);
			
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			// Left Face
	

	glBindTexture(GL_TEXTURE_2D,img4);
	
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face
		glBindTexture(GL_TEXTURE_2D,img10);
	
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
void ToysRoom::drawboxrubik (Point center , double width , double height,double depth){
	int img5;
    Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
								 		glEnable(GL_TEXTURE_2D);
	
			
	img5 =LoadTexture("rubik.bmp",255);

 glBegin(GL_QUADS);
			glBindTexture(GL_TEXTURE_2D,img5);
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			
	// Bottom Face

	
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
		// Back Face
		

			
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			// Right face
	

			
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			// Left Face
	

	
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face

	
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
void ToysRoom::drawboxboard (Point center , double width , double height,double depth){
int img7;
    Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
								 		glEnable(GL_TEXTURE_2D);
	
			
	img7 =LoadTexture("board.bmp",255);

 glBegin(GL_QUADS);
			glBindTexture(GL_TEXTURE_2D,img7);
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			
	// Bottom Face

	
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
		// Back Face
		

	
			
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			// Right face
	

	
			
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			// Left Face
	

	
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face


 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
void ToysRoom::DrawCube(Point dimentions,Point position) {
	int img23;
	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glEnable(GL_TEXTURE_2D);
	img23 =LoadTexture("wood.bmp",255);
	glBindTexture(GL_TEXTURE_2D, img23);
	glBegin(GL_QUADS);
		glTexCoord2f(1,0);
		glVertex3f(  dimentions.x, -dimentions.y, dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f(  dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x, -dimentions.y, dimentions.z );
    glEnd();
	
    glBegin(GL_QUADS);
		glTexCoord2f(1,0);
		glVertex3f( dimentions.x, -dimentions.y, -dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( dimentions.x,  dimentions.y,  dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( dimentions.x, -dimentions.y,  dimentions.z );
    glEnd();
	
    glBegin(GL_QUADS);
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z );
    glEnd();
	

    glBegin(GL_QUADS);
		glTexCoord2f(1,0);
		glVertex3f(  dimentions.x,  dimentions.y,  dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f(  dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x,  dimentions.y,  dimentions.z );
    glEnd();

    glBegin(GL_QUADS);
		glTexCoord2f(0,1);
		glVertex3f(  dimentions.x, -dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f(  dimentions.x, -dimentions.y,  dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x, -dimentions.y,  dimentions.z );
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z );
    glEnd();

    glBegin(GL_QUADS);
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z);       
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z);      
		glTexCoord2f(0,1);
		glVertex3f(  dimentions.x,  dimentions.y, -dimentions.z);      
		glTexCoord2f(0,0);
		glVertex3f(  dimentions.x, -dimentions.y, -dimentions.z); 
    glEnd();

	 glPopMatrix();
  

}
void ToysRoom::drawtable(Point dimentions, Point position,float heightOnfloor, float legLength){
   
	 glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	//table
	
	DrawCube(dimentions,position);
	//legs
	
	DrawCube(Point(legLength,heightOnfloor,legLength),Point(position.x-dimentions.x+legLength, position.y-dimentions.y-heightOnfloor,position.z+dimentions.z-legLength));
	DrawCube(Point(legLength,heightOnfloor,legLength),Point(position.x-dimentions.x+legLength, position.y-dimentions.y-heightOnfloor,position.z-dimentions.z+legLength));
	DrawCube(Point(legLength,heightOnfloor,legLength),Point( position.x+dimentions.x-legLength, position.y-dimentions.y-heightOnfloor,position.z+dimentions.z-legLength));
	DrawCube(Point(legLength,heightOnfloor,legLength),Point( position.x+dimentions.x-legLength, position.y-dimentions.y-heightOnfloor,position.z-dimentions.z+legLength));

	 glPopMatrix();
}
void ToysRoom::drawchalkbox(Point center , double width , double height,double depth){
	int img27;
	int img28;
	Point pUpperRight(center.x  + (width /2), center.y +(height/2) , center.z +(depth/2) ) ;
	Point pUpperLeft (center.x - (width/2) , center.y +(height/2) , center.z + (depth/2));
	Point pLowerLeft (center.x - (width/2) , center.y -(height/2) , center.z + (depth/2));
	Point pLowerRight (center.x +( width/2) , center.y -(height/2) , center.z + (depth/2));
								 		glEnable(GL_TEXTURE_2D);
	
			
		img27=	LoadTexture("gamesmachinesback.bmp",255);
	img28 =LoadTexture("chalk.bmp",255);
	glBindTexture(GL_TEXTURE_2D,img27);
	glColor3f(1,1,1);
  glBegin(GL_QUADS);
			
			// Front Face
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			
	// Bottom Face
			glBindTexture(GL_TEXTURE_2D,img27);
			glColor3f(1,1,1);
			 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glEnd();
		// Back Face
		

	
			 glBegin(GL_QUADS);
			 glColor3f(1,1,1);
			 glBindTexture(GL_TEXTURE_2D,img27);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glEnd();
			// Right face
	
			glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,img27);
			 glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( pLowerRight.x, pLowerRight.y, pLowerRight.z-depth);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
			glEnd();
			// Left Face
	
			glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,img27);
			 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z-depth);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
		glEnd();
			// upper Face

	glBindTexture(GL_TEXTURE_2D,img28);
 glBegin(GL_QUADS);
			
			glTexCoord2f(0.0f, 0.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( pUpperLeft.x, pUpperLeft.y, pUpperLeft.z-depth);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z-depth);
			glEnd();
			glDisable(GL_TEXTURE_2D);
}
	


void ToysRoom::initRoom() {
	this->addObject(Point(-1.2,0.5,-1),0.5,1.5);
	this->addObject(Point(0.7,0.5,-2.75),0.4,0.5);
	this->addObject(Point(-0.7,0.5,-2.75),0.4,0.5);
	this->addObject(Point(1.1,0.45,-0.5),0.4,0.8);
	this->addObject(Point(1.1,0.64,-0.65),0.2,0.2);
	this->addObject(Point(1.1,0.25,1),0.4,0.4);
	this->addObject(Point(1.1,0.2,-2),0.4,0.4);
	this->addObject(Point(-1.5,0.35,2),0.01,1.5);
}
//int img24;

void ToysRoom::buildRoom() {	
	//glEnable(GL_TEXTURE_2D);
			
	//img24 =LoadTexture("wallabd.bmp",255);
	//img24 =LoadTexture("wallpaper.bmp",255);
	//glPushMatrix();
	//glTranslated(0,0,z_axis_for_car);
	this->drawroom(this->z_axis_for_car);
	//drawtraincarwith2door(img24,img24,img24,img24,img24,img24,0);
	
	//left
	//pacman game
	ToysRoom::drawboxpacman(Point(-1.2,0.5,-1),0.5,1,1.5);
	//front 
	// 2 teddybears besides the door
	ToysRoom::drawboxteddybear(Point(0.7,0.5,-2.75),0.4,1,0.5);
	ToysRoom::drawboxteddybear(Point(-0.7,0.5,-2.75),0.4,1,0.5);
	
	//right 
	// table and 2 teddybears chairs and on top of table rubics cube and a chalkbox
	ToysRoom::drawtable(Point(0.4,0.08,0.8),Point(1.1,0.45,-0.5),0.2,0.08);
	ToysRoom::drawboxrubik(Point(1.1,0.64,-0.65),0.2,0.2,0.2);
	ToysRoom::drawchalkbox(Point(1.1,0.55,0),0.2,0.1,0.2);
	ToysRoom::drawboxteddybearface(Point(1.1,0.25,1),0.4,0.4,0.4);
	ToysRoom::drawboxteddybearface(Point(1.1,0.2,-2),0.4,0.4,0.4);
	//left
	//goal and the ball
	ToysRoom::drawboxboard(Point(-1.5,0.5,2),0.01,0.7,1.5);
	//glTranslated(-1,0.35,2);
	//ToysRoom::Drawball();

	
	//glPopMatrix();
}