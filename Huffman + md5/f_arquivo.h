/// INSTRU��O PARA O COMPILADOR S� IMPORTAR AS BIBLIOTECAS ABAIXO QUE N�O EXISTIREM
#pragma once
#include <stdlib.h>//Biblioteca para abrir arquivos
#include <stdio.h>//Biblioteca padr�o de Entrada e Saida do C

/// NESSA BIBLIOTECA EST�O REUNIDAS AS FUN��ES PARA ARQUIVOS txt OU SEU CONTEUDO

//Fun��o que recebe: uma String, representado o local do arquivo a ser aberto, onde url != "\0";
//e se ocorrer bem devolve um ponteiro para um tipo FILE, representado o arquivo .txt,
//se ocorrer algum erro, devolve 0.
FILE *abrir_Arquivo(char *url);

