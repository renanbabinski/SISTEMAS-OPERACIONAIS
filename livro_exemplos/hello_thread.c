#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
	/* Esta função imprime o identificador do thread e sai. */
	printf("Hello World. Greetings from the thread %d\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	/* O programa principal cria 10 threads e sai. */
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;

	for(i=0; i<NUMBER_OF_THREADS; i++){
		printf("Main Here. Creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL,  print_hello_world, (void *)i);

		if (status != 0){
			printf("Oops. pthread_create returned error code %d\n", status);
			exit(-1);
		}
	}
	exit(0);
}