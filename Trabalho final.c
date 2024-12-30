#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Necessário para usar a função strcmp
#include <stdlib.h> // Necessário para usar a função system()

// Função para realizar o login
int realizarLogin(const char *usuarioCorreto, const char *senhaCorreta, int tentativasMaximas)
{
    char usuario[20];
    char senha[20];
    int tentativas = 0;

    while (tentativas < tentativasMaximas)
    {
        // Solicitar nome de usuário
        printf("\nDigite seu nome de usuário: ");
        scanf("%s", usuario);

        // Solicitar senha
        printf("Digite sua senha: ");
        scanf("%s", senha);

        // Verificar credenciais
        if (strcmp(usuario, usuarioCorreto) == 0 && strcmp(senha, senhaCorreta) == 0)
        {
            // A função strcmp (abreviação de string compare) é usada para comparar duas strings
            return 1; // Login bem-sucedido
        }
        else
        {
            tentativas++;
            system("cls");
            printf("Usuário ou senha incorretos. Tentativas restantes: %d\n", tentativasMaximas - tentativas);
        }
    }

    return 0; // Falha no login após todas as tentativas
}

// funsão para ferificar se o codigo do produto ja existe.
bool verificar1(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i; j < tam; j++)
        {
            if (vetor[i] == vetor[j + 1])
            {
                return true;
            }
        }
    }

    return false;
}
// printar o alimento na tela
void aparecer(int tam, char matriz[][50])
{

    printf("%s\n", matriz[tam]);
}

// funsão para calcular o lruco estimado de cada produto, com base na quantidade, preço unitario e o preço de custo.
void calcularlucro(float lucro_estimado[], float venda[], int quanti[], float custo[], int i)
{

    lucro_estimado[i] += ((venda[i] * quanti[i]) - custo[i]);
}
// funsão para consultar produto em estoque
int consultar(int consultar, int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] == consultar)
        {
            return i;
        }
    }

    return -1;
}
// funsão para calcular lucro esperado do produto
float calcularlucroproduto(int indice, float preco_venda[], int quan[], float preco_custo[])
{

    return (preco_venda[indice] * quan[indice]) - preco_custo[indice];
}

// função para adicionar produtos do estoque
int adicionar_produtos(int vetor[], int indice, int quantidade_de_produtos)
{
    return vetor[indice] += quantidade_de_produtos;
}

