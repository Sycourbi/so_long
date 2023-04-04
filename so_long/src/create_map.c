/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:27 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/09 16:41:38 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	ft_nbr_line(char *ber)
{
	char	*line;
	int		nbr;
	int		fd;

	nbr = 0;
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (ft_printf("fonction open\n"), -1);
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("fichier vide\n"), -1);
	while (line != NULL)
	{
		nbr++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nbr);
}

void	ft_map_tab(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(data->map.fd);
	if (line != NULL)
	{
		while (line != NULL)
		{
			data->map.mapi[i] = ft_strdup(line);
			if (!data->map.mapi[i])
				return (free(line), ft_free(data->map.mapi));
			i++;
			free(line);
			line = get_next_line(data->map.fd);
		}
	}
	data->map.mapi[i] = NULL;
}

int	ft_create_map(char *ber, t_data *data)
{
	data->map.ber = ber;
	data->map.nbr_line = ft_nbr_line(ber);
	if (data->map.nbr_line == -1)
		return (-1);
	data->map.mapi = malloc(sizeof(char *) * (data->map.nbr_line + 1));
	if (!data->map.mapi)
		return (ft_printf("Error\nprobleme malloc char **mapi\n"), -1);
	data->map.fd = open(ber, O_RDONLY);
	if (data->map.fd < 0)
		return (ft_printf("Error\nprobleme fonction open\n"),
			ft_free(data->map.mapi), -1);
	else
		ft_map_tab(data);
	close(data->map.fd);
	return (1);
}
