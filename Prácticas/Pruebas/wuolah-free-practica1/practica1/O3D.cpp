#include "O3D.h"
#include <GL/glut.h>

void O3D::draw_lines(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        for(int i = 0; i < triangles.size(); i++){
			glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z),
            glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z),
            glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
		}
		
	glEnd();
}

void O3D::draw_fill(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
            glColor3f(1,0,0);
            for(int i = 0; i < triangles.size(); i++){
                glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z),
                glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z),
                glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
            }

    glEnd();
}


void O3D::draw_chess(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
		
			for(int i = 0; i < triangles.size(); i++){
                if(i%2==0)
					glColor3f(1,0,0);
                else
                    glColor3f(0,1,0);
                glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z),
                glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z),
                glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
			}
		
	glEnd();
}


