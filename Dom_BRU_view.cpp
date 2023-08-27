//Dom_BRU_view.cpp
//Grupo Brumenau
//Vitor Assuncao
//Gabriel Souza
//David Miranda
//Pedro Henrique Saraiva

#include "Dom_BRU_view.h"
#include <stdio.h>
#include <iostream>


int menuinicial()
{
    int op;

    //apresenta o menu do jogo
    printf("\n       BRUMENAU'S DOMINO GAME\n ");
    printf("-----------------------------------------------\n");
    printf("|1 - Iniciar jogo (2 jogadores)                |\n");
    printf("|2 - Iniciar jogo (computador vira jogador 2)  |\n");
    printf("|3 - Retornar ao jogo interrompido             |\n");
    printf("|4 - Regras gerais do jogo                     |\n");
    printf("|5 - Salvar o jogo                             |\n");
    printf("|6 - Recuperar o jogo salvo                    |\n");
    printf("|0 - Sair                                      |\n");
    printf("------------------------------------------------\n");
    printf("\nDigite a sua opcao: ");

    scanf("%d", &op);

    printf("\n");

    return(op);



}


void apresentaPeca()
{

    int k, u;


    //printf("Jogador 1: ");
    for(k = 0; k < 28; k++)
    {
        if(pecas[k].status == '1')
        {

            printf("A: [%d|%d]    ", pecas[k].Lado1, pecas[k].Lado2);
        }

        printf("\n");

        if (pecas[k].status == '2')
        {
            printf("B: [%d|%d]      ", pecas[k].Lado1, pecas[k].Lado2);
        }

    }

    printf("\n");



}

void maiorPeca(){
	
	printf("MAIOR PECA:[%d/%d] -> ",aux.Lado1,aux.Lado2);
	
}

void pecasJg1(){
	
	printf("Jogador 1  \n");
	
}

void pecasJg2(){
	
	printf("Jogador 2  \n");
	
}



void desenhoMesa(){
	printf("=");
}

void Mesa(){
	
	printf("MESA");

}

void pecasjogo(){
	
	int i;
	
	printf("[%d/%d] ",mesa[i].Lado1, mesa[i].Lado2);
	
}

void vezJg1(){
	
	printf("--------VEZ DO JOGADOR 1--------\n\n");
	
}

void vezJg2(){
	
	printf("--------VEZ DO JOGADOR 2--------\n\n");
	
}

void pecasEscrito(){
	
	 printf("PECAS:  ");
	
}

void msgPossivel(){
	
	printf("PECA PODE SER JOGADA\n");

}

void msgladoErrado(){
	
	printf("Lado escolhido e impossivel.\n");
	
}

void opcaoErrada(){
	
	printf("Opcao invalida de lado na mesa\n");
	
}

void numeroErrado(){
	
	printf("Peca com numero errada\n");
	
}

void vazio(){
	
	printf("Nao ha mais pecas para comprar\n");
	
}

void passaravez(){
	
	printf("PASSOU A VEZ\n");
	
}

void aindada(){

	printf("Ainda ha pecas para serem compradas ou jogadas\n");

}

void opcaoInvalida(){

	printf("Opcao Invalida!\n");

}

void partidaacabou(){
	
	printf("A partida acabou (sem mais jogadas)\n");
	
}

void contaPontos(){
	
	printf("Pela contagem dos pontos\n");
	
}

void jg1ganhou(){
	
	   
        printf("\n-------------------------------------\n");
        printf("|              vencedor             |\n");
        printf("|              JOGADOR 1            |\n");
        printf("-------------------------------------\n");
        system("pause");
        
}

void jg2ganhou(){
	
	    
        printf("\n-------------------------------------\n");
        printf("|              vencedor             |\n");
        printf("|              JOGADOR 2            |\n");
        printf("-------------------------------------\n");
        system("pause");
        
}

void interrompeJogo(){
	
	printf("jogo interrompido\n");

}

void empateJogo(){
	
	printf("Empate (jogadores tem o mesmo numero de pecas e somatorias)\n");
	
}
//indica vez de jogador
void pecaDiff(struct statusPecas pecas[28], char z ){
	
	int i, loc;
	loc = 1;
	if(z=='1') 
	{
		printf("--------VEZ DO JOGADOR 1--------\n\n");
	}
	else 
	{
		printf("--------VEZ DO JOGADOR 2--------\n\n");
	}
	printf("PECAS: ");
	for(i = 0; i < 28; i++) 
	{
		if(pecas[i].status == z) 
		{
			printf("%d.[%d|%d]\t",loc , pecas[i].Lado1, pecas[i].Lado2);
			loc++;
		}
	}
	printf("\n");
	
}



void pecasimpressas(struct statusMesa mesa[28], int i){
	
	
	printf("[%d/%d] ",mesa[i].Lado1, mesa[i].Lado2);
		
	
}
int escolhapeca(int loc){

{
	int op;
	printf("Escolha a peca para jogar (0 para desistir): \n");
	scanf("%d",&op);
	return op;
}

}

