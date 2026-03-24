#include "Bedroom.h"
#include <cmath>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

#include <texture.h>
#include "Point.h"
#include "Helpers.h"
#include "TrainCar.h"

void Bedroom::buildBed(
		Point dimentions, Point position, Point color, int bedTexture,
		float heightOnfloor, float legLength,int legTexture,
		bool hasEadges=false,bool eadgesReversed=false,
		bool hasMattress=false,float mattressLength = 0,int mattressTexture=0, Point mattressColor=Point(1,1,1)
	) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

	//bed
	glColor3f(color.x, color.y, color.z);
	Helpers::DrawCube(dimentions,position,bedTexture);

	//legs
	Helpers::DrawCube(Point(legLength,heightOnfloor,legLength),Point(position.x-dimentions.x+legLength, position.y-dimentions.y-heightOnfloor,position.z+dimentions.z-legLength),legTexture);
	Helpers::DrawCube(Point(legLength,heightOnfloor,legLength),Point(position.x-dimentions.x+legLength, position.y-dimentions.y-heightOnfloor,position.z-dimentions.z+legLength),legTexture);
	Helpers::DrawCube(Point(legLength,heightOnfloor,legLength),Point( position.x+dimentions.x-legLength, position.y-dimentions.y-heightOnfloor,position.z+dimentions.z-legLength),legTexture);
	Helpers::DrawCube(Point(legLength,heightOnfloor,legLength),Point( position.x+dimentions.x-legLength, position.y-dimentions.y-heightOnfloor,position.z-dimentions.z+legLength),legTexture);
	// front and back
	if(hasEadges) {
		glColor3f(color.x, color.y, color.z);
		if(eadgesReversed) {
			Helpers::DrawCube(Point(dimentions.x,dimentions.y , legLength),  Point(position.x,position.y + 2*dimentions.y,position.z - dimentions.z + legLength),bedTexture);
			Helpers::DrawCube(Point(dimentions.x,2*dimentions.y , legLength),  Point(position.x,position.y + 3*dimentions.y,position.z + dimentions.z - legLength),bedTexture);

		} else {
			Helpers::DrawCube(Point(dimentions.x,dimentions.y , legLength),  Point(position.x,position.y + 2*dimentions.y,position.z + dimentions.z - legLength),bedTexture);
			Helpers::DrawCube(Point(dimentions.x,2*dimentions.y , legLength),  Point(position.x,position.y + 3*dimentions.y,position.z - dimentions.z + legLength),bedTexture);
		}


	}

	// farsha
	if(hasMattress){
		glColor3f(mattressColor.x,mattressColor.y,mattressColor.z);
		Helpers::DrawCube(Point(dimentions.x,mattressLength,dimentions.z-2*legLength),  Point(position.x,position.y+dimentions.y+mattressLength,position.z),mattressTexture);
	}

    glPopMatrix();
}


void Bedroom::buildLocker(Point dimentions, Point position, Point color,float heightOnfloor, float legLength,int legTextsure, int shelfTexture) {
	Bedroom::buildBed(dimentions,position,color,shelfTexture,heightOnfloor,legLength,legTextsure,false,false,false,0,0,Point(0,0,0));
	Bedroom::buildBed(dimentions,Point(position.x,position.y + 2*dimentions.y + 2*heightOnfloor,position.z),color,shelfTexture,heightOnfloor,legLength,legTextsure,false,false,false,0,0,Point(0,0,0));
	Bedroom::buildBed(dimentions,Point(position.x,position.y + 4*dimentions.y + 4*heightOnfloor,position.z),color,shelfTexture,heightOnfloor,legLength,legTextsure,false,false,false,0,0,Point(0,0,0));
	Bedroom::buildBed(dimentions,Point(position.x,position.y + 6*dimentions.y + 6*heightOnfloor,position.z),color,shelfTexture,heightOnfloor,legLength,legTextsure,false,false,false,0,0,Point(0,0,0));
}

