#include "O3DS.h"
#include <GL/glut.h>


void O3DS::draw_points(){
    glBegin(GL_POINTS);

	for(int i = 0; i < vertices.size(); i++){
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();
}
