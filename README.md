# Projeto03
Controle de Estoque

# OBJETIVO DO PROJETO
Este projeto cria um sistema de controle de estoque em C para gerenciar produtos, registrar entradas/saídas e gerar relatórios. Armazena dados em arquivos binários para persistência e oferece interface simples via terminal, ideal para pequenos negócios que precisam de uma solução offline e eficiente.

# FORMA DE COMPILAÇÃO E EXECUÇÃO
Quando o programa é executado, ele primeiro tenta carregar os dados existentes do arquivo binário estoque.dat. Se for a primeira execução e o arquivo não existir, o sistema inicia com um estoque vazio. O menu principal é então exibido, permitindo ao usuário cadastrar produtos, registrar movimentações e consultar informações. Todas as alterações ficam armazenadas na memória durante a execução. Quando o usuário seleciona a opção de sair ou quando gera um relatório, os dados são persistidos - o estoque atualizado é salvo no arquivo estoque.dat e um relatório completo é gerado no arquivo texto relatorio_estoque.txt. É importante encerrar o programa sempre pela opção de saída do menu para garantir que todas as alterações sejam devidamente salvas. O sistema mantém os dados entre execuções através do arquivo, enquanto o arquivo de texto serve para consultas externas e backup dos dados.

# BREVE EXPLICAÇÃO SOBRE A FORMA DE USO DO PROGRAMA
1.cadastrarProduto: Permite registrar novos itens no estoque informando: Código único (não pode repetir), nome e descrição do produto, quantidade inicial, preço unitário
2.listarProdutos: Mostra todos os produtos em formato de tabela com: Código, nome e descrição, quantidade disponível, preço unitário e valor total (quantidade × preço)
3.buscarProduto/buscarPorNome: Busca por código: retorna todos os dados do produto exato / Busca por nome: encontra produtos com termos parecidos. Resultado: Exibe informações detalhadas do(s) produto(s) encontrado(s)
4.registrarEntrada/registrarSaida: Entrada: aumenta a quantidade em estoque / Saída: diminui a quantidade (com verificação de estoque suficiente). Obrigatório informar código do produto e quantidade. Além de, bloqueiar saídas maiores que o estoque disponível
5.gerarRelatorio: Cria arquivo "relatorio_estoque.txt" contendo: Lista completa de produtos, cálculos de valor total por item, valor agregado de todo o estoque
6.carregarEstoque/salvarEstoque: Ao iniciar, lê dados de "estoque.dat" e ao sair, salva tudo no mesmo arquivo. Só grava no disco ao sair corretamente pelo menu.
7.Encerramento Seguro (Opção 0 no menu): Salva todas as alterações no arquivo e ncerra o programa com confirmação.

# LISTA COM NOMES E MATRÍCULAS DOS PARTICIPANTES DO GRUPO
Lucas Belo Gaspardo - RA: 22.224.007-9
Leonardo Fernandes E. Silva - RA: 52.224.003-5
Luis Guilherme Camillo Teixeira - RA: 22.224.006-1