void Bedroom::initRoom() {
	this->init();

	this->addObject(Point(-1,0,1.8),0.5,1.2);
	this->addObject(Point(-1,0,-1.8),0.5,1.2);
	this->addObject(Point(-1.3,0,0.1),0.2,0.3);
	this->addObject(Point(1,0,1.8),0.5,1.2);
	this->addObject(Point(1,0,-1.8),0.5,1.2);
	this->addObject(Point(1.3,0,0.1),0.2,0.3);

	if(this->isGirls) {
		this->BedroomWallPaper = LoadTexture("Texture/Bedroom/BedroomGirlsWallPaperTextre.bmp");
		this->BedroomFloor = LoadTexture("Texture/Bedroom/BedroomGirlsFloorTexture.bmp");
		this->BedroomRoof = LoadTexture("Texture/Bedroom/BedroomGirlsWallPaperTextre.bmp");
	} else {
		this->BedroomWallPaper = LoadTexture("Texture/Bedroom/BedroomBoysWallPaperTextrure.bmp");
		this->BedroomFloor = LoadTexture("Texture/Bedroom/BedroomBoysFloorTexture.bmp");
		this->BedroomRoof = LoadTexture("Texture/Bedroom/BedroomBoysWallPaperTextrure.bmp");
	}

	this->BedroomIron = LoadTexture("Texture/Bedroom/BedroomIronTexture.bmp");
	this->BedroomQutun = LoadTexture("Texture/Bedroom/BedroomQutunTexture.bmp");
	this->BedroomWood = LoadTexture("Texture/Bedroom/BedroomWoodTexture.bmp");
}


GLfloat lightValueR,lightValueG,lightValueB;

void Bedroom::buildRoom(){
	glPushMatrix();
	glTranslated(0,0,this->z_axis_for_car);
	int wood = this->BedroomWood;
	int iron = this->BedroomIron;
	int qutun = this->BedroomQutun;





	if(this->isLightEnabled) {
		lightValueR = 1.0f;
		lightValueG = 1.0f;
		lightValueB = 1.0f;
	} else {
		lightValueR = 0.1f;
		lightValueG = 0.1f;
		lightValueB = 0.5f;
	}

	GLfloat lightColor0[] = {lightValueR, lightValueG, lightValueB, 0.0f};
	GLfloat lightPos0[] = {0.0f, 4.0f, this->z_axis_for_car, 1.0f};

	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightColor0);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos0);


	//left
	//single bed
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	//glNormal3f(-1,0.28,1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(-1,0.28,1.8),Point(1,1,1),wood,0.1,0.03,wood,true,true,true,0.05,qutun);

	//engaged bed
	//glNormal3f(-1,0.28,-1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(-1,0.28,-1.8),Point(1,1,1),wood,0.1,0.03,wood,false,false,true,0.05,qutun);
	//glNormal3f(-1,0.28,-1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(-1,0.78,-1.8),Point(1,1,1),wood,0.2,0.03,wood,true,false,true,0.05,qutun);
	//locker
	//glNormal3f(-1.3,0.12,0.1);
	Bedroom::buildLocker(Point(0.2,0.03,0.3),Point(-1.3,0.12,0.1),Point(1,1,1),0.05,0.01,iron,wood);

	//right
	//single bed
	//glNormal3f(1,0.28,1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(1,0.28,1.8),Point(1,1,1),wood,0.1,0.03,wood,true,true,true,0.05,qutun);
	//engaged bed
	//glNormal3f(1,0.28,-1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(1,0.28,-1.8),Point(1,1,1),wood,0.1,0.03,wood,false,false,true,0.05,qutun);
	//glNormal3f(1,0.28,-1.8);
	Bedroom::buildBed(Point(0.5,0.09,1.2),Point(1,0.78,-1.8),Point(1,1,1),wood,0.2,0.03,wood,true,false,true,0.05,qutun);
	//locker
	//glNormal3f(1.3,0.12,0.1);
	Bedroom::buildLocker(Point(0.2,0.03,0.3),Point(1.3,0.12,0.1),Point(1,1,1),0.05,0.01,iron,wood);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_NORMALIZE);
	this->drawtraincarwith2door(this->BedroomWallPaper,this->BedroomFloor,this->BedroomRoof);
	glPopMatrix();

}