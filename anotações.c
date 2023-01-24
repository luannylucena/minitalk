Basicão para começar:

CLIENT - Vai enviar um sinal (msg)
Como? 
usando a função Kill.

Kill tem 2 argumentos:
1) o sinal: SIGUSR1 OU SIGUSR2
2) Uma função que será executada quando o primeiro argumento for recebido. Esta função tem um retorno void e seu argumento é um inteiro.

O que eu preciso checar para começar o processo?
-checar erro (função que printa erros)
-checar argumentos (argv tem que ser 3 [nomedoarquivo.c/PID/"mensagem"])
-PID: não pode ser > 7 caracters.

Passos:
Criar uma função que envia uma msg (sinal)
-retorno void;
-argumentos: PID, STRING;
-Percorrer a string, receber um >> (bitshift) e fazer a comparação & com o número 1 binário (00000001).

ESTUDAR BITWISE