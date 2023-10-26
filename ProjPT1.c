#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char nome[50];
    int idade;
    int d = 5, h = 16; // 5 dias da semana, 16 horas do dia (6:00 - 21:00)
    int rotina[d][h];

    // Inicialize a matriz rotina
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            rotina[i][j] = 0;
        }
    }

    printf("-Seja bem vindo(a) ao seu suporte de horario para estudo\n");
    printf("-Digite seu nome:\n");
    scanf("%s", nome);
    printf("-Qual a sua idade:\n");
    scanf("%d", &idade);

    int turno;
    printf("-Ola %s, para começarmos, preciso saber em qual turno você estuda?\n-Digite 1 para manha, 2 para tarde ou 3 para noite:\n", nome);
    scanf("%d", &turno);

    if (turno != 1 && turno != 2 && turno != 3) {
        printf("-Valor nao definido.\n");
        return 1;
    }

    int numMaterias = 3;
    int not = 5;
    double notas[numMaterias][not];

    int pontosparaaprovacao[numMaterias];
    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite quantos pontos precisa para ser aprovado na materia %d: ", i + 1);
        scanf("%d", &pontosparaaprovacao[i]);
    }

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite suas ultimas 5 notas da materia %d:\n", i + 1);
        for (int j = 0; j < not; j++) {
            scanf("%lf", &notas[i][j]);
        }
    }

    for (int i = 0; i < numMaterias; i++) {
        double somaMat = 0;
        for (int j = 0; j < not; j++) {
            somaMat += notas[i][j];
        }
        pontosparaaprovacao[i] = pontosparaaprovacao[i] - somaMat;
    }

    printf("\n-Prioridade de materias:\n");
    for (int i = 0; i < numMaterias; i++) {
        printf("-Materia %d: %d pontos faltando para aprovacao\n", i + 1, pontosparaaprovacao[i]);
    }
    //tabela de orientação
 /* Posições->  0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15        
 ----------|   6:00 07:00 08:00 09:00 10:00 11:00 12:00 13:00 14:00 15:00 16:00 17:00 18:00 19:00 20:00 21:00 
  segunda |   
  terça   |
  quarta  |
  quinta  |
  sexta   |
 */ 
     for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            if (turno == 1) { // Turno da 7:00 às 11:00
                if (j >= 1 && j < 6) {
                    rotina[i][j] = 1;
                }
                if (pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 2;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]) {
                    if (j >= 7 && j < 10) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 10 && j < 14) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 14 && j < 16) {
                        rotina[i][j] = 2;
                    }
                }
            } else if (turno == 2) { // Turno das 13:00 às 17:00
                if (j >= 7 && j < 12) {
                    rotina[i][j] = 1;
                }

                if (pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 2;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]) {
                    if (j >= 12 && j < 16) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 2;
                    }
                }
            } else { // Turno das 18:00 às 21:00
                if (j >= 11 && j < 16) {
                    rotina[i][j] = 1;
                }

                if (pontosparaaprovacao[0] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[2]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[0] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[1]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[2]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 4;
                    }
                } else if (pontosparaaprovacao[1] > pontosparaaprovacao[2] && pontosparaaprovacao[2] > pontosparaaprovacao[0]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 2;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[0] && pontosparaaprovacao[0] > pontosparaaprovacao[1]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 2;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 3;
                    }
                } else if (pontosparaaprovacao[2] > pontosparaaprovacao[1] && pontosparaaprovacao[1] > pontosparaaprovacao[0]) {
                    if (j >= 7 && j < 11) {
                        rotina[i][j] = 4;
                    }
                    if (j >= 1 && j < 4) {
                        rotina[i][j] = 3;
                    }
                    if (j >= 4 && j < 6) {
                        rotina[i][j] = 2;
                    }
                }
            }
        }
    }
     printf("\n");
    // Dias da semana
    char *dias_semana[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    printf("Rotina de Estudos:\n");

    // Imprima os cabeçalhos das horas
    printf("Dias\t");
    for (int i = 0; i < h; i++) {
        int hora = 6 + i; // Calcula a hora a partir do índice da coluna
        printf("%02d:00  ", hora); // Imprime o horário no formato "hora:minuto"
    }
    printf("\n");

    // Imprima os dias e a matriz de rotina
    for (int i = 0; i < d; i++) {
        printf("%s\t", dias_semana[i]);

        for (int j = 0; j < h; j++) {
            printf("  %d    ", rotina[i][j]);
        }
        printf("\n");
    }

    return 0;
}