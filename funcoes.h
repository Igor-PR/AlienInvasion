#define Xmax 100 
#define Xmin -100
#define Ymax 80
#define Ymin -100

#define NUM_ALIENS 6
#define BASE_OFFSET 30



void desenhaEsfera(float raio,int param1, int param2, float paramCor1,float paramCor2,float paramCor3);
void DesenhaEixos(void);
bool movimentoEPoissvel(char plano,float posAtual,float movimento);
