#include <stdio.h>   // printf
#include <unistd.h>  // getpid, getppid, fork, sleep
#include <stdlib.h>  // exit
#include <sys/wait.h>// wait

void childProcess(void);
void fatherProcess(int childpid);

int main(int argc, char **argv){
  
  printf("\n[INIZIO] - Prima della fork - pid processo=%d, pid padre=%d\n",getpid(),getppid());

  int pid=fork();
  if (pid==0) {
    childProcess();
  } else if (pid>0) {
    fatherProcess(pid);
  } else {
    printf("Creazione del processo figlio fallita!\n");
  }

  printf("[FINE] - Termine del processo con pid=%d avente pid padre=%d\n",getpid(),getppid());
  exit(3);
}
void childProcess(void) {
  sleep(3);
  printf("[Figlio] - pid=%d, pid padre=%d\n", getpid(), getppid());
  exit(100);
}
void fatherProcess(int childpid) {
  
  printf("\n[Padre] - pid=%d, pid padre=%d, pid figlio=%d\n",getpid(),getppid(),childpid);
  int wait_status;
  int wait_retvalue;
  wait_retvalue = wait(&wait_status);
  printf("[Padre] - wait_retvalue=%d, wait_status=%d\n", wait_retvalue, wait_status);
}
