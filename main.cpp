// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

// #include <stdlib.h>
// #include <iostream>
#include <unistd.h>

#include <GL/glut.h>
#include "classeDesenho.h"
#include "funcoes.h"


GLfloat angle, fAspect;

Nave *nave = new Nave();

Desenho *aliens[NUM_ALIENS];

const unsigned int sleepTime = 5000; //Micro segundos
// Desenho *alien =  new Alien();


void Controles(unsigned char tecla, int mouseX, int mouseY){

	switch(tecla){
		case(' '):
			nave->atiraMissil();
			break;
		case('a'):
			nave->setMovimento(-1.0f);
			break;
		case('d'):
			nave->setMovimento(1.0f);
			break;
	}

}

void UpdateFrame(Desenho *d){

	d->movimenta();
	d->desenha();
	d->resetMovimento();
	if (d->getMissil() != NULL)
	{
		d->getMissil()->testaColisao(aliens,nave);
		UpdateFrame(d->getMissil());
	}

}



// Função callback chamada para fazer o desenho
void Desenha(void)
{
	bool fimJogo = true;

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	UpdateFrame(nave);
	// usleep(sleepTime);
	for (int i = 0; i < NUM_ALIENS; ++i)
	{
		if (aliens[i] != NULL)
		{
			UpdateFrame(aliens[i]);
			// usleep(sleepTime);
			fimJogo = false;
		}
		
	}

	if(fimJogo)
		throw std::exception();
	

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}



// Programa Principal
int main(int argc, char** argv)
{
	for (int i = 0; i < NUM_ALIENS; ++i)
	{	
		aliens[i] = new Alien(i);
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Alien Invasion");
	try{
		glutDisplayFunc(Desenha);
		glutIdleFunc(Desenha);
	}
	catch (std::exception& e){
		return 0;
	}

	glutKeyboardFunc(Controles);
    glutReshapeFunc(AlteraTamanhoJanela);


	Inicializa();
	glutMainLoop();
}
