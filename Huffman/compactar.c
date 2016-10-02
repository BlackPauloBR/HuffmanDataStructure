#include "f_hashtable.h"
#include "compactar.h"
#define TAMANHO_SHORT 16

/* FUN��O UTILIZADA PARA SETAR UM DETERMINADO BIT EM UM CHAR */
unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}

/* FUN��O QUE RETORNA 0(FALSO) OU 1(VERDADEIRO) CASO O BIT SELECIONADO ESTEJA SETADO */
unsigned short is_bit_set(unsigned short c, int i)
{
    unsigned short mask = 1 << i;
    return mask & c;
}

/* FAZ O DESLOCAMENTO DOS 3 BITS DE LIXO PARA OS TR�S PRIMEIROS BITS DO SHORT */
unsigned short converter_lixo(unsigned short lixo)
{
    return lixo << 13;
}

/* ESCREVE O CABE�ALHO(LIXO E TAMANHO DA �RVORE) */
void escrever_cabecalho_inicio(unsigned short cabecalho_inicial, FILE* arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < TAMANHO_SHORT; i++)
    {
        if(is_bit_set(cabecalho_inicial, (15 - i)))
        {
            c = set_bit(c, (7 - (i % TAMANHO_BYTE)));
        }

        if(i % TAMANHO_BYTE == 7)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }
}

/* ESCREVE A �RVORE EM PR�-ORDEM NO ARQUIVO */
void escrever_arvore(Node *cabeca, FILE *arquivo)
{
    if(cabeca != NULL)
    {
        fputc(cabeca->letra, arquivo);
        escrever_arvore(cabeca->filho_esquerda, arquivo);
        escrever_arvore(cabeca->filho_direita, arquivo);
    }
}

/* ESCREVE O TEXTO J� COMPACTADO NO ARQUIVO */
void escrever_texto(unsigned short int *array_texto, int tamanho, FILE *arquivo)
{
    int i;
    unsigned char c = 0;

    for(i = 0; i < tamanho; i++)
    {
        if(array_texto[i] == 1)
        {
            c = set_bit(c, ((7 - (i % TAMANHO_BYTE))));
        }

        if(i % TAMANHO_BYTE == 7)
        {
            fputc(c, arquivo);
            c = 0;
        }
    }

    if(i-1 % TAMANHO_BYTE != 7)
        fputc(c, arquivo);
}

void criar_array_binarios(Hashtable *ht, unsigned char *txt, int tam_txt, unsigned short *array_binario, unsigned int freq_x_profundidade)
{
    int i, c;
    unsigned int j, k = 0;
    unsigned short valor;

    Element *atual = criar_node_hash_null();
    for(i = 0 ; i<tam_txt ; i++)
    {
        c = txt[i];
        atual = ht->table[c];

        if(atual != NULL)
        {
            for(j = k ; j<freq_x_profundidade ; j++)
            {
                if(atual != NULL)
                {
                    valor = atual->value;
                    array_binario[j] = valor;
                    atual = atual->next_element;
                }
                else
                {
                    k = j;
                    break;
                }

            }
        }

        else
        {
            puts("ERRO AO ACESSAR HASHTABLE, LETRA APONTANDO PRA NULO\n");
            return;
        }
    }
}
