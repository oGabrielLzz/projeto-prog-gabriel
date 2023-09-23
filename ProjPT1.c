#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
//declaração das variaveis iniciais
   char nome[50];
   int idade;
//declaração da matriz que servirá como tabela   
   int d = 5,h = 31; // d = dia da semana ; h = horario do dia que sera divido em 30 minutos cada                 
   int tabela[d][h];
//começando a matriz tabela = 0
   for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            tabela[i][j] = 0;
        }
    }
 //entrada dos dados iniciaais em relação ao usuario
    printf("Olá , Seja-bem vindo(a) ao HoraAssist, o seu suporte de horario para estudo\n");
     printf("Digite seu nome:\n");
        scanf("%s",&nome);
     printf("Qual a sua idade:\n");
        scanf("%d",&idade);
//Colete de informação do turno para começarmos a planejar o dia
   int turno;
    printf("Para começarmos , você estuda em qual turno?\nDigite 1 para manha, 2 para tarde ou 3 para tarde:");
      scanf("%d",&turno);
//Revisão para ver se o valor esta entre os informados
    if(turno != 1 && turno != 2 && turno != 3) {
        printf("Valor não definido.\n");
        return 1;
    }
    //tabela de orientação
/* Posições->  0      1     2     3     4     5     6     7     8     9     10    11    12    13    14    15     16   17    18    19    20    21    22    23    24    25    26    27    28     29   30    31   
----------|   6:00  06:30 07:00 07:30 08:00 08:30 09:00 09:30 10:00 10:30 11:00 11:30 12:00 12:30 13:00 13:30 14:00 14:30 15:00 15:30 16:00 16:30 17:00 17:30 18:00 18:30 19:00 19:30 20:00  20:30 21:00 22:00
  segunda |   
  terça   |
  quarta  |
  quinta  |
  sexta   |
*/ 
//incrementando o horario do turno do estudante a tabela geral
    for(int i = 0; i < d;i++){
      for(int j = 0;j < h;j++){

         if(turno == 1){ //turno da 7:00 as 11:00
            if (j >= 1 && j < 11) {
                tabela[i][j] = 1;
             }       
          }else if(turno == 2){ //turno das 13:00 até as 17:00
             if(j > 13 && j < 23){
               tabela[i][j] = 1;
             }
          }else{ //turno das 18:00 até 2git0:00
             if (j >= 24) {
               tabela[i][j] = 1;
             }
          }
      }      
    }  
  //imprimir a matriz tabela
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            printf("%d ", tabela[i][j]);
        }
      printf("\n"); 
    }
 return 0;
}