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
Criar uma função que envia uma msg (sinal) //ex: ft_send_bit(pid, char *str)
//A função send_bit é chamada quando todos os bits da mensagem foramrecebido pelo servidor. A função send_null() envia 8 sinais SIGUSR1representando o caractere nulo em binário - 00000000. Uma vez que i é igual a 8 - uma vez que todos os zeros (SIGUSR1) foram enviados - a função retorna 1.
-retorno void;
-argumentos: PID, STRING;
-Percorrer a string, receber um >> (bitshift) e fazer a comparação & com o número 1 binário (00000001).

//Esta função é chamada toda vez que o cliente recebe um sinal - SIGUSR1 ou SIGUSR2 do servidor. Se o sinal recebido for SIGUSR1 significa que o servidor confirma o recebimento um bit do cliente e está pronto para receber outro. Se o sinal recebido for SIGUSR2 significa que ocorreu um erro no servidor fazendo com que ele feche inesperadamente, então o cliente emite uma mensagem de erroe sai com EXIT_FAILURE.
int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(str);
		return (0);
	}
	return (1);

ESTUDAR BITWISE