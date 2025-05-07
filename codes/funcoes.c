#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void carregarEstoque() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado. Criando novo estoque.\n");
        return;
    }
    
    totalProdutos = fread(estoque, sizeof(Produto), MAX_PRODUTOS, arquivo);
    fclose(arquivo);
    printf("Estoque carregado com sucesso. %d produtos registrados.\n", totalProdutos);
}

void salvarEstoque() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar dados.\n");
        return;
    }
    
    fwrite(estoque, sizeof(Produto), totalProdutos, arquivo);
    fclose(arquivo);
    printf("Estoque salvo com sucesso.\n");
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    
    Produto novo;
    printf("\n=== CADASTRO DE NOVO PRODUTO ===\n");
    
    printf("Codigo: ");
    scanf("%d", &novo.codigo);
    limparBuffer();
    
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == novo.codigo) {
            printf("Erro: Codigo ja existe no estoque!\n");
            return;
        }
    }
    
    printf("Nome: ");
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';
    
    printf("Descricao: ");
    fgets(novo.descricao, 100, stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';
    
    printf("Quantidade inicial: ");
    scanf("%d", &novo.quantidade);
    
    printf("Preco unitario: ");
    scanf("%f", &novo.preco_unitario);
    limparBuffer();
    
    estoque[totalProdutos] = novo;
    totalProdutos++;
    
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    printf("\n=== LISTA DE PRODUTOS ===\n");
    printf("%-6s %-20s %-30s %-10s %-10s\n", 
           "Cod", "Nome", "Descricao", "Qtd", "Preco Uni");
    
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-6d %-20s %-30s %-10d %-10.2f\n", 
               estoque[i].codigo, 
               estoque[i].nome, 
               estoque[i].descricao, 
               estoque[i].quantidade, 
               estoque[i].preco_unitario);
    }
}

void menuPrincipal() {
    int opcao;
    do {
        printf("\n=== SISTEMA DE CONTROLE DE ESTOQUE (ETAPA 1) ===\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Listar todos os produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 0: 
                salvarEstoque();
                printf("Saindo do sistema...\n");
                break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);


}

void buscarProduto() {
    int codigo;
    printf("\n=== BUSCAR PRODUTO ===\n");
    printf("Digite o codigo: ");
    scanf("%d", &codigo);
    limparBuffer();
    
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Nome: %s\n", estoque[i].nome);
            printf("Descricao: %s\n", estoque[i].descricao);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Preco unitario: %.2f\n", estoque[i].preco_unitario);
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

void registrarEntrada() {
    int codigo, quantidade;
    printf("\n=== REGISTRAR ENTRADA DE PRODUTO ===\n");
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("Quantidade a adicionar: ");
    scanf("%d", &quantidade);
    limparBuffer();
    
    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }
    
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            estoque[i].quantidade += quantidade;
            printf("Entrada registrada. Nova quantidade: %d\n", estoque[i].quantidade);
            return;
        }
    }
    
    printf("Produto nao encontrado!\n");
}

void registrarSaida() {
    int codigo, quantidade;
    printf("\n=== REGISTRAR SAIDA DE PRODUTO ===\n");
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
    printf("Quantidade a remover: ");
    scanf("%d", &quantidade);
    limparBuffer();
    
    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }
    
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            if (estoque[i].quantidade < quantidade) {
                printf("Erro: Quantidade em estoque insuficiente!\n");
                return;
            }
            
            estoque[i].quantidade -= quantidade;
            printf("Saida registrada. Nova quantidade: %d\n", estoque[i].quantidade);
            return;
        }
    }
    
    printf("Produto nao encontrado!\n");
}

// Atualizar menuPrincipal para Etapa 2
void menuPrincipal() {
    int opcao;
    do {
        printf("\n=== SISTEMA DE CONTROLE DE ESTOQUE (ETAPA 2) ===\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Buscar produto por codigo\n");
        printf("4. Registrar entrada de produtos\n");
        printf("5. Registrar saida de produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: buscarProduto(); break;
            case 4: registrarEntrada(); break;
            case 5: registrarSaida(); break;
            case 0: 
                salvarEstoque();
                printf("Saindo do sistema...\n");
                break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}


