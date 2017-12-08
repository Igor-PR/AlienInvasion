#include <GL/glut.h>
#include "funcoes.h"

void desenhaEsfera(float raio,int param1, int param2, float paramCor1,float paramCor2,float paramCor3){
	glColor3f(paramCor1,paramCor2,paramCor3);
	glutSolidSphere(raio, param1, param2);
}
