/// INSTRU��O PARA O COMPILADOR S� IMPORTAR AS BIBLIOTECAS ABAIXO QUE N�O EXISTIREM
#pragma once
#include "f_arvore.h"// Arquivo que possui as definic�es iniciais da �rvore de Huffman

/// NESSA BIBLIOTECA EST�O AS FUN��ES PARA A LISTA DE HUFFMAN

//Fun��o que n�o recebe vari�veis;
//e devolve um ponteiro para N�s, inicializado com NULL
Node *criar_Node_NULL();

//Fun��o que recebe: a lista de n�s de Huffman, como um ponteiro para n�s, apontada por cabeca_lista
//e devolve 0, se a lista passada conter algum elemento,
//ou devolve um inteiro, se a lista estiver vazia.
int esta_Vazia(Node *cabeca_lista);

//Fun��o que recebe: a lista de n�s de Huffman, como um ponteiro para n�s, apontada por cabeca_lista;
//um caractere a ser inserido na lista, armazenado como unsigned char na vari�vel letra;
//a frequ�ncia desse caractere no texto, armazenado no inteiro num;
//e devolve um ponteiro para N�s como o primeiro n� da nova lista, contendo o novo elemento.
Node *add_Node_meio_ordenado(Node *cabeca_lista, unsigned char letra, int num);

//Fun��o que recebe a lista de n�s de Huffman, como um ponteiro para n�s, apontada por cabeca_lista
//e que n�o possui nenhuma devolu��o. FUN��O RECURSIVA.
//Sua a��o � utilizar o printf para imprimir na tela o conteudo da Lista de Huffman. Se estiver vazia, n�o excuta a��o.
// Modelo:   [%c]
void print_lista_Frequencia(Node *cabeca_lista);

//Fun��o que recebe: a lista de n�s de Huffman (preferencialmente vazia), como um ponteiro, apontada por cabeca_lista;
//o texto a ser analizado, como uma String, que ser� apontada por txt;
//o tamanho do texto recebido, armazenado no inteiro tam, onde tam >= 0;
//e devolve a lista de n�s de Huffman, com elementos ordenados pela frequ�ncia do caractere, de acordo com o texto passado.
Node *criar_lista_Frequencia(Node *cabeca_lista, unsigned char *txt, int tam);

//Fun��o que recebe a lista de n�s de Huffman, como um ponteiro para n�s, apontada por cabeca_lista
//e devolve a quantidade de elementos na lista no formato inteiro.
//FUN��O N�O UTILIZADA
int calcular_tam_lista(Node *cabeca_lista);

