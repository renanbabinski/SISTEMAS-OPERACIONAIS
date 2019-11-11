#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"


#define LOOP 2000
#define nprocs 3


int main(void){
	int pid;

if((pid=fork() ) <= 0){
  for(int i=0; i<LOOP; i++);
}else{
  fork();
  fork();
  fork();
}

return 0;
}