#include "classeDesenho.h"

class Desenho {
private:
	float posX;
	float posY;
	float movimento;	
public:
 	virtual void movimenta(); 
 	virtual void desenha();
 	// virtual void testaColisao();
 	virtual void resetMovimento();
};