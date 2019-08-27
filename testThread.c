/* Dica para compilação: 
                         gcc -o test1 testThread.c -lpthread */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 


void *mythread(void *data);   //cabeçalho da função my thread

#define N 5 // number of threads

int main(void) {
   pthread_t tids[N];     //define um vetor de Threads ID
   int i=0;               // inicia i com 0


   
   for(i=0; i<N; i++) {               // de acordo com a quatidade de threads
      int *j = malloc(sizeof(int));   // aloca um espaço para inteiro na memória e coloca o endereço em j
      *j = i;                         // j guarda o valor de i
      pthread_create(&tids[i], NULL, mythread, (void *)j);    //criação de thread: pthread_create( pthread_t *id, atributo, *rotina, void *arg (passado como argumento para a rotina))
   }
   /* We will now wait for each thread to<\n>
    * terminate */
   for(i=0; i<N; i++) {
      pthread_join(tids[i], NULL);                           //espera a thread terminar
      printf("Thread id %ld returned\n", tids[i]);
   }
   return(1);
}


void *mythread(void *data) {
int id;
   id = *((int *) data);
   
   printf("\n I am thread %d \n", id);
   sleep(1);
   /* We can return a pointer. Whatever pointer
    * we return can later be retrieved using the
    * pthread_join function */
   pthread_exit(NULL);
}

