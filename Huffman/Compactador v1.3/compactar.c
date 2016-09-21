#include "f_arvore.h"

/* FUN��O PARA ESCREVER AS INFORMA��ES NO ARQUIVO *.huff */
void escrever_arquivo(Node *cabeca, unsigned short lixo, unsigned short tamanho_arvore, char *array_texto, int tamanho)
{
    /* CRIA NOVO ARQUIVO *.HUFF, CASO J� EXISTA N�O � CRIADO */
    FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

    /* COMO O TAMANHO TOTAL DO LIXO MAIS O TAMANHO DA �RVORE � DE 16 BITS, REALIZEI A SOMA
       DO LIXO DESLOCADO 13 VEZES PARA A ESQUERDA E DO TAMANHO DA �RVORE. */
    unsigned short cabecalho_inicial[1] = {converter_lixo(lixo) + tamanho_arvore;}

    /* ESCREVE OS DADOS NO ARQUIVO NA ORDEM: LIXO (3 BITS), TAMANHO DA �VORE(13 BITS),
       �RVORE E TEXTO COMPACTADO */
    fwrite(cabecalho_inicial, sizeof(short), sizeof(cabecalho_inicial), novo_arquivo);

    /* ESCREVE A �RVORE EM PR�-ORDEM */
    escrever_�rvore(cabeca, novo_arquivo);
    /* ESCREVE O TEXTO J� COMPACTADO */
    escrever_texto(array_texto, tamanho, novo_arquivo);

    /* FECHA O ARQUIVO */
    fclose(novo_arquivo);
}

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

/* DESLOCA O LIXO 13 VEZES PARA A ESQUERDA */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

/* ESCREVE A �RVORE NO ARQUIVO */
void escrever_�rvore(Node *cabeca, FILE *arquivo)
{
    if(cabeca != NULL)
    {
        fputc(cabeca->letra, arquivo);
        print_pre_ordem_arvore(cabeca->filho_esquerda);
        print_pre_ordem_arvore(cabeca->filho_direita);
    }
}

void escrever_texto(char *array_texto, int tamanho, File *arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < size; i++)
    {
        if(array_texto[i] == 1)
        {
            c = set_bit(c, (i % 8 + 1));
        }

        if(i % 8 == 1)
        {
            fputs(c, arquivo);
            c = 0;
        }
    }
}
