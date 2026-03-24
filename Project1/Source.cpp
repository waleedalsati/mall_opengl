

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <glut.h>
#include <cmath>
#include <iostream>
#include <ctime>
#include <texture.h>
#include "camera.h"
#include "Point.h"
#include "PrimitiveDrawer.h"
#include "houses.h"
#include "areas.h"
#include "3DTexture.h"
#include "Model_3DS.h"
#include "sky.h"
#define PI 3.14159263
//Camera mycamera();
Model_3DS *tree;
Model_3DS *chair;

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(30.0f, (GLfloat)width / (GLfloat)height, 1.1f, 50000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


Camera MyCamera;
PrimitiveDrawer r = PrimitiveDrawer();


double v=-25;
float lightPos[] = {1,8000,8,1};
float lightpos2[]= {-10000000,1000000,-1000000,1};
float lightAmb[] = {0.6,0.6,0.6,1};
float lightDiff[] ={0.6,0.6,0.6,1};
float lightSpec[] ={-0.2,-0.2,-0.2,1};

float MatAmb[] = {1,1,1,1};
float MatDiff[] = {0.6,0.6,0.6,1.0};
float MatSpec[] = {0,0,0,1};
float MatShn[] = {128};
int skback,skfront,skleft ,house10,house2,block1,block2,area2,a1,a2,a3,a4,a6,kk10,q,kk22,kk1,kk2,img1,img,p,pp,ppp,p11111,strip,waellite;
int grasss,qpp,qp,herp,str,front1,photo1,sol,area1 , yello ,yello1,book1,area,hour,book,photo6,photo3,so1,mo,img2,photo4,book10,photo5,a,i1,n1,WAL,you,fo,ka,gre,k0,wa;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GLuint floorshop3Texture,wallshop3Texture,roofshop3Texture,doorshop3Texture, refrigeratorbodyTexture1,refrigeratordoorTexture1,refrigeratorbodyTexture2,refrigeratordoorTexture2,
washmachinebodyTexture1, washmachinedoorTexture1,washmachinebodyTexture2,washmachinedoorTexture2,ovenbodyTexture1, ovendoorTexture1,ovenbodyTexture2, ovendoorTexture2,
	microwavedoorTexture1,microwavebodyTexture1,microwavedoorTexture2,microwavebodyTexture2,microwavedoorTexture3,microwavebodyTexture3,microwavebodyTexture4,microwavedoorTexture4,
clockfaceTexture1,clockfaceTexture2,clockfaceTexture3,woodTexture1,woodTexture2,woodTexture3,woodTexture7,waterkoelerTexture1,waterkoelerTexture2,casherscreenTexture1,casherscreenTexture2,graytexture,frontshop3Texture;

const float M_PI = 3.14;
float doorshop3Angle = 0.0f;    
bool doorshop3Opening = false;  
bool doorshop3Closing = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GLTexture leg,leather,nail,chair_leg,chair_leather,chair_leg2;

float mainDoor = 0.0;


void Key(bool* keys, float speed)
{
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * speed);
	if (keys[VK_UP])
		MyCamera.MoveForward(1 * speed);
	if (keys[VK_DOWN])
		MyCamera.MoveForward(-1 * speed);
	if (keys[VK_RIGHT])
		MyCamera.MoveRight(1 * speed);
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-1 * speed);
	if (keys['O'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-1 * speed);

	
}
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	 
	tree=new Model_3DS();

	tree->Load("M_TREE5.3DS");

	leg.LoadBMP("grasss.bmp");
	leather.LoadBMP("grasss.bmp");
	nail.LoadBMP("grasss.bmp");
	
	chair=new Model_3DS();
	
	chair->Load("chair2.3DS");
	
	chair_leg.LoadBMP("wood_70D.bmp");
	chair_leather.LoadBMP("wood_70D.bmp");
	chair_leg2.LoadBMP("wood_70D.bmp");
	


	qpp=LoadTexture("qpp.bmp",255);
	qp=LoadTexture("qp.bmp",255);
	//tree=new Model_3DS();
	herp=LoadTexture("herb.bmp",255);
	q=LoadTexture("q.bmp",255);
	img1=LoadTexture("img14.bmp",255);
	img=LoadTexture("img10.bmp",255);
	area1=LoadTexture("area1.bmp",255);
	sol=LoadTexture("WAEEEL.bmp",255);
	str=LoadTexture("strip.bmp",255);
	front1=LoadTexture("front1.bmp",255);
	p11111=LoadTexture("mosala.bmp",255);
	ppp=LoadTexture("up.bmp",255);
    pp=LoadTexture("rock.bmp",255);
    p=LoadTexture("rock.bmp",255);
	yello=LoadTexture("Concrete.bmp",255);
	yello1=LoadTexture("yello1.bmp",255);
	photo1=LoadTexture("photo11",255);
	area2=LoadTexture("area2.bmp",255);
	grasss=LoadTexture("grasss.bmp",255);
	kk1=LoadTexture("kk1.bmp",255);
	kk2=LoadTexture("kk2.bmp",255);
	kk22=LoadTexture("kk22.bmp",255);
    //mosala1=LoadTexture("bb8",255);
	kk10=LoadTexture("kk10.bmp",255);
    a1=LoadTexture("a1.bmp",255);
	a2=LoadTexture("a2.bmp",255);
	a3=LoadTexture("a3.bmp",255);
	a6=LoadTexture("a6.bmp",255);
	//block1=LoadTexture("block1.bmp",255);
	block2=LoadTexture("block2.bmp",255);
	house10=LoadTexture("build111.bmp",255);
	house2=LoadTexture("house2.bmp",255);
		waellite=LoadTexture("build1.bmp",255);


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         photo4=LoadTexture("photo4.bmp",255);
		 img2=LoadTexture("WoodTexture.bmp",255);
         mo=LoadTexture("istockphoto-1183106359-1024x1024.bmp",255);
		 so1=LoadTexture("istockphoto-624848888-1024x1024.bmp",255);
         photo3=LoadTexture("Screenshot 2025-01-17 110755.bmp",255);
	     photo6=LoadTexture("Screenshot 2025-01-16 222026.bmp",255);
         photo5=LoadTexture("Screenshot 2025-01-17 120314.bmp",255);
         book1=LoadTexture("istockphoto-2161233911-612x612.bmp",255);
	//area=LoadTexture("wood_70D.bmp",255);
	//hour=LoadTexture("pexels-kowalievska-1174776.bmp",255);
	     book10=LoadTexture("img.bmp",255);
a=LoadTexture("un.bmp",255);//a,i1,n1,WAL,you,fo,ka,gre,k0

i1=LoadTexture("i.bmp",255);
  n1=LoadTexture("des.bmp",255);

WAL=LoadTexture("ada.bmp",255);

you=LoadTexture("WoodTexture.bmp",255);
  fo=LoadTexture("jkm.bmp",255);
  ka=LoadTexture("pexels-pixabay-358042 (1).bmp",255);

a4=LoadTexture("a4.bmp",255);
	wa=LoadTexture("00.bmp",255);
	
gre=LoadTexture("herb.bmp",255);

k0=LoadTexture("p.bmp",255);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ahmed shop 3 textures 

	floorshop3Texture = LoadTexture("floor-shop.bmp", 255);
	wallshop3Texture = LoadTexture("white-wall.bmp", 255);
	roofshop3Texture = LoadTexture("roof-with-light.bmp", 255);
	doorshop3Texture  = LoadTexture("shopDoor-2.bmp", 255);
	frontshop3Texture = LoadTexture("shopfront7.bmp", 255);
	refrigeratorbodyTexture1 = LoadTexture("gray.bmp", 255);
	refrigeratordoorTexture1 = LoadTexture("refrigerator.bmp", 255);
	refrigeratorbodyTexture2 = LoadTexture("gray.bmp", 255);
	refrigeratordoorTexture2 = LoadTexture("refrigerator2.bmp", 255);
	washmachinebodyTexture1 = LoadTexture("gray.bmp", 255);
	washmachinedoorTexture1 = LoadTexture("washmachinedoor1.bmp", 255);
	washmachinebodyTexture2 = LoadTexture("gray.bmp", 255);
	washmachinedoorTexture2= LoadTexture("washmachinedoor2.bmp", 255);
	ovenbodyTexture1 = LoadTexture("gray.bmp", 255);
	ovendoorTexture1 = LoadTexture("oven1.bmp", 255);
	ovenbodyTexture2 = LoadTexture("gray.bmp", 255);
	ovendoorTexture2= LoadTexture("oven1.bmp", 255);
	microwavebodyTexture1 = LoadTexture("gray.bmp", 255);
	microwavedoorTexture1 = LoadTexture("microwave1.bmp", 255);
	microwavebodyTexture2 = LoadTexture("gray.bmp", 255);
	microwavedoorTexture2= LoadTexture("microwave2.bmp", 255);
	microwavebodyTexture3 = LoadTexture("gray.bmp", 255);
	microwavedoorTexture3= LoadTexture("microwave3.bmp", 255);
	microwavebodyTexture4 = LoadTexture("gray.bmp", 255);
	microwavedoorTexture4= LoadTexture("microwave3.bmp", 255);
	clockfaceTexture1 = LoadTexture("clocktexture1.bmp", 255);
	clockfaceTexture2 = LoadTexture("clocktexture2.bmp", 255);
	clockfaceTexture3 = LoadTexture("clocktexture3.bmp", 255);
    woodTexture1  = LoadTexture("wood1.bmp", 255);
	woodTexture2  = LoadTexture("wood2.bmp", 255);
	woodTexture3 = LoadTexture("wood3.bmp", 255);
	woodTexture7  = LoadTexture("wood_70D.bmp", 255);
    waterkoelerTexture1 = LoadTexture("WaterKoeler.bmp", 255);
	waterkoelerTexture2 = LoadTexture("WaterKoeler.bmp", 255);
    graytexture = LoadTexture("gray.bmp", 255);

	// ahmed shop 3 textures 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

book1=LoadTexture("istockphoto-2161233911-612x612.bmp",255);//,book1,area,hour,book
  area=LoadTexture("wood_70D.bmp",255);
  hour=LoadTexture("pexels-kowalievska-1174776.bmp",255);
  book=LoadTexture("img.bmp",255);




	skback=LoadTexture("skback.bmp",255);
    skfront=LoadTexture("skfront.bmp",255);
	skleft=LoadTexture("skleft.bmp",255);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.5);
	glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	// Texture
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	
	// lighting 
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lightDiff);
	glLightfv(GL_LIGHT1,GL_SPECULAR,lightSpec);
	glLightfv(GL_LIGHT1,GL_AMBIENT,lightAmb);

	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDiff);
	glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
	glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);


		MyCamera = Camera();
	MyCamera.Position.x = 10;
	MyCamera.Position.y = 2;
	MyCamera.Position.z = 100;



    // glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_DEPTH_TEST);
	return TRUE;										// Initialization Went OK
}
 
GLfloat x=0;
GLfloat y=0;
//GLfloat z=-100;
GLfloat i,m,k=0;
GLfloat j=0.0f;
GLfloat n=-20;
 
