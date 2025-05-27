#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço em memória
#include <locale.h>//Biblioteca de alocação de texto por região
#include <string.h>//Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	int continuar_registro = 1; // Variável para controlar o loop de registro

	while(continuar_registro == 1)
	{
		printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
		scanf("%s", cpf);// %s refere-se a salvar string
		
		strcpy(arquivo, cpf);//Responsável por copiar os valores das string
		
		FILE *file;// Cria o arquivo
		file = fopen(arquivo, "w");// Cria o arquivo na pasta e o "w" significa escrever
		fprintf(file, cpf);// Salva o valor da variável
		fclose(file);//Fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		printf("\nUsuário cadastrado com sucesso!\n");
		printf("Deseja cadastrar outro usuário? (1 para sim, 0 para voltar ao menu): ");
		scanf("%d", &continuar_registro);
		system("cls"); // Limpa a tela para a próxima iteração ou para o menu
	}
	
	system("pause");
	return 0; // Adicionado um retorno para a função registro
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	return 0; // Adicionado um retorno para a função consultar
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	else
		printf("O usuário foi deletado com sucesso!.\n");
		system("pause");	

	return 0; // Adicionado um retorno para a função deletar
}

int main()
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("----- Cartório da EBAC -----\n\n");
	printf("Login de admnistrador!\n\nDigite a sua senha: ");
	scanf("%s, senhadigitada");

	if(senhadigitada[10] == "admin")
	{
	
		for(laco=1;laco=1;)
		{
			system("cls");//Responsável por limpar a tela
		
			setlocale(LC_ALL, "Portuguese");//Definindo linguagem
		
			printf("----- Cartório da EBAC -----\n\n");//Início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");//Fim do menu	
		
			scanf("%d", &opcao);//Armazenando a escolha do usuário
		
			system("cls");//Responsável por limpar a tela
		
			switch(opcao)//Início da seleção do menu
			{
				case 1:
					registro();//Chamada de funções
					break;	
			
				case 2:
					consultar();
					break;
			
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
			
				default:
					printf("Essa opção não está disponível!\n");
					system("pause");
					break;
				
			}	
		}
	}
	else
		printf("Senha incorreta")
	return 0; // Adicionado um retorno para a função main
}
