// Wagner Kauan Mendes dos Santos  -  Turma 1
// Allison do Vale Santos  -   Turma 2

#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Necessário para usar a função strcmp
#include <stdlib.h> // Necessário para usar a função system()

// Função limpar tela para ambos os sistemas.
void limparTela()
{
#ifdef _WIN32
    system("cls"); // Comando para Windows
#elif __linux__
    system("clear"); // Comando para Linux
#else
    printf("Comando de limpar tela não suportado no seu sistema.\n");
#endif
}

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
        limparTela(); // Chama a função que limpa a tela

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

// função para ferificar se o codigo do produto ja existe.
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
// função para printar o alimento na tela
void aparecer(int tam, char matriz[][50])
{

    printf("%s\n", matriz[tam]);
}

// função para calcular o lruco estimado de cada produto, com base na quantidade, preço unitario e o preço de custo.
// void calcularlucro(float lucro_estimado[], float venda[], int quanti[], float custo[], int i)
//{
//
// lucro_estimado[i] += ((venda[i] * quanti[i]) - custo[i]);
//}
// função para consultar produto em estoque

// função para verificar se id digitado pelo usuario existe no estoque
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
// função para calcular margem de lucro esperado do produto com base no preço de venda e no preço de custo unitario
float calcularlucroproduto(int indice, float preco_venda[], float preco_custo[], int quantidade_[])
{

    return (((preco_venda[indice] * quantidade_[indice]) - (preco_custo[indice] * quantidade_[indice])) / (preco_custo[indice] * quantidade_[indice])) * 100;
}
// função para adicionar lucro no cixa quando sair a venda de produtos
void adicionar_lucro(float *caixa, int saida, float preco[], int indice)
{

    *caixa += (saida * preco[indice]);
}
// função para ajustar o preço de custo de um produto e atualizar o caixa
void trocar_preco_de_custo(float *caixa, float novo_preco_de_custo, float preco_de_custo_antigo[], int indice)
{
    int temp;
    if (novo_preco_de_custo > preco_de_custo_antigo[indice])
    {
        temp = (novo_preco_de_custo - preco_de_custo_antigo[indice]);
        *caixa -= temp;
        preco_de_custo_antigo[indice] = novo_preco_de_custo;
    }
    else
    {
        temp = (preco_de_custo_antigo[indice] - novo_preco_de_custo);
        *caixa += temp;
        preco_de_custo_antigo[indice] = novo_preco_de_custo;
    }
}
// função para adicionar custo do produto no caixa, para ficar sempre atualizado
void adicionar_custo(float custoadcional, float custooriginal[], int indice)
{
    custooriginal[indice] += custoadcional;
}

