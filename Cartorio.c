#include <stdio.h> //bliblioteca de comunicação com o usuario 
#include <stdlib.h> //bliblioteca de alocação de espaço em memoria 
#include <locale.h> //bliblioteca de alocação de texto por região 
#include <string.h> //bliblioteca responsavel por cuidar das strings 

int registro() // função responsavel por cadastrar os usuarios no sistema 
{
	//Inicio criação de variaveis/ strings- conjunto de variaveis 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variaveis 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a strings 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// o A significa atualização 
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
		printf("Arquivo não encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
	char senhadigitada[10]="a";
	int comparacao; 
			
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Login do Adminstrador!\n\nDigite a sua Senha: ");
		scanf("%s", senhadigitada);
		
		comparacao = strcmp(senhadigitada, "1234");
		
		if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
		
			system("cls");
	
 		   	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagen
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("### Escolha a Opção Desejada do Menu: ###\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4  - Sair do Sistema\n\n");
			printf("Digite uma opção: "); // fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuario 
	
			system("cls"); // limpa a tela 
		
		
			switch(opcao) // incio da selecão 
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
					
				case 4:
				printf("Obrigado por ultilizar o Sistema!");
				return 0;
				break;
			
				default:
				printf("Essa opção não esta desponivel!\n");
				system("pause");
				break;
			
			}  //fim da selecao 
  	  	}
	}
	
	else
		printf("Senha Incorreta!\nTente Novamente");
}
