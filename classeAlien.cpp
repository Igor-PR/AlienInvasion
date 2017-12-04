#include "classeDesenho.h"

class Alien : public Desenho
{
public:
	Alien(){
		this->posX = 0.0f;
		this->posY = 20.0f;

		//Teste
		this->movimento = 1.0f;
	}
	~Alien();
	movimenta(){
		this->posY + this->movimento;
	}
	desenha(){
		glPushMatrix();
			glTranslatef(this->posX,this->posY,0.0f);

			glPushMatrix();
				glColor3f(0.502f, 0.502f, 0.0f);
				glScalef(1.0f,1.0f,0.25f);
				glutSolidCube(9.0f);
			glPopMatrix();	
			
			desenhaEsfera(5.0f,20,20,0.196f, 0.804f, 0.196f);

		glPopMatrix();	
	}
	resetMovimento(){
		//Teste
		this->movimento = 1.0f;
	}
};