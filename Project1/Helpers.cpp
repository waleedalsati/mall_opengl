#include "Helpers.h"
#include "Point.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>

# define pi 3.141592653589793238462643383279502884


void Helpers::DrawShpere(Point position,int nx, int ny,int texture) {
	float alfa, beta;
    float x1, y1, z1, x2, y2, z2;
	glEnable(GL_TEXTURE_2D);
    alfa = (2*pi)/nx;
    beta = pi/ny;


	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glBindTexture(GL_TEXTURE_2D, texture);
    glPolygonMode(GL_FRONT, GL_LINE);

    for(int j=0; j<=ny/2; j++){
        glBegin(GL_TRIANGLE_STRIP);
        for(int i=0; i<=ny; i++){
            x1 = cos(alfa*i)*sin(beta*j);
            y1 = cos(beta*j);
            z1 = sin(alfa*i)*sin(beta*j);

            x2 = cos(alfa*i)*sin(beta*(j+1));
            y2 = cos(beta*(j+1));
            z2 = sin(alfa*i)*sin(beta*(j+1));

            glNormal3f(x1, y1, z1);
			glTexCoord2f(1,0);
            glVertex3f(x1, y1, z1);
            glNormal3f(x2, y2, z2);
			glTexCoord2f(1,1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

    }
}

void Helpers::DrawCube(Point dimentions,Point position,int texture) {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslatef(position.x, position.y, position.z);
	glBindTexture(GL_TEXTURE_2D, texture);

	//front
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		glTexCoord2f(1,0);
		glVertex3f(  dimentions.x, -dimentions.y, dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f(  dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x, -dimentions.y, dimentions.z );
    glEnd();



	//right
    glBegin(GL_QUADS);
		glNormal3f(1,0,0);
		glTexCoord2f(1,0);
		glVertex3f( dimentions.x, -dimentions.y, -dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( dimentions.x,  dimentions.y,  dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( dimentions.x, -dimentions.y,  dimentions.z );
    glEnd();


	//left
    glBegin(GL_QUADS);
		glNormal3f(-1,0,0);
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x,  dimentions.y, dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z );
    glEnd();


	//top
    glBegin(GL_QUADS);
		glNormal3f(0,1,0);
		glTexCoord2f(1,0);
		glVertex3f(  dimentions.x,  dimentions.y,  dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f(  dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f( -dimentions.x,  dimentions.y,  dimentions.z );
    glEnd();



	//bottom
    glBegin(GL_QUADS);
		glNormal3f(0,-1,0);
		glTexCoord2f(0,1);
		glVertex3f(  dimentions.x, -dimentions.y, -dimentions.z );
		glTexCoord2f(0,0);
		glVertex3f(  dimentions.x, -dimentions.y,  dimentions.z );
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x, -dimentions.y,  dimentions.z );
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z );
    glEnd();

	//back
    glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2f(1,0);
		glVertex3f( -dimentions.x, -dimentions.y, -dimentions.z);
		glTexCoord2f(1,1);
		glVertex3f( -dimentions.x,  dimentions.y, -dimentions.z);
		glTexCoord2f(0,1);
		glVertex3f(  dimentions.x,  dimentions.y, -dimentions.z);
		glTexCoord2f(0,0);
		glVertex3f(  dimentions.x, -dimentions.y, -dimentions.z);
    glEnd();

	glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