void skybox(int skybox11,int skybox2,int skybox3,int sea,int bldsqf3,int skybox1,int skysnow,int snow,int rsef){
	glPushMatrix();
	//glRotated(180,0,1,0);
	//glTranslated(0,0,1420);
		glBindTexture(GL_TEXTURE_2D, skybox11);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(-75,-10,0);
	glTexCoord2d(0,0);glVertex3d(75,-10,0);
	glTexCoord2d(0.5,1);glVertex3d(75,100,0);
	glTexCoord2d(1.5,1);glVertex3d(-75,100,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox11);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,0,0);
	glTexCoord2d(1, 0);glVertex3d(-75,0,-220);
	glTexCoord2d(1.55,1);glVertex3d(-75,200,-220);
	glTexCoord2d(0.5,1);glVertex3d(-75,200,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,0,-220);
	glTexCoord2d(1, 0);glVertex3d(-75,0,-420);
	glTexCoord2d(1,1);glVertex3d(-75,100,-420);
	glTexCoord2d(0,1);glVertex3d(-75,100,-220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,0,-420);
	glTexCoord2d(1, 0);glVertex3d(-75,0,-620);
	glTexCoord2d(1,1);glVertex3d(-75,100,-620);
	glTexCoord2d(0,1);glVertex3d(-75,100,-420);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,0,-620);
	glTexCoord2d(1, 0);glVertex3d(-75,0,-820);
	glTexCoord2d(1,1);glVertex3d(-75,100,-820);
	glTexCoord2d(0,1);glVertex3d(-75,100,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);glVertex3d(-75,-50,-520);
	glTexCoord2d(1, 1);glVertex3d(-75,-50,-620);
	glTexCoord2d(1,0);glVertex3d(-75,0,-620);
	glTexCoord2d(0,0);glVertex3d(-75,0,-520);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);glVertex3d(-75,-50,-620);
	glTexCoord2d(1, 1);glVertex3d(-75,-50,-820);
	glTexCoord2d(1,0);glVertex3d(-75,0,-820);
	glTexCoord2d(0,0);glVertex3d(-75,0,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);glVertex3d(75,-50,-520);
	glTexCoord2d(1, 1);glVertex3d(75,-50,-620);
	glTexCoord2d(1,0);glVertex3d(75,0,-620);
	glTexCoord2d(0,0);glVertex3d(75,0,-520);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);glVertex3d(75,-50,-620);
	glTexCoord2d(1, 1);glVertex3d(75,-50,-820);
	glTexCoord2d(1,0);glVertex3d(75,0,-820);
	glTexCoord2d(0,0);glVertex3d(75,0,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, sea);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-520);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-520);
	glTexCoord2d(2.8,1);glVertex3d(75,-10,-620);
	glTexCoord2d(1.8,1);glVertex3d(-75,-10,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, sea);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-520);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-520);
	glTexCoord2d(2.8,1);glVertex3d(75,0,-520);
	glTexCoord2d(1.8,1);glVertex3d(-75,0,-520);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, sea);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-620);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-620);
	glTexCoord2d(2.8,1);glVertex3d(75,-10,-820);
	glTexCoord2d(1.8,1);glVertex3d(-75,-10,-820);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox11);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(75,0,0);
	glTexCoord2d(1, 0);glVertex3d(75,0,-220);
	glTexCoord2d(1.55,1);glVertex3d(75,200,-220);
	glTexCoord2d(0.55,1);glVertex3d(75,200,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(75,0,-220);
	glTexCoord2d(1, 0);glVertex3d(75,0,-420);
	glTexCoord2d(1,1);glVertex3d(75,100,-420);
	glTexCoord2d(0,1);glVertex3d(75,100,-220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(75,0,-420);
	glTexCoord2d(1, 0);glVertex3d(75,0,-520);
	glTexCoord2d(1,1);glVertex3d(75,100,-520);
	glTexCoord2d(0,1);glVertex3d(75,100,-420);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(75,0,-520);
	glTexCoord2d(1, 0);glVertex3d(75,0,-620);
	glTexCoord2d(1,1);glVertex3d(75,100,-620);
	glTexCoord2d(0,1);glVertex3d(75,100,-520);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(75,0,-620);
	glTexCoord2d(1, 0);glVertex3d(75,0,-820);
	glTexCoord2d(1,1);glVertex3d(75,100,-820);
	glTexCoord2d(0,1);glVertex3d(75,100,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,0);
	glTexCoord2d(1, 0);glVertex3d(75,100,0);
	glTexCoord2d(2.8,1);glVertex3d(75,100,-220);
	glTexCoord2d(1.8,1);glVertex3d(-75,100,-220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-220);
	glTexCoord2d(1, 0);glVertex3d(75,100,-220);
	glTexCoord2d(2.8,1);glVertex3d(75,100,-420);
	glTexCoord2d(1.8,1);glVertex3d(-75,100,-420);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-420);
	glTexCoord2d(1, 0);glVertex3d(75,100,-420);
	glTexCoord2d(2.8,1);glVertex3d(75,100,-620);
	glTexCoord2d(1.8,1);glVertex3d(-75,100,-620);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skybox1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-620);
	glTexCoord2d(1, 0);glVertex3d(75,100,-620);
	glTexCoord2d(2.8,1);glVertex3d(75,100,-820);
	glTexCoord2d(1.8,1);glVertex3d(-75,100,-820);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, rsef);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);	glVertex3d(-75,0,0);
	glTexCoord2d(1, 0);glVertex3d(75,0,0);
	glTexCoord2d(2.8,1);glVertex3d(75,0,-220);
	glTexCoord2d(1.8,1);glVertex3d(-75,0,-220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, rsef);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,0,-220);
	glTexCoord2d(1, 0);glVertex3d(75,0,-220);
	glTexCoord2d(2.8,1);glVertex3d(75,0,-520);
	glTexCoord2d(1.8,1);glVertex3d(-75,0,-520);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(-75,-10,-820);
	glTexCoord2d(0,0);glVertex3d(-75,-10,-1020);
	glTexCoord2d(0,1);glVertex3d(-75,100,-1020);
	glTexCoord2d(1,1);glVertex3d(-75,100,-820);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(75,-10,-820);
	glTexCoord2d(0,0);glVertex3d(75,-10,-1020);
	glTexCoord2d(0,1);glVertex3d(75,100,-1020);
	glTexCoord2d(1,1);glVertex3d(75,100,-820);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-820);
	glTexCoord2d(1, 0);glVertex3d(75,100,-820);
	glTexCoord2d(2.8,1);glVertex3d(75,100,-1020);
	glTexCoord2d(1.8,1);glVertex3d(-75,100,-1020);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(-75,-10,-1020);
	glTexCoord2d(0,0);glVertex3d(-75,-10,-1220);
	glTexCoord2d(0.5,1);glVertex3d(-75,100,-1220);
	glTexCoord2d(1.5,1);glVertex3d(-75,100,-1020);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(75,-10,-1020);
	glTexCoord2d(0,0);glVertex3d(75,-10,-1220);
	glTexCoord2d(0.5,1);glVertex3d(75,100,-1220);
	glTexCoord2d(1.5,1);glVertex3d(75,100,-1020);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-1020);
	glTexCoord2d(1, 0);glVertex3d(75,100,-1020);
	glTexCoord2d(1,1);glVertex3d(75,100,-1220);
	glTexCoord2d(0,1);glVertex3d(-75,100,-1220);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-1020);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-1020);
	glTexCoord2d(1,1);glVertex3d(75,-10,-1220);
	glTexCoord2d(0,1);glVertex3d(-75,-10,-1220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(-75,-10,-1220);
	glTexCoord2d(0,0);glVertex3d(-75,-10,-1420);
	glTexCoord2d(0.5,1);glVertex3d(-75,100,-1420);
	glTexCoord2d(1.5,1);glVertex3d(-75,100,-1220);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(75,-10,-1220);
	glTexCoord2d(0,0);glVertex3d(75,-10,-1420);
	glTexCoord2d(0.5,1);glVertex3d(75,100,-1420);
	glTexCoord2d(1.5,1);glVertex3d(75,100,-1220);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, snow);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);glVertex3d(-75,-10,-1420);
	glTexCoord2d(0,0);glVertex3d(75,-10,-1420);
	glTexCoord2d(0.5,1);glVertex3d(75,100,-1420);
	glTexCoord2d(1.5,1);glVertex3d(-75,100,-1420);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,100,-1220);
	glTexCoord2d(1, 0);glVertex3d(75,100,-1220);
	glTexCoord2d(1,1);glVertex3d(75,100,-1420);
	glTexCoord2d(0,1);glVertex3d(-75,100,-1420);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-1220);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-1220);
	glTexCoord2d(1,1);glVertex3d(75,-10,-1420);
	glTexCoord2d(0,1);glVertex3d(-75,-10,-1420);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, skysnow);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(-75,-10,-820);
	glTexCoord2d(1, 0);glVertex3d(75,-10,-820);
	glTexCoord2d(2.8,1);glVertex3d(75,-10,-1020);
	glTexCoord2d(1.8,1);glVertex3d(-75,-10,-1020);
	glEnd();
	glPopMatrix();
}
void BuildBlock(double x,double y, double z ,int back ,int front){

	glBindTexture(GL_TEXTURE_2D,back);
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

	glBindTexture(GL_TEXTURE_2D,front);
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

   glBindTexture(GL_TEXTURE_2D,front);
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
  
 
 
   glBindTexture(GL_TEXTURE_2D,front);
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
 
 
  glBindTexture(GL_TEXTURE_2D,front);
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

  
  glBindTexture(GL_TEXTURE_2D,front);
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
 
  
  glEnd();

}
void BuildBlockbyrepeatexture(double x, double y, double z, int back, int front,double repeatFactor,double repeatfactort) {
     

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-x, 0, 0);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(x, 0, 0);
    glTexCoord2d(repeatFactor, repeatfactort);
    glVertex3d(x, y, 0);
    glTexCoord2d(0, repeatfactort);
    glVertex3d(-x, y, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-x, 0, 0);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(-x, 0, z);
    glTexCoord2d(repeatFactor, 1);
    glVertex3d(-x, y, z);
    glTexCoord2d(0, 1);
    glVertex3d(-x, y, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, back);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-x, y, 0);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(x, y, 0);
    glTexCoord2d(repeatFactor, 1);
    glVertex3d(x, y, z);
    glTexCoord2d(0, 1);
    glVertex3d(-x, y, z);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(x, 0, 0);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(x, 0, z);
    glTexCoord2d(repeatFactor, 1);
    glVertex3d(x, y, z);
    glTexCoord2d(0, 1);
    glVertex3d(x, y, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-x, 0, 0);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(-x, 0, z);
    glTexCoord2d(repeatFactor, 1);
    glVertex3d(x, 0, z);
    glTexCoord2d(0, 1);
    glVertex3d(x, 0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(-x, 0, z);
    glTexCoord2d(repeatFactor, 0);
    glVertex3d(x, 0, z);
    glTexCoord2d(repeatFactor, 1);
    glVertex3d(x, y, z);
    glTexCoord2d(0, 1);
    glVertex3d(-x, y, z);
    glEnd();
}
 double ii = 30 , jj = 15,zz = 100, nn=0 ,mm=0,spd=0.01;
