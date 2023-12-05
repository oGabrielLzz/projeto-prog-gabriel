#include <stdio.h>
#include "alunos.h"

void dadosAluno(aluno *dados) {
     printf("Digite seu nome: ");
    fgets(dados->nome, sizeof(dados->nome), stdin);
    dados->nome[strcspn(dados->nome, "\n")] = '\0'; 

    printf("Digite sua idade: ");
    scanf("%d", &(dados->idade));

    printf("Olá, %s, preciso que informe o turno em que estuda (1 para manhã, 2 para tarde, 3 para noite): ", dados->nome);
    scanf("%d", &(dados->turno));
}

void salvarDadosAluno(aluno dados) {
    FILE *arquivo = fopen("dadosAluno.txt", "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "Nome: %s\n", dados.nome);
    fprintf(arquivo, "Idade: %d\n", dados.idade);
    fprintf(arquivo, "Turno: %d\n", dados.turno);

    fclose(arquivo);

    printf("Dados do aluno foram salvos em dadosAluno.txt\n");
}