// função para retirar produtos do estoque
int saida_de_produtos(int vetor[], int quantidade_de_produtos, int indice)
{

    return vetor[indice] -= quantidade_de_produtos;
}
int main()
{

    int id[50], quantidade[50], k = 0, quantidade_adicional = 0, quantidade_saida = 0, idconsulta, r;
    float precodevenda[50], precodecusto[50], lucro_estimado[50], caixa = 0;
    char nome[50][50], categoria[50][50];
    // Credenciais predefinidas
    const char usuarioCorreto[] = "admin";
    const char senhaCorreta[] = "1234";
    const int tentativasMaximas = 3;
    printf("\n------------------------------\n");
    printf("Bem-vindo ao sistema de login!\n");
    printf("------------------------------\n");

    // Chamar a função de login
    if (realizarLogin(usuarioCorreto, senhaCorreta, tentativasMaximas))
    {
        system("cls");
        printf("\nLogin bem-sucedido! Bem-vindo ao sistema.\n");
        printf("\n");
    }
    else
    {
        system("cls");
        printf("\nNúmero máximo de tentativas excedido. Acesso bloqueado.\n");
        return 1;
    }
    int opcao = 0;
    while (opcao != 6)
    {
        opcao = 0;

        printf(" Escolha uma opção do menu a seguir que deseja fazer no seu supermecado :\n");
        printf("--------------------------MENU-------------------------------\n");
        printf("  1- Cadastar produto.\n");
        printf("  2- Consultar, Editar e Realizar Entrada em Estoque. \n");
        printf("  3- Registrar saida em Estoque e controle de Caixa. \n");
        printf("  4- Consultar Caixa. \n");
        printf("  5- Relatórios e Estatisticas.\n");
        printf("  6- Sair. \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("-------------------Cadastro de Produto-----------------\n");
            printf("Digite o codigo do produto :");
            scanf("%d", &id[k]);
            while (verificar1(id, k))
            {
                printf("O código digitado já existe, porfavor digite outro código :\n");
                scanf("%d", &id[k]);
            }
            printf("Digite o nome do produto : ");
            scanf("%s", &nome[k]);
            // aparecer(k, nome);
            printf("Digite a categoria do produto : ");
            scanf("%s", &categoria[k]);
            // aparecer(k, categoria);

            printf("Digite o preço unitario de venda : ");
            scanf("%f", &precodevenda[k]);
            printf("Digite o preço de custo de produto  : ");
            scanf("%f", &precodecusto[k]);
            printf("Digite a quantidade de produtos : ");
            scanf("%d", &quantidade[k]);

            calcularlucro(lucro_estimado, precodevenda, quantidade, precodecusto, k);
            k++;
            break;
        case 2:
        int case2=0;
            printf("Opção 2: Consultar, Editar e Realizar Entrada em Estoque.\n");
           
            while (case2 != 4)
            {
                case2 = 0;

                printf("                 Oque deseja fazer ? \n");
                printf("1- Consultar produto : \n");
                printf("2- Editar produto :\n");
                printf("3- Entrada em Estoque : \n");
                printf("4- Voltar.\n");
                scanf("%d", &case2);

                switch (case2)
                {
                case 1:
                    printf("                        Consultar produto:\n");
                    printf("Digite o código do protudo, para fazer a consultar no estoque :\n");
                    scanf("%d", &idconsulta);
                    r = consultar(idconsulta, id, k);

                    if (r != -1)
                    {
                        printf("        Produto com com código %d encontrado !!!\n", idconsulta);
                        printf(" Nome do produto : %s\n", nome[r]);
                        printf(" Categoria do produto : %s\n", categoria[r]);
                        printf(" Preço unitario de venda : R$= %.2f\n", precodevenda[r]);
                        printf(" Preço de custo do produto : R$= %.2f\n", precodecusto[r]);
                        printf(" Quantidade do produto em estoque : %d\n", quantidade[r]);
                        printf(" Lucro esperado do produto : R$= %.2f\n", calcularlucroproduto(r, precodevenda, quantidade, precodecusto));
                    }
                    else
                    {
                        printf("        Produto com código %d não encontrado !!!\n", idconsulta);
                    }
                    break;

                case 2:
                    int case21=0;
                    while (case21 != 5)
                    {
                        case21 = 0;

                        // vai editar o produto de acordo com oque ele deseja editar, com base no id do produto.
                        printf("                        Editar produto:\n");
                        printf("Oque deseja fazer ?\n");
                        printf("1- Editar nome do produto.\n");
                        printf("2- Editar categoria do produto.\n");
                        printf("3- Editar preço de unitario do produto.\n");
                        printf("4- Editar preço de custo do produto.\n");
                        printf("5- Voltar.\n");
                        scanf("%d", &case21);

                        switch (case21)
                        {
                        case 1:
                            printf("Digite o código do produto que deseja editar o nome :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            if (r != -1)
                            {
                                printf("Nome atual do produto: %s\n", nome[r]);
                                printf("Digite o novo nome do produto :\n");
                                scanf("%s", &nome[r]);

                                printf("Nome do produto editado com sucesso !!!\n");
                            }
                            else
                            {

                                printf("Produto com código %d não encontrado !!!\n", idconsulta);
                            }
                            break;
                        case 2:
                            printf("Digite o código do produto que deseja editar a categoria :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            if (r != -1)
                            {
                                printf("Categoria atual do produto: %s\n", categoria[r]);
                                printf("Digite a nova categoria do produto :\n");
                                scanf("%s", &categoria[r]);

                                printf("Categoria do produto editado com sucesso !!!\n");
                            }
                            else
                            {

                                printf("Produto com código %d não encontrado !!!\n", idconsulta);
                            }
                            break;
                        case 3:
                            printf("Digite o código do produto que deseja editar o preço de venda :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            if (r != -1)
                            {

                                printf("Preço unitario atual do produto : %.2f \n", precodevenda[r]);
                                printf("Digite o novo preço unitario do prduto :\n");
                                scanf("%f", &precodevenda[r]);

                                printf("Categoria do produto editado com sucesso !!!\n");
                            }
                            else
                            {

                                printf("Produto com código %d não encontrado !!!\n", idconsulta);
                            }
                            break;
                        case 4:
                            printf("Digite o código do produto que deseja editar o preço de custo :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            if (r != -1)
                            {

                                printf("Preço custo atual do produto : %.2f \n", precodecusto[r]);
                                printf("Digite o novo preço de custo do prduto :\n");
                                scanf("%f", &precodecusto[r]);

                                printf("Categoria do produto editado com sucesso !!!\n");
                            }
                            else
                            {

                                printf("Produto com código %d não encontrado !!!\n", idconsulta);
                            }
                            break;

                        case 5:

                            break;

                        default:

                            printf("Opção invalida, tente novamente \n");
                            break;
                        }
                    }
                    break;
                case 3:

                    // o usuario digita o id do produto, se o produto existir ele vai adicionar novar unidades desse mesmo produto no estoque, se o numero digitado pelo usuario for <0 vai dar um erro e ele vai ter que diigitar a quantidade novamente.
                    printf("                       Entrada em Estoque:\n");
                    printf("Digite o código do produto para realizar a entrada no estoque :\n");
                    scanf("%d", &idconsulta);
                    r = consultar(idconsulta, id, k);
                    if (r != -1)
                    {
                        printf("Nome do produto: %s\n", nome[r]);
                        printf("Categoria do produto: %s\n", categoria[r]);
                        printf("Preço unitario do produto : %.2f \n", precodevenda[r]);
                        printf("Preço custo do produto : %.2f \n", precodecusto[r]);
                        printf("Quantidade atual do produto em estoque = %d\n", quantidade[r]);
                        printf("\n");
                        printf("Qual vai ser a quantidade adicionada de protudos ?\n");
                        scanf("%d", &quantidade_adicional);
                        while (quantidade_adicional < 0)
                        {

                            printf("ERRO!!!. A quantidade de produtos não pode ser adicionada pois é um número negativo \n Digite um número inteiro positivo :\n");
                            scanf("%d", &quantidade_adicional);
                        }
                        printf("sucesso !!, você retirou %d ,%s  do estoque  \n", quantidade_saida, nome[r]);
                        printf("Restou %d, %s no estoque ", quantidade[r], nome[r]);
                    }
                    else
                    {
                        printf("Produto com código %d não encontrado !!!\n", idconsulta);
                    }
                    break;

                case 4:

                    break;

                default:
                    printf("Opção invalida, tente novamente \n");
                    break;
                }
            }

            break;
        case 3:
            printf("Opção 3: Registrar Saida em Estoque e Controle de Caixa.\n");
            printf("\n");
            printf("Digite o código do produto para realizar a saida em estoque :\n");
            scanf("%d", &idconsulta);
            r = consultar(idconsulta, id, k);
            if (r != -1)
            {
                printf("Nome do produto: %s\n", nome[r]);
                printf("Categoria do produto: %s\n", categoria[r]);
                printf("Preço unitario do produto : %.2f \n", precodevenda[r]);
                printf("Preço custo do produto : %.2f \n", precodecusto[r]);
                printf("Quantidade atual do produto em estoque = %d\n", quantidade[r]);
                printf("\n");
                printf("Qual vai ser a quantidade de produtos que iram sair  ?\n");
                scanf("%d", &quantidade_saida);
                while (quantidade_saida > quantidade[r])
                {

                    printf("ERRO!!!. A quantidade de produtos no estoque insuficiente para a quantidade que deseja retirar :\n");
                    printf("A quantidade do produto escolhido no estoque atual é = %d\n", quantidade[r]);
                    printf("Digite uma quantidade de saida menor ou igual a quantidade do produto atual, para dar certo :\n");
                    scanf("%d", &quantidade_saida);
                }
                printf("sucesso !!, a nova quantidade de produtos no estoque é =%d \n", saida_de_produtos(quantidade, quantidade_saida, r));
            }
            else
            {
                printf("Produto com código %d não encontrado !!!\n", idconsulta);
            }

            break;
        case 4:
            printf("Opção 4: Consultar Caixa.\n");
            break;
        case 5:
            printf("Opção 5: Relatórios e Estatísticas.\n");
            break;
        case 6:
            printf("Opção 6: Sair.\n");
            break;
        default:
            printf("Opção invalida, tente novamente \n");
            break;
        }
    }

    // printf(" O lucro total foi R$= %.2lf\n", lucrototal);
    return 0;
}
