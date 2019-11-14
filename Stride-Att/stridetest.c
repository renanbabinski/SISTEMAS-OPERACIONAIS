#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"


#define LOOP 1000000
#define nprocs 3


int main(void){

	for(int i=0; i<nprocs; i++){
		if(fork((i+1)*100) == 0){
			for(int j=0; j<LOOP; j++){
				int a = 0, b = 10;
				a += b;
			}
			exit();
		}
	}
	for(int x=0; x<nprocs; x++){
		wait();
	}

return 0;
}