void key()
{
	if(keys['0']){
    glDisable(GL_LIGHTING);
    }
	if (keys['1'])
	{
		 glEnable(GL_LIGHTING);
	}
  if(keys['5']){
    glLightfv(GL_LIGHT1 , GL_POSITION , lightpos2);
  }

}
void drawtree(Point p){
	glPushMatrix();
	tree->pos.x=p.x;
	tree->pos.y=p.y;
	tree->pos.z=p.z;
	tree->rot.y=80;
	tree->scale=2.3;
	tree->Materials[0].tex=leather;
	tree->Materials[1].tex=leather;
	tree->Materials[2].tex=leather;
	tree->Materials[3].tex=leather;
	tree->Materials[4].tex=leather;
	tree->Materials[5].tex=leather;

	tree->Draw();
	glPopMatrix();	
}
void drawchair(Point p){
	glPushMatrix();
	chair->pos.x=p.x;
	chair->pos.y=p.y+6;
	chair->pos.z=p.z;
	chair->rot.y=180;
	chair->scale=6.5;
	chair->Materials[0].tex=chair_leather;
	chair->Materials[1].tex=chair_leg;
	chair->Materials[2].tex=chair_leg2;
	chair->Draw();
	glPopMatrix();	
}
void Stair(int steps, double stepWidth, double stepHeight, double stepDepth,GLuint textureBottom, GLuint textureFront,double repeatFactor) {
  glPushMatrix();
    for (int i = 0; i < steps; ++i)
	{
		BuildBlockbyrepeatexture(stepWidth, stepHeight, stepDepth,textureBottom,textureFront,repeatFactor,1);
        glTranslated(0, stepHeight, stepDepth);  
    }
    glPopMatrix();
}
void drawgarden(int x, int z,int xarea,int zarea){

	glTranslated(x,0,z);
	 
   glPushMatrix();
   //glTranslated(20,0,0);
   areas::drawarea(xarea,zarea,grasss,10,10);
	glPopMatrix();
		    drawchair(Point(10,2,-100));
	    drawchair(Point(10,2,-60));
        drawchair(Point(10,2,-15));

		drawtree(Point  (0,0,-140) );
		//drawtree(Point  (0,0,-120) );
		drawtree(Point  (0,0,-100) );
		//drawtree(Point  (0,0,-80) );
		drawtree(Point  (0,0,-60) );
		//drawtree(Point  (0,0,-40) );
		drawtree(Point  (0,0,-20) );
		//drawtree(Point  (0,0,0) );
		drawtree(Point  (0,0,20) );
		//drawtree(Point  (0,0,40) );
		drawtree(Point  (0,0,60) );
		//drawtree(Point  (0,0,80) );
		drawtree(Point  (0,0,100) );
		//drawtree(Point  (0,0,120) );
		drawtree(Point  (0,0,140) );
		

		

		//drawtree(Point  (50,0,-140) );
		//drawtree(Point  (50,0,-120) );
		//drawtree(Point  (50,0,-100) );
		//drawtree(Point  (50,0,-80) );
		//drawtree(Point  (50,0,-60) );
		//drawtree(Point  (50,0,-40) );
		//drawtree(Point  (50,0,-20) );
		//drawtree(Point  (50,0,0) );
		//drawtree(Point  (50,0,20) );
		//drawtree(Point  (50,0,40) );
		//drawtree(Point  (50,0,60) );
		//drawtree(Point  (50,0,80) );
		//drawtree(Point  (50,0,100) );
		//drawtree(Point  (50,0,120) );
		//drawtree(Point  (50,0,140) );

		

		drawtree(Point  (-50,0,-140) );
	//	drawtree(Point  (-50,0,-120) );
		drawtree(Point  (-50,0,-100) );
	//	drawtree(Point  (-50,0,-80) );
		drawtree(Point  (-50,0,-60) );
	//	drawtree(Point  (-50,0,-40) );
		drawtree(Point  (-50,0,-20) );
	//	drawtree(Point  (-50,0,0) );
		drawtree(Point  (-50,0,20) );
	//	drawtree(Point  (-50,0,40) );
		drawtree(Point  (-50,0,60) );
	//	drawtree(Point  (-50,0,80) );
		drawtree(Point  (-50,0,100) );
	//	drawtree(Point  (-50,0,120) );
		drawtree(Point  (-50,0,140) );

		


		drawchair(Point  (10,2,60));
	 drawchair(Point  (10,2,100));
	 
}
void drawgardenw(int x, int z,int xarea,int zarea){

	glTranslated(x,0,z);
	 
   glPushMatrix();
   //glTranslated(20,0,0);
   areas::drawarea(xarea,zarea,grasss,10,10);
	 	glPopMatrix();

}
void drawtrees(){
	//الجانب الامامي  
		    drawtree(Point  (-50,0,+245) );
			drawtree(Point  (-100,0,+245) );
		    drawtree(Point  (-150,0,245) );
		    drawtree(Point  (-200,0,245) );
		    drawtree(Point  (-250,0,245) );		  
		    drawtree(Point  (-300,0,245) );
             drawtree(Point  (-350,0,245) );
			drawtree(Point  (-400,0,245) );
		    drawtree(Point  (-450,0,245) );
			drawtree(Point  (-500,0,245) );
		    drawtree(Point  (-550,0,245) );
		    drawtree(Point  (-600,0,245) );
		    drawtree(Point  (-650,0,245) );
		    drawtree(Point  (-700,0,245) );
		    drawtree(Point  (-740,0,245) );



		    drawtree(Point  (0,0,245) );
		    drawtree(Point  (50,0,245) );
			drawtree(Point  (100,0,245) );
		    drawtree(Point  (150,0,245) );
		    drawtree(Point  (200,0,245) );
		    drawtree(Point  (250,0,245) );		  
		    drawtree(Point  (300,0,245) );
		    drawtree(Point  (350,0,245) );
			drawtree(Point  (400,0,245) );
		    drawtree(Point  (450,0,245) );
			drawtree(Point  (500,0,245) );
		    drawtree(Point  (550,0,245) );
		    drawtree(Point  (+600,0,245) );
		    drawtree(Point  (+650,0,245) );
		    drawtree(Point  (+700,0,245) );
		    drawtree(Point  (+750,0,245) );
		    drawtree(Point  (+800,0,245) );
		    drawtree(Point  (+850,0,245) );
//الجانب الامامي 11 
		
		
			drawtree(Point  (-0,0,+427) );
			drawtree(Point  (-50,0,+427) );
			drawtree(Point  (-100,0,+427) );
		    drawtree(Point  (-150,0,427) );
		    drawtree(Point  (-200,0,427) );
		    drawtree(Point  (-250,0,427) );		  
		    drawtree(Point  (-300,0,427) );
             drawtree(Point  (-350,0,427) );
			drawtree(Point  (-400,0,427) );
		    drawtree(Point  (-450,0,427) );
			drawtree(Point  (-500,0,427) );
		    drawtree(Point  (-550,0,427) );
		    drawtree(Point  (-600,0,427) );
		    drawtree(Point  (-650,0,427) );
		    drawtree(Point  (-700,0,427) );
		    drawtree(Point  (-750,0,427) );
			drawtree(Point  (-800,0,427) );
		    drawtree(Point  (-850,0,427) );
            drawtree(Point  (-900,0,427) );
		    drawtree(Point  (-950,0,427) );
   



		    drawtree(Point  (0,0,427) );
		    drawtree(Point  (50,0,427) );
			drawtree(Point  (100,0,427) );
		    drawtree(Point  (150,0,427) );
		    drawtree(Point  (200,0,427) );
		    drawtree(Point  (250,0,427) );		  
		    drawtree(Point  (300,0,427) );
		    drawtree(Point  (350,0,427) );
			drawtree(Point  (400,0,427) );
		    drawtree(Point  (450,0,427) );
			drawtree(Point  (500,0,427) );
		    drawtree(Point  (550,0,427) );
		    drawtree(Point  (+600,0,427) );
		    drawtree(Point  (+650,0,427) );
		    drawtree(Point  (+700,0,427) );
		    drawtree(Point  (+750,0,427) );
		    drawtree(Point  (+800,0,427) );
		    drawtree(Point  (+850,0,427) );
			drawtree(Point  (+900,0,427) );
		    drawtree(Point  (+950,0,427) );
			drawtree(Point  (+1000,0,427) );
			
	///الجانب الخلفي 

		    drawtree(Point  (-50,0,-827) );
			drawtree(Point  (-100,0,-827) );
		    drawtree(Point  (-150,0,-827) );
		    drawtree(Point  (-200,0,-827) );
		    drawtree(Point  (-250,0,-827) );		  
		    drawtree(Point  (-300,0,-827) );
             drawtree(Point  (-350,0,-827) );
			drawtree(Point  (-400,0,-827) );
		    drawtree(Point  (-450,0,-827) );
			drawtree(Point  (-500,0,-827) );
		    drawtree(Point  (-550,0,-827) );
		    drawtree(Point  (-600,0,-827) );
		    drawtree(Point  (-650,0,-827) );
		    drawtree(Point  (-700,0,-827) );
		    drawtree(Point  (-740,0,-827) );



		    drawtree(Point  (0,0,-827) );
		    drawtree(Point  (50,0,-827) );
			drawtree(Point  (100,0,-827) );
		    drawtree(Point  (150,0,-827) );
		    drawtree(Point  (200,0,-827) );
		    drawtree(Point  (250,0,-827) );		  
		    drawtree(Point  (300,0,-827) );
		    drawtree(Point  (350,0,-827) );
			drawtree(Point  (400,0,-827) );
		    drawtree(Point  (450,0,-827) );
			drawtree(Point  (500,0,-827) );
		    drawtree(Point  (550,0,-827) );
		    drawtree(Point  (+600,0,-827) );
		    drawtree(Point  (+650,0,-827) );
		    drawtree(Point  (+700,0,-827) );
		    drawtree(Point  (+750,0,-827) );
		    drawtree(Point  (+800,0,-827) );
		    drawtree(Point  (+850,0,-827) );



	//الجاني الايمن 
	    drawtree(Point  (+944,0,-740) );
	    drawtree(Point  (+944,0,-700) );
	    drawtree(Point  (944,0,-660) );
        drawtree(Point  (944,0,-620) );
        drawtree(Point  (944,0,-580) );
        drawtree(Point  (944,0,-540) );
		drawtree(Point  (944,0,-500) );
        drawtree(Point  (944,0,-460) );
	    drawtree(Point  (944,0,-420) );	
	    drawtree(Point  (944,0,-380) );
        drawtree(Point  (944,0,-340) );
	    drawtree(Point  (944,0,-300) );
	    drawtree(Point  (944,0,-260) );
        drawtree(Point  (944,0,-220) );
        drawtree(Point  (944,0,-180) );
        drawtree(Point  (944,0,-140) );
		drawtree(Point  (944,0,-100) );
		drawtree(Point  (944,0,-60) );
		drawtree(Point  (944,0,-20) );
		drawtree(Point  (944,0,20) );
		drawtree(Point  (944,0,60) );
		drawtree(Point  (944,0,100) );
		drawtree(Point  (944,0,140) );

	///////الجانب الايسر 
        drawtree(Point  (-845,0,-740) );
	    drawtree(Point  (-845,0,-700) );
	    drawtree(Point  (-845,0,-660) );
        drawtree(Point  (-845,0,-620) );
        drawtree(Point  (-845,0,-580) );
        drawtree(Point  (-845,0,-540) );
		drawtree(Point  (-845,0,-500) );
        drawtree(Point  (-845,0,-460) );
	    drawtree(Point  (-845,0,-420) );	
	    drawtree(Point  (-845,0,-380) );
        drawtree(Point  (-845,0,-340) );
	    drawtree(Point  (-845,0,-300) );
	    drawtree(Point  (-845,0,-260) );
        drawtree(Point  (-845,0,-220) );
        drawtree(Point  (-845,0,-180) );
        drawtree(Point  (-845,0,-140) );
		drawtree(Point  (-845,0,-100) );
		drawtree(Point  (-845,0,-60) );
		drawtree(Point  (-845,0,-20) );
		drawtree(Point  (-845,0,20) );
		drawtree(Point  (-845,0,60) );
		drawtree(Point  (-845,0,100) );
		drawtree(Point  (-845,0,140) );
}
void buildmain(){
  
	//ÑÝÚ ÇáÌÇãÚ
   
	glPushMatrix();
   glTranslated(25,-9.7,-450);
  BuildBlock(250,10,500,kk1,kk1);//لرسم بناء اكثر كفاءة
   glPopMatrix();
	

    glPushMatrix();

	glTranslated(15,-15,78);
	glRotated(180,0,1,0);
	Stair(15,30,1,2,kk1,a3,10);///الدرج 
	 

	glTranslated(130,0,-5.5);
	BuildBlock(110,15,34,kk1,kk1);//الايسر

	glPushMatrix();
	glTranslated(-270,0,1);
	BuildBlock(120,15.2,34,kk1,kk1);//الجانب الايمن للدرج
	glPopMatrix();

	glPushMatrix();//Start the right side of the stairs 
	
	glTranslated(25,17.5,12);
	
	
	glRotated(90,1,0,0);
	glTranslated(0,-12,-7);

   // BuildBlock(15,30,20,a1,a1);
	glRotated(-90,1,0,0);
	glTranslated(0,0,10);
	//drawDomeWithTexture(7,kk2,4,4);

 	glPopMatrix();//End the right side of the stairs 
	
	
	glPopMatrix(); 

}
void wraphouse(){
	 glTranslated(0,0,120);
	 for (int i = 0; i < 4; i++)
	 {
		 
	glTranslated(-120,0,0);

	BuildBlockbyrepeatexture(50,490,100,a3,waellite,1,1);//waellite/
	     
	 }
 
 }
