#include <windows.h>		// Header File For Windows
#include <glut.h>
#include <texture.h>
#include "TrainCar.h"
#include "Point.h"
#include "Helpers.h"
#include <iostream>
#include <cmath> 
#define WIDTH 3
#define HEIGHT 2
#define DEPTH 6
//variables
int door;
float z_axis_for_car;//this is to help collision dedctor to locate object that are drawn for 0 ,0 
int counter=0;//this counter for objects that are add to the car it is for the work of the array
float collison_dedction_array[40][4];

//note that the x of the center is collison_dedction_array[i][0]  then the collision with x is between xcenter + width   xcenter -width
//width is collison_dedction_array[i][2]   

//note that the z of the center is collison_dedction_array[i][1]  then the collision with z is between zcenter + depth   zcenter -depth
//depth is collison_dedction_array[i][3]   

//TODO: <Moataz> functions body.

void TrainCar::setWindowsDedction(int index,bool value) {
	this->isWindowOpen[index] = value;
}

void TrainCar::setIsLightEnabled(bool value) {
	this->isLightEnabled = value;		
}
int TrainCar::windowsDedction(Point camera_position) {
	// this i<2 , wwe could make another counter for it if needed, but for now this is enough;
	for (int i = 0; i <2; i++) {
		if (this->windows_dedction_array[i][0] - this->windows_dedction_array[i][2]<camera_position.x&&
			camera_position.x<this->windows_dedction_array[i][0]+ this->windows_dedction_array[i][2]&&
			this->windows_dedction_array[i][1] - this->windows_dedction_array[i][3] + z_axis_for_car<camera_position.z&&
			camera_position.z<this->windows_dedction_array[i][1] + this->windows_dedction_array[i][3] + z_axis_for_car) {
			return i;  //0||1||2||3 (index of the window)
		}
	}
	return 4; // 4 mean falsy value
}

bool TrainCar::doorsDedction(Point camera_position) {
	if (-1<camera_position.x&&
		camera_position.x<1&&
		this->z_axis_for_car + 2<camera_position.z&&
		camera_position.z< this->z_axis_for_car + 6) {
		return true;
	}
	return false;
}

bool TrainCar::lightDedction(Point camera_position) {
	if (-1<camera_position.x &&
		camera_position.x<1 &&
		this->z_axis_for_car - 4 < camera_position.z &&
		camera_position.z< this->z_axis_for_car -1) {
		return true;
	}
	return false;
}

void TrainCar::resetWindow() {
	for (int i = 0; i <2; i++) {
		this->isCameraFaceTheWindow[i] = false;
	}
}

void TrainCar::init() {

	//## Walls
	//left wall
	this->addObject(Point(-1.5,0,this->z_axis_for_car),0.2,6);
	//right wall
	this->addObject(Point(1.5,0,this->z_axis_for_car),0.2,6);
	//front wall left side
	this->addObject(Point(-1,0,this->z_axis_for_car - 3),0.6,0.2);
	//front wall right side
	this->addObject(Point(1,0,this->z_axis_for_car - 3),0.6,0.2);
	//back wall left  side
	this->addObject(Point(-1,0,this->z_axis_for_car + 3),0.6,0.2);
	//back wall right side
	this->addObject(Point(1,0,this->z_axis_for_car + 3),0.6,0.2);

	//## Windows	
	this->addWindow(Point(-WIDTH/2,0,this->z_axis_for_car + DEPTH/12),0,1.2,DEPTH/5);
	this->addWindow(Point(WIDTH/2,0,this->z_axis_for_car + DEPTH/4),1,1.2,DEPTH/5);
	//.... if we have more

	//load textures
	this->DoorTexture = LoadTexture("Texture/Common/door.bmp");
	this->OutSideTexture = LoadTexture("Texture/Common/outside.bmp");
	this->WindowTexture = LoadTexture("Texture/Common/window.bmp",125);
	this->SitaraTexture = LoadTexture("Texture/Common/sitaraTexture.bmp");

}

