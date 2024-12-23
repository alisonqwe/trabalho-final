#include <stdio.h>
#include <stdbool.h>
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

// funsão para calcular o liucro
void calcularlucro(double *lucro, float venda[], int quanti[], float custo[], int i)
{

    *lucro += ((venda[i] * quanti[i]) - custo[i]);
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

int main()
{

    int opcao = 0, opcao2 = 0, id[50], quantidade[50], k = 0;
    float precodevenda[50], precodecusto[50];
    double lucrototal = 0;
    char nome[50][50], categoria[50][50];

    while (opcao != 6)
    {

        printf(" Escolha uma opção do menu a seguir que deseja fazer no seu supermecado :\n");
        printf("------------------------MENU-------------------------------\n");
        printf("  1- Cadastar produto.\n");
        printf("  2- Consultar, Esitar e Realizar Entrada em Estoque. \n");
        printf("  3- Registrar saida em Estoque e controle de Caixa. \n");
        printf("  4- Consultar Caixa. \n");
        printf("  5- Relatórios e ..............Estatisticas.\n");
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
            printf("Digite o nome do produto :");
            scanf("%s", &nome[k]);
            // aparecer(k, nome);
            printf("Digite a categoria do produto :\n");
            scanf("%s", &categoria[k]);
            // aparecer(k, categoria);

            printf("Digite o preço unitario de venda :\n");
            scanf("%f", &precodevenda[k]);
            printf("Digite o preço de custo de produto  :\n");
            scanf("%f", &precodecusto[k]);
            printf("Digite a quantidade de produtos : \n");
            scanf("%d", &quantidade[k]);
            calcularlucro(&lucrototal, precodevenda, quantidade, precodecusto, k);
            k++;
            break;
        case 2:
            printf("Opção 2: Consultar, Editar e Realizar Entrada em Estoque.\n");
            while (opcao2 != 4)
            {
                printf("                 Oque degeja fazer ? \n");
                printf("1- Consultar produto : \n");
                printf("2- Editar produto :\n");
                printf("3- Entrada em Estoque : \n");
                printf("4- Voltar.\n");
                scanf("%d", &opcao2);
                int idconsulta;

                switch (opcao2)
                {
                case 1:
                    printf("                        Consultar produto:\n");
                    printf("Digite o código do protudo, para fazer a consultar no estoque :\n");
                    scanf("%d", &idconsulta);
                    int r = consultar(idconsulta, id, k);
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
                    int opcao21;
                case 2:
                    while (opcao21 != 5)
                    {

                        printf("                        Editar produto:\n");
                        printf("Oque deseja fazer ?\n");
                        printf("1- Editar nome do produto.\n");
                        printf("2- Editar categoria do produto.\n");
                        printf("3- Editar preço de unitario do produto.\n");
                        printf("4- Editar preço de custo do produto.\n");
                        printf("5- Voltar.\n");
                        scanf("%d", &opcao21);
                        switch (opcao21)
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

                        default:
                            printf("Opção invalida, tente novamente \n");
                            break;
                        }
                    }
                    break;

                default:
                    printf("Opção invalida, tente novamente \n");
                    break;
                }
            }

            break;
        case 3:
            printf("Opção 3: Registrar Saida em Estoque e Controle de Caixa.\n");
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
