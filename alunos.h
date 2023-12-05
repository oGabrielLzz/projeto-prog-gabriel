#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct {
    char nome[50];
    int idade;
    int turno;
} aluno;

void dadosAluno(aluno *dados);
void salvarDadosAluno(aluno dados);

#endif