bool TrainCar::collisonDedction(Point camera_position) {
	for (int i = 0; i <counter; i++) {
		if (this->collison_dedction_array[i][0] - this->collison_dedction_array[i][2]<camera_position.x&&
			camera_position.x<this->collison_dedction_array[i][0]+ this->collison_dedction_array[i][2]&&
			this->collison_dedction_array[i][1] - this->collison_dedction_array[i][3] + z_axis_for_car<camera_position.z&&
			camera_position.z<this->collison_dedction_array[i][1] + this->collison_dedction_array[i][3] + z_axis_for_car) {
			return true;
		}
	}
	return false;
}

void TrainCar::addObject(Point center,float width,float depth) {
	this->collison_dedction_array[counter][0] = center.x;
	this->collison_dedction_array[counter][1] = center.z;
	this->collison_dedction_array[counter][2] = width;
	this->collison_dedction_array[counter][3] = depth;
	this->counter++;
}

void TrainCar::addWindow(Point center,int index,float width,float depth) {
	this->windows_dedction_array[index][0] = center.x;
	this->windows_dedction_array[index][1] = center.z;
	this->windows_dedction_array[index][2] = width;
	this->windows_dedction_array[index][3] = depth;
}

void TrainCar::drawtraincarwith2door(int imginside, int floor,int roof) {
	double width = WIDTH;
	double height = HEIGHT;
	double depth = DEPTH;

	//drawing floor (2 layers) with texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, floor);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-width / 2, 0, depth / 2); //LP
	glTexCoord2d(1, 0);	glVertex3d(width / 2, 0, depth / 2); //RP
	glTexCoord2d(1, 1);	glVertex3d(width / 2, 0, -depth / 2);
	glTexCoord2d(0, 1);glVertex3d(-width / 2, 0, -depth / 2); //LP NEAR THE sCREEN
	glEnd();
	glDisable(GL_TEXTURE_2D);
	////////////////////texture for under train ///////////////////////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-width / 2, -0.05, depth / 2); //LP
	glTexCoord2d(1, 0);glVertex3d(width / 2, -0.05, depth / 2); //RP
	glTexCoord2d(1, 1);glVertex3d(width / 2, -0.05, -depth / 2);
	glTexCoord2d(0, 1);glVertex3d(-width / 2, -0.05, -depth / 2); //LP NEAR THE sCREEN
	glEnd();
	glDisable(GL_TEXTURE_2D);
	/////////////////////////////////////////


	glBegin(GL_QUADS);
	glVertex3d(-width / 2, 0, depth / 2); //LP
	glVertex3d(-width / 2, -0.05, depth / 2); //LP
	glVertex3d(-width / 2, -0.05, -depth / 2); //LP NEAR THE sCREEN
	glVertex3d(-width / 2, 0, -depth / 2); //LP NEAR THE sCREEN

	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(-width / 2, 0, depth / 2); //LP
	glVertex3d(-width / 2, -0.05, depth / 2); //LP
	glVertex3d(width / 2, -0.05, depth / 2); //LP
	glVertex3d(width / 2, 0, depth / 2); //LP

	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(width / 2, -0.05, depth / 2); //LP
	glVertex3d(width / 2, 0, depth / 2); //LP
	glVertex3d(width / 2, 0, -depth / 2); //LP
	glVertex3d(width / 2, -0.05, -depth / 2); //LP
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(width / 2, 0, -depth / 2); //LP
	glVertex3d(width / 2, -0.05, -depth / 2); //LP
	glVertex3d(-width / 2, -0.05, -depth / 2); //LP
	glVertex3d(-width / 2, 0, -depth / 2); //LP
	glEnd();



	//drawing left wall with texture (2 layers)

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, 0, depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 2, 0, depth / 6);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 2, height, depth / 6);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, (65 * height) / 100, depth / 6);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 2, (65 * height) / 100, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 2, height, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, depth / 6);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 2, 0, -depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 2, height, -depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, 0, depth / 6);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 2, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 2, (4 * height) / 10, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, (4 * height) / 10, depth / 6);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);	glVertex3d((-width / 2) - 0.05, 0, depth / 2);
	glTexCoord2d(1, 0);glVertex3d((-width / 2) - 0.05, 0, depth / 6);
	glTexCoord2d(1, 1);glVertex3d((-width / 2) - 0.05, height, depth / 6);
	glTexCoord2d(0, 1);glVertex3d((-width / 2) - 0.05, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d((-width / 2) - 0.05, (65 * height) / 100, depth / 6);
	glTexCoord2d(1, 0);glVertex3d((-width / 2) - 0.05, (65 * height) / 100, 0);
	glTexCoord2d(1, 1);glVertex3d((-width / 2) - 0.05, height, 0);
	glTexCoord2d(0, 1);glVertex3d((-width / 2) - 0.05, height, depth / 6);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d((-width / 2) - 0.05, 0, 0);
	glTexCoord2d(1, 0);glVertex3d((-width / 2) - 0.05, 0, -depth / 2);
	glTexCoord2d(1, 1);glVertex3d(-width / 2 - 0.05, height, -depth / 2);
	glTexCoord2d(0, 1);glVertex3d(-(width / 2) - 0.05, height, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d((-width / 2) - 0.05, 0, depth / 6);
	glTexCoord2d(1, 0);glVertex3d((-width / 2) - 0.05, 0, 0);
	glTexCoord2d(1, 1);glVertex3d((-width / 2) - 0.05, (4 * height) / 10, 0);
	glTexCoord2d(0, 1);glVertex3d((-width / 2) - 0.05, (4 * height) / 10, depth / 6);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	
	// left window
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER,-1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->WindowTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d((-width / 2) - 0.025,  (4 * height) / 10, 0);
	glTexCoord2d(1, 0);glVertex3d((-width / 2) - 0.025,  (4 * height) / 10, depth / 6);
	glTexCoord2d(1, 1);glVertex3d((-width / 2) - 0.025, (65 * height) / 100, depth / 6);
	glTexCoord2d(0, 1);glVertex3d((-width / 2) - 0.025,(65 * height) / 100, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glColor4b(1,1,1,1);

	// left Sitara
	if(this->isWindowOpen[0]) {
		if(this->sitaraHieght[0] < (65 * height) / 100) { //open sitara
			this->sitaraHieght[0] += 0.01;
		}
	} else {
		if(this->sitaraHieght[0] > (4*height)/10) { //close sitara
			this->sitaraHieght[0] += -0.01;
		}
	}
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->SitaraTexture);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glTexCoord2d(0, 0);glVertex3d((-width / 2), sitaraHieght[0], 0);
	glTexCoord2d(1, 0);glVertex3d((-width / 2), sitaraHieght[0], depth / 6);
	glTexCoord2d(1, 1);glVertex3d((-width / 2), (65 * height) / 100, depth / 6);
	glTexCoord2d(0, 1);glVertex3d((-width / 2), (65 * height) / 100, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	

	glBegin(GL_QUADS);
	glVertex3d(-width / 2, 0, depth / 2);
	glVertex3d((-width / 2) - 0.05, 0, depth / 2);
	glVertex3d((-width / 2) - 0.05, 0, -depth / 2);
	glVertex3d(-width / 2, 0, -depth / 2);

	glVertex3d(-width / 2, height, depth / 2);
	glVertex3d((-width / 2) - 0.05, height, depth / 2);
	glVertex3d((-width / 2) - 0.05, height, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2);

	glVertex3d(-width / 2, 0, depth / 2);
	glVertex3d((-width / 2) - 0.05, 0, depth / 2);
	glVertex3d((-width / 2) - 0.05, height, depth / 2);
	glVertex3d(-width / 2, height, depth / 2);

	glVertex3d(-width / 2, 0, -depth / 2);
	glVertex3d((-width / 2) - 0.05, 0, -depth / 2);
	glVertex3d((-width / 2) - 0.05, height, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2);

	glVertex3d(-width / 2, (4 * height) / 10, 0);
	glVertex3d(-width / 2, (4 * height) / 10, depth / 6);
	glVertex3d(-(width / 2) - 0.05, (4 * height) / 10, depth / 6);
	glVertex3d((-width / 2) - 0.05, (4 * height) / 10, 0);

	glVertex3d(-width / 2, (4 * height) / 10, 0);
	glVertex3d((-width / 2) - 0.05, (4 * height) / 10, 0);
	glVertex3d((-width / 2) - 0.05, (65 * height) / 100, 0);
	glVertex3d((-width / 2), (65 * height) / 100, 0);

	glVertex3d(-width / 2, (4 * height) / 10, depth / 6);
	glVertex3d((-width / 2) - 0.05, (4 * height) / 10, depth / 6);
	glVertex3d((-width / 2) - 0.05, (65 * height) / 100, depth / 6);
	glVertex3d((-width / 2), (65 * height) / 100, depth / 6);

	glVertex3d((-width / 2) - 0.05, (65 * height) / 100, depth / 6);
	glVertex3d((-width / 2), (65 * height) / 100, depth / 6);
	glVertex3d((-width / 2), (65 * height) / 100, 0);
	glVertex3d((-width / 2) - 0.05, (65 * height) / 100, 0);


	glEnd();



	//drawing right wall with texture (2 layers)

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 2, 0, depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, 0, depth / 3);
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, depth / 3);
	glTexCoord2d(0, 1);
	glVertex3d(width / 2, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 2, (65 * height) / 100, depth / 3);

	glTexCoord2d(1, 0);
	glVertex3d(width / 2, (65 * height) / 100, depth / 6);
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, depth / 6);
	glTexCoord2d(0, 1);
	glVertex3d(width / 2, height, depth / 3);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 2, 0, -depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, 0, depth / 6);
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, depth / 6);
	glTexCoord2d(0, 1);
	glVertex3d(width / 2, height, -depth / 2);

	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 2, 0, depth / 3); // cord 2 window 
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, 0, depth / 6); // cord 2 window
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, (4 * height) / 10, depth / 6); // cord 2 window
	glTexCoord2d(0, 1);
	glVertex3d(width / 2, (4 * height) / 10, depth / 3); // cord 2 window 

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 2 + 0.05, 0, depth / 2);
	glTexCoord2d(1, 0);glVertex3d(width / 2 + 0.05, 0, depth / 3);
	glTexCoord2d(1, 1);glVertex3d(width / 2 + 0.05, height, depth / 3);
	glTexCoord2d(0, 1);glVertex3d(width / 2 + 0.05, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 3);
	glTexCoord2d(1, 0);glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 6);
	glTexCoord2d(1, 1);glVertex3d(width / 2 + 0.05, height, depth / 6);
	glTexCoord2d(0, 1);glVertex3d(width / 2 + 0.05, height, depth / 3);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 2 + 0.05, 0, -depth / 2);
	glTexCoord2d(1, 0);glVertex3d(width / 2 + 0.05, 0, depth / 6);
	glTexCoord2d(1, 1);glVertex3d(width / 2 + 0.05, height, depth / 6);
	glTexCoord2d(0, 1);glVertex3d(width / 2 + 0.05, height, -depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 2 + 0.05, 0, depth / 3);
	glTexCoord2d(1, 0);glVertex3d(width / 2 + 0.05, 0, depth / 6);
	glTexCoord2d(1, 1);glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 6);
	glTexCoord2d(0, 1);glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 3);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//right window
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER,-1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->WindowTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d((width / 2) + 0.025, (4 * height) / 10, depth / 3);
	glTexCoord2d(1, 0);glVertex3d((width / 2) + 0.025, (4 * height) / 10, depth / 6);
	glTexCoord2d(1, 1);glVertex3d((width / 2) + 0.025, (65 * height) / 100, depth / 6);
	glTexCoord2d(0, 1);glVertex3d((width / 2) + 0.025, (65 * height) / 100, depth/3);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glColor4b(1,1,1,1);

	// right Sitara
	if(this->isWindowOpen[1]) {
		if(this->sitaraHieght[1] < (65 * height) / 100) { //open sitara
			this->sitaraHieght[1] += 0.01;
		}
	} else {
		if(this->sitaraHieght[1] > (4*height)/10) { //close sitara
			this->sitaraHieght[1] += -0.01;
		}
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->SitaraTexture);
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glTexCoord2d(0, 0);glVertex3d((width / 2), this->sitaraHieght[1], depth / 3);
	glTexCoord2d(1, 0);glVertex3d((width / 2), this->sitaraHieght[1], depth / 6);
	glTexCoord2d(1, 1);glVertex3d((width / 2), (65 * height) / 100, depth / 6);
	glTexCoord2d(0, 1);glVertex3d((width / 2), (65 * height) / 100, depth/3);
	glEnd();
	glDisable(GL_TEXTURE_2D);
		


	glBegin(GL_QUADS);
	glVertex3d(width / 2, (65 * height) / 100, depth / 3);
	glVertex3d(width / 2, (4 * height) / 10, depth / 3);
	glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 3);
	glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 3);

	glVertex3d(width / 2, (65 * height) / 100, depth / 6);
	glVertex3d(width / 2, (4 * height) / 10, depth / 6);
	glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 6);
	glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 6);

	glVertex3d(width / 2, (65 * height) / 100, depth / 3);
	glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 3);
	glVertex3d(width / 2 + 0.05, (65 * height) / 100, depth / 6);
	glVertex3d(width / 2, (65 * height) / 100, depth / 6);

	glVertex3d(width / 2, (4 * height) / 10, depth / 3);
	glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 3);
	glVertex3d(width / 2 + 0.05, (4 * height) / 10, depth / 6);
	glVertex3d(width / 2, (4 * height) / 10, depth / 6);

	glVertex3d(width / 2 + 0.05, 0, depth / 2);
	glVertex3d(width / 2, 0, depth / 2);
	glVertex3d(width / 2, 0, -depth / 2);
	glVertex3d(width / 2 + 0.05, 0, -depth / 2);

	glVertex3d(width / 2, height, depth / 2);
	glVertex3d(width / 2 + 0.05, height, depth / 2);
	glVertex3d(width / 2 + 0.05, 0, depth / 2);
	glVertex3d(width / 2, 0, depth / 2);

	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2 + 0.05, height, -depth / 2);
	glVertex3d(width / 2 + 0.05, 0, -depth / 2);
	glVertex3d(width / 2, 0, -depth / 2);

	glVertex3d(width / 2 + 0.05, height, depth / 2);
	glVertex3d(width / 2, height, depth / 2);
	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2 + 0.05, height, -depth / 2);
	glEnd();



	//drawing roof with texture (2 layers)
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, roof);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS); //roaf
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, height, depth / 2); //LP
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, height, depth / 2); //RP
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, -depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, -depth / 2); //LP NEAR THE SCREEN

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS); //roaf
	glTexCoord2d(0, 0);glVertex3d(-width / 2, height + 0.05, depth / 2);
	glTexCoord2d(1, 0);glVertex3d(width / 2, height + 0.05, depth / 2);
	glTexCoord2d(1, 1);glVertex3d(width / 2, height + 0.05, -depth / 2);
	glTexCoord2d(0, 1);glVertex3d(-width / 2, height + 0.05, -depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3d(-width / 2, height + 0.05, depth / 2);
	glVertex3d(-width / 2, height, depth / 2);
	glVertex3d(width / 2, height, depth / 2);
	glVertex3d(width / 2, height + 0.05, depth / 2);
	
	

	glVertex3d(width / 2, height + 0.05, depth / 2);
	glVertex3d(width / 2, height + 0.05, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2, height, depth / 2);

	glVertex3d(-width / 2, height + 0.05, depth / 2);
	glVertex3d(-width / 2, height + 0.05, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2);
	glVertex3d(-width / 2, height, depth / 2);

	glVertex3d(-width / 2, height + 0.05, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2, height + 0.05, -depth / 2);

	

	glEnd();


	// drawing front wall (with door)(2 layers)


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, 0, -depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 8, 0, -depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 8, height, -depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, -depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 8, (625 * height) / 1000, -depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 8, (625 * height) / 1000, -depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(width / 8, height, -depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 8, height, -depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 8, 0, -depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, 0, -depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, -depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(width / 8, height, -depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	if(this->isDoorOpen) {
		if(this->doorX > -0.8) { //close door
			this->doorX -= 0.01;
		}
	} else {
		if(this->doorX < 0) { //open door
			this->doorX += 0.01;
		}
	}


	glPushMatrix();
	glTranslated(doorX,0,0);
	glEnable(GL_TEXTURE_2D) ; 
	glBindTexture(GL_TEXTURE_2D,this->DoorTexture);  
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 8, 0, depth / 2); // cord of door
	glTexCoord2d(1, 0);
	glVertex3d(width / 8, 0, depth / 2); // cord of door
	glTexCoord2d(1, 1);
	glVertex3d(width / 8, (625 * height) / 1000, depth / 2); // cord of door
	glTexCoord2d(0, 1);
	glVertex3d(-width / 8, (625 * height) / 1000, depth / 2); // cord of door
	glEnd();
	glDisable(GL_TEXTURE_2D) ; 
	glPopMatrix();



	// light
	if(this->isLightEnabled) {
		glColor3ub(255, 0,0);
		Helpers::DrawCube(Point(0.025,0.025,0.01),Point(-width/8-0.065,height/3,-depth/2+0.05),0);
	}


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-width / 2, 0, -depth / 2 - 0.05);
	glTexCoord2d(1, 0);glVertex3d(-width / 8, 0, -depth / 2 - 0.05);
	glTexCoord2d(1, 1);glVertex3d(-width / 8, height, -depth / 2 - 0.05);
	glTexCoord2d(0, 1);glVertex3d(-width / 2, height, -depth / 2 - 0.05);
	glDisable(GL_TEXTURE_2D) ;
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 8, (625 * height) / 1000, -depth / 2 - 0.05);
	glTexCoord2d(1, 0);glVertex3d(-width / 8, (625 * height) / 1000, -depth / 2 - 0.05);
	glTexCoord2d(1, 1);glVertex3d(-width / 8, height, -depth / 2 - 0.05);
	glTexCoord2d(0, 1);glVertex3d(width / 8, height, -depth / 2 - 0.05);
	glDisable(GL_TEXTURE_2D) ;
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 8, 0, -depth / 2 - 0.05);
	glTexCoord2d(1, 0);glVertex3d(width / 2, 0, -depth / 2 - 0.05);
	glTexCoord2d(1, 1);glVertex3d(width / 2, height, -depth / 2 - 0.05);
	glTexCoord2d(0, 1);glVertex3d(width / 8, height, -depth / 2 - 0.05);
	glDisable(GL_TEXTURE_2D) ;
	glEnd();
	


	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3d(-width / 2, 0, -depth / 2 - 0.05);
	glVertex3d(-width / 2, 0, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2);
	glVertex3d(-width / 2, height, -depth / 2 - 0.05);

	glVertex3d(-width / 2, 0, -depth / 2 - 0.05);
	glVertex3d(-width / 2, 0, -depth / 2);
	glVertex3d(width / 2, 0, -depth / 2);
	glVertex3d(width / 2, 0, -depth / 2 - 0.05);

	glVertex3d(-width / 2, height, -depth / 2 - 0.05);
	glVertex3d(-width / 2, height, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2 - 0.05);

	glVertex3d(width / 2, 0, -depth / 2 - 0.05);
	glVertex3d(width / 2, 0, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2);
	glVertex3d(width / 2, height, -depth / 2 - 0.05);

	
	glVertex3d(-width / 8, (625 * height) / 1000, -depth / 2);
	glVertex3d(width / 8, (625 * height) / 1000, -depth / 2); // cord of door
	glVertex3d(width / 8, (625 * height) / 1000, -depth / 2 - 0.05); // cord of door
	glVertex3d(-width / 8, (625 * height) / 1000, -depth / 2 - 0.05);




	glEnd();

	//drawing back wall (with door) (2 layers)

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 2, 0, depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(-width / 8, 0, depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(-width / 8, height, depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 2, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-width / 8, (625 * height) / 1000, depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 8, (625 * height) / 1000, depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(width / 8, height, depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(-width / 8, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imginside);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(width / 8, 0, depth / 2);
	glTexCoord2d(1, 0);
	glVertex3d(width / 2, 0, depth / 2);
	glTexCoord2d(1, 1);
	glVertex3d(width / 2, height, depth / 2);
	glTexCoord2d(0, 1);
	glVertex3d(width / 8, height, depth / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-width / 2, 0, depth / 2 + 0.05);
	glTexCoord2d(1, 0);glVertex3d(-width / 8, 0, depth / 2 + 0.05);
	glTexCoord2d(1, 1);glVertex3d(-width / 8, height, depth / 2 + 0.05);
	glTexCoord2d(0, 1);glVertex3d(-width / 2, height, depth / 2 + 0.05);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 2, 0, depth / 2 + 0.05);
	glTexCoord2d(1, 0);glVertex3d(width / 8, 0, depth / 2 + 0.05);
	glTexCoord2d(1, 1);glVertex3d(width / 8, height, depth / 2 + 0.05);
	glTexCoord2d(0, 1);glVertex3d(width / 2, height, depth / 2 + 0.05);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->OutSideTexture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(width / 8, (625 * height) / 1000, depth / 2 + 0.05);
	glTexCoord2d(1, 0);glVertex3d(-width / 8, (625 * height) / 1000, depth / 2 + 0.05);
	glTexCoord2d(1, 1);glVertex3d(-width / 8, height, depth / 2 + 0.05);
	glTexCoord2d(0, 1);glVertex3d(width / 8, height, depth / 2 + 0.05);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3d(-width / 2, 0, depth / 2 + 0.05);
	glVertex3d(-width / 2, 0, depth / 2);
	glVertex3d(-width / 2, height, depth / 2);
	glVertex3d(-width / 2, height, depth / 2 + 0.05);

	glVertex3d(-width / 2, 0, depth / 2 + 0.05);
	glVertex3d(-width / 2, 0, depth / 2);
	glVertex3d(width / 2, 0, depth / 2);
	glVertex3d(width / 2, 0, depth / 2 + 0.05);

	glVertex3d(-width / 2, height, depth / 2 + 0.05);
	glVertex3d(-width / 2, height, depth / 2);
	glVertex3d(width / 2, height, depth / 2);
	glVertex3d(width / 2, height, depth / 2 + 0.05);

	glVertex3d(width / 2, 0, depth / 2 + 0.05);
	glVertex3d(width / 2, 0, depth / 2);
	glVertex3d(width / 2, height, depth / 2);
	glVertex3d(width / 2, height, depth / 2 + 0.05);


	glVertex3d(-width / 8, (625 * height) / 1000, depth / 2);
	glVertex3d(width / 8, (625 * height) / 1000, depth / 2);
	glVertex3d(width / 8, (625 * height) / 1000, depth / 2 + 0.05);
	glVertex3d(-width / 8, (625 * height) / 1000, depth / 2 + 0.05);

	
	glEnd();
}
