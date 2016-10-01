#include <locale.h>// BIBLIOTECA DE REGIONALIZA��O DO C (UTILIZADA NO ARQUIVO MAIN)
#include "f_arquivo.h"// Fun��es para manipular o arquivo .txt ou seu conte�do
#include "f_arvore.h"// TAD da �rvore de Huffman como Arvore
#include "compactar.h"
#include "descompactar.h"
#include "f_lista.h"// Fun��es para utilizar a �rvore de Huffman na estrutura de Lista
#include "f_hashtable.h"

//N�o recebe parametros, devolve 0 se chegar ao fim do programa e aqui come�a a execu��o do (Des)Compactador
int main()
{
    /// FUN��O QUE DETERMINA A REGIONALIZA��O DO C�DIGO PARA PADR�O. ESSENCIAL PARA IMPRIMIR NA TELA CARACTERES ESPECIAIS
    setlocale(LC_ALL,"");

    // String url salva a URL do arquivo texto que ser� lido
    char url[]="arquivos_txt_para_testes\\eulaENU.txt";

    /// A FUN��O "abrir_Arquivo()" RETORNA UM PONTEIRO DO TIPO "FILE", QUE APONTA PARA ARQUIVO.
    FILE *arq = abrir_Arquivo(url);



    /// -x- A PARTIR DESSE PONTO, J� TEMOS ACESSO AO ARQUIVO .txt -x-



    ///  SE "abrir_Arquivo()" RETORNAR DIFERENTE DE ZERO, ARQUIVO ABERTO COM SUCESSO.
    if(arq != 0)
    {
        int tam = contar_tam_texto_char(arq);//Calculando o tamanho do texto

        /// LEMBRAR QUE UNSIGNED SERVE PARA UTILIZAR TODOS OS BITS DO CHAR E N�O PERDER O BIT DE SINAL
        unsigned char txt[tam];//Declarando o array que possui o mesmo tamanho do texto.
        char letra;//Vari�vel condicional da repeti��o
        int i = 0;//Vari�vel de indice do array txt

        /// OBS.: FOI NECESSARIO ULTILIZAR A FUN��O "rewind()" == "FUN��O QUE REAPONTA "fgetc()" PARA O INICIO DO ARQUIVO."
        /// POIS NA CHAMADA DE "contar_tam_texto_char(arq)" , A FUN��O "fgetc()" ESTAVA APONTANDO PARA O FINAL DO ARQUIVO.
        rewind(arq);

        /// REPETI��O FAZ COPIA DO CONTEUDO DE "arq" PARA BUFFER "txt[]".
        while((letra = fgetc(arq)) != EOF)
        {
            txt[i] = letra;
            i++;
        }
        /// NAO PRECISO MAIS DO ARQUIVO!
        fclose(arq);
        //print_txt(txt,tam);//Verifica��o do Buffer, deve imprimir o mesmo texto de "url".



        /// -x- A PARTIR DESSE PONTO, J� TEMOS O TEXTO DO ARQUIVO .txt SALVO NO BUFFER -x-



        // O ponteiro para N�s cabeca_lista � declarado e inicializado com NULL
        Node *cabeca_lista = criar_Node_NULL();

        /// RECEBEMOS UMA LISTA DE ELEMENTOS QUE CONTEM OS CARACTERES DISTINTOS E A FREQU�NCIA DELES NO TEXTO
        cabeca_lista = criar_lista_Frequencia(cabeca_lista,txt,tam);
        print_lista_Frequencia(cabeca_lista);//Verifica��o da Lista de Huffman, deve ter todos os caracteres distintos.

        puts("\n");



        /// -x- A PARTIR DESSE PONTO, J� TEMOS A LISTA DE HUFFMAN. -x-



        /// UTILIZAMOS UNSIGNED PARA N�O PERDER O BIT DO SINAL.
        /// J� O SHORT, POIS ELE UTILIZA 2 BYTES PARA ARMAZENAR VALORES, EXATAMENTE OS 2 BYTES INICIAIS DO CABE�ALHO
        unsigned short lixo = 0;// Vari�vel para armazenar quantos bits do �ltimo byte n�o ser�o significativos.
        unsigned short tamanho_arvore = 0;// Vari�vel para armazenar quantos n�s tem na arvore de Huffman.

        Node *cabeca_arvore = cabeca_lista;//Criamos uma v�riavel que aponta para o inicio da Lista

        /// AGORA O PONTEIRO cabeca_arvore RECEBE A ARVORE DE HUFFMAN, GERADA A PARTIR DA LISTA ANTERIOR
        cabeca_arvore = criar_arvore_huffman(cabeca_arvore);

        /// CALCULA A PROFUNDIDADE DE CADA N� DA ARVORE E SALVA NA ESTRUTURA DO N� DE HUFFMAN
        calcular_profundidade_nodes(cabeca_arvore,cabeca_arvore->profundidade);
        print_pre_ordem_arvore(cabeca_arvore);// Verifica��o da �rvore de Huffman, deve estar todos os n�s em Pr�-Ordem

        /// A V�RIAVEL lixo RECEBE QUANTOS BITS DO ULTIMO BYTE S�O REPRESENTATIVOS (E 0 SE TODOS O S�O)
        lixo = calcular_lixo(cabeca_arvore, lixo);

        /// FAZEMOS A OPERA��O TERNARIA, DE MODO A SALVAR 0, SE N�O POSSUI LIXO NO ULTIMO BYTE; (8-lixo) SE HOUVER LIXO
        lixo = lixo != 0 ? (8 - lixo): 0 ;

        /// A V�RIAVEL tamanho_arvore RECEBE A QUANTIDADE DE N�S NA ARVORE DE HUFFMAN
        tamanho_arvore = calcular_tam_arvore(cabeca_arvore, tamanho_arvore);



        /// -x- A PARTIR DESSE PONTO, J� TEMOS A ARVORE DE HUFFMAN E AS INFORMA��ES DO CABE�ALHO. -x-



        puts("\n");
        Hashtable *ht = create_hashtable();
        Element *lista = criar_node_hash_null();

        construir_ht(cabeca_arvore,lista,ht);


        cabeca_arvore = remove_arvore(cabeca_arvore);//remove_arvore da um free() na arvore inteira.
        print_ht(ht);// imprime a hash criada baseada na arvore

        ///Se lista == NULL , ent�o a funcao construir_ht foi execultada com sucesso.
        if(lista == NULL)
        {
            puts("construir_ht OK!!");
        }
        else
        {
            puts("construir_ht nao concluido\n");
        }
        ht = remove_hashtable(ht);//remove_hashtable da um free() em todas as listas da hash e na propia hash

        /*FILE *novo_arquivo = fopen("arquivo.huff", "w+x");

        unsigned short cabecalho_inicial = {(converter_lixo(lixo) + tamanho_arvore)};

        escrever_cabecalho_inicio(cabecalho_inicial, novo_arquivo);
        escrever_arvore(cabeca_arvore, novo_arquivo);
        escrever_texto(texto, tamanho_texto, novo_arquivo);
        fclose(novo_arquivo);*/
    }

    return 0;
}

