//Dom_BRU_controller.cpp
//Grupo Brumenau
//Vitor Assuncao
//Gabriel Souza
//David Miranda
//Pedro Henrique Saraiva

#include "Dom_BRU_controller.h"
#include "Dom_BRU_view.cpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void controller()
{
    int op;
    int i, k;
    int teste;
    do
    {
        op = menuinicial();

        switch (op)
        {
        case 1:
            modojogo = 1;
            iniciarJogo();

            break;

        case 2:
			modojogo = 2;
			contramaquina();
			break;
        case 3:
            if (modojogo == 1)
            {
			continuar();
			}
			if  (modojogo == 2)
			{
			continuarmaquina();
			}
			if  (modojogo != 1 && modojogo != 2 )
			
			break;
        case 4:
            break;
        case 5:
           salvajogo();
		  teste = salvajogo();
           if(teste==0)
           {
           	jogosalvo();
		   }
		   else
		   {
		   	errojgsalvo();
		   }
		   
		    break;
        case 6:
            carregajogo();
            teste = carregajogo();
			if(teste==0)
           {
           	jogocarregado();
		   }
		   else
		   {
		   	errojgcarregado();
		   }
		   
			break;
        case 0:
            break;

        default:
            break;
        }


    }
    while(op!=0);


}

//gera as pecas do jogo
void gerarpeca()
{


    int i, j, k=0;

    for (i=0; i<=6; i++)
    {
        for (j=i; j<=6; j++)
        {
            pecas[k].Lado1 = i;
            pecas[k].Lado2 = j;
            k++;
        }
    }
}

//esta funcao para embaralhas as pecas
void embaralhapeca()
{

    int i, k;
    struct statusPecas aux;

    gerarpeca();

    
    srand(time(NULL));


    //loop para impedir repeticao
    for (i=0; i<28; i++)
    {
        k=rand()%28;
        aux=pecas[i];
        pecas[i]=pecas[k];
        pecas[k]=aux;
    }


}

