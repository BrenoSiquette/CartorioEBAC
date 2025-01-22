#include <stdio.h> //bliblioteca de comunica��o com o usuario 
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o 
#include <string.h> //bliblioteca responsavel por cuidar das strings 

int registro() // fun��o responsavel por cadastrar os usuarios no sistema 
{
	//Inicio cria��o de variaveis/ strings- conjunto de variaveis 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variaveis 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a strings 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// o A significa atualiza��o 
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digine to cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	
	char cpf [40];
	char conteudo [200];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	
	
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf ("Digite o CPF  a ser deletado: ");
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf, "cpf");
	
	if(file == NULL)
	{
		printf("O usuario deletetado ou fora do sistema!.\n");
		system("pause");
	}	
}

int main()
{
	int opcao=0; //Definindo variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagen
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("### Escolha a Op��o Desejada do Menu: ###\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Digite uma op��o: "); // fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario 
	
		system("cls"); // limpa a tela 
		
		
		switch(opcao) // incio da selec�o 
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3: 
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o esta desponivel!\n");
			system("pause");
			break;
			
		}  //fim da selecao 
    }
}
