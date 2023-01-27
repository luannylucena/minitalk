/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:15:31 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/01/27 19:51:59 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

//função globlal (struct no header)

t_char	g_char;

//vai executar essa função quando receber o sinal do client. 

static void	print_char(int signal)
{
	
	if (signal == SIGUSR1)
		g_char.str += (0b00000001 << g_char.bits_shifted);
	if (g_char.bits_shifted == 7) //1 char é 8 bits (1 byte). Aqui significa que ela leu os 8 bites, então temos a primeira letra. E assim vai.. 
	{
		ft_putchar_fd(g_char.str, STDOUT_FILENO); //é uma MACRO da bibiteoca, que seria o 1. a saida (stdout).
		g_char.str = 0; // para setar a variável e começar a letura dos 8 bits novamente, sem que haja sobreposição das letras.
		g_char.bits_shifted = 0;
		return ;
	}
	g_char.bits_shifted++;
}



int main(void)
{
    int pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    // aqui usar a sigaction TROCAR (ver amanhã)
    signal(SIGUSR1, print_char);
	signal(SIGUSR2, print_char);
	while (1)
	    pause();
}