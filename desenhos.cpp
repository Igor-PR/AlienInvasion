#include "desenhos.h"


void desenhaEsfera(float raio,int param1, int param2, float paramCor1,float paramCor2,float paramCor3){
	glColor3f(paramCor1,paramCor2,paramCor3);
	glutSolidSphere(raio, param1, param2);
}

void desenhaNave(){
	
	glPushMatrix();
		glColor3f(0.439f, 0.502f, 0.565f);
		glScalef(1.0f,1.0f,0.25f);
		glutSolidCube(10.0f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f,5.0f,0.0f);
		desenhaEsfera(2.5f,20,20,0.255f, 0.412f, 0.882f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.0f,5.0f,0.0f);
		desenhaEsfera(2.5f,20,20,0.255f, 0.412f, 0.882f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.0f,-5.0f,0.0f);
		desenhaEsfera(2.5f,20,20,0.255f, 0.412f, 0.882f);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f,-5.0f,0.0f);
		desenhaEsfera(2.5f,20,20,0.255f, 0.412f, 0.882f);
	glPopMatrix();	
}


void desenhaAlien(){

	glPushMatrix();
		glColor3f(0.502f, 0.502f, 0.0f);
		glScalef(1.0f,1.0f,0.25f);
		glutSolidCube(9.0f);
	glPopMatrix();	
	
	desenhaEsfera(5.0f,20,20,0.196f, 0.804f, 0.196f);

}

void desenhaMissil(){

	desenhaEsfera(3.0f,20,20,1.0f,0.0f,0.0f);

}
// glRotatef(-80.0f,0.0f,0.0f,1.0f);