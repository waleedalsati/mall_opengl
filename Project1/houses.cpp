#include "houses.h"
#include "texture.h"
//#include "Wall.h"
//#include "Point.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>
//#include "Shapes.h"
void houses::buildhouse(int x,int y ,int z,int texture1,int texture2 ,int textures,int texture4,int texture5 ,int texture6){


	glBindTexture(GL_TEXTURE_2D,texture1);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x,0,0);
	glTexCoord2d(1,0);
	glVertex3d(x,0,0);
	glTexCoord2d(1,1);
	glVertex3d(x,y,0);
	glTexCoord2d(0,1);
	glVertex3d(-x,y,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,texture2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
    glVertex3d(-x,0,0);
    glTexCoord2d(1,0);
    glVertex3d(-x,0,z);
    glTexCoord2d(1,1);
    glVertex3d(-x,y,z);
    glTexCoord2d(0,1);
    glVertex3d(-x,y,0);
    glEnd();

   glBindTexture(GL_TEXTURE_2D,textures);
   glBegin(GL_QUADS);
   glTexCoord2d(0,0);
   glVertex3d(-x,y,0);
   glTexCoord2d(1,0);
   glVertex3d(x,y,0);
   glTexCoord2d(1,1);
   glVertex3d(x,y,z);
   glTexCoord2d(0,1);
   glVertex3d(-x,y,z);
   glEnd();
  
 
 
   glBindTexture(GL_TEXTURE_2D,texture4);
   glBegin(GL_QUADS);
   glTexCoord2d(0,0);
   glVertex3d(x,0,0);
   glTexCoord2d(1,0);
   glVertex3d(x,0,z);
   glTexCoord2d(1,1);
   glVertex3d(x,y,z);
   glTexCoord2d(0,1);
   glVertex3d(x,y,0);
   glEnd();
 
 
  glBindTexture(GL_TEXTURE_2D,texture5);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);
  glVertex3d(-x,0,0);
  glTexCoord2d(1,0);
  glVertex3d(-x,0,z);
  glTexCoord2d(1,1);
  glVertex3d(x,0,z);
  glTexCoord2d(0,1);
  glVertex3d(x,0,0);
  glEnd();

  
  glBindTexture(GL_TEXTURE_2D,texture6);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);
  glVertex3d(-x,0,z);
  glTexCoord2d(1,0);
  glVertex3d(x,0,z);
  glTexCoord2d(1,1);
glVertex3d(x,y,z);
  glTexCoord2d(0,1);
 glVertex3d(-x,y,z);
  glEnd();
 
  
 
}