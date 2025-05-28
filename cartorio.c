#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

// Adicionei um cabeçalho para a função main antes de usá-la, embora não seja estritamente necessário neste caso,
// é uma boa prática para funções que são definidas após o seu uso.
int main();

int registro() // Função responsável por cadastrar os usuários no sistema
{
    // Início criação de variáveis/string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/string

    int continuar_registro = 1; // Variável para controlar o loop de registro

    while (continuar_registro == 1)
    {
        printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
        scanf("%s", cpf); // %s refere-se a salvar string

        // O nome do arquivo será o CPF.
        // Não é necessário usar strcpy(arquivo, cpf) e depois abrir o arquivo com "arquivo".
        // Você pode abrir diretamente com 'cpf'.
        FILE *file;
        file = fopen(cpf, "w"); // Cria ou sobrescreve o arquivo com o CPF

        if (file == NULL) // Verifica se o arquivo foi aberto com sucesso
        {
            printf("Erro ao criar o arquivo para o CPF %s.\n", cpf);
            system("pause");
            return 1; // Retorna um código de erro
        }

        fprintf(file, "CPF: %s\n", cpf); // Salva o CPF no arquivo com um rótulo

        printf("Digite o nome a ser cadastrado: ");
        scanf("%s", nome);
        fprintf(file, "Nome: %s\n", nome); // Salva o nome

        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);
        fprintf(file, "Sobrenome: %s\n", sobrenome); // Salva o sobrenome

        printf("Digite o cargo a ser cadastrado: ");
        scanf("%s", cargo);
        fprintf(file, "Cargo: %s\n", cargo); // Salva o cargo

        fclose(file); // Fecha o arquivo

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

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo. CPF não localizado!\n");
    }
    else
    {
        printf("\nEssas são as informações do usuário:\n");
        while (fgets(conteudo, sizeof(conteudo), file) != NULL) // Usar sizeof(conteudo) para segurança
        {
            printf("%s", conteudo);
        }
        fclose(file); // Fechar o arquivo após a leitura
        printf("\n");
    }

    system("pause");
    return 0; // Adicionado um retorno para a função consultar
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    // 'remove' retorna 0 em caso de sucesso, e um valor diferente de 0 em caso de erro.
    if (remove(cpf) == 0)
    {
        printf("O usuário foi deletado com sucesso!\n");
    }
    else
    {
        printf("O usuário não se encontra no sistema ou houve um erro ao tentar deletar!\n");
    }

    system("pause");
    return 0; // Adicionado um retorno para a função deletar
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;
    char senhadigitada[10]; // Tamanho suficiente para "admin" + terminador nulo

    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem no main também

    printf("----- Cartório da EBAC -----\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada); // Corrigido o formato de scanf

    // Corrigido a comparação de string para usar strcmp
    if (strcmp(senhadigitada, "admin") == 0)
    {
        while (laco == 1) // O loop for(laco=1;laco=1;) é um loop infinito. 'while(laco == 1)' é mais claro.
        {
            system("cls"); // Responsável por limpar a tela

            printf("----- Cartório da EBAC -----\n\n"); // Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Opção: "); // Fim do menu

            scanf("%d", &opcao); // Armazenando a escolha do usuário

            system("cls"); // Responsável por limpar a tela

            switch (opcao) // Início da seleção do menu
            {
            case 1:
                registro(); // Chamada de funções
                break;

            case 2:
                consultar();
                break;

            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                laco = 0; // Define laco para 0 para sair do loop
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
            }
        }
    }
    else
    {
        printf("Senha incorreta!\n"); // Adicionado '\n' para melhor formatação
        system("pause"); // Adicionado pause para que o usuário veja a mensagem
    }

    return 0;
}
