/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:02:07 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/28 10:08:47 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	ft_graphic_win(t_data *data)
{
	data->win_height = data->map.nbr_line * 32;
	data->win_witdth = (data->map.len_line) * 32;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_witdth,
			data->win_height, "fenetre de jeu");
	if (data->win_ptr == NULL)
		return (-1);
	return (1);
}

int	ft_check_image(t_data *data)
{
	if (data->img.player == NULL)
		return (ft_printf("Error\nprobleme image player\n"), -1);
	else if (data->img.mur == NULL)
		return (ft_printf("Error\nprobleme image mur\n"), -1);
	else if (data->img.sol == NULL)
		return (ft_printf("Error\nprobleme image sol\n"), -1);
	else if (data->img.exit == NULL)
		return (ft_printf("Error\nprobleme image exit\n"), -1);
	else if (data->img.item == NULL)
		return (ft_printf("Error\nprobleme image item\n"), -1);
	else if (data->img.noir == NULL)
		return (ft_printf("Error\nprobleme image fond\n"), -1);
	return (1);
}

int	ft_file_to_image(t_data *data)
{
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER,
			&data->img.width, &data->img.height);
	data->img.mur = mlx_xpm_file_to_image(data->mlx_ptr, MUR,
			&data->img.width, &data->img.height);
	data->img.sol = mlx_xpm_file_to_image(data->mlx_ptr, SOL,
			&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->img.width, &data->img.height);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&data->img.width, &data->img.height);
	data->img.noir = mlx_xpm_file_to_image(data->mlx_ptr, NOIR,
			&data->img.width, &data->img.height);
	if (ft_check_image(data) == -1)
		return (ft_destroy_img_bug(data), -1);
	else
		return (1);
}

void	ft_parse_char(t_data *data, int larg, int i, int j)
{
	if (data->map.mapi[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mur, larg, i * 32);
	else if (data->map.mapi[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.sol, larg, i * 32);
	else if (data->map.mapi[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.item, larg, i * 32);
	else if (data->map.mapi[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.exit, larg, i * 32);
	else if (data->map.mapi[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player, larg, i * 32);
}

int	ft_render(t_data *data)
{
	int	i;
	int	j;
	int	larg;

	j = 0;
	i = 0;
	larg = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (data->map.mapi[i])
	{
		while (data->map.mapi[i][j])
		{
			ft_parse_char(data, larg, i, j);
			larg = larg + 32;
			j++;
		}
		j = 0;
		larg = 0;
		i++;
	}
	data->move = ft_itoa(data->step);
	mlx_string_put(data->mlx_ptr, data->win_ptr, ((data->map.len_line - 1)
			* 32 + 10), 20, 0xAAF02025, data->move);
	return (free(data->move), 0);
}