//funcao onde ocorre o jogo
void iniciarJogo()
{


    int i, k, u,x,loc,cont,cont2,final,N,lado, teste1;
    int esc;
    char test;
    

    aux.status = ' ';
    aux.Lado1 = 0;
    aux.Lado2 = 1;
    compra=13;
    mesaP=1;
    lado=0;
    empate=0;
    Tamanhomesa=5;
    for(i = 0; i <28; i++)
    {
        pecas[i].status = ' ';
    }

    embaralhapeca();

    for(i = 0; i <= 6; i++)
    {
        pecas[i].status = '1';
    }

    for(i = 7; i <= 13; i++)
    {
        pecas[i].status = '2';
    }

    

    for(i=0; i<=13; i++)
    {
        if(pecas[i].Lado1 == pecas[i].Lado2)
        {
            if(aux.Lado1 <= pecas[i].Lado1)
            {
                aux = pecas[i];
                u = i;
            }
            else
            {

                if(aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
                {
                    if(aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2 )
                    {
                        aux = pecas[i];
                        u = i;
                    }
                }

            }
        }
    }
    Tamanhomesa = Tamanhomesa+7;
    maiorPeca();
    if(pecas[u].status == '1')
    {
        pecasJg1();
    }
    else
    {
        pecasJg2();
    }
    
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    extE = mesa[0].Lado1;
    extD = mesa[0].Lado2;

    if(pecas[u].status=='1')
    {
        z='2';
    }
    else
    {
        z='1';
    }
    pecas[u].status = 'm';

    do
    {
        i=0;

        do
        {
            desenhoMesa();
            i++;
        }
        while(Tamanhomesa-1 != i);
        
        i=0;
        novalinha();
       Mesa();
       
        do
        {

            pecasimpressas(mesa, i);
            i++;
        }
        while(i<mesaP);
        novalinha();

        i=0;
        do
        {
            desenhoMesa();
            i++;
        }
        while(Tamanhomesa-1 != i);

        i=0;
        novalinha();
        novalinha();
        
   
        pecaDiff(pecas, z);


		teste1 = menuJogo(teste1, extE, extD);

        cont=0;
        switch (teste1)
        {
        case 1:
        	
        	loc = escolhapeca(loc);

            if(loc==0)
            {
                break;
            }
			else
            for(i=0; i<27; i++)
            {
                if(pecas[i].status==z)
                {
                    cont++;
                }
                if(cont==loc)
                {
                    if(pecas[i].Lado1 == extE || pecas[i].Lado1 ==extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                    {
                        msgPossivel();
                        empate=0;
                        if((((pecas[i].Lado1 == extE ||  pecas[i].Lado1 ==extD ) && (pecas[i].Lado2==extE || pecas[i].Lado2==extD))&& pecas[i].Lado1 != pecas[i].Lado2)|| extE == extD)
                        {
                        	
                        	
							
                            lado = escolherLado(lado);

                            if(lado==1)
                            {
                                if(pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                {

                                    for(N=mesaP; N>=0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N-1].Lado1;
                                        mesa[N].Lado2 = mesa[N-1].Lado2;
                                    }
                                    if(pecas[i].Lado1==extE)
                                    {
                                        mesa[0].Lado1 = pecas[i].Lado2 ;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mesaP++;
                                        extE=mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if(z=='1')
                                        {
                                            z='2';
                                        }
                                        else 
                                        {
                                            z='1';
                                        }
                                        Tamanhomesa = Tamanhomesa+6;
                                        break;
                                    }
                                    else 
									if(pecas[i].Lado2==extE)
                                    {
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mesaP++;
                                        extE=mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if(z=='1')
                                        {
                                            z='2';
                                        }
                                        else
                                        {
                                            z='1';
                                        }
                                        Tamanhomesa = Tamanhomesa+6;
                                        break;
                                    }
                                    else
                                    {
                                	msgladoErrado();
                                    }

                                }
                                
                                

                            }
                            if(lado==2 )
                            {

                                if(pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                {
                                    if(pecas[i].Lado1 == extD)
                                    {
                                        mesa[mesaP].Lado1=pecas[i].Lado1;
                                        mesa[mesaP].Lado2=pecas[i].Lado2;
                                        extD=mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if(z=='1')
                                        {
                                            z='2';
                                        }
                                        else
                                        {
                                            z='1';
                                        }
                                        Tamanhomesa = Tamanhomesa+6;
                                        break;
                                        
                                    }
                                    else 
									if(pecas[i].Lado2 == extD)
                                    {
                                        mesa[mesaP].Lado1=pecas[i].Lado2;
                                        mesa[mesaP].Lado2=pecas[i].Lado1;
                                        extD=mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if(z=='1')
                                        {
                                            z='2';
                                        }
                                        else
                                        {
                                            z='1';
                                        }
                                        Tamanhomesa = Tamanhomesa+6;
                                        break;
                                    }
								    else msgladoErrado();
                                    }
                            }
                            if(lado == 3)
                            {
                                
                                
                                    opcaoErrada();
                            }
                            
                         
                        }
                        else
                        {
                            if(pecas[i].Lado1==extE)
                            {
                                for(N=mesaP; N>=0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N-1].Lado1;
                                    mesa[N].Lado2 = mesa[N-1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2 ;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mesaP++;
                                extE=mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if(z=='1')
                                {
                                    z='2';
                                }
                                else
                                {
                                    z='1';
                                }
                                Tamanhomesa = Tamanhomesa+6;
                                break;
                            }
                            else 
							if(pecas[i].Lado2==extE)
                            {
                                for(N=mesaP; N>=0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N-1].Lado1;
                                    mesa[N].Lado2 = mesa[N-1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mesaP++;
                                extE=mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if(z=='1')
                                {
                                    z='2';
                                }
                                else
                                {
                                    z='1';
                                }
                                Tamanhomesa = Tamanhomesa+6;
                                break;
                            }
                            else 
							if(pecas[i].Lado1 == extD)
                            {
                                mesa[mesaP].Lado1=pecas[i].Lado1;
                                mesa[mesaP].Lado2=pecas[i].Lado2;
                                extD=mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if(z=='1')
                                {
                                    z='2';
                                }
                                else
                                {
                                    z='1';
                                }
                                Tamanhomesa = Tamanhomesa+6;
                                break;
                            }
                            else 
							if(pecas[i].Lado2 == extD)
                            {
                                mesa[mesaP].Lado1=pecas[i].Lado2;
                                mesa[mesaP].Lado2=pecas[i].Lado1;
                                extD=mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if(z=='1')
                                {
                                    z='2';
                                }
                                else
                                {
                                    z='1';
                                }
                                Tamanhomesa = Tamanhomesa+6;
                               break;
                            }


                        }

                    }
                    else
                    {
                        numeroErrado();
                        
                        break;
                    }


                }
            }
            if(cont<loc)
              {
                 opcaoInvalida();	
			  }
            
			
            break;

        case 2:
        



            if(compra==27)
            {

                vazio();
            }
            else
            {


                compra++;
                pecas[compra].status=z;


            }


            break;
        case 4:
        
            cont=0;
            if(compra==27 )
            {
                for(i=0; i<27; i++)
                {

                    if(pecas[i].status == z)
                    {
                        if(pecas[i].Lado1 == extE || pecas[i].Lado1 ==extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            cont++;
                        }
                    }
                }
                if( cont == 0)
                {
                    passaravez();
                    empate++;
                    if(z=='1')
                    {
                        z='2';
                    }
                    else
                    {
                        z='1';
                    }

                }
                else
                {
                    aindada();
                }
            }
            else
            {
               
                aindada();
            }
            break;


        case 3:
        

            final=3;
            teste1 = 3;
            break;

        default:

            opcaoInvalida();
            break;

        }
        

        cont=0;
        cont2=0;

        if(empate == 2)
        {
            for(i=0; i<27; i++)
            {
                if(pecas[i].status=='1')
                {
                    cont++;
                }
                if(pecas[i].status=='2')
                {
                    cont2++;
                }
            }
            if(cont<cont2)
            {
                final=1;
                teste1 = 3;
                partidaacabou();
                contaPontos();
            }
            if(cont2<cont)
            {
                final=2;
                teste1 = 3;
                partidaacabou();
                contaPontos();
            }
            if(cont==cont2)
            {
                cont=0;
                cont2=0;

                for(i=0; i<27; i++)
                {
                    if(pecas[i].status=='1')
                    {
                        cont = cont + pecas[i].Lado1;
                        cont = cont + pecas[i].Lado2;
                    }
                    if(pecas[i].status=='2')
                    {
                        cont2 = cont2 + pecas[i].Lado1;
                        cont2 = cont2 + pecas[i].Lado2;
                    }
                }
                if(cont<cont2)
                {
                    final=1;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if(cont2<cont)
                {
                    final=2;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if(cont==cont2)
                {
                    final=4;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }

            }
        }

        cont=0;
        cont2=0;
        for(i=0; i<28; i++)
        {
            if (pecas[i].status =='1')
            {
                cont++;
            }
            if(pecas[i].status == '2')
            {
                cont2++;
            }
        }

        if(cont==0 && compra==27)
        {
            final=1;
            teste1 = 3;
        }
        if(cont2==0 && compra==27)
        {
            final=2;
            teste1 = 3;
        }
    }
    while (teste1 != 3 );

    if(final==1)
    {
       jg1ganhou();
    }
    if(final==2)
    {
    	jg2ganhou();
    }
    if(final==3)
    {
        interrompeJogo();
    }
    if(final==4)
    {
        empateJogo();
    }
}
//funcao para salvar o jogo
int salvajogo()
{
	int i;
	
	FILE *fp;
	if( (fp= fopen("ARQPecas", "w")) == NULL)      
	{
		 arqpecanabre();
		return 1;   
	}

	
		for(i = 0; i < 28; i++)
		{
			if(fwrite(&pecas[i], sizeof(struct statusPecas), 1, fp)  != 1)
			{
				erroarqpecasalvamento();
				break;
			}
		}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQMesa", "w")) == NULL)      
	{
		arqmesanabre();
		return 1;   
	}
	
	for(i = 0; i < mesaP; i++)
		{
			if(fwrite(&mesa[i], sizeof(struct statusMesa), 1, fp)  != 1)
			{
				erroarqmesalvamento();
				break;
			}
		}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQJog", "w")) == NULL)      
	{
		arqjognabre();
		return 1;   
	}
	
	if(fwrite(&z, sizeof(z), 1, fp)  != 1)
	{
		erroarqjogsalvamento();
        return 1;
	}
		
	fclose(fp);
	
	
	if( (fp= fopen("ARQmesaP", "w")) == NULL)      
	{
		arqmesapnabre();
		return 1;   
	}

	if(fwrite(&mesaP, sizeof(mesaP), 1, fp)  != 1)
	{
		erroarqmesapsalvamento();
        return 1;
	}
		
	fclose(fp);
	
	
	if( (fp= fopen("ARQTmesa", "w")) == NULL)      
	{
		arqtmesanabre();
		return 1;   
	}

	if(fwrite(&Tamanhomesa, sizeof(Tamanhomesa), 1, fp)  != 1)
	{
		erroarqtmesasalvamento();
        return 1;
	}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQTcompr", "w")) == NULL)     
	{
	    arqtcompranabre();
		return 1;   
	}

	if(fwrite(&compra, sizeof(compra), 1, fp)  != 1)
	{
		erroarqtcompralvamento();
        return 1;
	}
	fclose(fp);
	
	
	if( (fp= fopen("ARQempate", "w")) == NULL)     
	{
		arqempatenabre();
		return 1;   
	}

	if(fwrite(&empate, sizeof(empate), 1, fp)  != 1)
	{
		erroarqempatesalvamento();
        return 1;
	}
	fclose(fp);
	
	return 0;
}

//esta funcao recupera o jogo salvo 
int carregajogo()
{
	int i;
	
	FILE *fp;
	
	if( (fp= fopen("ARQmesaP", "r")) == NULL)      
	{
		arqmesapnabre2();
		return 1;   
	}
	
	if(fread(&mesaP, sizeof(mesaP), 1, fp)  != 1)
		{
			erroarqmesapcarregamento();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQPecas", "r")) == NULL)      
			{
				arqpecasnabre2();
				return 1;   
			}
			
	for(i = 0; i < 28; i++)
	{
		if(fread(&pecas[i], sizeof(struct statusPecas), 1, fp)  != 1)
		{
			erroarqpecascarregamento();
			return 1 ;
		}
	}
	fclose(fp);
	
	
	
	if( (fp= fopen("ARQMesa", "r")) == NULL)      
			{
				arqmesanabre2(); 
				return 1;   
			}
			
	for(i = 0; i < mesaP; i++)
	{
		if(fread(&mesa[i], sizeof(struct statusMesa), 1, fp)  != 1)
		{
			erroarqmesacarregamento();
			break;
		}
	}
	fclose(fp);
	
	
	if( (fp= fopen("ARQJog", "r")) == NULL)      
	{
		arqjognabre2();
		return 1;   
	}
	if(fread(&z, sizeof(z), 1, fp)  != 1)
		{
			erroarqjogcarregamento();
			return 1;
		}
	fclose(fp);
	
	
	
	if( (fp= fopen("ARQTmesa", "r")) == NULL)      
	{
		arqtmesanabre2();
		return 1;   
	}
	if(fread(&Tamanhomesa, sizeof(Tamanhomesa), 1, fp)  != 1)
		{
			erroarqtmesacarregamento();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQTcompr", "r")) == NULL)      
	{
		arqtcomprnabre2();
		return 1;   
	}
	if(fread(&compra, sizeof(compra), 1, fp)  != 1)
		{
			erroarqtcomprcarregamento();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQempate", "r")) == NULL)      
	{
		arqempoatenabre2();
		return 1;   
	}
	if(fread(&empate, sizeof(empate), 1, fp)  != 1)
		{
			erroarqempatearregamento();
			return 1;
		}
	fclose(fp);
	
	
	
	return 0;
}
//funcao para retomar o jogo salvo e carregado
void continuar()
{
	int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc;
    char test;
   
    
    extE=mesa[0].Lado1;
    extD=mesa[mesaP-1].Lado2;
    
	do
    {
        i = 0;

        do
        {
            desenhoMesa();
            i++;
        } while (Tamanhomesa - 1 != i);

        i = 0;
        novalinha();
        Mesa();
        do
        {

            pecasimpressas(mesa, i);
            i++;
        } while (i < mesaP);
        novalinha();

        i = 0;
        do
        {
            desenhoMesa();
            i++;
        } while (Tamanhomesa - 1 != i);

        i = 0;
        novalinha();
        novalinha();

        pecaDiff(pecas, z);

        // menu jogador
        teste1 = menuJogo(teste1, extE, extD);

        cont = 0;
        switch (teste1)
        {
        case 1:

            loc = escolhapeca(loc);

            if (loc == 0)
            {
                break;
            }
            else
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == z)
                    {
                        cont++;
                    }
                    if (cont == loc)
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            msgPossivel();
                            empate = 0;
                            if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                            {

                                lado = escolherLado(lado);

                                if (lado == 1)
                                {
                                    if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                    {

                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        if (pecas[i].Lado1 == extE)
                                        {
                                            mesa[0].Lado1 = pecas[i].Lado2;
                                            mesa[0].Lado2 = pecas[i].Lado1;
                                            mesaP++;
                                            extE = mesa[0].Lado1;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tamanhomesa = Tamanhomesa + 6;
                                            break;
                                        }
                                        else if (pecas[i].Lado2 == extE)
                                        {
                                            mesa[0].Lado1 = pecas[i].Lado1;
                                            mesa[0].Lado2 = pecas[i].Lado2;
                                            mesaP++;
                                            extE = mesa[0].Lado1;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tamanhomesa = Tamanhomesa + 6;
                                            break;
                                        }
                                        else
                                        {
                                            msgladoErrado();
                                        }
                                    }
                                }
                                if (lado == 2)
                                {

                                    if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                    {
                                        if (pecas[i].Lado1 == extD)
                                        {
                                            mesa[mesaP].Lado1 = pecas[i].Lado1;
                                            mesa[mesaP].Lado2 = pecas[i].Lado2;
                                            extD = mesa[mesaP].Lado2;
                                            mesaP++;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tamanhomesa = Tamanhomesa + 6;
                                            break;
                                        }
                                        else if (pecas[i].Lado2 == extD)
                                        {
                                            mesa[mesaP].Lado1 = pecas[i].Lado2;
                                            mesa[mesaP].Lado2 = pecas[i].Lado1;
                                            extD = mesa[mesaP].Lado2;
                                            mesaP++;
                                            pecas[i].status = 'm';
                                            if (z == '1')
                                            {
                                                z = '2';
                                            }
                                            else
                                            {
                                                z = '1';
                                            }
                                            Tamanhomesa = Tamanhomesa + 6;
                                            break;
                                        }
                                        else
                                            msgladoErrado();
                                    }
                                }
                                if (lado == 3)
                                {

                                    opcaoErrada();
                                }
                            }
                            else
                            {
                                if (pecas[i].Lado1 == extE)
                                {
                                    for (N = mesaP; N >= 0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N - 1].Lado1;
                                        mesa[N].Lado2 = mesa[N - 1].Lado2;
                                    }
                                    mesa[0].Lado1 = pecas[i].Lado2;
                                    mesa[0].Lado2 = pecas[i].Lado1;
                                    mesaP++;
                                    extE = mesa[0].Lado1;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tamanhomesa = Tamanhomesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado2 == extE)
                                {
                                    for (N = mesaP; N >= 0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N - 1].Lado1;
                                        mesa[N].Lado2 = mesa[N - 1].Lado2;
                                    }
                                    mesa[0].Lado1 = pecas[i].Lado1;
                                    mesa[0].Lado2 = pecas[i].Lado2;
                                    mesaP++;
                                    extE = mesa[0].Lado1;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tamanhomesa = Tamanhomesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado1 == extD)
                                {
                                    mesa[mesaP].Lado1 = pecas[i].Lado1;
                                    mesa[mesaP].Lado2 = pecas[i].Lado2;
                                    extD = mesa[mesaP].Lado2;
                                    mesaP++;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tamanhomesa = Tamanhomesa + 6;
                                    break;
                                }
                                else if (pecas[i].Lado2 == extD)
                                {
                                    mesa[mesaP].Lado1 = pecas[i].Lado2;
                                    mesa[mesaP].Lado2 = pecas[i].Lado1;
                                    extD = mesa[mesaP].Lado2;
                                    mesaP++;
                                    pecas[i].status = 'm';
                                    if (z == '1')
                                    {
                                        z = '2';
                                    }
                                    else
                                    {
                                        z = '1';
                                    }
                                    Tamanhomesa = Tamanhomesa + 6;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            numeroErrado();
                            novalinha();
                            break;
                        }
                    }
                }
            if (cont < loc)
            {
               opcaoInvalida();
            }

            break;

        case 2:

            if (compra == 27)
            {

                vazio();
            }
            else
            {

                compra++;
                pecas[compra].status = z;
            }

            break;
        case 4:

            cont = 0;
            if (compra == 27)
            {
                for (i = 0; i < 27; i++)
                {

                    if (pecas[i].status == z)
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            cont++;
                        }
                    }
                }
                if (cont == 0)
                {
                    passaravez();
                    empate++;
                    if (z == '1')
                    {
                        z = '2';
                    }
                    else
                    {
                        z = '1';
                    }
                }
                else
                {
                    aindada();
                }
            }
            else
            {
                novalinha();
                aindada();
            }
            break;

        case 3:

            final = 3;
            teste1 = 3;
            break;

        default:

            opcaoInvalida();
            break;
        }
       novalinha();

        cont = 0;
        cont2 = 0;

        if (empate == 2)
        {
            for (i = 0; i < 27; i++)
            {
                if (pecas[i].status == '1')
                {
                    cont++;
                }
                if (pecas[i].status == '2')
                {
                    cont2++;
                }
            }
            if (cont < cont2)
            {
                final = 1;
                teste1 = 3;
                partidaacabou();
                contaPontos();
            }
            if (cont2 < cont)
            {
                final = 2;
                teste1 = 3;
                 partidaacabou();
                 contaPontos();
            }
            if (cont == cont2)
            {
                cont = 0;
                cont2 = 0;

                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont = cont + pecas[i].Lado1;
                        cont = cont + pecas[i].Lado2;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2 = cont2 + pecas[i].Lado1;
                        cont2 = cont2 + pecas[i].Lado2;
                    }
                }
                if (cont < cont2)
                {
                    final = 1;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont2 < cont)
                {
                    final = 2;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont == cont2)
                {
                    final = 4;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
            }
        }

        cont = 0;
        cont2 = 0;

        // loop para dar o resultado da partida
        for (i = 0; i < 28; i++)
        {
            if (pecas[i].status == '1')
            {
                cont++;
            }
            if (pecas[i].status == '2')
            {
                cont2++;
            }
        }

        if (cont == 0 && compra == 27)
        {
            final = 1;
            teste1 = 3;
        }
        if (cont2 == 0 && compra == 27)
        {
            final = 2;
            teste1 = 3;
        }
    } while (teste1 != 3);

    if (final == 1)
    {
        jg1ganhou();
    }
    if (final == 2)
    {
        jg2ganhou();
    }
    if (final == 3)
    {
        interrompeJogo();
    }
    if (final == 4)
    {
        empateJogo();
    }
	
}

void contramaquina()
{
    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc, pmesa;
    char test;
   

    aux.status = ' ';
    aux.Lado1 = 0;
    aux.Lado2 = 1;
    compra = 13;
    mesaP = 1;
    lado = 0;
    empate = 0;
    Tamanhomesa = 5;
    for (i = 0; i < 28; i++)
    {
        pecas[i].status = ' ';
    }

    embaralhapeca();

    // loop para pecas do jogador 1
    for (i = 0; i <= 6; i++)
    {
        pecas[i].status = '1';
    }
    // loop para pecas da maquina  
    for (i = 7; i <= 13; i++)
    {
        pecas[i].status = '2';
    }

    // loop para saber quem comeca
    for (i = 0; i <= 13; i++)
    {
        if (pecas[i].Lado1 == pecas[i].Lado2)
        {
            if (aux.Lado1 <= pecas[i].Lado1)
            {
                aux = pecas[i];
                u = i;
            }
            else
            {

                if (aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
                {
                    if (aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2)
                    {
                        aux = pecas[i];
                        u = i;
                    }
                }
            }
        }
    }
    Tamanhomesa = Tamanhomesa + 7;
    maiorPeca();
    if (pecas[u].status == '1')
    {
        pecasJg1();
    }
    else
    {
        pecasJg2();
    }
    novalinha();
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    extE = mesa[0].Lado1;
    extD = mesa[0].Lado2;

    if (pecas[u].status == '1')
    {
        z = '2';
    }
    else
    {
        z = '1';
    }
    pecas[u].status = 'm';

    do
    {
        if (z == '1')
        {
            i = 0;

            do
            {
                desenhoMesa();
                i++;
            } while (Tamanhomesa - 1 != i);

            i = 0;
            novalinha();
            Mesa();
            do
            {

                pecasimpressas(mesa, i);
                i++;
            } while (i < mesaP);
            novalinha();

            i = 0;
            do
            {
                desenhoMesa();
                i++;
            } while (Tamanhomesa - 1 != i);

            i = 0;
            novalinha();
            novalinha();

            pecaDiff(pecas,z);

            // menu jogador
            teste1 = menuJogo(teste1, extE, extD);

            cont = 0;
            switch (teste1)
            {
            case 1:

                loc = escolhapeca(loc);

                if (loc == 0)
                {
                    break;
                }
                else
                    for (i = 0; i <= 27; i++)
                    {
                        if (pecas[i].status == z)
                        {
                            cont++;
                        }
                        if (cont == loc)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                msgPossivel();
                                empate = 0;
                                if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                                {

                                    lado = escolherLado(lado);

                                    if (lado == 1)
                                    {
                                        if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                        {

                                            for (N = mesaP; N >= 0; N--)
                                            {
                                                mesa[N].Lado1 = mesa[N - 1].Lado1;
                                                mesa[N].Lado2 = mesa[N - 1].Lado2;
                                            }
                                            if (pecas[i].Lado1 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado2;
                                                mesa[0].Lado2 = pecas[i].Lado1;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado1;
                                                mesa[0].Lado2 = pecas[i].Lado2;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else
                                            {
                                                msgladoErrado();
                                            }
                                        }
                                    }
                                    if (lado == 2)
                                    {

                                        if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                        {
                                            if (pecas[i].Lado1 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else
                                                msgladoErrado();
                                        }
                                    }
                                    if (lado == 3)
                                    {

                                        opcaoErrada();
                                    }
                                }
                                else
                                {
                                    if (pecas[i].Lado1 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado2;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado1 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado1;
                                        mesa[mesaP].Lado2 = pecas[i].Lado2;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado2;
                                        mesa[mesaP].Lado2 = pecas[i].Lado1;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                numeroErrado();
                                novalinha();
                                break;
                            }
                        }
                    }
                if (cont < loc)
                {
                    opcaoInvalida();
                }

                break;

            case 2:

                if (compra == 27)
                {

                    vazio();
                }
                else
                {

                    compra++;
                    pecas[compra].status = z;
                }

                break;
            case 4:

                cont = 0;
                if (compra == 27)
                {
                    for (i = 0; i < 27; i++)
                    {

                        if (pecas[i].status == z)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                cont++;
                            }
                        }
                    }
                    if (cont == 0)
                    {
                        passaravez();
                        empate++;
                        if (z == '1')
                        {
                            z = '2';
                        }
                        else
                        {
                            z = '1';
                        }
                    }
                    else
                    {
                        aindada();
                    }
                }
                else
                {
                    novalinha();
                    aindada();
                }
                break;

            case 3:

                final = 3;
                teste1 = 3;
                break;

            default:

                opcaoInvalida();
                break;
            }
            novalinha();

            cont = 0;
            cont2 = 0;

            if (empate == 2)
            {
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }
                if (cont < cont2)
                {
                    final = 1;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont2 < cont)
                {
                    final = 2;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont == cont2)
                {
                    cont = 0;
                    cont2 = 0;

                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont = cont + pecas[i].Lado1;
                            cont = cont + pecas[i].Lado2;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2 = cont2 + pecas[i].Lado1;
                            cont2 = cont2 + pecas[i].Lado2;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont == cont2)
                    {
                        final = 4;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                }
            }

            cont = 0;
            cont2 = 0;

            // loop para descborir quem ganhara o jogo em caso de empate
            for (i = 0; i < 28; i++)
            {
                if (pecas[i].status == '1')
                {
                    cont++;
                }
                if (pecas[i].status == '2')
                {
                    cont2++;
                }
            }

            if (cont == 0 && compra == 27)
            {
                final = 1;
                teste1 = 3;
            }
            if (cont2 == 0 && compra == 27)
            {
                final = 2;
                teste1 = 3;
            }
        }

        if (z == '2' && teste1 != 3)
        {

            do
            {
                pmesa = 0;
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '2')
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            pmesa = 1;
                            empate = 0;
                            maquinajogou();
                            if (pecas[i].Lado1 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado1 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                        }
                    }
                }
                if (pmesa == 0)
                {
                    if (compra == 27)
                    {
                        pmesa = 0;
                    }
                    else
                    {
                        compra++;
                        pmesa = 1;
                        maquinacomprou();
                        pecas[compra].status = z;
                    }
                }
                if (pmesa == 0)
                {
                    z = '1';
                    empate++;
                    maquinapassou();
                }

                cont = 0;
                cont2 = 0;

                if (empate == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont++;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2++;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont == cont2)
                    {
                        cont = 0;
                        cont2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (pecas[i].status == '1')
                            {
                                cont = cont + pecas[i].Lado1;
                                cont = cont + pecas[i].Lado2;
                            }
                            if (pecas[i].status == '2')
                            {
                                cont2 = cont2 + pecas[i].Lado1;
                                cont2 = cont2 + pecas[i].Lado2;
                            }
                        }
                        if (cont < cont2)
                        {
                            final = 1;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                        if (cont2 < cont)
                        {
                            final = 2;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                        if (cont == cont2)
                        {
                            final = 4;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                    }
                }

                cont = 0;
                cont2 = 0;

                // loop para descobir o vencedor do jogo caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }

                if (cont == 0 && compra == 27)
                {
                    final = 1;
                    teste1 = 3;
                }
                if (cont2 == 0 && compra == 27)
                {
                    final = 2;
                    teste1 = 3;
                }

            } while (z != '1');
        }

    } while (teste1 != 3);

    if (final == 1)
    {
        jg1ganhou();
    }
    if (final == 2)
    {
        jg2ganhou();
    }
    if (final == 3)
    {
        interrompeJogo();
    }
    if (final == 4)
    {
        empateJogo();
    }
}

void continuarmaquina()
{
    int i, k, u, x, loc, cont, cont2, final, N, lado, teste1;
    int esc, pmesa;
    char test;
    

    extE = mesa[0].Lado1;
    extD = mesa[mesaP-1].Lado2;
    do
    {
        if (z == '1')
        {
            i = 0;

            do
            {
                desenhoMesa();
                i++;
            } while (Tamanhomesa - 1 != i);

            i = 0;
            novalinha();
            Mesa();
            do
            {

                pecasimpressas(mesa, i);
                i++;
            } while (i < mesaP);
            novalinha();

            i = 0;
            do
            {
                desenhoMesa();
                i++;
            } while (Tamanhomesa - 1 != i);

            i = 0;
            novalinha();
            novalinha();

            pecaDiff(pecas, z);

            // menu jogador
            teste1 = menuJogo(teste1, extE, extD);

            cont = 0;
            switch (teste1)
            {
            case 1:

                loc = escolhapeca(loc);

                if (loc == 0)
                {
                    break;
                }
                else
                    for (i = 0; i <= 27; i++)
                    {
                        if (pecas[i].status == z)
                        {
                            cont++;
                        }
                        if (cont == loc)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                msgPossivel();
                                empate = 0;
                                if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                                {

                                    lado = escolherLado(lado);

                                    if (lado == 1)
                                    {
                                        if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                        {

                                            for (N = mesaP; N >= 0; N--)
                                            {
                                                mesa[N].Lado1 = mesa[N - 1].Lado1;
                                                mesa[N].Lado2 = mesa[N - 1].Lado2;
                                            }
                                            if (pecas[i].Lado1 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado2;
                                                mesa[0].Lado2 = pecas[i].Lado1;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado1;
                                                mesa[0].Lado2 = pecas[i].Lado2;
                                                mesaP++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else
                                            {
                                                msgladoErrado();
                                            }
                                        }
                                    }
                                    if (lado == 2)
                                    {

                                        if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                        {
                                            if (pecas[i].Lado1 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extD)
                                            {
                                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                                extD = mesa[mesaP].Lado2;
                                                mesaP++;
                                                pecas[i].status = 'm';
                                                if (z == '1')
                                                {
                                                    z = '2';
                                                }
                                                else
                                                {
                                                    z = '1';
                                                }
                                                Tamanhomesa = Tamanhomesa + 6;
                                                break;
                                            }
                                            else
                                                msgladoErrado();
                                        }
                                    }
                                    if (lado == 3)
                                    {

                                        opcaoErrada();
                                    }
                                }
                                else
                                {
                                    if (pecas[i].Lado1 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado2;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extE)
                                    {
                                        for (N = mesaP; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mesaP++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado1 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado1;
                                        mesa[mesaP].Lado2 = pecas[i].Lado2;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extD)
                                    {
                                        mesa[mesaP].Lado1 = pecas[i].Lado2;
                                        mesa[mesaP].Lado2 = pecas[i].Lado1;
                                        extD = mesa[mesaP].Lado2;
                                        mesaP++;
                                        pecas[i].status = 'm';
                                        if (z == '1')
                                        {
                                            z = '2';
                                        }
                                        else
                                        {
                                            z = '1';
                                        }
                                        Tamanhomesa = Tamanhomesa + 6;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                numeroErrado();
                                novalinha();
                                break;
                            }
                        }
                    }
                if (cont < loc)
                {
                    opcaoInvalida();
                }

                break;

            case 2:

                if (compra == 27)
                {

                    vazio();
                }
                else
                {

                    compra++;
                    pecas[compra].status = z;
                }

                break;
            case 4:

                cont = 0;
                if (compra == 27)
                {
                    for (i = 0; i < 27; i++)
                    {

                        if (pecas[i].status == z)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                cont++;
                            }
                        }
                    }
                    if (cont == 0)
                    {
                        passaravez();
                        empate++;
                        if (z == '1')
                        {
                            z = '2';
                        }
                        else
                        {
                            z = '1';
                        }
                    }
                    else
                    {
                        aindada();
                    }
                }
                else
                {
                    novalinha();
                    aindada();
                }
                break;

            case 3:

                final = 3;
                teste1 = 3;
                break;

            default:

                opcaoInvalida();
                break;
            }
            novalinha();

            cont = 0;
            cont2 = 0;

            if (empate == 2)
            {
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }
                if (cont < cont2)
                {
                    final = 1;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont2 < cont)
                {
                    final = 2;
                    teste1 = 3;
                    partidaacabou();
                    contaPontos();
                }
                if (cont == cont2)
                {
                    cont = 0;
                    cont2 = 0;

                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont = cont + pecas[i].Lado1;
                            cont = cont + pecas[i].Lado2;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2 = cont2 + pecas[i].Lado1;
                            cont2 = cont2 + pecas[i].Lado2;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont == cont2)
                    {
                        final = 4;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                }
            }

            cont = 0;
            cont2 = 0;

            // loop para descborir quem e o vencedor o jogo caso empate
            for (i = 0; i < 28; i++)
            {
                if (pecas[i].status == '1')
                {
                    cont++;
                }
                if (pecas[i].status == '2')
                {
                    cont2++;
                }
            }

            if (cont == 0 && compra == 27)
            {
                final = 1;
                teste1 = 3;
            }
            if (cont2 == 0 && compra == 27)
            {
                final = 2;
                teste1 = 3;
            }
        }

        if (z == '2' && teste1 != 3)
        {

            do
            {
                pmesa = 0;
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '2')
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            pmesa = 1;
                            empate = 0;
                            maquinajogou();
                            if (pecas[i].Lado1 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extE)
                            {
                                for (N = mesaP; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mesaP++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado1 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado1;
                                mesa[mesaP].Lado2 = pecas[i].Lado2;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extD)
                            {
                                mesa[mesaP].Lado1 = pecas[i].Lado2;
                                mesa[mesaP].Lado2 = pecas[i].Lado1;
                                extD = mesa[mesaP].Lado2;
                                mesaP++;
                                pecas[i].status = 'm';
                                if (z == '1')
                                {
                                    z = '2';
                                }
                                else
                                {
                                    z = '1';
                                }
                                Tamanhomesa = Tamanhomesa + 6;
                                break;
                            }
                        }
                    }
                }
                if (pmesa == 0)
                {
                    if (compra == 27)
                    {
                        pmesa = 0;
                    }
                    else
                    {
                        compra++;
                        pmesa = 1;
                        maquinacomprou();
                        pecas[compra].status = z;
                    }
                }
                if (pmesa == 0)
                {
                    z = '1';
                    empate++;
                    maquinapassou();
                }

                cont = 0;
                cont2 = 0;

                if (empate == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            cont++;
                        }
                        if (pecas[i].status == '2')
                        {
                            cont2++;
                        }
                    }
                    if (cont < cont2)
                    {
                        final = 1;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont2 < cont)
                    {
                        final = 2;
                        teste1 = 3;
                        partidaacabou();
                        contaPontos();
                    }
                    if (cont == cont2)
                    {
                        cont = 0;
                        cont2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (pecas[i].status == '1')
                            {
                                cont = cont + pecas[i].Lado1;
                                cont = cont + pecas[i].Lado2;
                            }
                            if (pecas[i].status == '2')
                            {
                                cont2 = cont2 + pecas[i].Lado1;
                                cont2 = cont2 + pecas[i].Lado2;
                            }
                        }
                        if (cont < cont2)
                        {
                            final = 1;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                        if (cont2 < cont)
                        {
                            final = 2;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                        if (cont == cont2)
                        {
                            final = 4;
                            teste1 = 3;
                            partidaacabou();
                            contaPontos();
                        }
                    }
                }

                cont = 0;
                cont2 = 0;

                // loop para descborir quem vencedor do jogo caso empate
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        cont++;
                    }
                    if (pecas[i].status == '2')
                    {
                        cont2++;
                    }
                }

                if (cont == 0 && compra == 27)
                {
                    final = 1;
                    teste1 = 3;
                }
                if (cont2 == 0 && compra == 27)
                {
                    final = 2;
                    teste1 = 3;
                }

            } while (z != '1');
        }

    } while (teste1 != 3);

    if (final == 1)
    {
        jg1ganhou();
    }
    if (final == 2)
    {
        jg2ganhou();
    }
    if (final == 3)
    {
        interrompeJogo();
    }
    if (final == 4)
    {
        empateJogo();
    }
}
