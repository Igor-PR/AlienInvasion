#ifndef Class_Desenho
#define Class_Desenho

class Desenho {
protected:
	float posX;
	float posY;
	float movimento;	
public:
 	virtual void movimenta() = 0; 
 	virtual void desenha() = 0;
 	// virtual void testaColisao();
 	virtual void resetMovimento() = 0;
};

class Nave : public Desenho
{
public:
	Nave(){
		this->posX = 0.0f;
		this->posY = 0.0f;

		//Teste
		this->movimento = -1.0f;
	}
	~Nave();
	void movimenta(){
		this->posY + this->movimento;
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
		this->movimento = -1.0f;
	}
};

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
	void movimenta(){
		this->posY + this->movimento;
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
		this->movimento = 1.0f;
	}
};

#endif