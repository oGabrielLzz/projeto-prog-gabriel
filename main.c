#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//===========================================Struct Do Aluno======================================================
struct DadosUsuario {
    char nome[50];
    int turno;
    int numMaterias;
    int not;
    int pontosparaaprovacao[10]; // Assumindo no máximo 10 matérias
    double notas[10][10];        // Assumindo no máximo 10 matérias e 10 notas por matéria
};
// ============================================Função do Horario de Aula=========================================================
void preenchendoHorariodeaula(int rotina[][17], int dia, int turno) {
    for (int j = 0; j < 17; j++) {
        if (turno == 1) {
            if (j >= 1 && j < 6) {
                rotina[dia][j] = -1;
            }
        } else if (turno == 2) {
            if (j >= 7 && j < 12) {
                rotina[dia][j] = -1;
            }
        } else if (turno == 3) {
            if (j >= 11 && j < 16) {
                rotina[dia][j] = -1;
            }
        }
    }
}
// ===========================================Função Das Materias========================================================
void preenchendomaterias(int rotina[5][16], int turno, int numMaterias) {
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            // Verifica se a célula já está marcada como tempo livre
            if (rotina[i][j] == 0) {
                if (turno == 1 && (j > 6 && j < 16)) {
                    rotina[i][j] = rand() % numMaterias + 1;
                } else if (turno == 2 && ((j >= 1 && j <= 5) || (j > 11 && j < 16))) {
                    rotina[i][j] = rand() % numMaterias + 1;
                } else if (turno == 3 && ((j >= 1 && j <= 5) || (j >= 7 && j <= 11))) {
                    rotina[i][j] = rand() % numMaterias + 1;
                }
            }
        }
    }
}

//===========================================================Main============================================================
int main() {
    int d = 5, h = 17; // 5 dias da semana, 19 horas do dia
    int rotina[d][h];

    // Inicialize a matriz rotina
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            rotina[i][j] = 0;
        }
    }

 //=====================================Lendo o Struct Automaticamente ou Manualmente==================================================
    struct DadosUsuario dados;

    // Adicionando a flag para leitura de arquivo ou manual
    int escolha;
    printf("Digite 1 para ler dados do arquivo ou 2 para inserir manualmente: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
       FILE *arquivo = fopen("C:\\Users\\gabri\\projeto-prog-suportehorario\\Teste.txt", "r");

// Adapte este bloco de código conforme o formato do arquivo
if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
}

// Leitura do nome
fscanf(arquivo, "%49[^\n]", dados.nome);

// Leitura dos outros dados
fscanf(arquivo, "%d", &dados.turno);
fscanf(arquivo, "%d", &dados.numMaterias);
fscanf(arquivo, "%d", &dados.not);

for (int i = 0; i < dados.numMaterias; i++) {
    fscanf(arquivo, "%d", &dados.pontosparaaprovacao[i]);
}

for (int i = 0; i < dados.numMaterias; i++) {
    for (int j = 0; j < dados.not; j++) {
        fscanf(arquivo, "%lf", &dados.notas[i][j]);
    }
}

fclose(arquivo);
    } else if (escolha == 2) {
        printf("-Seja bem vindo(a) ao seu suporte de horario para estudo\n");
        printf("-Digite seu nome:\n");
        scanf("%s", dados.nome);

        printf("-Ola %s, Para comecarmos, preciso saber em qual turno voce estuda?\n-Digite 1 para manha, 2 para tarde ou 3 para noite:\n", dados.nome);
        scanf("%d", &dados.turno);

        while (dados.turno != 1 && dados.turno != 2 && dados.turno != 3) {
            printf("-Digite um valor valido.\n");
            scanf("%d", &dados.turno);
        }

        printf("Diga quantas materias voce tem no momento:\n");
        scanf("%d", &dados.numMaterias);

        printf("Para calcularmos suas notas, Me diga quantas notas por materia voce ja tem\n");
        scanf("%d", &dados.not);

        for (int i = 0; i < dados.numMaterias; i++) {
            printf("-Digite quantos pontos precisa para ser aprovado na materia %d: ", i + 1);
            scanf("%d", &dados.pontosparaaprovacao[i]);
        }

        for (int i = 0; i < dados.numMaterias; i++) {
            printf("-Digite suas ultimas %d notas da materia %d:\n", dados.not, i + 1);
            for (int j = 0; j < dados.not; j++) {
                scanf("%lf", &dados.notas[i][j]);
            }
        }
    } else {
        printf("Escolha invalida. Encerrando o programa.\n");
        return 1;
    }

//=============================================Parte matemática das notas=======================================================
    for (int i = 0; i < dados.numMaterias; i++) {
        double somaMat = 0;
        for (int j = 0; j < dados.not; j++) {
            somaMat += dados.notas[i][j];
        }
        dados.pontosparaaprovacao[i] = dados.pontosparaaprovacao[i] - somaMat;
    }

//==========================================Amostra do resultado das notas======================================================
    printf("\n");
    printf("\nPrioridade de materias:\n");
    for (int i = 0; i < dados.numMaterias; i++) {
        printf("Materia %d: %d pontos faltando para aprovacao\n", i + 1, dados.pontosparaaprovacao[i]);
    }

//============================================Chamada da função===================================================================
    preenchendomaterias(rotina, dados.turno, dados.numMaterias);
    for (int i = 0; i < d; i++) {
        preenchendoHorariodeaula(rotina, i, dados.turno);
    }

//=======================================Adicionando o tempo livre na matriz corrigindo a rand======================================
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            rotina[i][0] = 0;
            rotina[i][6] = 0;
            rotina[i][16] = 0;

            }
        }
//================================================Impressao da Matriz===============================================================
    printf("\n");
    printf("____________________________________________________________________\n");
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
    printf("____________________________________________________________________\n");

    printf("Tabela de orientacao da matriz:\n"
           " 0 - tempolivre\n"
           "-1 - horario de escola/faculdade predefinido\n"
           " 1 - primeira materia que precisa de mais estudo\n"
           " 2 - segunda materia que precisa de mais estudo\n"
           " 3 - terceira materia que precisa de mais estudo\n"
           " Assim em diante conforme o numero de materias.\n");

    printf("____________________________________________________________________\n");

    return 0;
}