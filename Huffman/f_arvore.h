/// INSTRU��O PARA O COMPILADOR S� IMPORTAR AS BIBLIOTECAS ABAIXO QUE N�O EXISTIREM
#pragma once
#include <stdlib.h>// Biblioteca para abrir arquivos
#include <stdio.h>// Biblioteca padr�o de Entrada e Saida do C

/// NESSA BIBLIOTECA EST� A DEFINI��O DE N� DA ARVORE DE HUFFMAN E AS FUN��ES PARA A ARVORE

typedef struct Node Node;// Para se referir a estrutura n� usar:Node

/// DEFINI��O DE N� DE ACORDO COM OS N�S DEFINIDOS POR HUFFMAN NA ARVORE DE HUFFMAN
struct Node
{
    int num; /// FREQU�NCIA DA variav�l LETRA NO TEXTO
    unsigned char letra; /// CARACTERE CONTIDO NO TEXTO
    int profundidade; /// variav�l QUE CONT�M A PROFUNDIDADE DESSE N� NA ARVORE DE HUFFMAN
    Node *proximo_node; /// PONTEIRO PARA O PROXIMO N� NA LISTA DE HUFFMAN
    Node *filho_esquerda; /// PONTEIRO PARA O N� � ESQUERDA NA LISTA DE HUFFMAN
    Node *filho_direita; /// PONTEIRO PARA O N� � DIREITA NA LISTA DE HUFFMAN
};

//Fun��o que recebe a lista de n�s de Huffman, como um ponteiro para n�s, apontada por cabeca
//e devolve um ponteiro para a raiz da Arvore de Huffman, correspondente � lista passada.
//FUN��O RECURSIVA
Node *criar_arvore_huffman(Node *cabeca_arvore);

void print_pre_ordem_arvore(Node *cabeca_arvore);

//Fun��o que recebe: a �rvore de Huffman, como um ponteiro para n�s, apontada por cabeca;
//um inteiro profundidade, que DEVE SER INICIALIZADO COM 0, para ser utilizado na fun��o;
//e que n�o possui nenhuma devolu��o. FUN��O RECURSIVA.
//Sua a��o � escrever o item profundidade dos n�s da �rvore de Huffman.
void calcular_profundidade_nodes(Node *cabeca_arvore, int profundidade);

unsigned short calcular_lixo(Node *cabeca_arvore, unsigned short lixo);

unsigned short calcular_tam_arvore(Node *cabeca_arvore, unsigned short tam);

Node *remove_arvore(Node *cabeca_arvore);
