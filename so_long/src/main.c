/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:19:32 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 12:50:39 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (ft_check_erreur(av[1]) == -1)
			return (1);
		if (ft_create_map(av[1], &data) == -1)
			return (1);
		ft_mise_zero(&data);
		if (ft_check_map(&data) == -1)
			return (ft_free(data.map.mapi), 1);
		if (ft_flip_flop(&data) == -1)
			return (ft_free(data.map.mapi), 1);
		if (ft_graphic_win(&data) == -1)
			return (ft_free(data.map.mapi), 1);
		if (ft_file_to_image(&data) == -1)
			return (ft_free(data.map.mapi), free(data.mlx_ptr), 1);
		ft_render(&data);
		ft_loop_hook(data);
		return (0);
	}
}
