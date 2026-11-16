#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num1 = 12;
    int num2 = 5;
    int ris = 0;
    int operazione = 2; 
    pid_t pid = fork();
    if (pid < 0) {
        perror("Errore durante la creazione del processo figlio");
        exit(1);
    } 
    else if (pid == 0) {
        if (operazione == 1) {
            ris = num1 + num2;
        } else if (operazione == 2) {
            ris = num1 * num2;
        } else {
            ris = 0;
        }
        exit(ris);
    }
    else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("[PADRE] Il processo figlio ha terminato l'esecuzione.\n");
            printf("[PADRE] Exit status (risultato dell'operazione): %d\n", exit_status);
        } else {
            printf("[PADRE] Il processo figlio non è terminato regolarmente.\n");
        }
    }

    return 0;
}
