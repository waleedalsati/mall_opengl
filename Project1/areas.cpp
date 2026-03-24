#include "areas.h"
#include "houses.h"
#include "texture.h"
//#include "Wall.h"
//#include "Point.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>
//#include "Shapes.h"
  

void areas::drawarea(int x, int z, GLint texture, float h, float w) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3d(-x, 0, -z);

    glTexCoord2f(1 * h, 0);
    glVertex3d(x, 0, -z);

    glTexCoord2f(1 * h, 1 * w);
    glVertex3d(x, 0, z);

    glTexCoord2f(0, 1 * w);
    glVertex3d(-x, 0, z);

    glEnd();
}

void areas::drawareatoqibli(int x,int z ,int texture,float wrapt,float wraps ){

	 glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3d(0, 0, 0);

    glTexCoord2f(1 * wrapt, 0);
    glVertex3d(x, 0, 0);

    glTexCoord2f(1 * wrapt, 1 * wraps);
    glVertex3d(x, 0, z);

    glTexCoord2f(0, 1 * wraps);
    glVertex3d(0, 0, z);

    glEnd();

}
