#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"


#define LOOP 100    //quantidade de iterações que o -for irá executar
#define nprocs 5	//quantidade de processos que serão criados


int main(void){

	for(int i=0; i<nprocs; i++){				//cria a quantidade de processos definidos em nprocs
		if(fork((i+1)*100) == 0){				//se o processo for filho, executa os loops abaixo
			int a = 0, b = 10;
			for(int j=0; j<LOOP; j++){
				a += b;
				for(int k = 0; k < LOOP; k++){
					a -= b;
					printf(0," ");				//gasta processamento dos filhos
				}
				printf(1,"\n");	
			}
			a = b;
			b = a;
			exit();
		}
	}
	for(int x=0; x<nprocs; x++){		//espera até o processo terminar
		wait();
	}

return 0;
}