void wraphouse2(){
 
	 for (int i = 0; i < 13; i++)
	 {
		 glTranslated(0,0,-60);
		 for (int i = 0; i < 5; i++)
		 {
			 glPushMatrix();
			 wraphouse();
			 glPopMatrix();

		 }
	 }

 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ahmed shop 3 functions
void DrawQuad(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2,GLfloat x3, GLfloat y3, GLfloat z3, GLfloat x4, GLfloat y4, GLfloat z4,GLuint texture) {
				  glEnable(GL_TEXTURE_2D);
				  glBindTexture(GL_TEXTURE_2D, texture);
				  glBegin(GL_QUADS);
				  glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, y1, z1);
				  glTexCoord2f(1.0f, 0.0f); glVertex3f(x2, y2, z2);
				  glTexCoord2f(1.0f, 1.0f); glVertex3f(x3, y3, z3);
				  glTexCoord2f(0.0f, 1.0f); glVertex3f(x4, y4, z4);
				  glEnd();
				  glDisable(GL_TEXTURE_2D);
}
void UpdateDoor() {
	if (doorshop3Opening && doorshop3Angle < 90.0f) {
		doorshop3Angle += 0.5f;  // Increment angle for opening
		std::cout << "this is the doorAngle " << doorshop3Angle;
	}
	else if (doorshop3Closing && doorshop3Angle > 0.0f) {
		doorshop3Angle -= 0.5f;  // Decrement angle for closing
	}

	if (doorshop3Angle >= 90.0f) doorshop3Opening = false;
	if (doorshop3Angle <= 0.0f) doorshop3Closing = false;
}
void ToggleDoor(bool open) {
	if (open) {
		if (doorshop3Angle == 0.0f) {
			doorshop3Opening = true;  // Start opening the door
		}
	}
	else {
		if (doorshop3Angle == 90.0f) {
			doorshop3Closing = true;  // Start closing the door
		}
	}
	UpdateDoor();
}
void DrawShop(float width, float height, float depth, GLuint floorTexture, GLuint roofTexture,GLuint wallTexture, GLuint frontTexture, float doorWidth, float doorHeight, GLuint doorTexture) {
				  // Draw Floor
				  DrawQuad(-width, 0, -depth, width, 0, -depth, width, 0, depth, -width, 0, depth, floorTexture);

				  // Draw Roof
				  DrawQuad(-width, height, -depth, width, height, -depth, width, height, depth, -width, height, depth, roofTexture);

				  // Back Wall
				  DrawQuad(-width, 0, -depth, width, 0, -depth, width, height, -depth, -width, height, -depth, wallTexture);

				  // Left Wall
				  DrawQuad(-width, 0, -depth, -width, 0, depth, -width, height, depth, -width, height, -depth, wallTexture);

				  // Right Wall
				  DrawQuad(width, 0, -depth, width, 0, depth, width, height, depth, width, height, -depth, wallTexture);

				  //// Front Wall (with door gap, corrected texture distribution)
				  float halfDoorWidth = doorWidth / 2;

				  //// Left part of the front wall
				  //DrawQuad(-width, 0, depth, -halfDoorWidth, 0, depth, -halfDoorWidth, height, depth, -width, height, depth, frontTexture);

				  //// Right part of the front wall
				  //DrawQuad(halfDoorWidth, 0, depth, width, 0, depth, width, height, depth, halfDoorWidth, height, depth, frontTexture);

				  //// Section above the door (ensures no empty space above the door)
				  //DrawQuad(-halfDoorWidth, doorHeight, depth, halfDoorWidth, doorHeight, depth, halfDoorWidth, height, depth, -halfDoorWidth, height, depth, frontTexture);

				  //// Draw Door with rotation
				  glPushMatrix();
				  glTranslatef(-halfDoorWidth, 0, depth);  // Move to the hinge
				  glRotatef(doorshop3Angle, 0, 1, 0);           // Rotate around the hinge
				  glTranslatef(halfDoorWidth, 0, -depth);  // Move back to door position

				//  DrawQuad(-halfDoorWidth, 0, depth, halfDoorWidth, 0, depth, halfDoorWidth, doorHeight, depth, -halfDoorWidth, doorHeight, depth, doorTexture);

				  glPopMatrix();
}
void DrawRefrigerator(float width, float height, float depth, GLuint bodyTexture, GLuint doorTexture) {
	float freezerHeight = height * 0.3f; // The top freezer section is 30% of the total height.
	float fridgeHeight = height - freezerHeight;

	// Refrigerator Body
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glBegin(GL_QUADS);

	// Front
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left

	// Back
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Right
	glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-left

	// Top
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height, -depth / 2); // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height, -depth / 2);  // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2);   // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2);  // Top-left

	// Bottom
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0, depth / 2);    // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0, depth / 2);   // Top-left

	glEnd();

	// Refrigerator Door
	glBindTexture(GL_TEXTURE_2D, doorTexture);
	glBegin(GL_QUADS);

	// Front Door
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2 + 0.01f);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2 + 0.01f);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2 + 0.01f); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2 + 0.01f); // Top-left


	glEnd();
}
void DrawWashingMachine(float width, float height, float depth, GLuint bodyTexture, GLuint frontTexture) {
	// Body of the washing machine (all sides except front)
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glBegin(GL_QUADS);

	// Back
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Right
	glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-left

	// Top
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height, -depth / 2); // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height, -depth / 2);  // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2);   // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2);  // Top-left

	// Bottom
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0, depth / 2);   // Top-left

	glEnd();

	// Front face with texture
	glBindTexture(GL_TEXTURE_2D, frontTexture);
	glBegin(GL_QUADS);

	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left


	// Front face texture coordinates
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left



	glEnd();
}
void DrawOven(float width, float height, float depth, GLuint bodyTexture, GLuint doorTexture) {
	// Body of the washing machine (all sides except front)
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glBegin(GL_QUADS);

	// Back
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Right
	glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-left

	// Top
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height, -depth / 2); // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height, -depth / 2);  // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2);   // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2);  // Top-left

	// Bottom
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0, depth / 2);   // Top-left

	glEnd();

	// Front face with texture
	glBindTexture(GL_TEXTURE_2D, doorTexture);
	glBegin(GL_QUADS);

	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left


	// Front face texture coordinates
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left



	glEnd();
}
void DrawMicrowave(float width, float height, float depth, GLuint bodyTexture, GLuint doorTexture) {

	glPushMatrix();
	glColor3d(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glBegin(GL_QUADS);

	// Back
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Right
	glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-left

	// Top
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height, -depth / 2); // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height, -depth / 2);  // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2);   // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2);  // Top-left

	// Bottom
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0, depth / 2);   // Top-left

	glEnd();

	// Front face with texture
	glBindTexture(GL_TEXTURE_2D, doorTexture);
	glBegin(GL_QUADS);

	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left


	// Front face texture coordinates
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void drawTexturedCuboid(float length, float width, float height, int textureID) {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glBegin(GL_QUADS);

	// Top face
	glTexCoord2f(0.0, 0.0); glVertex3f(-length / 2, height / 2, -width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(length / 2, height / 2, -width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(length / 2, height / 2, width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-length / 2, height / 2, width / 2);

	// Bottom face
	glTexCoord2f(0.0, 0.0); glVertex3f(-length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(length / 2, -height / 2, width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-length / 2, -height / 2, width / 2);

	// Front face
	glTexCoord2f(0.0, 0.0); glVertex3f(-length / 2, -height / 2, width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(length / 2, -height / 2, width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(length / 2, height / 2, width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-length / 2, height / 2, width / 2);

	// Back face
	glTexCoord2f(0.0, 0.0); glVertex3f(-length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(length / 2, height / 2, -width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-length / 2, height / 2, -width / 2);

	// Left face
	glTexCoord2f(0.0, 0.0); glVertex3f(-length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(-length / 2, -height / 2, width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(-length / 2, height / 2, width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-length / 2, height / 2, -width / 2);

	// Right face
	glTexCoord2f(0.0, 0.0); glVertex3f(length / 2, -height / 2, -width / 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(length / 2, -height / 2, width / 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(length / 2, height / 2, width / 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(length / 2, height / 2, -width / 2);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void drawTexturedTable(float topLength, float topWidth, float topThickness,float legWidth, float legHeight, int textureID) {
						   // Draw table top
						   glPushMatrix();
						   glTranslated(0.0, legHeight + topThickness / 2, 0.0);
						   drawTexturedCuboid(topLength, topWidth, topThickness, textureID);
						   glPopMatrix();

						   // Draw legs
						   float legXOffset = (topLength - legWidth) / 2;
						   float legZOffset = (topWidth - legWidth) / 2;

						   // Front-left leg
						   glPushMatrix();
						   glTranslated(-legXOffset, legHeight / 2, legZOffset);
						   drawTexturedCuboid(legWidth, legWidth, legHeight, textureID);
						   glPopMatrix();

						   // Front-right leg
						   glPushMatrix();
						   glTranslated(legXOffset, legHeight / 2, legZOffset);
						   drawTexturedCuboid(legWidth, legWidth, legHeight, textureID);
						   glPopMatrix();

						   // Back-left leg
						   glPushMatrix();
						   glTranslated(-legXOffset, legHeight / 2, -legZOffset);
						   drawTexturedCuboid(legWidth, legWidth, legHeight, textureID);
						   glPopMatrix();

						   // Back-right leg
						   glPushMatrix();
						   glTranslated(legXOffset, legHeight / 2, -legZOffset);
						   drawTexturedCuboid(legWidth, legWidth, legHeight, textureID);
						   glPopMatrix();
}
void drawTexturedShelf(GLfloat width, GLfloat depth, GLfloat thickness,GLuint textureID) {
						   glEnable(GL_TEXTURE_2D);
						   glBindTexture(GL_TEXTURE_2D, textureID);

						   // Draw the top face of the shelf
						   glBegin(GL_QUADS);

						   // Top face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0.0f, depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0.0f, depth / 2);

						   // Bottom face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, -thickness, -depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, -thickness, -depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, -thickness, depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, -thickness, depth / 2);

						   // Front face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0.0f, depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0.0f, depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, -thickness, depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, -thickness, depth / 2);

						   // Back face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, -thickness, -depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, -thickness, -depth / 2);

						   // Left face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0.0f, depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, -thickness, depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, -thickness, -depth / 2);

						   // Right face
						   glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0.0f, -depth / 2);
						   glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0.0f, depth / 2);
						   glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, -thickness, depth / 2);
						   glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, -thickness, -depth / 2);

						   glEnd();
						   glDisable(GL_TEXTURE_2D);
}
void drawClock(GLuint clockfaceTexture) {
	time_t currentTime = time(nullptr);
	struct tm* localTime = localtime(&currentTime);

	int hour = localTime->tm_hour;
	int minute = localTime->tm_min;
	int second = localTime->tm_sec;

	hour = hour % 12;

	double secondAngle = second * 6.0;
	double minuteAngle = minute * 6.0 + second * 0.1;
	double hourAngle = hour * 30.0 + minute * 0.5;

	glPushMatrix();
	glTranslated(10, 5, -9.6);
	glScaled(1.5, 1.5, 1.5);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3d(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, clockfaceTexture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1, -1, 0);
	glTexCoord2d(1, 0);
	glVertex3d(1, -1, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-1, 1, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 255, 0);
	glRotated(-hourAngle, 0.0, 0.0, 1.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotated(-minuteAngle, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotated(-secondAngle, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.9, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

}
void DrawCube(GLfloat size, GLuint textureID) {
	GLfloat vertices[][3] = {
		{-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5,  0.5, -0.5}, {-0.5,  0.5, -0.5},
		{-0.5, -0.5,  0.5}, {0.5, -0.5,  0.5}, {0.5,  0.5,  0.5}, {-0.5,  0.5,  0.5}
	};

	GLint faces[][4] = {
		{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 1, 5, 4},
		{2, 3, 7, 6}, {0, 3, 7, 4}, {1, 2, 6, 5}
	};

	GLfloat texCoords[][2] = {
		{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}
	};

	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			glTexCoord2fv(texCoords[j]);
			glVertex3fv(vertices[faces[i][j]]);
		}
	}
	glEnd();
}
void drawCashiersCounter(GLuint monitorTextureID) {
    glPushMatrix();
    glTranslated(0.0f, 3.0f, 0.0f); // Translate the entire setup to the desired position

    // Draw the counter
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.0f); // Brown color for the counter
    glBegin(GL_QUADS);
    // Top surface
    glVertex3f(-1.5f, 0.0f, 0.5f);
    glVertex3f(1.5f, 0.0f, 0.5f);
    glVertex3f(1.5f, 0.0f, -0.5f);
    glVertex3f(-1.5f, 0.0f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    // Front side
    glVertex3f(-1.5f, -1.0f, 0.5f);
    glVertex3f(1.5f, -1.0f, 0.5f);
    glVertex3f(1.5f, 0.0f, 0.5f);
    glVertex3f(-1.5f, 0.0f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    // Left side
    glVertex3f(-1.5f, -1.0f, 0.5f);
    glVertex3f(-1.5f, -1.0f, -0.5f);
    glVertex3f(-1.5f, 0.0f, -0.5f);
    glVertex3f(-1.5f, 0.0f, 0.5f);
    // Right side
    glVertex3f(1.5f, -1.0f, 0.5f);
    glVertex3f(1.5f, -1.0f, -0.5f);
    glVertex3f(1.5f, 0.0f, -0.5f);
    glVertex3f(1.5f, 0.0f, 0.5f);
    glEnd();
    glPopMatrix();

    // Draw the monitor
    glPushMatrix();
    glTranslated(0.0f, 0.0f, 0.2f); // Position the monitor
    glColor3f(0.0f, 0.0f, 0.0f); // Black monitor
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, 0.1f);
    glVertex3f(0.5f, 0.5f, 0.1f);
    glVertex3f(0.5f, 1.0f, 0.1f);
    glVertex3f(-0.5f, 1.0f, 0.1f);
    glEnd();

    // Apply texture to the monitor screen if available
    if (monitorTextureID) {
	    glPushMatrix();
        DrawCube(1.0f, monitorTextureID);
		glPopMatrix();
    }

    glColor3f(0.3f, 0.3f, 0.3f); // Gray color for the stand
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, 0.0f, 0.1f);
    glVertex3f(0.1f, 0.0f,  0.1f);
    glVertex3f(0.1f, 0.5f,  0.1f);
    glVertex3f(-0.1f, 0.5f, 0.1f);
    glEnd();
    glPopMatrix();

    // Draw the cash register
    glPushMatrix();
    glTranslated(0.7f, 0.0f, 0.0f); // Position the cash register
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glBegin(GL_QUADS);
    glVertex3f(-0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f,  0.4f);
    glVertex3f(0.4f, 0.3f,  0.4f);
    glVertex3f(-0.4f, 0.3f, 0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Black display
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, 0.3f,  0.4f);
    glVertex3f(0.2f, 0.3f,   0.4f);
    glVertex3f(0.2f, 0.5f,   0.4f);
    glVertex3f(-0.2f, 0.5f,  0.4f);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}
void drawChair(GLuint textureID) {

	// Seat
	glEnable(GL_TEXTURE_2D);
	glColor3d(1,1,1);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	glScalef(2.0f, 0.1f, 2.0f);
	DrawCube(1.0f, textureID);
	glPopMatrix();

	// Backrest
	glPushMatrix();
	glTranslatef(0.0f, 1.75f, -0.9f);
	glScalef(2.0f, 1.5f, 0.1f);
	DrawCube(1.0f, textureID);
	glPopMatrix();

	// Legs
	for (float x = -0.9f; x <= 0.9f; x += 1.8f) {
		for (float z = -0.9f; z <= 0.9f; z += 1.8f) {
			glPushMatrix();
			glTranslatef(x, 0.5f, z);
			glScalef(0.1f, 1.0f, 0.1f);
			DrawCube(1.0f, textureID);
			glPopMatrix();
		}
	}
	glDisable(GL_TEXTURE_2D);

}
void DrawWaterKoeler(float width, float height, float depth, GLuint bodyTexture, GLuint doorTexture) {

	float freezerHeight = height * 0.3f; // The top freezer section is 30% of the total height.
	float fridgeHeight = height - freezerHeight;
	glColor3d(1,1,1);
	glEnable(GL_TEXTURE_2D);
	// WaterKoeler Body
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glBegin(GL_QUADS);

	// Front
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-left

	// Back
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Left
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, -depth / 2); // Top-left

	// Right
	glTexCoord2f(0.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2);    // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(width / 2, height, -depth / 2); // Top-left

	// Top
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, height, -depth / 2); // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, height, -depth / 2);  // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2);   // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2);  // Top-left

	// Bottom
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, -depth / 2);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, -depth / 2);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, 0, depth / 2);    // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, 0, depth / 2);   // Top-left

	glEnd();

	// WaterKoeler Door
	glBindTexture(GL_TEXTURE_2D, doorTexture);
	glBegin(GL_QUADS);

	// Front Door
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-width / 2, 0, depth / 2 + 0.01f);  // Bottom-left
	glTexCoord2f(1.0f, 0.0f); glVertex3f(width / 2, 0, depth / 2 + 0.01f);   // Bottom-right
	glTexCoord2f(1.0f, 1.0f); glVertex3f(width / 2, height, depth / 2 + 0.01f); // Top-right
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-width / 2, height, depth / 2 + 0.01f); // Top-left


	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void drawShop3(){

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslated(137,11,-345); 

	glTranslated(-0.7,0,0);
	DrawShop(
		99.0f, // Shop width
		71.0f, // Shop height
		96.0f, // Shop depth
		floorshop3Texture, // Floor texture
		roofshop3Texture,  // Roof texture
		wallshop3Texture,  // Wall texture
		frontshop3Texture, // Front texture
		20.0f,         // Door width
		40.0f,         // Door height
		doorshop3Texture   // Door texture
		);

		glTranslated(0,0,6);

	// draw refrigerators

	glPushMatrix();
	glTranslated(63,0,-90.5);
	glEnable(GL_TEXTURE_2D);
	DrawRefrigerator(20.0f, 35.0f, 20.0f, refrigeratorbodyTexture1, refrigeratordoorTexture1);
	glPushMatrix();
	glTranslated(25,0,0);
	DrawRefrigerator(20.0f, 35.0f, 20.0f, refrigeratorbodyTexture2, refrigeratordoorTexture2);
	glPopMatrix();
	glPopMatrix();

	// draw washmachines 

	glPushMatrix();
	glTranslated(15, 0, -90.5);
	DrawWashingMachine(20.0f,20.0f, 20, washmachinebodyTexture1, washmachinedoorTexture1);
	glPushMatrix();
	glTranslated(25, 0, 0);         
	DrawWashingMachine(20.0f,20.0f, 20, washmachinebodyTexture2, washmachinedoorTexture2);
	glPopMatrix();
	glPopMatrix();

	// draw ovens 

	glPushMatrix();
	glTranslated(-10, 0, -90.5);
	DrawOven(20.0f,15.0f, 20, ovenbodyTexture1, ovendoorTexture1);
	glPushMatrix();
	glTranslated(-25, 0, 0);         
	DrawOven(20.0f,15.0f, 20, ovenbodyTexture2, ovendoorTexture2);
	glPopMatrix();
	glPopMatrix();

	// draw clocks 


	glPushMatrix();
	glTranslated(15, 35, -90.5);
	glScaled(3, 3, 1);
	drawClock(clockfaceTexture2);
	glPushMatrix();
	glTranslated(5, 0, 0);  
	drawClock(clockfaceTexture2);
	glPushMatrix();
	glTranslated(-10, 0, 0);  
	drawClock(clockfaceTexture3);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();  



	// draw microwaves 

	glPushMatrix();
	glTranslated(-60, 0, -90.5);
	DrawMicrowave(20.0f,10.0f, 20, microwavebodyTexture1, microwavedoorTexture1);
	
	glPushMatrix();
	glTranslated(0, 21, 0); 
	DrawMicrowave(20.0f,10.0f, 20, microwavebodyTexture2, microwavedoorTexture2);
	glTranslated(0, 0, 3); 
	drawTexturedShelf(25.0f,23.0f, 0.1f, graytexture); // Dimensions: width, depth, thickness
	
	glPushMatrix();
	glTranslated(35, 0, 0); 
	DrawMicrowave(20.0f,10.0f, 20, microwavebodyTexture3, microwavedoorTexture2);
	glTranslated(0, 0, 3); 
	drawTexturedShelf(25.0f,23.0f, 0.1f, graytexture); // Dimensions: width, depth, thickness
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// draw tables 
	glPushMatrix();
	glTranslated(-85, 0, -70.5); 
	glRotated(90, 0, 1, 0);      
	drawTexturedTable(50.0f, 25.0f, 0.2f, 1.0f, 15.0f, woodTexture1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-85, 0, 14.5);
	glRotated(90, 0, 1, 0);    
	drawTexturedTable(50.0f, 25.0f, 0.2f, 1.0f, 15.0f, woodTexture2);
	glPopMatrix();

	// draw CashiersCounter

	glPushMatrix();
	glScaled(15,15,15);
	glTranslated(4,-2,5);
	glRotated(-90,0,1,0);
	glTranslated(-0.55,0,0);

	//drawCashiersCounter(casherscreenTexture1);
	glPopMatrix();

	glPushMatrix();
	glScaled(9,9,9);
	glRotated(-90,0,1,0);
	glTranslated(7.9,0,-9.5);
	//drawChair(graytexture);
	glPopMatrix();




	// draw chairs 

	glPushMatrix();
	glTranslated(-85, 0.1, -30.5); 
	glScaled(9,9,9);
	glRotated(90,0,1,0);
	drawChair(woodTexture7);
	glTranslated(-9.5, 0, 0); 
	drawChair(woodTexture7);
	glTranslated(0.55,0,0);
	glTranslated(-3, 0, 0); 
	drawChair(woodTexture7);
	glPopMatrix();



	// draw waterkoelers 

	glPushMatrix();
	glScaled(5, 5, 5);
	glRotated(-90, 0, 1, 0);
	glTranslated(-5,0,-18.5);
	DrawWaterKoeler(2.3,4.7,2.4,graytexture, waterkoelerTexture1);
	glTranslated(6, 0, 0);
	DrawWaterKoeler(2.3, 4.7, 2.4, graytexture, waterkoelerTexture1);
	glPopMatrix();

	//glPushMatrix();
	//	glScaled(5, 5, 5);
	//bulb_set();
	//	fan_full_set();
	//	    alpha += 320.0; // زيادة زاوية الدوران
	//glPopMatrix();




	glPopMatrix();
}
// ahmed shop 3 functions 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void drawSphereWithTexture(float radius, int slices, int stacks, GLuint textureID, float x, float y, float z) {
    glPushMatrix();                    // حفظ الحالة الحالية
    glTranslatef(x, y, z);             // تحريك الكرة إلى الموقع المحدد
    glEnable(GL_TEXTURE_2D);           // تفعيل الإكساء
    glBindTexture(GL_TEXTURE_2D, textureID); // ربط النسيج

    for (int i = 0; i < slices; ++i) {
        float lat0 = M_PI * (-0.5 + (float)i / slices);
        float lat1 = M_PI * (-0.5 + (float)(i + 1) / slices);
        for (int j = 0; j < stacks; ++j) {
            float lon0 = 2 * M_PI * (float)j / stacks;
            float lon1 = 2 * M_PI * (float)(j + 1) / stacks;

            float x0 = radius * cos(lat0) * cos(lon0);
            float y0 = radius * cos(lat0) * sin(lon0);
            float z0 = radius * sin(lat0);

            float x1 = radius * cos(lat1) * cos(lon0);
            float y1 = radius * cos(lat1) * sin(lon0);
            float z1 = radius * sin(lat1);

            float x2 = radius * cos(lat1) * cos(lon1);
            float y2 = radius * cos(lat1) * sin(lon1);
            float z2 = radius * sin(lat1);

            float x3 = radius * cos(lat0) * cos(lon1);
            float y3 = radius * cos(lat0) * sin(lon1);
            float z3 = radius * sin(lat0);

            float u0 = (float)j / stacks;
            float u1 = (float)(j + 1) / stacks;
            float v0 = (float)i / slices;
            float v1 = (float)(i + 1) / slices;

            glBegin(GL_QUADS);
            glTexCoord2f(u0, v0); glVertex3f(x0, y0, z0);
            glTexCoord2f(u0, v1); glVertex3f(x1, y1, z1);
            glTexCoord2f(u1, v1); glVertex3f(x2, y2, z2);
            glTexCoord2f(u1, v0); glVertex3f(x3, y3, z3);
            glEnd();
        }
	}
 glDisable(GL_TEXTURE_2D); // إلغاء تفعيل الإكساء
    glPopMatrix();            // استعادة الحالة السابقة
}

void waleed(){
		   r.QuadWithHighAndTextureMainGround(Point(-45,0, -35), -200, 73.3, 1, area,1);
 r.QuadWithHighAndTextureMainGround(Point(-45,0, -34), -200, 73.3, 1, a3,1);
 r.QuadWithHighAndTextureMainGround(Point(-45,0, -234), -200, 73.3, 1, area,1);//الحيط اليميني الاخير
r.QuadWithHighAndTextureMainGround(Point(-244,0, -235), -1, 73.3, 100.6,a3 ,5);
r.QuadWithHighAndTextureMainGround(Point(-243,0, -235), -1, 73.3, 100.6,area ,5);
r.QuadWithHighAndTextureMainGround(Point(-46,0, -235), -1, 73.3, 200.6, area,1);
//r.QuadWithHighAndTextureMainGround(Point(-45,0, -235), -1, 73.3, 200.6, a3,1);//الحائط الامامي للغرفةالامامية
  r.QuadWithHighAndTextureMainGround(Point(-244,1,-55), 40, 40, 20.6, sol,1); 
 r.QuadWithHighAndTextureMainGround(Point(-244,1,-233), 40, 40, 20.6, sol,1);//  الحائط الخلفي للغرفةاليسارية
r.QuadWithHighAndTextureMainGround(Point(-150,1,-233), 40, 40, 20.6, sol,1);//  الحائط الخلفي للغرفةاليسارية
 r.QuadWithHighAndTextureMainGround(Point(-200,1,-233), 40, 40, 20.6, sol,1);
r.QuadWithHighAndTextureMainGround(Point(-150,1,-55), 40, 40, 20.6, sol,1);
 r.QuadWithHighAndTextureMainGround(Point(-200,1,-55), 40, 40, 20.6, sol,1);
 r.QuadWithHighAndTextureMainGround(Point(-87,1,-120), 40, 40, 60.6, sol,1);
 r.QuadWithHighAndTextureMainGround(Point(-87,1,-200), 40, 40, 60.6, sol,1);
r.QuadWithHighAndTextureMainGround(Point(-244,70.7,-235), 198, 1, 202, a4,1);////////////////
 r.QuadWithHighAndTextureMainGround(Point(-244,0,-235), 198, 1, 202, a4,1);////////////////
 r.QuadWithHighAndTextureMainGround(Point(-150,12,-127), 15, 2, 30, a4,1);////////////////
 r.QuadWithHighAndTextureMainGround(Point(-140,9,-120), 10, 2, 15, area,1);
 r.QuadWithHighAndTextureMainGround(Point(-132,10,-120), 2, 10, 15, a4,1);
 r.QuadWithHighAndTextureMainGround(Point(-145,13.2,-119), 8, 1.5, 8, book,1);
   r.QuadWithHighAndTextureMainGround(Point(-135,14.2,-105), 2, 8, 8, book1,1);
r.QuadWithHighAndTextureMainGround(Point(-145,15.2,-122), 8, 1.5, 8, book,1);
 r.QuadWithHighAndTextureMainGround(Point(-145,16.2,-120), 8, 1.5, 8, book,1);
 r.QuadWithHighAndTextureMainGround(Point(-145,12,-125), -2, -13, 2, area,200);
 r.QuadWithHighAndTextureMainGround(Point(-139,12,-125), -2, -13, 2, area,200);
r.QuadWithHighAndTextureMainGround(Point(-145,12,-100), -2, -13, 2, area,200);
 r.QuadWithHighAndTextureMainGround(Point(-139,12,-100), -2, -13, 2, area,200);
r.QuadWithHighAndTextureMainGround(Point(-135,10,-117), -2, -13, 2, area,200);
 r.QuadWithHighAndTextureMainGround(Point(-135,10,-110), -2, -13, 2, area,200);
 r.QuadWithHighAndTextureMainGround(Point(-130,10,-117), -2, -13, 2, area,200);
r.QuadWithHighAndTextureMainGround(Point(-130,10,-110), -2, -13, 2, area,200);
 r.QuadWithHighAndTextureMainGround(Point(-84,40,-233), 15, 15, 1, hour,1);
 r.QuadWithHighAndTextureMainGround(Point(-84,40,-36), 20, 20, 1, hour,1);
}
void ysef(){

r.QuadWithHighAndTextureMainGround(Point(-246,1, 15), 200, 72, 1, a3,1);//براد

r.QuadWithHighAndTextureMainGround(Point(-246,1, 215), 200, 72, 1, a3,1);//براد
r.QuadWithHighAndTextureMainGround(Point(-60,2, 16), 10, 71.3, 199.06, n1,1);//شاشه
////////////////////////////////////
  r.QuadWithHighAndTextureMainGround(Point(-145,12,214), 40, 45, 1, a,1); 
  r.QuadWithHighAndTextureMainGround(Point(-150,12,16), 40, 45, 1, wa,1); 
  r.QuadWithHighAndTextureMainGround(Point(-245,0, 115), -1, 73.3, 100.6, a3,5);
  r.QuadWithHighAndTextureMainGround(Point(-245,0, 15), -1, 73.3, 50.6, a3,5);













///////////////////////////////////////

r.QuadWithHighAndTextureMainGround(Point(-190,10, 195), 30, 1, 20.06, you,5);
r.QuadWithHighAndTextureMainGround(Point(-190,19, 195), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-190,29, 195), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-100,10, 195), 30, 1, 20.06, you,5);
r.QuadWithHighAndTextureMainGround(Point(-100,19, 195), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-100,29, 195), 30, 1, 20.06, you,5);


