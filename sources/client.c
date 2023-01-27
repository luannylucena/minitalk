/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:15:28 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/01/27 19:51:12 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// Essa função checa se o argumento é o argumeto é valido. No caso, o argv[1]. 
// Checa se é maior que 7 ou se é letra (isdigit)

static int	check_args(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

// Faz a conversão dos bits e manda essa conversão pro server.

void    send_char(pid_t pid, char *message)
{
	int	i;
	int	kill_status;
	int	bits_shifted; //conta os bits deslocados.

	i = 0;
	while (message[i] != '\0')
	{
		bits_shifted = 0;
		while (bits_shifted < 8)
		{
			if ((message[i] >> bits_shifted) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
				error("kill error.\n");
			bits_shifted++;
			usleep(500);
		}
		i++;
	}
}


int main(int argc, char **argv)
{
    
    pid_t pid;
    
    if (argc != 3)
        error("Invalid number of arguments.\n");
    if (ft_strlen(argv[1]) > 7 || check_args(argv[1]))
        error("Invalid PID.\n");
    pid = ft_atoi(argv[1]);
    send_char(pid, argv[2]);
    return(0);
}