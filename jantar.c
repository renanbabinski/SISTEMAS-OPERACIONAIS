#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 

#define N     5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

void *mythread(void *data);

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t s[N];




void philosopher (int i){
	while(TRUE){
		think();
		take_forks(i);
		eat();
		put_forks(i);
	}
}

void take_forks(int i){
	down(&mutex);
	state[i] = HUNGRY;
	teste(i);
	up(&mutex);
	down(&s[i]);
}

void put_forks(i){
	down(&mutex);
	state[i] = THINKING;
	test(LEFT);
	test(RIGHT);
	up(&mutex);
}

void test(i){
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[i] = EATING;
		up(&s[i]);
	}
}

void eating(){
	printf("HUMMMM ESPAGUETE!!\n");
	sleep(5000);
}

void *mythread(void *data) {
struct timeval tv;
struct timezone tz;
struct tm *tm;
int id;
   id = *((int *) data);
   free((int *)data);

   // demonstração tratamento exclusão mútua utilizando mutex
   while(x < 10) {

      pthread_mutex_lock(&count_mutex);
      
      x++;
      gettimeofday(&tv, &tz);
      tm=localtime(&tv.tv_sec);
      printf("(USING MUTEX)  Thread ID %d: x is now %d (%d:%02d:%02d:%d).\n",id, x, tm->tm_hour, tm->tm_min, tm->tm_sec, (int)tv.tv_usec);
      /* We will now release the mutex so that
       * another thread gets the chance to run. */
      
      pthread_mutex_unlock(&count_mutex);

      sleep(1);
   }
    
   // demonstração tratamento exclusão mútua utilizando semáforo
   while(x < 20) {

      sem_wait(&s); // operação DOWN

      x++;
      gettimeofday(&tv, &tz);
      tm=localtime(&tv.tv_sec);
      printf("(USING SEMAFORE) Thread ID %d: x is now %d (%d:%02d:%02d:%d).\n",id, x, tm->tm_hour, tm->tm_min, tm->tm_sec, (int)tv.tv_usec);
      /* We will now release the mutex so that
       * another thread gets the chance to run. */
      
      sem_post(&s); // operação UP
      

      sleep(1);

   }

   /* We can return a pointer. Whatever pointer
    * we return can later be retrieved using the
    * pthread_join function */
   pthread_exit(NULL);
}









int main(){
	philosopher(3);



}