int menuJogo(int test, int extE, int extD){
	
	int op, saida;
	
		printf("\n---------------------------------------------\n");	
		printf("|J - Jogar (possiveis %d ou %d)               |\n",extE,extD);
		printf("|C - Comprar                                |\n");
		printf("|P - Passar                                 |\n");
		printf("|S - Sair (interrorper o jogo)              |\n");
		printf("---------------------------------------------\n");
		printf("\nDigite a sua opcao: ");
	
	scanf("%s", &op);
	
	if(op == 'j'  || op == 'J')
	{
		saida = 1;
	}
	if(op == 'c' || op == 'C')
	{
		saida =2;
	}
	if(op == 's' || op == 'S')
	{
		saida =3;
	}
	if(op =='p' || op == 'P')
	{
		saida =4;
	}
	if(op != 'j' && op!= 'J' && op != 'c' && op != 'C' && op != 'p' && op != 'P' && op != 's' && op != 'S')
	{
		saida = 5;
	}
	return saida;
	

}

int escolherLado(int lado){
	
	char op;
	int saida;
	
	
	printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D): ");
	scanf("%s",&op);
	
	if(op == 'e'|| op == 'E' )
	{
		saida = 1;
	}
	if(op == 'd'|| op == 'D' )
	{
		saida = 2;
	}
	if(op != 'e' && op != 'E' && op != 'd' && op != 'D' )
	{
		saida = 3;
	}
	
	return saida;
	
}

void novalinha()
{
	printf("\n");
}

void arqpecanabre(){
	printf("\narquivo ARQpecas não pode ser aberto para salvar");
}

void erroarqpecasalvamento(){
	printf("\nerro no salvamento do ARQpecas");
}

void arqmesanabre(){
	printf("\narquivo ARQmesa não pode ser aberto para salvar");
}

void erroarqmesalvamento(){
	printf("\nerro no salvamento do ARQmesa");
}

void arqjognabre(){
	printf("\narquivo ARQjog não pode ser aberto para salvar");
}

void erroarqjogsalvamento(){
	printf("\nerro no salvamento do ARQjog");
}

void arqmesapnabre(){
	printf("\narquivo ARQmesap não pode ser aberto para salvar");
}

void erroarqmesapsalvamento(){
	printf("\nerro no salvamento do ARQmesap");
}

void arqtmesanabre(){
	printf("\narquivo ARQTmesa não pode ser aberto para salvar");
}

void erroarqtmesasalvamento(){
	printf("\nerro no salvamento do ARQTmesa");
}

void arqtcompranabre(){
	printf("\narquivo ARQTcompr não pode ser aberto para salvar");
}

void erroarqtcompralvamento(){
	printf("\nerro no salvamento do ARQTcompr");
}

void arqempatenabre(){
	printf("\narquivo ARQempate não pode ser aberto para salvar");
}

void erroarqempatesalvamento(){
	printf("\nerro no salvamento do ARQempate");
}

void arqmesapnabre2(){
	printf("\narquivo ARQmesap não pode ser aberto para carregar");
}

void erroarqmesapcarregamento(){
	printf("\nerro no carregamento do ARQmesap");
}

void arqpecasnabre2(){
	printf("\narquivo ARQpecas não pode ser aberto para carregar");
}

void erroarqpecascarregamento(){
	printf("\nerro no carregamento do ARQpecas");
}

void arqmesanabre2(){
	printf("\narquivo ARQmesa não pode ser aberto para carregar");
}

void erroarqmesacarregamento(){
	printf("\nerro no carregamento do ARQmesa");
}

void arqjognabre2(){
	printf("\narquivo ARQjog não pode ser aberto para carregar");
}

void erroarqjogcarregamento(){
	printf("\nerro no carregamento do ARQjog");
}

void arqtmesanabre2(){
	printf("\narquivo ARQTmesa não pode ser aberto para carregar");
}

void erroarqtmesacarregamento(){
	printf("\nerro no carregamento do ARQTmesa");
}
	
	void arqtcomprnabre2()
	{
	printf("\narquivo ARQTcompr não pode ser aberto para carregar");
}

void erroarqtcomprcarregamento()
{
	printf("\nerro no carregamento do ARQTcompr");
}

	void arqempoatenabre2(){
	printf("\narquivo ARQTcompr não pode ser aberto para carregar");
}

void erroarqempatearregamento(){
	printf("\nerro no carregamento do ARQTcompr");
}
void jogosalvo(){
	printf("\njogo salvo");
}

void errojgsalvo()
{
	printf("\nerro ao salvar o jogo");
}

void jogocarregado()
{
	printf("\njogo carregado");
}

void errojgcarregado()
{
	printf("\nerro ao carregar o jogo");
}
void semjogo()
{
	printf("\nnao comecou nenhum jogo");
	printf("\npara ser carregado");
	
}

void maquinajogou()
{
	printf("\nmaquina jogou a peca \n");
}

void maquinacomprou()
{
	printf("\nmaquina comprou uma peca\n");
}

void maquinapassou()
{
	printf("\nmaquina passou a vez\n");
}

void regras()
{
	printf("\nO domino e jogado com 28 pecas com dois lados variando de 0 a 6");
	printf("\ncada jogador comeca com 7 pecas e aquele q tiver a maior peca sai jogando");
	printf("\no objetivo do jogo e jogar todas as suas pecas na mesa");
	printf("\naquele que tiver menos pecas ou mais pontos vence ao final do jogo");
}
