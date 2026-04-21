#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void cadastrarTerritorios(Territorio* mapa, int n);
void exibirMapa(Territorio* mapa, int n);
void atacar(Territorio* atacante, Territorio* defensor);
void atribuirMissao(char** destino, char* missoes[], int total);
int verificarMissao(char* missao, Territorio* mapa, int n);

int main() {
    int n;
    srand(time(NULL)); 
    
    printf("### BEM-VINDO AO WAR DIGITAL ###\n");
    printf("Digite o numero de territorios: ");
    scanf("%d", &n);

    Territorio* mapa = (Territorio*) malloc(n * sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    char* listaMissoes[] = {
        "Dominar a America do Sul",
        "Conquistar 3 territorios",
        "Eliminar a cor adversaria",
        "Ter 10 tropas em um unico territorio",
        "Conquistar a Asia"
    };
    char* missaoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(&missaoJogador, listaMissoes, 5);
    
    printf("\nSUA MISSAO: %s\n", missaoJogador);

    cadastrarTerritorios(mapa, n);

    int venceu = 0;
    while (!venceu) {
        exibirMapa(mapa, n);
        
        int at, df;
        printf("\n--- SEU TURNO --- (Missao: %s)\n", missaoJogador);
        printf("Indice Atacante: "); scanf("%d", &at);
        printf("Indice Defensor: "); scanf("%d", &df);

        if (at < 0 || at >= n || df < 0 || df >= n) {
            printf("[ERRO] Indices invalidos!\n");
        } else if (strcmp(mapa[at].cor, mapa[df].cor) == 0) {
            printf("\n[AVISO] Voce nao pode atacar seu proprio territorio (%s)!\n", mapa[at].cor);
        } else {
            atacar(&mapa[at], &mapa[df]);
        }

        venceu = verificarMissao(missaoJogador, mapa, n);
        
        if (venceu) {
            printf("\nPARABENS! VOCE CUMPRIU SUA MISSAO!");
            exibirMapa(mapa, n);
        }
    }

    free(missaoJogador);
    free(mapa);

    return 0; 
}

void cadastrarTerritorios(Territorio* mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro do Territorio %d ---\n", i + 1);
        printf("Nome: "); scanf(" %[^\n]s", mapa[i].nome);
        printf("Cor: "); scanf(" %[^\n]s", mapa[i].cor);
        printf("Quantidade de tropas: "); scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(Territorio* mapa, int n) {
    printf("\n--- MAPA ATUALIZADO ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] %-15s | Cor: %-10s | Tropas: %d\n", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n[DADOS] Atacante: %d vs Defensor: %d\n", dadoAtacante, dadoDefensor);
    
    if (dadoAtacante > dadoDefensor) {
        printf("RESULTADO: O atacante venceu!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas / 2;
    } else {
        printf("RESULTADO: O defensor resistiu! O atacante perde 1 tropa.\n");
        if(atacante->tropas > 0) atacante->tropas--;
    }
}

void atribuirMissao(char** destino, char* missoes[], int total) {
    int sorteio = rand() % total;
    strcpy(*destino, missoes[sorteio]);
}

int verificarMissao(char* missao, Territorio* mapa, int n) {
    if (strstr(missao, "3 territorios") != NULL) {
        int contador = 0;
        char* minhaCor = mapa[0].cor; 
        for (int i = 0; i < n; i++) {
            if (strcmp(mapa[i].cor, minhaCor) == 0) contador++;
        }
        if (contador >= 3) return 1;
    }
    
    if (strstr(missao, "10 tropas") != NULL) {
        for (int i = 0; i < n; i++) {
            if (mapa[i].tropas >= 10) return 1;
        }
    }
    return 0; 
}