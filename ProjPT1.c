#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
//declaração das variaveis iniciais
   char nome[50];
   int idade;
//declaração da matriz que servirá como tabela   
   int d = 5,h = 33; // d = dia da semana ; h = horario do dia que sera divido em 30 minutos cada                 
   int rotina[d][h];
//começando a matriz tabela = 0
   for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            rotina[i][j] = 0;
        }
    }
 //entrada dos dados iniciais em relação ao usuario
    printf("-Seja bem vindo(a) ao HoraAssist, o seu suporte de horario para estudo.\n",nome);
     printf("-Digite seu nome:\n");
        scanf("%s",&nome);
     printf("-Qual a sua idade:\n");
        scanf("%d",&idade);
//Colete de informação do turno para começarmos a planejar o dia
   int turno;
    printf("-Ola %s , Para comecarmos preciso saber em qual turno voce estuda?\n-Digite 1 para manha, 2 para tarde ou 3 para tarde:\n",nome);
      scanf("%d",&turno);
//Revisão para ver se o valor esta entre os informados
    if(turno != 1 && turno != 2 && turno != 3) {
        printf("-Valor nao definido.\n");
        return 1;
    }
    //tabela de orientação
/* Posições->  0      1     2     3     4     5     6     7     8     9     10    11    12    13    14    15     16   17    18    19    20    21    22    23    24    25    26    27    28     29   30      
----------|   6:00  06:30 07:00 07:30 08:00 08:30 09:00 09:30 10:00 10:30 11:00 11:30 12:00 12:30 13:00 13:30 14:00 14:30 15:00 15:30 16:00 16:30 17:00 17:30 18:00 18:30 19:00 19:30 20:00  20:30 21:00 
  segunda |   
  terça   |
  quarta  |
  quinta  |
  sexta   |
*/ 
//materias limitaadas a 3
  int numMaterias = 3;
    
 printf("\n");
//armazenando as notas por materia (supondo a 5 notas por materia)
     int not = 5;
    double notas[numMaterias][not];

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite suas ultimas 5 notas da materia %d:\n", i + 1);
        for (int j = 0; j < not; j++) {
            scanf("%lf", &notas[i][j]);
        }
    }
    printf("\n");
    int pontosparaaprovacao[numMaterias];
    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite quantos pontos precisa para ser aprovado na materia %d: ", i + 1);
        scanf("%d", &pontosparaaprovacao[i]);
    }
// Cálculo da prioridade de matéria
    for (int i = 0; i < numMaterias; i++) {
    double somaMat = 0; // Variável para armazenar a soma das notas da matéria i
    for (int j = 0; j < not; j++) {
        somaMat += notas[i][j]; // Acumula as notas da matéria i
    }
    pontosparaaprovacao[i] = pontosparaaprovacao[i] - somaMat; // Calcula a prioridade da matéria i
    }
 printf("\n-Prioridade de materias:\n");
    for (int i = 0; i < numMaterias; i++) {
        printf("-Materia %d: %d pontos faltando para aprovacao\n", i + 1, pontosparaaprovacao[i]);
    }
printf("\n");

//Colocando valores relacionados a materia ou horario de estudo
//incrementando o horario do turno do estudante a tabela rotina  
    for(int i = 0; i < d;i++){
      for(int j = 0;j < h;j++){

         if(turno == 1){ //turno da 7:00 as 11:00
            if (j > 1 && j < 11) {
                rotina[i][j] = 1;
                if(pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 2;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 3;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 2;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 4;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 3;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 2;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 3;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 4;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 2;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 4;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 2;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]){
                    if(j > 13 && j < 21){
                        rotina[i][j] = 4;
                    }
                    if(j > 21 && j < 27 ){
                        rotina[i][j] = 3;
                    }
                    if(j > 26 && j >=32){
                        rotina[i][j] = 2;
                    }

          }else if(turno == 2){ //turno das 13:00 até as 17:00
             if(j > 13 && j < 23){
               rotina[i][j] = 1;
               if(pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 2;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 3;
                    }
                    if(j > 28 && j >=32){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 2;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 4;
                    }
                    if(j > 28 && j >= 32){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 3;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 2;
                    }
                    if(j > 28 && j >= 32){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 3;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 4;
                    }
                    if(j > 28 && j >=32){
                        rotina[i][j] = 2;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 4;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 2;
                    }
                    if(j > 28 && j >=32){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 4;
                    }
                    if(j > 23 && j < 29 ){
                        rotina[i][j] = 3;
                    }
                    if(j > 28 && j >=32){
                        rotina[i][j] = 2;
                    }
             }

          }else{ //turno das 18:00 até 20:00
             if(j >= 24) {
               rotina[i][j] = 1;
               if(pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 2;
                    }
                    if(j > 13 && j < 19 ){
                        rotina[i][j] = 3;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 2;
                    }
                    if(j > 13 && j < 19 ){
                        rotina[i][j] = 4;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 3;
                    }
                    if(j > 13 && j < 19){
                        rotina[i][j] = 2;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 4;
                    }
                }else if(pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 3;
                    }
                    if(j > 13 && j < 19){
                        rotina[i][j] = 4;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 2;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 4;
                    }
                    if(j > 13 && j < 19){
                        rotina[i][j] = 2;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 3;
                    }
                }else if(pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]){
                    if(j > 1 && j < 11){
                        rotina[i][j] = 4;
                    }
                    if(j > 13 && j < 19){
                        rotina[i][j] = 3;
                    }
                    if(j > 18 && j >=22){
                        rotina[i][j] = 2;
                    }
                }
            }
         }
      }    
// impressão da matriz rotina

/* Tabela de orientação na matriz
1 = turno de estudo(escola/faculdade)
2 = materia 1
3 = materia 2
4 = materia 3
5 = materia 4
6 = materia 5
*/
// impressão da matriz rotina
 // Dias da semana em formato de texto
    char* dias_semana[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    printf("Rotina de Estudos:\n");
// Imprima os cabeçalhos dos dias da semana
    printf("Dias\t");
    for (int i = 0; i < d; i++) {
        printf("%s\t", dias_semana[i]);
    }
    printf("\n");
// Imprima os horários e a matriz de rotina
    for (int j = 0; j < h; j++) {
        int hora = 6 + j / 2; // Calcula a hora a partir do índice da coluna
        int minuto = (j % 2) * 30; // Calcula os minutos (0 ou 30) a partir do índice da coluna
        printf("%02d:%02d\t", hora, minuto); // Imprime o horário no formato "hora:minuto"
        
        for (int i = 0; i < d; i++) {
            printf("%d\t", rotina[i][j]);
        }
        printf("\n");
    }  
return 0;
}