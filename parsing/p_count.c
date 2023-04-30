/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_count.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:54:33 by yboughan          #+#    #+#             */
/*   Updated: 2023/04/30 13:54:34 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../minishell.h"

int	count_p(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			nb++;
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
		}
		i++;
	}
	return (nb);
}

int	count_redir(char *cmd)
{
	int		nb;
	char	q;

	nb = 0;
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '\"')
		{
			q = *cmd;
			cmd++;
			while (*cmd != q)
				cmd++;
		}
		if (*cmd == '>' || *cmd == '<')
		{
			q = *cmd;
			while (*cmd == q)
				cmd++;
			nb++;
			cmd--;
		}
		cmd++;
	}
	return (nb);
}
