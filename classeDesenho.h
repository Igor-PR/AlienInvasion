#ifndef Class_Desenho
#define Class_Desenho


#include "funcoes.h"

int Xmax = 100, Xmin = -100, Ymax = 80, Ymin = -100;

class Desenho {
protected:
	float posX;
	float posY;
	float movimento;
	Desenho *missil = NULL;
public:
 	virtual void movimenta() = 0; 
 	virtual void desenha() = 0;
 	// virtual void testaColisao();
 	virtual void resetMovimento() = 0;
 	Desenho* getMissil(){
 		return missil;
 	}
};

class Missil : public Desenho{
private:
	Desenho *pai = NULL;
public:	
	Missil(float X, float Y, Desenho *pai){
		this->posX = X;
		this->posY = Y;

		//Teste
		this->movimento = 1.0f;
		this->pai = pai;
	}
	void movimenta(){
		this->posY = this->posY + this->movimento;
	}
	void desenha(){
		glPushMatrix();
			glTranslatef(this->posX,this->posY,0.0f);

			desenhaEsfera(3.0f,20,20,1.0f,0.0f,0.0f);

		glPopMatrix();	
	}
	void resetMovimento(){
		//Teste
		this->movimento = 1.0f;
	}
};

class Nave : public Desenho
{
private:
	bool podeAtirar = true;
public:
	Nave(){
		this->posX = 0.0f;
		this->posY = Ymin + 10;

		//Teste
		this->movimento = -1.0f;
	}
	~Nave();
	void movimenta(){
		this->posX = this->posX + this->movimento;
	}
	void desenha(){
		glPushMatrix();
			glTranslatef(this->posX,this->posY,0.0f);

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
		glPopMatrix();	
		}
	void resetMovimento(){
		//Teste
		this->movimento = 0.0f;
	}

	void setMovimento(float movimento){
		this->movimento = movimento;
	}

	// Desenho getMissil(){
	// 	return this->missil;
	// }

	void atiraMissil(){

		if (this->podeAtirar)
		{
			this->missil = new Missil(this->posX,this->posY + 2,this);
			this->podeAtirar = false;
		}

	}
};

class Alien : public Desenho
{
public:
	Alien(){
		this->posX = 0.0f;
		this->posY = Ymax - 10;

		//Teste
		this->movimento = 1.0f;
	}
	~Alien();
	void movimenta(){
		this->posX = this->posX + this->movimento;
	}
	void desenha(){
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
	void resetMovimento(){
		//Teste
		this->movimento = 0.0f;
	}
};




#endif