#include <stdio.h>
#include <math.h>
#include "rotina.h"

//===============================================Iniciando nossa tabela de horarios===================================================
int main() {
    int d = 5, h = 17; // 5 dias da semana, 19 horas do dia
    int rotina[d][h];
    
    // Inicialize a matriz rotina
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            rotina[i][j] = 0;
        }
    }

//==================================================Lendo dados iniciais do usuario====================================================
    printf("-Seja bem vindo(a) ao seu suporte de horario para estudo\n");
    aluno dados;
    dadosAluno(&dados);
    salvarDadosAluno(dados);


    while (dados.turno != 1 && dados.turno != 2 && dados.turno != 3) {
        printf("-Digite um valor valido.\n");
    }

    int numMaterias;
    int not;

    printf("Diga quantas materias voce tem no momento:\n");
    scanf("%d",&numMaterias);

    printf("Para calcularmos suas notas , Me diga quantas notas por materia voce ja tem:\n");
    scanf("%d",&not);

    double notas[numMaterias][not];
    int pontosparaaprovacao[numMaterias];

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite quantos pontos precisa para ser aprovado na materia %d: ", i + 1);
        scanf("%d", &pontosparaaprovacao[i]);
    }

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite suas ultimas %d notas da materia %d:\n",not, i + 1);
        for (int j = 0; j < not; j++) {
            scanf("%lf", &notas[i][j]);
        }
    }
//=====================================================Parte matematica das notas========================================================

    for (int i = 0; i < numMaterias; i++) {
        double somaMat = 0;
        for (int j = 0; j < not; j++){
            somaMat += notas[i][j];
        }
        pontosparaaprovacao[i] = pontosparaaprovacao[i] - somaMat;
    }


//=================================================Amostra do resultado das notas========================================================= 
    printf("\n");
    printf("_____________________________________________________________________________________");
     printf("\n");  
      printf("\nPrioridade de materias:\n");
    for (int i = 0; i < numMaterias; i++) {
        printf("Materia %d: %d pontos faltando para aprovacao\n", i + 1, pontosparaaprovacao[i]);
    }

//==========================================Adicionando as materias na matriz tabela====================================================

    preenchendomaterias(rotina, dados, numMaterias);
    for(int i = 0; i < d; i++){
    preenchendoHorariodeaula(rotina, i, dados);
}

//==============================================Impressao da Matriz=============================================
 printf("_____________________________________________________________________________________");
 printf("\n");
    // Dias da semana
    char *dias_semana[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    printf("Rotina de Estudos:\n");

    // Imprima os cabeçalhos das horas
    printf("Dias\t");
    for (int i = 0; i < 17; i++) {
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
     printf("\n");
     printf("_____________________________________________________________________________________");
    printf("\n");
    printf("Tabela de orientacao da matriz:\n"
           " 0 - tempolivre\n"
           "-1 - horario da escola\n"
           " 1 - primeira materia que precisa de mais estudo\n"
           " 2 - segunda materia que precisa de mais estudo\n"
           " 3 - terceira materia que precisa de mais estudo\n"
           " Assim por diante."
           );

    return 0;
}