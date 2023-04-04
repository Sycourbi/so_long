/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:59 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 12:49:12 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_mise_zero(t_data *data)
{
	data->map.nbr_c = 0;
	data->map.nbr_e = 0;
	data->map.nbr_p = 0;
	data->map.len_line = 0;
	data->p_i = 0;
	data->p_j = 0;
	data->step = 0;
	data->item = 0;
	data->flag_exit = 0;
	data->img.width = 32;
	data->img.height = 32;
}

void	ft_player(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (data->map.mapi[i])
	{
		while (data->map.mapi[i][j])
		{
			if (data->map.mapi[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
