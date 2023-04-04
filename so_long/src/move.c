/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:12:30 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 13:51:44 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	ft_check_next_step(t_data *data, char dir, char next)
{
	if (dir == 'w' && data->map.mapi[data->p_i - 1][data->p_j] == next)
		return (1);
	if (dir == 'a' && data->map.mapi[data->p_i][data->p_j - 1] == next)
		return (1);
	if (dir == 's' && data->map.mapi[data->p_i + 1][data->p_j] == next)
		return (1);
	if (dir == 'd' && data->map.mapi[data->p_i][data->p_j + 1] == next)
		return (1);
	else
		return (0);
}

void	ft_collect_item(t_data *data, char dir)
{
	if (dir == 'w' && data->map.mapi[data->p_i - 1][data->p_j] == 'C')
		data->item++;
	else if (dir == 'a' && data->map.mapi[data->p_i][data->p_j - 1] == 'C')
		data->item++;
	else if (dir == 's' && data->map.mapi[data->p_i + 1][data->p_j] == 'C')
		data->item++;
	else if (dir == 'd' && data->map.mapi[data->p_i][data->p_j + 1] == 'C')
		data->item++;
}

void	ft_win(t_data *data)
{
	if (data->flag_exit == 1)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return ;
}

void	ft_move_player(t_data *data, char dir)
{
	if (ft_check_next_step(data, dir, '1') == 1)
		return ;
	if (data->flag_exit == 0 && ft_check_next_step(data, dir, 'E') == 1)
		return ;
	data->step++;
	ft_printf("%d\n", data->step);
	ft_collect_item(data, dir);
	if (data->item == data->map.nbr_c)
		data->flag_exit = 1;
	data->map.mapi[data->p_i][data->p_j] = '0';
	if (dir == 'w')
		data->p_i--;
	else if (dir == 'a')
		data->p_j--;
	else if (dir == 's')
		data->p_i++;
	else if (dir == 'd')
		data->p_j++;
	if (data->flag_exit == 1 && data->map.mapi[data->p_i][data->p_j] == 'E')
		ft_win(data);
	data->map.mapi[data->p_i][data->p_j] = 'P';
}
