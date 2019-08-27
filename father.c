#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
     pid_t pid;                             //pid é o Process ID, um inteiro que guarda a ID do processo
     char *argv[] = { NULL};     
     
     if((pid=fork())!=0){                   //cria um prcesso filho, o pai recebe retorno diferente de 0 e o filho = 0

       printf("\n I am the father of %d \n",pid);  
       waitpid(pid, NULL, 0);               //vai esperar um retorno do filho, mas como o filho é sobreescrito com um código de loop infinito isso nunca vai retornar
       return;        
     }else {
       printf("\n I am the son, and right now I am like my father\n"); 
       execv("./son",argv);                 //sobrescreve o código atual do filho (igual ao pai) com o código do programa "son"
     }




}
