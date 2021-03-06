/*trabalho de algoritmo - jogo da dama */
#include <stdio.h>
#include <stdlib.h>
#define N 8
/* preenche o tabuleiro com peças e printa */
void printMatriz(char **M){
    int i,j;
    printf("\n   0  1  2  3  4  5  6  7\n");

    for (i = 0; i < N; i++)
    {
      printf("%d ",i);
        for(j = 0; j < N; j++)
        {
            printf("[%c]",M[i][j]);
        }
        printf(" %d",i);
        printf("\n");
    }
    printf("   0  1  2  3  4  5  6  7\n");
}     
char **initialize () {
  /* alocação das linhas e colunas */
  char **M;
  int i,j;
  M = (char **)calloc(N, sizeof(char *));
    for(i = 0; i < N; i++)
        M[i] = (char *)calloc(N, sizeof(char));

    for(i = 0; i < N; i++)
      {
        for(j = 0; j < N; j++)
        {
          if (i == 0 || i == 2)
          {
            if(j%2 == 0)
            {
              M[i][j]=' ';
            }
            else 
            {
              M[i][j]='B';
            }
          }
          else if (i == 1)
          {
            if (j%2 == 0)
            {
              M[i][j]='B';
            }
             else 
            {
              M[i][j]=' ';
            }
          }
          if (i == 5 || i == 7)
          {
            if(j%2 == 0)
            {
              M[i][j]='P';
            }
            else 
            {
              M[i][j]=' ';
            }
          }
          else if (i == 6)
          {
            if (j%2 == 0)
            {
              M[i][j]=' ';
            }
             else 
            {
              M[i][j]='P';
            }
          }
          if (i == 4 || i == 3)
          {
            M[i][j]=' ';
          }
       }

    }        
    return M;
}
/*condições para a realização de jogadas e condições para poder comer */
int step (char **M, int linha,int coluna,int linhadest,int coldest, char jogador) {
        int i,j;

        //para mover não deve retornar 0
        if (linha < 0 || linhadest < 0 || 
            coluna < 0 || coldest < 0 || 
            linha >= N || linhadest >= N ||
            coluna >= N || coldest >= N) 
          { 
            return 0;
          } 
        if ((linha+coluna)%2 == 0 || (linhadest+coldest)%2 == 0) 
          {
         return 0; 
          }

        if (jogador == 'B') 
          {//movimentos não permitidos para B
          if (linhadest == linha ||
              M[linha][coluna] == 'P' || 
              M[linhadest][coldest] !=' ')
          {
            return 0;
          } //lembrando que não pode andar na mesma linha!!
          if (linhadest == linha+1) 
          {
            if (coldest > coluna+1)
            {
              return 0;
            }
            if (coldest < coluna-1)
            {
              return 0;
            }
          }
           if(linhadest == linha+2)//condições de B para poder comer para frente
          { 
            if (M[linha+2][coluna+2] ==' ' && M[linha+1][coluna+1] =='P')
            {
              M[linha][coluna] =' ';
              M[linha+1][coluna+1] =' ';
              M[linhadest][coldest] ='B';
              return 1;   
            } 
            if (M[linha+2][coluna-2] ==' ' && M[linha+1][coluna-1] =='P')
             {
              M[linha][coluna] =' ';
              M[linha+1][coluna-1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
             }
          }
          if (linhadest == linha-2)//para comer para trás
          {
            if (M[linha-1][coluna+1] =='P' && M[linha-2][coluna+2] ==' ')
            {
              M[linha][coluna] =' ';
              M[linha-1][coluna+1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
            }
            if (M[linha-1][coluna-1] =='P' && M[linha-2][coluna-2] == ' ')
            {
              M[linha][coluna] = ' ';
              M[linha-1][coluna-1] =' ';
              M[linha-2][coluna-2] ='B';
              return 1; 
            }
          }
          
          if (linhadest > linha+1 && !linha+2)
          {
            return 0;
          }
          if (linhadest < linha && !linha-2)
          {
            return 0;
          }
         }   
        if (jogador == 'P')
        {//movimentos não permitidos por P
          if( linhadest==linha ||
              M[linha][coluna] == 'B' || 
              M[linhadest][coldest] !=' ')
          {
            return 0;
          }
          if (linhadest == linha-1) 
          {
            if (coldest > coluna+1)
            {
              return 0;
            }
            if (coldest < coluna-1)
            {
              return 0;
            }
          } 
          if(linhadest == linha-2)//condições de P para poder comer 
          { 
            if (M[linha-2][coluna+2] ==' ' && M[linha-1][coluna+1] =='B')
            {
              M[linha][coluna] =' ';
              M[linha-1][coluna+1] =' ';
              M[linhadest][coldest] ='P';
              return 1;   
            } 
            if (M[linha-2][coluna-2] ==' ' && M[linha-1][coluna-1] =='B')
             {
              M[linha][coluna] =' ';
              M[linha-1][coluna-1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
             }
          }
          if (linhadest == linha+2)//para comer para trás
          {
            if (M[linha+1][coluna+1] =='B' && M[linha+2][coluna+2] ==' ')
            {
              M[linha][coluna] =' ';
              M[linha+1][coluna+1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
            }
            if (M[linha+1][coluna-1] =='B' && M[linha+2][coluna-2] == ' ')
            {
              M[linha][coluna] = ' ';
              M[linha+1][coluna-1] =' ';
              M[linha+2][coluna-2] ='P';
              return 1; 
            }
          }
          if (linhadest < linha-1 && !linha-2)
          {
            return 0;
          } 
          if (linhadest > linha && !linha+2)
          {
            return 0;
          }
         }
         
     M[linha][coluna] = ' '; 
     M[linhadest][coldest] = jogador;   
        return 1;
       }
int statusGamer(char **M, char jogador) {
  int i,j;
  int quantidade = 0; 

  for (i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      if (M[i][j] == jogador)
      {
        quantidade++;
      }
    }
  }

  if (quantidade == 0) 
  {
    return 1;
  }
  if (quantidade < 12)
  {
    return 0;
  }
}
int status(char **M) {
  /*condições para vitória 
 (1) - vitoria de B
 (2) - vitoria de P
 (-1) - segue jogo! */
  int i,j;  
  if (statusGamer(M,'P') == 1)
  {
   return 1;
  }
  if (statusGamer(M,'B') == 1)
  { 
  return 2;
  }
  //verifica se pode continuar
  for (i = 0; i < N; i++)
  {
   for (i = j; j < N; j++) 
   {
    if (M[i][j] !=' ')
      return -1;
   }
  }
}      
void game () {  
  char **tabuleiro;
  int linha, coluna,lind,cold;
  char jogador = 'B';
  int jogoativo = -1;
  
  tabuleiro = initialize();

    printf("\nBem vindo ao jogo da Dama!!\n");
    printf("Jogador B começa o jogo!\n");
    while (jogoativo==-1) 
    {
      printMatriz(tabuleiro);
      if (jogador == 'B')
      printf("\nVamos jogador B!! faça seus movimentos\n");
      if (jogador == 'P') 
      printf("\nVamos jogador P!! faça seus movimentos\n");
      printf("Origem: ");
      scanf("%d %d", &linha, &coluna);
      printf("Destino: ");
      scanf("%d %d", &lind, &cold);

      // caso a jogada seja errada
      if (!step(tabuleiro,linha, coluna, lind, cold, jogador)) {     
        printf("\nJogada Invalida!jogue novamente\n");
      continue;
    }

    jogoativo = status(tabuleiro);
    //alternancia de jogador
    if (jogador == 'B')
        jogador = 'P';
      else jogador = 'B';

    }
    if (jogoativo == 1)
    printf("\nFIM DE JOGO!\nParabéns pela vitória jogador B\n");
    
    if (jogoativo == 2) 
    printf("\nFIM DE JOGO!\nParabéns pela vitória jogador P\n");
  
   }   
int main (void) {

  game();
}  
