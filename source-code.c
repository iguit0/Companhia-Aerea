/*  
    **** LEIA-ME ****
     Projeto desenvolvido pelos alunos:
     -> Igor Alves - 3902
     -> Mateus Lopes - 3987
     -> Gabriel Batalha - 3915
     OBS: A senha para acesso do programa é:
     login: igm
     senha: 123
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
    int cont,y,z,i,f;              // variáveis (e/ou contadores) globais de controle (contador para cadastro de vôos e etc).
typedef struct CadastroNovoVoo{            //estrutura (struct) para armazenar variáveis de um cadastro de novo vôo.
	char origem_voo[50];
	char destino_voo[50];
	int capacidade_maxima;
} NovoVoo;

typedef struct Comprartickets{             //estrutura (struct) para armazenar variáveis da compra de tickets.
	char nome[60];
	char cpf[16];
	int numvoo;
	int numticket;
} Comprar_tickets;
	
	NovoVoo nv[5];          //assinando a struct.
	Comprar_tickets ct[10];   // assinando a struct.
	
void Cadastrovoo(){                 // função para cadastro de vôos.
		system("cls");
		fflush(stdin);
		printf("Digite a origem do voo %d: ",cont+1);
		gets(nv[cont].origem_voo);
		fflush(stdin);
		printf("\n");
		printf("Digite o destino do voo %d: ",cont+1);
		gets(nv[cont].destino_voo);
		fflush(stdin);
		printf("\n");
		printf("Digite a capacidade maxima de passageiros: ");
		scanf("%d",&nv[cont].capacidade_maxima);
		printf("\n\n\t\t\t >>> Vôo [%d] cadastrado com sucesso !! <<< \n\n",cont+1);
		cont++;
}

void Info_voos(){                        //função para informar os vôos cadastrados.
	for(y=0;y < cont;y++){	
		printf("Voo %d:\n",y+1);
		printf("Origem: %s -> Destino: %s\n",nv[y].origem_voo,nv[y].destino_voo);
		printf("Poltronas livres: %d\n",nv[y].capacidade_maxima);
		printf("**************\n\n");
	}
}

void ComprarBilhetes(){          // função para a compra de bilhetes.
	    fflush(stdin);
		printf("Digite seu nome: ");
		gets(ct[z].nome);
		printf("\n");
		printf("Digite seu CPF: ");
		gets(ct[z].cpf);
		printf("\n");
		printf("Digite o numero do voo: ");
		fflush(stdin);
		scanf("%d",&ct[z].numvoo);
		printf("\n");
		ct[z].numvoo += -1;
		    if (nv[ct[z].numvoo].capacidade_maxima >= 1) {
		       printf("\n\t\t\tParabéns!! Bilhete comprado com sucesso.");
		       nv[ct[z].numvoo].capacidade_maxima --;        //Se o bilhete foi comprado com sucesso, então, diminuir -1 na capacidade máxima.
	       	   ct[z].numticket =  z*z+1;                 // Os números de tickets são aleatórios, justamente para criar essa ideia de aleatoriedade para não confundir os clientes.
		       z++;
	        }
			else{
		       printf("\nDesculpe, não há poltronas livres :( .");
			}
}

void BilhetesVendidos(){             // função para consultar os bilhetes vendidos
        int cpfverificar=0;
        char verificar_cpf[16];
        fflush(stdin);
        printf("Digite seu CPF: ");
        gets(verificar_cpf);
        for(i=0;i < z;i++){
            if(strcmp(ct[i].cpf,verificar_cpf)==0){              //comparando cpf com o comando "strcmp" da biblioteca <string.h>        
                        printf("\nTicket nº: %d", ct[i].numticket);
                        printf("\nNome: %s", ct[i].nome);
                        printf("\nCPF: %s", ct[i].cpf);
                        printf("\nNúmero do Vôo: %d", ct[i].numvoo+1);
                        cpfverificar = +1;              // se encontrar um CPF, o contador aumenta.
                }
        }
        if (cpfverificar == 0) {             // se contador (do cpf) ficar 0 é porque não encontrou CPF cadastrado.
                printf("\nInfelizmente, o CPF não foi localizado.");
        }
}
void cancelartickets(){          // função para cancelar os tickets (bilhetes).
	int o;
	int cancelar=0;
	printf("\nDigite o nº do bilhete a ser cancelado: ");
	scanf("%d",&cancelar);
	for(o=0;o < z;o++){
		if (ct[o].numticket == cancelar) {                 
 			nv[ct[z].numvoo].capacidade_maxima ++;     //Se o bilhete foi cancelado com sucesso, então, aumentar +1 na capacidade máxima.
			printf("\n\nBilhete Cancelado com sucesso!!");
 		}
		
	}
}

void relatoriogeral(){          //função para printar o relatório geral de passageiros por vôo.
	int j;
	int relatorio=0;
	printf("\nDigite o nº de um vôo: ");
	scanf("%d",&relatorio);
	relatorio += -1;
		for(j=0;j < z;j++){
			if(ct[j].numvoo == relatorio){
				printf("\nNome: %s",ct[j].nome);
				printf("\nCPF: %s",ct[j].cpf);
				printf("\nVoo %d",j+1);
				printf("\nOrigem: %s -> Destino: %s",nv[j].origem_voo,nv[j].destino_voo);
				printf("\nPoltronas livres: %d\n",nv[j].capacidade_maxima);
			}
		}
}

void menu(){
    setlocale(LC_ALL,"Portuguese");       // Definição para uso de configurações em português.
    int opcao;
    do{
		system("cls");
		printf("\t\t\t**** COMPANHIA AEREA I.G.M. **** \n\n");      // I.G.M. = Igor.Gabriel.Mateus     :)
		printf("\t\t\t#### SEJA BEM VINDO(A) #### \n");     
		printf(":: Menu de Opções ::\n\n");
		printf("1 - Cadastrar um novo vôo\n");
		printf("2 - Visualizar informações de vôos\n");
		printf("3 - Realizar vendas de bilhetes\n");
		printf("4 - Consultar bilhetes vendidos\n");
		printf("5 - Cancelar Bilhetes\n");
		printf("6 - Relatório de passageiros por vôo\n");
		printf("7 - Encerrar o sistema\n\n");
		printf("Escolha uma opção:  ");
		scanf("%d",&opcao);
		printf("\a");   // beepzinho :)
		system("cls");
		switch(opcao){
			case 1:                                    //cadastrar um novo voo
	    		Cadastrovoo(); 
	    		printf("\n\n");
	    		system("pause");
			    break;
			case 2:                                   //Visualizar informações de vôos
			    Info_voos();
			    printf("\n\n");
			    system("pause");
			    break;
			case 3:                               //Realizar vendas de bilhetes
			    ComprarBilhetes();              
			    printf("\n\n");
				system("pause");
				break;
		    case 4:
		    	BilhetesVendidos();   //Consultar bilhetes vendidos
		    	printf("\n\n");
		    	system("pause");
		    	break;
			case 5:
				cancelartickets();     // Cancelar bilhetes comprados.
				printf("\n\n");
				system("pause");
				break;
			case 6:
				relatoriogeral();   // Relatório de passageiros por vôo.
				printf("\n\n");
				system("pause");
				break;
			}

	}while(opcao != 7);
}

void login(){           // função responsável pelo sistema de Login.
	setlocale(LC_ALL,"Portuguese");       // Definição para uso de configurações em português.
	int x,j=1,k=1;
	char *login;
	char *senha;
	char usuario[30];
	login = (char *) malloc(5*sizeof(char));   //5 bytes
	senha = (char *) malloc(5*sizeof(char));   //5 bytes
	printf("Digite seu nome: ");                  // Identificação do Usuário.
	gets(usuario);
	fflush(stdin);
	printf("\t\t\t ** Olá, seja bem vindo(a) %s ** \n\n\n",usuario);  //Sistema de login...
	fflush(stdin);
	for (x=0;x<99999;x++){     // x = número de tentativas de login, um loop (quase) infinito.
		printf("\n\tLogin: ");                
		fflush (stdin);
		gets(login);
		printf ("\n\tSenha: ");
		fflush(stdin);
		gets(senha);
		fflush (stdin);
		j=login[0];
		fflush (stdin);
		k=senha[0];
		if (j=='i'&&'g'&&'m' && k=='1'&&'2'&&'3'){
			break;
		}
		else{
			printf ("\n\nTente novamente. . .\n\n ");
    	}
	}
	free(login); //liberando memória
	free(senha);  //liberando memória
	login = NULL;
	senha = NULL;
}

int main(void){
	login();        //Sistema de Login.
	menu();        //Menu.
	system("pause");
	return 0;
}
