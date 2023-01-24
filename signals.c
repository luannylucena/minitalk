#include <stdio.h> // para printf
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int pid = fork(); //'fork' bifurca o processo. 
    if (pid == -1) //se for um número negativo
    {
        return (1);// retornamos um código de erro.
    }
    
    if (pid == 0)
    {
        while (1) //enquanto for verdadeiro
        {
        printf("Some text goes here.\n");
        usleep(50000);//Esta função é um ponto de cancelamento e, portanto, não marcada com '__throw'. Chamo ela pq nao quero que a frase seja impressa na velocidaed máxima, mas sim em 50.000 milionéismos de segundo = 1/20s.
        }
    } // com esse 'else' é possivel realmente encerrar algo que ficou executando em loop infinito. Vai imprimir a frase algumas vezes e parar. 
     else
     {  
        // ele não 'mata' propriamente dito, ele manda um sinal para um processo
        // e, então, o processo que recebe ele, sabe o que fazer com esse sinal. 
        //primeiro temos que passar o ID do processo para o qual queremos enviar o sinal. 

        // 'pid' para encerrar o processo pai e 'SIGKILL' para encerrar o processo filho. (olhar novamente sobre isso)
        
        sleep(1); //espere um segundo para matar o processo filho(?).
        kill(pid, SIGKILL); // (Kill vai chamar o pai para matar o filho?)
        wait(NULL);
     }
     return (0);
}   

// O que é importante lembrar é que o recebimento de sinais não depende da ordem de execução do código.

int main(int argc, char* argv[]
{
    int pid = fork();
    if(pid == -1)
    {
        return (1);
    }
    
}