// função para adicionar produtos do estoque
int adicionar_produtos(int vetor[], int indice, int quantidade_de_produtos)
{
    return vetor[indice] += quantidade_de_produtos;
}
// Função de relatorios e estatistica
void relatorio_e_estatistica(float preco_de_custo_unitario[], int quantidade_[], float preco_de_venda[], char nomes[][50], char categorias[][50], int indice, int indice_de_produtos[])
{
    float lucro_potencial_estimao = 0;
    printf("               Produtos cadastrados no sistemas \n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < indice; i++)
    {
        printf("  %d° :produto \n", i + 1);
        printf(" Codigo do produto : %d\n", indice_de_produtos[i]);
        printf(" Nome do produto : %s\n", nomes[i]);
        printf(" Categoria do produto : %s\n", categorias[i]);
        printf(" Preço unitario de venda : R$= %.2f\n", preco_de_venda[i]);
        printf(" Quantidade do produto em estoque : %d\n", quantidade_[i]);
        printf(" Valor total do estoque : R$= %.2f\n", (preco_de_custo_unitario[i] * quantidade_[i]));
        printf(" Margem de lucro aproximadamente : R$=  %.2f%%\n", calcularlucroproduto(i, preco_de_venda, preco_de_custo_unitario, quantidade_));
        printf("\n--------------------------------------------------------\n");
        printf("\n");
        lucro_potencial_estimao += calcularlucroproduto(i, preco_de_venda, preco_de_custo_unitario, quantidade_);
    }
    printf("A margem de lucro aproximadamente dos protudos em estoque : R$= %.2f%%\n", lucro_potencial_estimao);
}

// função para calcular o lucro total estimado com todos os produtos em estoque
float lucro_de_produtos_estimados(float preco_devenda[], int quantidad[], int indice)
{
    float lucrototal = 0;
    for (int i = 0; i < indice; i++)
    {
        lucrototal += (preco_devenda[i] * quantidad[i]);
    }

    return lucrototal;
}
// função para retirar produtos do estoque
int saida_de_produtos(int vetor[], int quantidade_de_produtos, int indice)
{

    return vetor[indice] -= quantidade_de_produtos;
}

// Função para consultar caixa.
void consultar_caixa(float total, float caixa_, int saidas__registradas, char produto[][50], int quantidades__vendidas[], float valores__arrecadados[], int indice_[])
{
    // Exibição das informações
    printf("\n-------------------- Informações do Caixa --------------------\n");
    printf("- Saldo atual do caixa: R$ %.2f\n", caixa_);
    printf("- Lucro total estimado com os produtos em estoque: R$ %.2f\n", total);

    printf("\n--------------- Todas as saídas registradas -----------------\n");
    if (saidas__registradas == 0) // verifica se houve alguma saida para registrar.
    {
        printf("\n                Nenhuma saida registrada!\n");
    }
    else
    {
        for (int i = 0; i < saidas__registradas; i++) // Lista todas as saidas.
        {
            printf("%d Saida. Produto: %s\n", i + 1, produto[indice_[i]]);
            printf("   Quantidade vendida: %d unidades\n", quantidades__vendidas[i]);
            printf("   lucro obtido com a venda do produto : R$ %.2f\n", valores__arrecadados[i]);
            printf("\n");
        }
    }
    // Limpar o buffer
    while (getchar() != '\n')
        ; // Remove o '\n' ou qualquer caractere restante no buffer
    printf("-------------------------------------------------------------\n");
    printf("Pressione Enter para continuar.");
    getchar();    // Aguarda até o usuário pressionar Enter
    limparTela(); // Chama a função que limpa a tela
}

int main()
{
    // variáves
    int temp, produtos_em_estoque_maximo = 50, lucro_maximo = 0, decisao, indice[50], opcao[50], case2[50], case21[50], id[50], quantidade[50], quantidades_vendidas[50], k = 0, quantidade_adicional = 0, quantidade_saida = 0, total_saidas, idconsulta, saidas_registradas = 0, r = 0, i = 0, p = 0, o = 0;
    float precodecustounitario[50], precodevenda[50], precodecusto[50], total_lucro, valores_arrecadados[50], caixa = 0, custo_adicional, novoprecodecusto = 0;
    char nome[50][50], categoria[50][50];
    // Credenciais predefinidas login
    const char usuarioCorreto[] = "admin";
    const char senhaCorreta[] = "1234";
    const int tentativasMaximas = 3;

    printf("\n------------------------------\n");
    printf("Bem-vindo ao sistema de login!\n");
    printf("------------------------------\n");

    // Chamar a função de login
    if (realizarLogin(usuarioCorreto, senhaCorreta, tentativasMaximas))
    {
        printf("\nLogin bem-sucedido! Bem-vindo ao sistema.\n");
        printf("\n");
    }
    else
    {
        printf("\n----------------------------------------------------------------\n");
        printf("\nNúmero máximo de tentativas excedido. Acesso bloqueado.\n");
        printf("\n----------------------------------------------------------------\n");
        return 1;
    }
    while (opcao[i] != 6) // condição para repetição
    {
        i++;
        opcao[i] = 0;
        // Menu interativo com usuário.
        printf(" Escolha uma opção do menu a seguir que deseja fazer no seu supermecado :\n");
        printf("--------------------------MENU-------------------------------\n");
        printf("  1- Cadastar produto.\n");
        printf("  2- Consultar, Editar e Realizar Entrada em Estoque. \n");
        printf("  3- Registrar saida em Estoque e controle de Caixa. \n");
        printf("  4- Consultar Caixa. \n");
        printf("  5- Relatórios e Estatisticas.\n");
        printf("  6- Sair. \n");
        scanf("%d", &opcao[i]);
        limparTela(); // Chama a função que limpa a tela

        switch (opcao[i])
        {
        case 1:
            if (produtos_em_estoque_maximo == 0)
            {
                printf("\n------------------------------------------------------------------\n");
                printf("            Número máximo de produtos no estoque já alcançado.\n");
                printf("\n------------------------------------------------------------------\n");
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para continuar.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
                break;
            }

            printf("-------------------Cadastro de Produto-----------------\n");
            while (1)
            { // Solicita e valida o código do produto
                printf("Digite o código do produto (apenas números): ");
                if (scanf("%d", &id[k]) != 1)
                {                 // Verifica se a entrada é um número válido
                    limparTela(); // Chama a função que limpa a tela
                    printf("\n----------------------------------------------------------\n");
                    printf("       Erro: O código deve ser um número válido!");
                    printf("\n-----------------------------------------------------------\n");
                    while (getchar() != '\n')
                        ; // Limpa o buffer para evitar loops infinitos
                }
                else if (verificar1(id, k))
                {                 // Verifica se o código já existe
                    limparTela(); // Chama a função que limpa a tela
                    printf("\n------------------------------------------------------------------\n");
                    printf("Erro: O código digitado já existe, por favor, digite outro código!");
                    printf("\n------------------------------------------------------------------\n");
                }
                else
                {
                    limparTela(); // Chama a função que limpa a tela
                    printf("-------------------Cadastro de Produto-----------------\n");
                    printf("Código do produto: %d\n", id[k]);
                    break; // Sai do loop se o código for válido e não repetido
                }
            }
            printf("Digite o nome do produto : ");
            scanf("%s", &nome[k]);
            // aparecer(k, nome);
            printf("Digite a categoria do produto : ");
            scanf("%s", &categoria[k]);
            // aparecer(k, categoria);
            printf("Digite a quantidade de produtos : ");
            scanf("%d", &quantidade[k]);
            while (quantidade[k] < 0 || quantidade[k] % 1 != 0)
            {
                printf("Erro!!!, a quantidade de produtos deve ser um número inteiro e positivo !\n");
                printf("Digite a quantidade novamento para continuar com o cadastro \n");
                scanf("%d", &quantidade[k]);
            }
            printf("Digite o preço unitario de venda : ");
            scanf("%f", &precodevenda[k]);
            while (precodevenda[k] < 0)
            {
                printf("Erro!!!, o preço de venda do produto deve ser um número positivo !\n");
                printf("Digite o preço de venda novamente para continuar com o cadastro \n");
                scanf("%f", &precodevenda[k]);
            }
            printf("Digite o preço que custou os %d %s :", quantidade[k], nome[k]);
            scanf("%f", &precodecusto[k]);

            if (precodecusto[k] > (precodevenda[k] * quantidade[k]))
            {
                printf("\n----------------------------------------------------------------\n");
                printf("Preço de custo do produto %s muito alto, não vai compensar vender o produto \nPois ele não vai retornar lucro !!\n", nome[k]);
                printf("Deseja continuar com o cadasto do produto ?\n");
                printf("1- SIM\n");
                printf("2- NÃO\n");
                scanf("%d", &decisao);
                if (decisao == 2)
                {

                    printf("Cadastro excluido, otima decisão !");
                    while (getchar() != '\n')
                        ; // Remove o '\n' ou qualquer caractere restante no buffer
                    printf("\nPressione Enter para continuar.\n");
                    getchar();    // Aguarda até o usuário pressionar Enter
                    limparTela(); // Chama a função que limpa a tela
                    break;
                }
            }

            precodecustounitario[k] = (precodecusto[k] / quantidade[k]);
            temp=precodecustounitario[k];
            lucro_maximo=(temp+(temp/2));
            if (lucro_maximo < precodevenda[k])
            {
                limparTela(); // Chama a função que limpa a tela
                printf("\n------------------------------------------------------------------\n");
                printf("Erro: O preço de venda do produto %s muito alto, algo de errado não esta certo, tente novamnete \n", nome[k]);
                printf("O lucro maximo que pode ser obtido com o produto %s é de R$ %.2d reais\n", nome[k], lucro_maximo);
                printf("O cadastro sera excluido, se presistir o problema procure ajuda !\n");
                // ponto de parada.
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para continuar.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
                break;
            }

            limparTela(); // Chama a função que limpa a tela
            printf("        Produto cadastrado com sucesso!");
            printf("\n---------------------------------------------------\n");
            printf("Código do produto: %d\n", id[k]);
            printf("Nome do produto: %s\n", nome[k]);
            printf("Categoria do produto: %s\n", categoria[k]);
            printf("Preço unitario de venda: R$ %.2f\n", precodevenda[k]);
            printf("Quantidade de produtos: %.2d\n", quantidade[k]);
            printf("Preço que custou os %d %s: R$ %.2f\n", quantidade[k], nome[k], precodecusto[k]);
            printf("Preço de custo por unidade: R$ %.2f\n", precodecustounitario[k]);
            printf("\n---------------------------------------------------\n");

            caixa -= precodecusto[k];
            k++;
            produtos_em_estoque_maximo--;
            // ponto de parada.
            while (getchar() != '\n')
                ; // Remove o '\n' ou qualquer caractere restante no buffer
            printf("\nPressione Enter para continuar.\n");
            getchar();    // Aguarda até o usuário pressionar Enter
            limparTela(); // Chama a função que limpa a tela
            break;
        case 2:

            printf("Opção 2: Consultar, Editar e Realizar Entrada em Estoque.\n");
            if (k == 0)
            {
                printf("Não existe produtos cadastrados ainda !!, imposivel de realizar a opção 2\n");
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para continuar.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
                break;
            }

            int o = 0;
            while (case2[o] != 4) // Sub menu.
            {
                o++;
                case2[o] = 0;

                printf("                 Oque deseja fazer ? \n");
                printf("1- Consultar produto : \n");
                printf("2- Editar produto :\n");
                printf("3- Entrada em Estoque : \n");
                printf("4- Voltar.\n");
                scanf("%d", &case2[o]);
                limparTela(); // Chama a função que limpa a tela

                switch (case2[o])
                {
                case 1:
                    printf("----------------------- Consultar produto ------------------------\n");

                    printf("Digite o código do protudo, para fazer a consultar no estoque :\n");
                    scanf("%d", &idconsulta);
                    r = consultar(idconsulta, id, k); // Verifica se existe produto com o código digitado.
                    limparTela();                     // Chama a função que limpa a tela

                    if (r != -1)
                    {
                        printf("        Produto com com código %d encontrado !!!\n", idconsulta);
                        printf("\n--------------------------------------------------------\n");
                        printf(" Nome do produto : %s\n", nome[r]);
                        printf(" Categoria do produto : %s\n", categoria[r]);
                        printf(" Preço unitario de venda : R$= %.2f\n", precodevenda[r]);
                        printf(" Preço de custo do produto : R$= %.2f\n", precodecusto[r]);
                        printf(" Quantidade do produto em estoque : %d\n", quantidade[r]);
                        printf(" Margem de lucro esperado do produto: R$= %.2f%%\n", calcularlucroproduto(r, precodevenda, precodecustounitario, quantidade));
                        printf("\n--------------------------------------------------------\n");
                        while (getchar() != '\n')
                            ; // Remove o '\n' ou qualquer caractere restante no buffer
                        printf("\nPressione Enter para voltar ao menu.\n");
                        getchar();    // Aguarda até o usuário pressionar Enter
                        limparTela(); // Chama a função que limpa a tela
                        break;
                    }
                    else
                    {
                        printf("\n----------------------------------------------------------------\n");
                        printf("          Produto com código %d não encontrado !!!\n", idconsulta);
                        printf("\n----------------------------------------------------------------\n");
                        while (getchar() != '\n')
                            ; // Remove o '\n' ou qualquer caractere restante no buffer
                        printf("\nPressione Enter para continuar.\n");
                        getchar();    // Aguarda até o usuário pressionar Enter
                        limparTela(); // Chama a função que limpa a tela3
                    }
                    break;
                case 2:
                    p = 0;
                    while (case21[p] != 5) // Sub menu.
                    {
                        p++;
                        case21[p] = 0;

                        // vai editar o produto de acordo com oque ele deseja editar, com base no id do produto.
                        printf("------------------ Editar produto --------------\n");
                        printf("Oque deseja fazer ?\n");
                        printf("1- Editar nome do produto.\n");
                        printf("2- Editar categoria do produto.\n");
                        printf("3- Editar preço unitario do produto.\n");
                        printf("4- Editar preço de custo do produto.\n");
                        printf("5- Voltar.\n");
                        scanf("%d", &case21[p]);
                        printf("\n--------------------------------------------------\n");
                        limparTela(); // Chama a função que limpa a tela

                        switch (case21[p])
                        {
                        case 1:
                            printf("Digite o código do produto que deseja editar o nome :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            limparTela(); // Chama a função que limpa a tela
                            if (r != -1)
                            {
                                printf("Nome atual do produto: %s\n", nome[r]);
                                printf("Digite o novo nome do produto :\n");
                                scanf("%s", &nome[r]);
                                limparTela(); // Chama a função que limpa a tela
                                printf("Nome do produto editado com sucesso !!!\n");

                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para voltar ao menu.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            else
                            {
                                printf("\n----------------------------------------------------------------\n");
                                printf("            Produto com código %d não encontrado !!!\n", idconsulta);
                                printf("\n----------------------------------------------------------------\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para continuar.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            break;
                        case 2:
                            printf("Digite o código do produto que deseja editar a categoria :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            limparTela(); // Chama a função que limpa a tela
                            if (r != -1)
                            {
                                printf("Categoria atual do produto: %s\n", categoria[r]);
                                printf("Digite a nova categoria do produto :\n");
                                scanf("%s", &categoria[r]);
                                limparTela(); // Chama a função que limpa a tela
                                printf("Categoria do produto editado com sucesso !!!\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para voltar ao menu.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            else
                            {
                                printf("\n----------------------------------------------------------------\n");
                                printf("         Produto com código %d não encontrado !!!\n", idconsulta);
                                printf("\n----------------------------------------------------------------\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para continuar.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            break;
                        case 3:
                            printf("Digite o código do produto que deseja editar o preço de venda :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            limparTela(); // Chama a função que limpa a tela
                            if (r != -1)
                            {

                                printf("Preço unitario atual do produto : %.2f \n", precodevenda[r]);
                                printf("Digite o novo preço unitario do prduto :\n");
                                scanf("%f", &precodevenda[r]);
                                limparTela(); // Chama a função que limpa a tela
                                printf("Categoria do produto editado com sucesso !!!\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para voltar ao menu.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            else
                            {
                                printf("\n----------------------------------------------------------------\n");
                                printf("          Produto com código %d não encontrado !!!\n", idconsulta);
                                printf("\n----------------------------------------------------------------\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para continuar.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            break;
                        case 4:
                            printf("Digite o código do produto que deseja editar o preço de custo :\n");
                            scanf("%d", &idconsulta);
                            r = consultar(idconsulta, id, k);
                            limparTela(); // Chama a função que limpa a tela
                            if (r != -1)
                            {

                                printf("Preço custo atual do produto : %.2f \n", precodecusto[r]);
                                printf("Digite o novo preço de custo do prduto :\n");
                                scanf("%f", &novoprecodecusto);
                                trocar_preco_de_custo(&caixa, novoprecodecusto, precodecusto, r);
                                limparTela(); // Chama a função que limpa a tela
                                printf("Preço de custo do produto editado com sucesso !!!\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para voltar ao menu.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            else
                            {
                                printf("\n----------------------------------------------------------------\n");
                                printf("         Produto com código %d não encontrado !!!\n", idconsulta);
                                printf("\n----------------------------------------------------------------\n");
                                while (getchar() != '\n')
                                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                                printf("\nPressione Enter para continuar.\n");
                                getchar();    // Aguarda até o usuário pressionar Enter
                                limparTela(); // Chama a função que limpa a tela
                            }
                            break;
                        case 5:
                            printf("\n----------------------------------------------------------------\n");
                            printf("             voltando..\n");
                            printf("\n----------------------------------------------------------------\n");
                            printf("\nPressione Enter para voltar ao menu.\n");
                            while (getchar() != '\n')
                                ; // Remove o '\n' ou qualquer caractere restante no buffer
                            printf("\nPressione Enter para continuar.\n");
                            getchar();    // Aguarda até o usuário pressionar Enter
                            limparTela(); // Chama a função que limpa a tela
                            break;

                        default:
                            printf("\n----------------------------------------------------------------\n");
                            printf("             Opção invalida, tente novamente \n");
                            printf("\n----------------------------------------------------------------\n");
                            while (getchar() != '\n')
                                ; // Remove o '\n' ou qualquer caractere restante no buffer
                            printf("\nPressione Enter para continuar.\n");
                            getchar();    // Aguarda até o usuário pressionar Enter
                            limparTela(); // Chama a função que limpa a tela
                            break;
                        }
                    }
                    break;
                case 3:
                    if (k == 0)
                    {
                        printf("Não existe produtos cadastrados ainda !!, imposivel de realizar a entrada em estoque \n");
                        while (getchar() != '\n')
                            ; // Remove o '\n' ou qualquer caractere restante no buffer
                        printf("\nPressione Enter para voltar ao menu.\n");
                        getchar();    // Aguarda até o usuário pressionar Enter
                        limparTela(); // Chama a função que limpa a tela
                        break;
                    }
                    // o usuario digita o id do produto, se o produto existir ele vai adicionar novas unidades desse mesmo produto no estoque, se o numero digitado pelo usuario for <0 vai dar um erro e ele vai ter que diigitar a quantidade novamente.
                    printf("--------------------- Entrada em Estoque -------------------------\n");
                    printf("Digite o código do produto para realizar a entrada no estoque :\n");
                    scanf("%d", &idconsulta);
                    r = consultar(idconsulta, id, k);
                    limparTela(); // Chama a função que limpa a tela
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
                        while (quantidade_adicional < 0) // Verifica se o adicional é negativo.
                        {
                            limparTela(); // Chama a função que limpa a tela
                            printf("ERRO!!!. A quantidade de produtos não pode ser adicionada pois é um número negativo \n Digite um número inteiro positivo :\n");
                            scanf("%d", &quantidade_adicional);
                        }
                        printf("Quanto foi pago pelos %d %s ?", quantidade_adicional, nome[r]);
                        scanf("%f", &custo_adicional);
                        caixa -= custo_adicional;
                        adicionar_custo(custo_adicional, precodecusto, r);
                        limparTela(); // Chama a função que limpa a tela
                        printf("sucesso !!, adicionou %d %s  no estoque  \n", quantidade_adicional, nome[r]);
                        adicionar_produtos(quantidade, r, quantidade_adicional);
                        printf("Contem %d unidades de %s em estoque no momento\n", quantidade[r], nome[r]);
                        while (getchar() != '\n')
                            ; // Remove o '\n' ou qualquer caractere restante no buffer
                        printf("\nPressione Enter para voltar ao menu.\n");
                        getchar();    // Aguarda até o usuário pressionar Enter
                        limparTela(); // Chama a função que limpa a tela
                    }
                    else
                    {
                        printf("\n----------------------------------------------------------------\n");
                        printf("Produto com código %d não encontrado !!!\n", idconsulta);
                        printf("\n----------------------------------------------------------------\n");
                        while (getchar() != '\n')
                            ; // Remove o '\n' ou qualquer caractere restante no buffer
                        printf("\nPressione Enter para continuar.\n");
                        getchar();    // Aguarda até o usuário pressionar Enter
                        limparTela(); // Chama a função que limpa a tela
                    }
                    break;
                case 4:
                    printf("\n----------------------------------------------------------------\n");
                    printf("             voltando..\n");
                    printf("\n----------------------------------------------------------------\n");
                    printf("\nPressione Enter para voltar ao menu.\n");
                    while (getchar() != '\n')
                        ; // Remove o '\n' ou qualquer caractere restante no buffer
                    printf("\nPressione Enter para continuar.\n");
                    getchar();    // Aguarda até o usuário pressionar Enter
                    limparTela(); // Chama a função que limpa a tela
                    break;
                default:
                    printf("\n----------------------------------------------------------------\n");
                    printf("               Opção invalida, tente novamente \n");
                    printf("\n----------------------------------------------------------------\n");
                    while (getchar() != '\n')
                        ; // Remove o '\n' ou qualquer caractere restante no buffer
                    printf("\nPressione Enter para continuar.\n");
                    getchar();    // Aguarda até o usuário pressionar Enter
                    limparTela(); // Chama a função que limpa a tela
                    break;
                }
            }

            break;
        case 3:
            if (k == 0)
            {
                printf("Não existe produtos cadastrados ainda !!, imposivel de realizar a opção 3\n");
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para voltar ao menu.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
                break;
            }
            printf("Opção 3: Registrar Saida em Estoque e Controle de Caixa.\n");
            printf("\n");
            printf("Digite o código do produto para realizar a saida em estoque :\n");
            scanf("%d", &idconsulta);

            r = consultar(idconsulta, id, k);
            limparTela(); // Chama a função que limpa a tela
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
                    limparTela(); // Chama a função que limpa a tela
                    printf("\n-------------------------------------------------------------------------------------------------\n");
                    printf("ERRO!!!. A quantidade de produtos no estoque insuficiente para a quantidade que deseja retirar :\n");
                    printf("\n-------------------------------------------------------------------------------------------------\n");
                    printf("A quantidade do produto disponivel no estoque atual é = %d\n", quantidade[r]);
                    printf("\n");
                    printf("Digite uma quantidade de saida menor ou igual a quantidade do produto atual, para dar certo :\n");
                    scanf("%d", &quantidade_saida);
                }
                limparTela(); // Chama a função que limpa a tela
                printf("sucesso !!, a nova quantidade de produtos no estoque é = %d \n", saida_de_produtos(quantidade, quantidade_saida, r));
                // Registro das saídas

                quantidades_vendidas[saidas_registradas] += quantidade_saida;                    // Incrementa a quantidade de produtos vendidos
                valores_arrecadados[saidas_registradas] += (quantidade_saida * precodevenda[r]); // Incrementa o valor arrecadado pela venda
                // salvar o indice do produto
                indice[saidas_registradas] = r;
                saidas_registradas++;   // Incrementa o contador de saídas registradas
                if (quantidade[r] <= 3) // Verifica se a quantidade do estoque está baixa.
                {
                    printf("\n-------------------------------------------------------------\n");
                    printf("Quantide do produto %s baixa, contem no estoque %d unidades \n", nome[r], quantidade[r]);
                    printf("Faça a reposição no estoque, para mantelo sempre atualizado \n");
                    printf("\n-------------------------------------------------------------\n");
                }

                adicionar_lucro(&caixa, quantidade_saida, precodevenda, r);
                printf("Caixa atualizado !!!!!!\n");
                printf("Caixa = R$ %.2f\n", caixa);
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para voltar ao menu.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
            }
            else
            {
                printf("\n----------------------------------------------------------------\n");
                printf("Produto com código %d não encontrado !!!\n", idconsulta);
                printf("\n----------------------------------------------------------------\n");
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para continuar.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
            }

            break;
        case 4:
            printf("Opção 4: Consultar Caixa.\n");
            total_lucro = lucro_de_produtos_estimados(precodevenda, quantidade, k);
            consultar_caixa(total_lucro, caixa, saidas_registradas, nome, quantidades_vendidas, valores_arrecadados, indice);
            break;
        case 5:
            limparTela(); // Chama a função que limpa a tela
            printf("Opção 5: Relatórios e Estatísticas.\n");
            if (k == 0)
            {
                printf("Não existe produtos cadatrados ainda !!");
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para voltar ao menu.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
                break;
            }
            else
            {
                relatorio_e_estatistica(precodecustounitario, quantidade, precodevenda, nome, categoria, k, id);
                while (getchar() != '\n')
                    ; // Remove o '\n' ou qualquer caractere restante no buffer
                printf("\nPressione Enter para voltar ao menu.\n");
                getchar();    // Aguarda até o usuário pressionar Enter
                limparTela(); // Chama a função que limpa a tela
            }
            break;
        case 6:
            printf("\n----------------------------------------------------------------\n");
            printf("\n                    Programa encerrado.\n");
            printf("\n----------------------------------------------------------------\n");
            return 0;
            break;
        default:
            printf("\n----------------------------------------------------------------\n");
            printf("Opção invalida, tente novamente \n");
            printf("\n----------------------------------------------------------------\n");
            break;
        }
    }

    // printf(" O lucro total foi R$= %.2lf\n", lucrototal);
    return 0;
}
