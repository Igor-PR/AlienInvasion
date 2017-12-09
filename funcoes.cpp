#include <GL/glut.h>
#include "funcoes.h"

void desenhaEsfera(float raio,int param1, int param2, float paramCor1,float paramCor2,float paramCor3){
	glColor3f(paramCor1,paramCor2,paramCor3);
	glutSolidSphere(raio, param1, param2);
}

void DesenhaEixos(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(20.0f,0.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,20.0f,0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,20.0f);
	glEnd();
}
