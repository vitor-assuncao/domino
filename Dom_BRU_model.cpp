//Dom_BRU_model.cpp
//Grupo Brumenau
//Vitor Assuncao
//Gabriel Souza
//David Miranda
//Pedro Henrique Saraiva

// usamos strucut para guardar informacoes das pecas
struct statusPecas
{

    char status;
    int Lado1;
    int Lado2;



} pecas[28], aux;

//struct para guardar irfomacoes da mesa
struct statusMesa
{

    char status;
    int Lado1;
    int Lado2;




} mesa[28];

int mesaP;
char z;
int Tamanhomesa;
int compra;
int empate;
int extD, extE;
int modojogo;
