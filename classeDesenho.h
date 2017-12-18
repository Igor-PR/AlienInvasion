#ifndef Class_Desenho
#define Class_Desenho

#include <stdio.h>
#include <iostream>

#include <cstdlib>

#include "funcoes.h"


class Desenho {
public:
	float posX;
	float posY;
	float movimento;
	Desenho *missil = NULL;
	bool podeAtirar = true;
public:
 	virtual void movimenta() = 0;
 	virtual void desenha() = 0;
 	// virtual void testaColisao();
 	virtual void resetMovimento() = 0;

 	Desenho* getMissil(){
 		return missil;
 	}

 	void deletaMissil(){
 		// delete this->missil;
 		this->missil = NULL;
 	}

 	void resetAtirar(){
 		this->podeAtirar = true;
 	}
};

class Missil : public Desenho{
protected:
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
		if (movimentoEPoissvel('Y',this->posY,this->movimento))
			this->posY = this->posY + this->movimento;
		else{
			this->pai->resetAtirar();
			this->pai->deletaMissil();
		}

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

class MissilJogador : public Missil{
public:
	MissilJogador(float X, float Y, Desenho *pai):Missil(X,Y,pai)
	{}
};

class MissilAlien : public Missil{
public:
	MissilAlien(float X, float Y, Desenho *pai):Missil(X,Y,pai){
		// this->posX = X;
		// this->posY = Y;
		this->movimento = -1.0f;
		// this->pai = pai;
	}
	void desenha(){
		glPushMatrix();
			glTranslatef(this->posX,this->posY,0.0f);

			desenhaEsfera(3.0f,20,20,0.0f,1.0f,0.0f);

		glPopMatrix();
	}
	void resetMovimento(){
		this->movimento = -1.0f;
	}
};

class Nave : public Desenho
{
public:
	Nave(){
		this->posX = 0.0f;
		this->posY = Ymin + 10;

		//Teste
		this->movimento = -1.0f;
	}
	~Nave();
	void movimenta(){
		if (movimentoEPoissvel('X',this->posX,this->movimento))
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

	void atiraMissil(){

		if (this->podeAtirar)
		{
			this->missil = new MissilJogador(this->posX,this->posY + 2,this);
			this->podeAtirar = false;
		}

	}
};

class Alien : public Desenho
{
private:
	int countAtiraMissil;
public:
	Alien(int offset){
		this->posX = (Xmin + 20) + (offset * BASE_OFFSET);
		this->posY = Ymax - 10;

		//Teste
		this->movimento = 0.0f;
		this->resetCountMissil();
	}
	~Alien();
	void movimenta(){
		if (movimentoEPoissvel('X',this->posX,this->movimento))
			this->posX = this->posX + this->movimento;
		if (this->countAtiraMissil <= 0)
			this->atiraMissil();

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

		int acao = rand() % 3;

		// std::cout<< "Acao" << acao << "POS:" <<this->posX << "-" << this->posY << "\n"<<std::flush;
		switch(acao){

			case 0:
				if(this->podeAtirar)
					this->countAtiraMissil -= 1;
				// acao = rand() % 3;
				this->movimento = 0.0f;
				break;
			case 1:
				this->movimento = 1.0f;
				break;
			case 2:
				this->movimento = -1.0f;
				break;
			default:
				this->movimento = 0.0f;
				break;
		}
	}
	void atiraMissil(){

		if (this->podeAtirar)
		{
			this->missil = new MissilAlien(this->posX,this->posY - 2,this);
			this->podeAtirar = false;
			this->resetCountMissil();
		}

	}

	void resetCountMissil(){
		this->countAtiraMissil = 20;
	}
};




#endif
