/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:55:06 by yboughan          #+#    #+#             */
/*   Updated: 2023/04/30 13:55:07 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../minishell.h"

int	ft_parcing_readline(t_data_mini *data)
{
	char	*cmd;
	int		status;

	data->keypipe = 0;
	cmd = malloc((ft_strlen(data->cmd) + 1) * sizeof(char));
	ft_strcpy(cmd, data->cmd);
	data->cmd = cmd;
	status = ft_verif_all(data);
	while (status == 1)
		status = ft_verif_all(data);
	if (status == 0)
		return (0);
	supp_char(data, '\t');
	supp_char(data, '\\');
	manage_dollar(data);
	lexer(data);
	return (1);
}
