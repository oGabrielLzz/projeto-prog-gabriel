#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alunos.h"
#include "rotinas.h"

void preenchendoHorariodeaula(int rotina[][17], int dia, aluno dados) {
     for (int j = 0; j < 17; j++){
        if(dados.turno == 1){
            if (j >= 1 && j < 6){
                rotina[dia][j] = -1;
            }
        }  
        if(dados.turno == 2){
            if (j >= 7 && j < 12){
                rotina[dia][j] = -1;
            } 
        }   
        if(dados.turno == 3){
            if (j >= 11 && j < 16){
                rotina[dia][j] = -1;
            }
        } 
     }
}

void preenchendomaterias(int rotina[5][16], aluno dados, int numMaterias) {
srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            if (dados.turno == 1 && (j > 6 && j < 16)) {
                rotina[i][j] = rand() % numMaterias + 1;
            } else if (dados.turno == 2 && ((j >= 1 && j <= 5) || (j > 11 && j < 16))) {
                rotina[i][j] = rand() % numMaterias + 1;
            } else if (dados.turno == 3 && (j >= 1 && j <= 5) || (j >= 7 && j <= 11)) {
                rotina[i][j] = rand() % numMaterias + 1;
            }
        }
    }
}