r.QuadWithHighAndTextureMainGround(Point(-190,10, 17), 30, 1, 20.06, you,5);
r.QuadWithHighAndTextureMainGround(Point(-190,19, 17), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-190,29, 17), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-100,10, 17), 30, 1, 20.06, you,5);
r.QuadWithHighAndTextureMainGround(Point(-100,19, 17), 30, 1, 20.06, you,5);

r.QuadWithHighAndTextureMainGround(Point(-100,29, 17), 30, 1, 20.06, you,5);

///////وةو


  
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 13.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 13.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 13.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 13.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 13.0f, 30.0f);
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 13.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 13.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 13.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 13.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 13.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 13.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 13.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 13.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 13.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 13.0f, 35.0f);
                drawSphereWithTexture(2.0f, 40, 30, fo, -85.7f, 16.0f, 30.0f);
              drawSphereWithTexture(2.0f, 40, 30, fo, -90.0f, 16.0f, 30.0f);
            drawSphereWithTexture(2.0f, 40, 30, fo, -80.5f, 16.0f, 30.0f);
             drawSphereWithTexture(2.0f, 40, 30, fo, -75.5f, 16.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -88.0f, 18.4f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -83.0f, 18.4f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -78.0f, 18.4f, 30.0f);
//r.QuadWithHighAndTextureMainGround(Point(-180,-36, 190), 40, 40, 20.06, yello1,5);
//الرف الثاني
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 22.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 22.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 22.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 22.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 22.0f, 30.0f);
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 22.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 22.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 22.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 22.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 22.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 22.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 22.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 22.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 22.0f, 35.0f);
drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 22.0f, 35.0f);
                drawSphereWithTexture(2.0f, 40, 30, fo, -85.7f, 25.0f, 30.0f);
              drawSphereWithTexture(2.0f, 40, 30, fo, -90.0f, 25.0f, 30.0f);
            drawSphereWithTexture(2.0f, 40, 30, fo, -80.5f, 25.0f, 30.0f);
             drawSphereWithTexture(2.0f, 40, 30, fo, -75.5f, 25.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -88.0f, 27.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -83.0f, 27.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -78.0f, 27.0f, 30.0f);
