#ifndef ROTINAS_H
#define ROTINAS_H

#ifndef ALUNOS_H
#define ALUNOs_H

typedef struct 
{
    char nome[50];
    int idade;
    int turno;
}aluno;
#endif

void preenchendoHorariodeaula(int rotina[][17], int dia, aluno dados);
void preenchendomaterias(int rotina[5][16], aluno dados, int numMaterias);

#endif