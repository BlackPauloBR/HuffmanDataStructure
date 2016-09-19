#include "f_arvore.h"

/* Fun��o para escrever as informa��es no arquivo *.huff */
void escrever_arquivo(Node *cabeca, unsigned short lixo, unsigned short tamanho_arvore)
{
    /* Cria novo arquivo.huff, caso j� exista, o arquivo n�o � criado */
    FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

    /* Como o tamanho total do lixo mais o tamanho da �rvore � de 16 bits, realizei a soma
       do lixo deslocado 13 vezes para a esquerda e do tamanho. */
    unsigned short cabecalho_inicial = converter_lixo(lixo) + tamanho_arvore;

    /* Escreve os dados no arquivo na ordem: lixo (3 bits), tamanho da �rvore(13 bits),
       arvore e texto(compactado) */
    fputs(cabecalho_inicial, novo_arquivo);
    fputs(print_pre_ordem_arvore(cabeca), novo_arquivo);
    fputs(escrever_texto, novo_arquivo);
}

/* Desloca o lixo 13 vezes para a esquerda */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

void escrever_texto(Node *cabeca)
{

}
