#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"


#define MAX 1123
#define nprocs 3

// int main(void){
//   int i, tpids[nprocs];
//   int vetor[nprocs] = {110,50,250};
//   for(i=0; i <= nprocs; i++){
//     if(fork(0) != 0)
//       tpids[i]=fork(vetor[i]);
//     if(tpids[i] == 0){
//       for(int j=0; j< MAX; j++); //Gasta processamento para o escalonador não tirar fora
//       exit();
//     }
//     for(i=0; i < nprocs; i++){ 
//     wait();
//     exit();
//   }
// }
//   return 0;
// }
//   

int main(void){
  int pid;


if((pid=fork(0))!=0){
    fork(110);
    fork(50);
    fork(250);
}else{
  for(int i=0; i<MAX; i++);
  exit();
}






return 0;
}