//الرف الثالث
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 32.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 32.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 32.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 32.0f, 30.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 32.0f, 30.0f);
    drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 32.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 32.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 32.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 32.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 32.0f, 25.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 32.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -78.0f, 32.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -83.0f, 32.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -88.0f, 32.0f, 35.0f);
  drawSphereWithTexture(2.0f, 40, 30, fo, -93.0f, 32.0f, 35.0f);
                drawSphereWithTexture(2.0f, 40, 30, fo, -85.7f, 35.0f, 30.0f);
              drawSphereWithTexture(2.0f, 40, 30, fo, -90.0f, 35.0f, 30.0f);
            drawSphereWithTexture(2.0f, 40, 30, fo, -80.5f, 35.0f, 30.0f);
             drawSphereWithTexture(2.0f, 40, 30, fo, -75.5f, 35.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -88.0f, 38.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -83.0f, 38.0f, 30.0f);
drawSphereWithTexture(2.0f, 38, 30, fo, -78.0f, 38.0f, 30.0f);
//الرف الثالث/
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 32.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 32.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, WAL, -85.7f, 34.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, WAL, -90.0f, 34.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, WAL, -80.5f, 34.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, WAL, -75.5f, 34.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -88.0f, 36.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -83.0f, 36.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -78.0f, 36.0f, 203.0f);
//الرف الثالث/2
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 22.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 22.0f, 198.0f);

drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 22.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, WAL, -85.7f, 24.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, WAL, -90.0f, 24.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, WAL, -80.5f, 24.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, WAL, -75.5f, 24.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -88.0f, 26.4f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -83.0f, 26.4f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -78.0f, 26.4f, 203.0f);
//1
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 13.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -74.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -78.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -83.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -88.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, WAL, -93.0f, 13.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, WAL, -85.7f, 15.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, WAL, -90.0f, 15.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, WAL, -80.5f, 15.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, WAL, -75.5f, 15.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -88.0f, 18.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -83.0f, 18.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, WAL, -78.0f, 18.0f, 203.0f);
//داخل
//الرف الثالث/
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 32.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 32.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 32.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 32.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 32.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, i1, -180.7f, 34.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, i1, -185.0f, 34.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, i1, -175.5f, 34.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, i1, -170.5f, 34.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -183.0f, 36.5f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -178.0f, 36.5f, 203.0f);


drawSphereWithTexture(2.0f, 38, 30, i1, -173.0f, 36.5f, 203.0f);
//الرف الثالث/2
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 22.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 22.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 22.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 22.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 22.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, i1, -180.7f, 24.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, i1, -185.0f, 24.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, i1, -175.5f, 24.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, i1, -170.5f, 24.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -183.0f, 26.4f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -178.0f, 26.4f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -173.0f, 26.4f, 203.0f);
//1
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 13.0f, 203.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 13.0f, 203.0f);
    drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -169.0f, 13.0f, 198.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -173.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -178.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -183.0f, 13.0f, 208.0f);
  drawSphereWithTexture(2.0f, 40, 30, i1, -188.0f, 13.0f, 208.0f);
                drawSphereWithTexture(2.0f, 40, 30, i1, -175.7f, 15.0f, 203.0f);
              drawSphereWithTexture(2.0f, 40, 30, i1, -185.0f, 15.0f, 203.0f);
            drawSphereWithTexture(2.0f, 40, 30, i1, -175.5f, 15.0f, 203.0f);
             drawSphereWithTexture(2.0f, 40, 30, i1, -170.5f, 15.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -183.0f, 18.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -178.0f, 18.0f, 203.0f);
drawSphereWithTexture(2.0f, 38, 30, i1, -173.0f, 18.0f, 203.0f);
//مقابل
drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 32.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 32.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 32.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 32.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 32.0f, 23.0f);
    drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 32.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 32.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 32.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 32.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 32.0f, 28.0f);
                drawSphereWithTexture(2.0f, 40, 30, k0, -180.7f, 34.0f, 23.0f);
              drawSphereWithTexture(2.0f, 40, 30, k0, -185.0f, 34.0f, 23.0f);
            drawSphereWithTexture(2.0f, 40, 30, k0, -175.5f, 34.0f, 23.0f);
             drawSphereWithTexture(2.0f, 40, 30, k0, -170.5f, 34.0f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -183.0f, 36.5f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -178.0f, 36.5f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -173.0f, 36.5f, 23.0f);
//الرف الثالث/2
    drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 22.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 22.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 22.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 22.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 22.0f, 23.0f);
    drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 22.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 22.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 22.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 22.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 22.0f, 28.0f);
                drawSphereWithTexture(2.0f, 40, 30, k0, -180.7f, 24.0f, 23.0f);
              drawSphereWithTexture(2.0f, 40, 30, k0, -185.0f, 24.0f, 23.0f);
            drawSphereWithTexture(2.0f, 40, 30, k0, -175.5f, 24.0f, 23.0f);
             drawSphereWithTexture(2.0f, 40, 30, k0, -170.5f, 24.0f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -183.0f, 26.4f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -178.0f, 26.4f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -173.0f, 26.4f, 23.0f);
//1
    drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 13.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 13.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 13.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 13.0f, 23.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 13.0f, 23.0f);
    drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -169.0f, 13.0f, 18.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -173.0f, 13.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -178.0f, 13.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -183.0f, 13.0f, 28.0f);
  drawSphereWithTexture(2.0f, 40, 30, k0, -188.0f, 13.0f, 28.0f);
                drawSphereWithTexture(2.0f, 40, 30, k0, -175.7f, 15.0f, 23.0f);


drawSphereWithTexture(2.0f, 40, 30, k0, -185.0f, 15.0f, 23.0f);
            drawSphereWithTexture(2.0f, 40, 30, k0, -175.5f, 15.0f, 23.0f);
             drawSphereWithTexture(2.0f, 40, 30, k0, -170.5f, 15.0f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -183.0f, 18.0f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -178.0f, 18.0f, 23.0f);
drawSphereWithTexture(2.0f, 38, 30, k0, -173.0f, 18.0f, 23.0f);

