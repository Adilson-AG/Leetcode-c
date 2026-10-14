#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Two Sum (LeetCode 1)
 *
 * Dado um array de inteiros nums e um inteiro alvo, encontrar os indices
 * de dois numeros que somados dao o alvo. Existe exatamente uma solucao
 * e o mesmo elemento nao pode ser usado duas vezes.
 *
 * Estrategia: percorrer o array uma vez. Para cada numero x, procurar o
 * complemento (alvo - x) numa tabela hash com os numeros ja vistos.
 *
 * Complexidade: O(n) de tempo e O(n) de espaco.
 */

/* Tabela hash com enderecamento aberto (sondagem linear). */
typedef struct {
  int* chaves;         /* valor do numero guardado         */
  int* indices;        /* posicao desse numero no array    */
  char* ocupado;       /* 1 se a posicao esta em uso       */
  unsigned capacidade; /* sempre potencia de 2             */
} TabelaHash;

/* Cria uma tabela com capacidade >= 2 * quantidade (poucas colisoes). */
static int criarTabela(TabelaHash* t, int quantidade) {
  t->capacidade = 2;
  while (t->capacidade < (unsigned)quantidade * 2) {
    t->capacidade <<= 1;
  }
  t->chaves = malloc(t->capacidade * sizeof(int));
  t->indices = malloc(t->capacidade * sizeof(int));
  t->ocupado = calloc(t->capacidade, sizeof(char));
  return t->chaves && t->indices && t->ocupado;
}

static void liberarTabela(TabelaHash* t) {
  free(t->chaves);
  free(t->indices);
  free(t->ocupado);
}

/* Transforma um inteiro em uma posicao da tabela. */
static unsigned posicao(const TabelaHash* t, int valor) {
  unsigned h = (unsigned)valor * 2654435761u;
  h ^= h >> 16;
  return h & (t->capacidade - 1);
}

/* Guarda o par (valor -> indice). */
static void inserir(TabelaHash* t, int valor, int indice) {
  unsigned p = posicao(t, valor);
  while (t->ocupado[p]) {
    p = (p + 1) & (t->capacidade - 1); /* colisao: tenta a proxima */
  }
  t->ocupado[p] = 1;
  t->chaves[p] = valor;
  t->indices[p] = indice;
}

/* Procura o valor. Retorna 1 e preenche *indice se encontrar, 0 se nao. */
static int buscar(const TabelaHash* t, int valor, int* indice) {
  unsigned p = posicao(t, valor);
  while (t->ocupado[p]) {
    if (t->chaves[p] == valor) {
      *indice = t->indices[p];
      return 1;
    }
    p = (p + 1) & (t->capacidade - 1);
  }
  return 0;
}

/**
 * @brief Encontra dois indices cujos valores somam o alvo.
 * @param nums      Array de inteiros.
 * @param tamanho   Quantidade de elementos do array.
 * @param alvo      Soma desejada.
 * @param resultado Array de 2 posicoes que recebe os indices.
 * @return 1 se encontrou uma solucao, 0 se nao encontrou (ou erro de memoria).
 */
int doisSomam(const int* nums, int tamanho, int alvo, int resultado[2]) {
  TabelaHash tabela;
  if (!criarTabela(&tabela, tamanho)) {
    liberarTabela(&tabela);
    return 0;
  }

  int achou = 0;
  for (int i = 0; i < tamanho && !achou; i++) {
    long long complemento = (long long)alvo - nums[i]; /* evita overflow */
    int indiceComplemento;

    /* So busca se o complemento cabe em um int */
    if (complemento >= INT_MIN && complemento <= INT_MAX &&
        buscar(&tabela, (int)complemento, &indiceComplemento)) {
      resultado[0] = indiceComplemento;
      resultado[1] = i;
      achou = 1;
    } else {
      /* Guarda o numero atual DEPOIS de buscar, para nao usar o mesmo
         elemento duas vezes. */
      inserir(&tabela, nums[i], i);
    }
  }

  liberarTabela(&tabela);
  return achou;
}

/* Le o array e o alvo do usuario e mostra o resultado. */
int main(void) {
  int tamanho;
  printf("Digite o tamanho do array: ");
  if (scanf("%d", &tamanho) != 1 || tamanho < 2 || tamanho > 10000) {
    printf("Tamanho invalido (use de 2 a 10000).\n");
    return 1;
  }

  int* nums = malloc(tamanho * sizeof(int));
  if (nums == NULL) {
    printf("Erro de memoria.\n");
    return 1;
  }

  printf("Digite os elementos do array: ");
  for (int i = 0; i < tamanho; i++) {
    if (scanf("%d", &nums[i]) != 1) {
      printf("Entrada invalida.\n");
      free(nums);
      return 1;
    }
  }

  int alvo;
  printf("Digite a soma alvo: ");
  if (scanf("%d", &alvo) != 1) {
    printf("Entrada invalida.\n");
    free(nums);
    return 1;
  }

  int resultado[2];
  if (doisSomam(nums, tamanho, alvo, resultado)) {
    printf("Indices: [%d, %d]\n", resultado[0], resultado[1]);
  } else {
    printf("Nenhuma solucao encontrada.\n");
  }

  free(nums);
  return 0;
}
