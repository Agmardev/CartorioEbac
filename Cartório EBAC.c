#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	// in�cio das cria��es das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final das cria��es das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); // "%s" refere as strings

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos string
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever  
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo arquivo
	fprintf(file,",");
	fclose(file);//fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");// coletando informa��es 
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");//abrindo arquivo
	fprintf(file,nome);//abrindo o arquivo 
	fclose(file);//fechando o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	 
	printf("Digite o sobrenome a ser cadastrado: ");//coletanto inform��es 
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//pausa pro usu�rio ler as informa��es 
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s",cpf);
    printf("\n\n");
    
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)//NULL significa quando nao tem 
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while comando de repeti��es 
	{
		printf("\nEssas s�o as infroma��es do usu�rio: \n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	else // else comando "se sim" 
	{
		remove(cpf);
		printf("CPF deletado com sucesso!\n");
		system("pause");
		
	}
	
}

      



int main () 
    {
	int opcao=0; //Definindo Vari�veis
	int laco=1;

	for(laco=1;laco=1;) 
    {
	    
	    system("cls");// respons�vel por limpar a tela 
	    
		setlocale(LC_ALL, "Portuguese"); // Deinindo a Linguagem

		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t - Registrar nomes\n");
		printf("\t - Consultar nomes\n"); 
		printf("\t - Deletar nomes\n");
		printf("Op��o: "); //Fim do Menu

		scanf("%d", &opcao); //Armazenagem a Escolha do Usu�rio

		system("cls"); //limpando a tela 
		
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o estar disponivel!\n");
			system("pause");
			break;	
		}//fim da sele��o
	
	}
}