r.QuadWithHighAndTextureMainGround(Point(-47.5,0, 15), -1, 73.3, 200.6, a4,1);
        //r.QuadWithHighAndTextureMainGround(Point(-245,0, 15), -1, 73.3, 100.6, a3,5);//حيط خلفي
        r.QuadWithHighAndTextureMainGround(Point(-244,1, 216), 190, 1, -200.06, gre,1);//ارضيه
        r.QuadWithHighAndTextureMainGround(Point(-248,73, 216), 202, 1, -200.06, a4,1);//سقف


}
void wael(){ 
	glPushMatrix();
	glTranslated(0,9.9,0);
	buildmain();//الارضية الاساسية
	glPopMatrix();////////////////1
	
	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//waleed();
		   ///////////////////////////////////////////////////////////////

	glTranslated(0,-0.2,0);
	areas::drawarea(2000,700,area1,25,25);
	 
	glTranslated(-25,0,250);

   glPushMatrix();///////////////1
    glTranslated(5.9,.01,100);
	
	glPushMatrix();///////////////2

	glTranslated(-27,.3,-80);


    drawgarden(-90,-40,75,150);//اليسار
	glPopMatrix();///////////////2
	
	glTranslated(100,0,0);
	glPushMatrix();///////////////3
	glTranslated(27,.3,-80);
	glRotated(180,0,1,0);

    drawgarden(-70,+40,75,150);
	glPopMatrix();///////////////3
	drawgardenw(-50,+350+120-120-120-120+35,800,10);
		drawgardenw(-50+15,+350+120-120-120-120+35+30,990,30);
			drawgardenw(-50+85,+350-120-120-120-120-990-127,800,5);
				drawgardenw(-350-120-120-120-120-71,550-20,7,450);
				drawgardenw(+1787,550-550,5,450);

		//drawgardenw(-450,+350+120-120-120-120+35,800,4);
    glPopMatrix();///////////////1

	glPushMatrix();
	glTranslated(-149,0,-60);
	glTranslated(-22,0,-180);
	//build houses
	glPushMatrix();
	glTranslated(0,0,200);
	wraphouse2();
	glPopMatrix();
	//end build houses
	//build houses
	glPushMatrix();
	glTranslated(+1050,0,200);
	//glRotated(180,0,1,0);
	wraphouse2();
	glPopMatrix();

	//end build houses
    glPopMatrix();
	

			glPushMatrix();
glTranslated(27,10.3,-200);
	glRotated(-90,0,1,0);
	            r.QuadWithHighAndTextureMainGround(Point(-45,0, -35), -x, y, 1, block1,5);//41.6//-48
	            r.QuadWithHighAndTextureMainGround(Point(-45,0, -235), -450, 73.3, 1, a3,1);//41.6//-48//الحيط الخارجي
	            r.QuadWithHighAndTextureMainGround(Point(-45,0, 215), -450, 73.3, 1, a3,1);//41.6//-48

		        r.QuadWithHighAndTextureMainGround(Point(-45,0, -35), -200, 73.3, 1, a3,1);//41.6//-48//الحيط للكريدور
	            r.QuadWithHighAndTextureMainGround(Point(-45,0, 15), -200, 73.3, 1, a3,1);//41.6//-48
		        r.QuadWithHighAndTextureMainGround(Point(-295,0, -35), -200, 73.3, 1, a3,1);//41.6//-48الحيط للكيردور الداخلي
	            r.QuadWithHighAndTextureMainGround(Point(-295,0, 15), -200, 73.3, 1, a3,1);//41.6//-48
		        r.QuadWithHighAndTextureMainGround(Point(-494,0, -235), -1, 73.3, 450.6, house10,5);//41.6//-48//الحائط الخلفي
				r.QuadWithHighAndTextureMainGround(Point(-295,0, -235), -1, 73.3, 100.6, a3,5);//الحائط الامامي للغرفةاليمينية
				r.QuadWithHighAndTextureMainGround(Point(-295,0, 15), -1, 73.3, 50.6, a3,5);
	            r.QuadWithHighAndTextureMainGround(Point(-295,0, -85), -1, 73.3, 50.6, a3,5); //  الحائط الامامي للغرفةاليسارية
				r.QuadWithHighAndTextureMainGround(Point(-295,0, 115), -1, 73.3, 100.6, a3,5);
				r.QuadWithHighAndTextureMainGround(Point(-245,0, -235), -1, 73.3, 100.6, a3,5);//الحائط الخلفي للغرفةاليمينية
				r.QuadWithHighAndTextureMainGround(Point(-245,0, 15), -1, 73.3, 50.6, a3,5);
	            r.QuadWithHighAndTextureMainGround(Point(-245,0, -85), -1, 73.3, 50.6, a3,5); //  الحائط الخلفي للغرفةاليسارية
				r.QuadWithHighAndTextureMainGround(Point(-245,0, 115), -1, 73.3, 100.6, a3,5);
				r.QuadWithHighAndTextureMainGround(Point(-45,0, -235), 1, 73.3, 200.6, house10,1);//الحائط الامامي للغرفةالامامية
				r.QuadWithHighAndTextureMainGround(Point(-45,0, 15), 1, 73.3, 200.6, house10,1);
			r.QuadWithHighAndTextureMainGround(Point(-45,772, -235), -450, 2.3, 450.6, a3,1);//41.6//-48//السطح2
	    r.QuadWithHighAndTextureMainGround(Point(-45,72, -235), -450, 698.3, 450.6, house10,1);//41.6//-48//السطح2
	    r.QuadWithHighAndTextureMainGround(Point(-45,72, -235), -450, 1.3, 450.6, a3,5);//41.6//-48//السطح
		r.QuadWithHighAndTextureMainGround(Point(-45,0, -35), -450, 1.3, 50.7, a3,2);//41.6//-48//ارضية الكيرادور 

/////////////////////////////////////////////////////////////////////////////
	 
		
			r.QuadWithHighAndTextureMainGround(Point(330,-10,60+275),20,5,80, a1,1);//8
			r.QuadWithHighAndTextureMainGround(Point(330,-10,60+275+120),20,5,80, a1,1);//9
			r.QuadWithHighAndTextureMainGround(Point(330,-10,60+275+120+120),20,5,80, a1,1);//10
			r.QuadWithHighAndTextureMainGround(Point(330,-10,60+275+120+120+120),20,5,80, a1,1);//11

		 r.QuadWithHighAndTextureMainGround(Point(330,-10,-350-120),20,5,80, a1,1);//12
		 r.QuadWithHighAndTextureMainGround(Point(330,-10,-350-120-120),20,5,80, a1,1);//13
		 r.QuadWithHighAndTextureMainGround(Point(330,-10,-350-120-120-120),20,5,80, a1,1);//14
		 r.QuadWithHighAndTextureMainGround(Point(330,-10,-350-120-120-120-120),20,5,80, a1,1);//15
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   
	      // r.QuadWithHighAndTextureMainGround(Point(330,-10,60),20,5,240, a1,5);//5
	       r.QuadWithHighAndTextureMainGround(Point(330,-10,-350),20,5,260, a1,5);//6
	   	   r.QuadWithHighAndTextureMainGround(Point(330,-10,60),20,5,240, a1,5);//7

		 r.QuadWithHighAndTextureMainGround(Point(430,-10,-350-120-120-120-120),10,5,1600, a1,10);//16
		 r.QuadWithHighAndTextureMainGround(Point(450,-10,-350-120-120-120-120),10,5,1600, a1,10);//17
		 r.QuadWithHighAndTextureMainGround(Point(-635,-10,-350-120-120-120-120),5,5,1600, a1,10);//18
		 r.QuadWithHighAndTextureMainGround(Point(-625,-10,-350-120-120-120-120),5,5,1600, a1,10);//19

		 r.QuadWithHighAndTextureMainGround(Point(550,-10,-350-120-120-120-120-120-50),50,5,2000, a1,10);//20
		 r.QuadWithHighAndTextureMainGround(Point(-750,-10,-350-120-120-120-120-120-50),50,5,2000, a1,10);//21
		 r.QuadWithHighAndTextureMainGround(Point(-550,-10,-350-120-120-120-120),50,5,1600, a1,10);//22
		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		   r.QuadWithHighAndTextureMainGround(Point(0,-10,-100),350,5,10, a1,1);//1
	   r.QuadWithHighAndTextureMainGround(Point(0,-10,60),350,5,10, a1,1);//2
	   r.QuadWithHighAndTextureMainGround(Point(0,-10,-260),350,5,10, a1,1);//3
	   r.QuadWithHighAndTextureMainGround(Point(0,-10,210),350,5,10, a1,1);//4
		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,-350-120-120-120-120),900,5,40, a1,5);//23
		  		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,-350-120-120-120-120-85),900,5,5, a1,5);//24
		  		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,-350-120-120-120-120-95),900,5,5, a1,5);//25

				   r.QuadWithHighAndTextureMainGround(Point(-550,-10,750+95+20),900,5,5, a1,5);//26
		  		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,750+105+20),900,5,5, a1,5);//27

		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,+750),900,5,40, a1,5);//28
		  r.QuadWithHighAndTextureMainGround(Point(-550,-10,+750),900,5,40, a1,5);//

		  r.QuadWithHighAndTextureMainGround(Point(-750,-10,+970),1400,5,40, a1,5);//
		   r.QuadWithHighAndTextureMainGround(Point(-750,-10,-350-120-120-120-120-200),1400,5,40, a1,5);//
		   // drawSphereWithTexture(2.0f, 40, 30, fo, -74.0f, 13.0f, 30.0f);
		   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		 



		   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		   	waleed();
		ysef();
////////////////////////////////////////////			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			 r.QuadWithHighAndTextureMainGround(Point(-494,70.7,15), 198, 1, 202, skleft,1);
  r.QuadWithHighAndTextureMainGround(Point(-494,0,15), 198, 1, 202, a4,1);


    r.QuadWithHighAndTextureMainGround(Point(-295,0, 16), -200, 73.3, 1, area,1);
	    r.QuadWithHighAndTextureMainGround(Point(-295,0, 214), -200, 73.3, 1, area,1);
		r.QuadWithHighAndTextureMainGround(Point(-490,0, 13), -1, 73.3, 200.6,area ,5);
		 r.QuadWithHighAndTextureMainGround(Point(-490,1,29), 40, 60, 40.6, so1,1);
		 		 r.QuadWithHighAndTextureMainGround(Point(-490,1,70), 40, 60, 80.6, so1,1);
r.QuadWithHighAndTextureMainGround(Point(-450,1,190), 40, 60, 20.6, mo,1);
r.QuadWithHighAndTextureMainGround(Point(-410,1,190), 40, 60, 20.6, mo,1);
 r.QuadWithHighAndTextureMainGround(Point(-350,50,213), 20, 20, 1, hour,1);
   r.QuadWithHighAndTextureMainGround(Point(-319,0,180), 23, 50, 1, photo4,1);
    r.QuadWithHighAndTextureMainGround(Point(-350,0,180), 15, 50, 1, photo4,1);
	  r.QuadWithHighAndTextureMainGround(Point(-350,0,180), 1, 50, 35, photo4,1);
	    r.QuadWithHighAndTextureMainGround(Point(-299,0,180), 1, 50, 35, photo4,1);
		   r.QuadWithHighAndTextureMainGround(Point(-350,50,180), 53, 2, 35, img2,1);


		    r.QuadWithHighAndTextureMainGround(Point(-317,0,179), 20, 50, 1, photo3,1);


				    r.QuadWithHighAndTextureMainGround(Point(-490,6,160), 1, 60, 20, photo3,1);
					   r.QuadWithHighAndTextureMainGround(Point(-490,6,190), 1, 60, 20, photo3,1);

					
				    r.QuadWithHighAndTextureMainGround(Point(-350,66,160), 4, 4, 4, photo5,1);
					   r.QuadWithHighAndTextureMainGround(Point(-400,66,160), 4, 4, 4, photo5,1);

					       r.QuadWithHighAndTextureMainGround(Point(-350,66,190), 4, 4, 4, photo5,1);
					   r.QuadWithHighAndTextureMainGround(Point(-400,66,190), 4, 4, 4, photo5,1);

					          r.QuadWithHighAndTextureMainGround(Point(-350,66,100), 4, 4, 4, photo5,1);
					   r.QuadWithHighAndTextureMainGround(Point(-400,66,100), 4, 4, 4, photo5,1);

					   




					   r.QuadWithHighAndTextureMainGround(Point(-450,1,16), 40, 60, 20.6, mo,1);
r.QuadWithHighAndTextureMainGround(Point(-410,1,16), 40, 60, 20.6, mo,1);


 r.QuadWithHighAndTextureMainGround(Point(-370,0,190), 1, 61, 20, img2,1);
 r.QuadWithHighAndTextureMainGround(Point(-370,0,16), 1, 61, 20, img2,1);

  r.QuadWithHighAndTextureMainGround(Point(-295,61,60), 1, 10, 60, photo3,1);


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			glPopMatrix();
drawtrees();

}
////////////////////////////////////////////////////////////////////

int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0,-1);
	key();
     MyCamera.Render();
	 		Key(keys, 70.4);
					

	
	//Key(keys, 0.8);  
	sky::Draw_Skybox(0,-10,0,14000,14000,14000,skback,skfront,skleft,skback,skfront,skleft);
	wael();
	// رسم المتجر الثالث 
	glPushMatrix();
	glTranslated(25,0,-250);
	drawShop3();
		glPopMatrix();



	// رسم المتجر الثالث 

	 return true;
	
}
GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}
/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
