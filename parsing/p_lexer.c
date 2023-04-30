/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:54:38 by yboughan          #+#    #+#             */
/*   Updated: 2023/04/30 13:54:39 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../minishell.h"

void	lexer(t_data_mini *data)
{
	int	i;

	i = 0;
	add_space_pipe(data);
	add_space_redir(data);
	data->list_token = ft_split(data->cmd);
	free(data->cmd);
}
