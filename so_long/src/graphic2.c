/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:40:18 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 12:54:01 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_destroy_img_display(t_data *data)
{
	if (data->img.mur)
		mlx_destroy_image(data->mlx_ptr, data->img.mur);
	if (data->img.sol)
		mlx_destroy_image(data->mlx_ptr, data->img.sol);
	if (data->img.item)
		mlx_destroy_image(data->mlx_ptr, data->img.item);
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	if (data->img.player)
		mlx_destroy_image(data->mlx_ptr, data->img.player);
	if (data->img.noir)
		mlx_destroy_image(data->mlx_ptr, data->img.noir);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map.mapi)
		ft_free(data->map.mapi);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (ft_strchr("wasd", key))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.noir, ((data->map.len_line - 1) * 32 + 10), 0);
		ft_move_player(data, key);
	}
	return (0);
}

int	handle_dest_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
/*boucle les image*/
/*pour utiliser la croix, envoie un message de la fin de la fenetre*/
/*pour utiliser les touches*/
/*boucle la fenetre*/

void	ft_loop_hook(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &ft_render, &data);
	mlx_hook(data.win_ptr, 33, 1L << 17, &handle_dest_win, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	ft_destroy_img_display(&data);
}
