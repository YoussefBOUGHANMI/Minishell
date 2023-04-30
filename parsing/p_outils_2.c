/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_outils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:54:46 by yboughan          #+#    #+#             */
/*   Updated: 2023/04/30 13:54:47 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../minishell.h"

void	supp_char(t_data_mini *data, char c)
{
	int	i;

	i = 0;
	while (data->cmd[i])
	{
		if (data->cmd[i] == '\'')
		{
			while (data->cmd[i] != '\'' && data->cmd[i])
				i++;
		}
		if (data->cmd[i] == '\"')
		{
			while (data->cmd[i] != '\"' && data->cmd[i])
				i++;
		}
		if (data->cmd[i] == c)
			data->cmd[i] = ' ';
		i++;
	}
}

int	cmd_empty(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
