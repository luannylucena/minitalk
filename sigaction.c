//o sigaction dá mais controle sobre o processo de como lidar com os sinais. 
//Torna o programa mais portátil.

//o primeiro argumetno (SIGHUP) para buscar a aação é apenas o tipo de sinal simples (SIGHUP). 
//O segundo argumento (&newact)é onde fica um pouco mais complicado, isso aponta para uma 
//estrutura de ação. -> sa_handler; sa_mask; sa_flags;

//sa_handler => esta primeira estrutura aponta para o manipulador ou pode ser um desses 
//dois valores (SIG_IGN e SIG_DFL) dizendo para ignorar ou definir o comportamento padrão para 
//o sinal. isso é exatmente o que foi para o sinal mais antigo. 

//chame esses bits de novo, no entanto, porque neste segundo membro especificar 

int main(void)
{
    printf("This is pid %d\n", getpid());
    
    struct sigaction act;
   
   act.sa_handler = &sighandler;
   sigfillset(&act.sa_mask);
   act.sa_flags = SA_RESTART;
   if(sigaction(SIGINT, &act, NULL) == -1)
   {
        perror("sigaction");
        exit(EXIT_FAILURE);
   }
   printf("important: kill this process by running 'killall -9 sigaction' in another terminaw window.\n");
   while(1)
   {
        if(unprossedSig)
        {
            unprocessedSig = 0;
            printf("SIGINT signal ocurred.\n");
        }
   }
}