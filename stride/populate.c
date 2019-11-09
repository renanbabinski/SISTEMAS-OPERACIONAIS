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


// if((pid=fork(0))!=0){
//     fork(100);
//     fork(50);
//     fork(250);
// }else{
//   for(int i=0; i<MAX; i++);
//   exit();
// }

if((pid=fork(0) )== 0){
  for(int i=0; i<MAX; i++){
  }
}else{
  fork(100);
  fork(50);
  fork(250);
}

return 0;
}




// return 0;
// }

// void main(){
//      pid_t pid;                             //pid é o Process ID, um inteiro que guarda a ID do processo
//      char *argv[] = { NULL};     
     
//      if((pid=fork())!=0){                   //cria um prcesso filho, o pai recebe retorno diferente de 0 e o filho = 0

//        printf("\n I am the father of %d \n",pid);  
//        waitpid(pid, NULL, 0);               //vai esperar um retorno do filho, mas como o filho é sobreescrito com um código de loop infinito isso nunca vai retornar
//        return;        
//      }else {
//        printf("\n I am the son, and right now I am like my father\n"); 
//        execv("./son",argv);                 //sobrescreve o código atual do filho (igual ao pai) com o código do programa "son"
//      }




// }
