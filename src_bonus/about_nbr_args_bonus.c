/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_nbr_args_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:40:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/09 15:18:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_valid_nbr_args(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Check the number of arguments \n", 2);
		exit(EXIT_FAILURE);
	}
}
