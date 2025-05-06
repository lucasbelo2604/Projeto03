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