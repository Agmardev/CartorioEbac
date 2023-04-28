#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar dos string

int registro()// função responsável por cadastrar os usuários no sistema 
{
	// início das criações das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final das criações das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cpf); // "%s" refere as strings

	strcpy(arquivo, cpf); //Responsável por copiar os valores dos string
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever  
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo arquivo
	fprintf(file,",");
	fclose(file);//fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");// coletando informações 
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");//abrindo arquivo
	fprintf(file,nome);//abrindo o arquivo 
	fclose(file);//fechando o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	 
	printf("Digite o sobrenome a ser cadastrado: ");//coletanto informções 
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
	
	system("pause");//pausa pro usuário ler as informações 
		
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
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while comando de repetições 
	{
		printf("\nEssas são as infromações do usuário: \n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
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
	int opcao=0; //Definindo Variáveis
	int laco=1;

	for(laco=1;laco=1;) 
    {
	    
	    system("cls");// responsável por limpar a tela 
	    
		setlocale(LC_ALL, "Portuguese"); // Deinindo a Linguagem

		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t - Registrar nomes\n");
		printf("\t - Consultar nomes\n"); 
		printf("\t - Deletar nomes\n");
		printf("Opção: "); //Fim do Menu

		scanf("%d", &opcao); //Armazenagem a Escolha do Usuário

		system("cls"); //limpando a tela 
		
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de funções 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não estar disponivel!\n");
			system("pause");
			break;	
		}//fim da seleção
	
	}
}













