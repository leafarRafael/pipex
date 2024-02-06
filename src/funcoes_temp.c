/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcoes_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:21:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/06 09:46:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_put_matrix(char **matrix)
{
	int i;

	i = 0;
	if (!matrix)
	{
		ft_printf("NULL");
		return ;
	}
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	ft_put_pointer_matrix(char ***pointer)
{
	int i;

	i = 0;
	while (pointer[i])
	{
		ft_put_matrix(pointer[i]);
		i++;
	}
}