/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:39:16 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 12:57:16 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	ft_check_erreur(char *ber)
{
	int	len;

	len = ft_strlen(ber);
	len--;
	if (ber[len] == 'r' && ber[len - 1] == 'e'
		&& ber[len - 2] == 'b' && ber[len - 3] == '.')
		return (1);
	else
		return (ft_printf("Error\nfichier map doit terminer par .ber\n"), -1);
}

void	ft_destroy_img_bug(t_data *data)
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
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
}
