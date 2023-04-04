/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:25 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 12:51:39 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	ft_check_rectangle(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	data->map.len_line = ft_strlen(data->map.mapi[i]);
	while (data->map.mapi[i])
	{
		while (data->map.mapi[i][j])
			j++;
		if (data->map.mapi[i][j - 1] == '\n')
			j--;
		if (j != data->map.len_line - 1)
			return (ft_printf("Error\nmap pas rectangle\n"), -1);
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_first(int i, char **mapi)
{
	int	j;

	j = 0;
	while (mapi[i][j] && mapi[i][j] != '\n')
	{
		if (mapi[i][j] != '1')
			return (-1);
		j++;
	}
	return (1);
}

int	ft_check_mur(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = (data->map.len_line - 2);
	if (ft_check_first(0, data->map.mapi) == -1)
		return (ft_printf("Error\nprobleme de mur\n"), -1);
	while (i < data->map.nbr_line)
	{
		if (data->map.mapi[i][0] != '1')
			return (ft_printf("Error\nprobleme de mur\n"), -1);
		if (data->map.mapi[i][j] != '1')
			return (ft_printf("Error\nprobleme de mur\n"), -1);
		i++;
	}
	if (ft_check_first((data->map.nbr_line - 1), data->map.mapi) == -1)
		return (ft_printf("Error\nprobleme de mur\n"), -1);
	return (1);
}

int	ft_check_cep(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (data->map.mapi[i])
	{
		while (data->map.mapi[i][j])
		{
			if (data->map.mapi[i][j] == 'C')
				data->map.nbr_c++;
			else if (data->map.mapi[i][j] == 'E')
				data->map.nbr_e++;
			else if (data->map.mapi[i][j] == 'P')
				data->map.nbr_p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (data->map.nbr_p != 1 || data->map.nbr_e != 1 || data->map.nbr_c < 1)
		return (-1);
	return (1);
}

int	ft_check_map(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (data->map.mapi[i] != NULL)
	{
		while (data->map.mapi[i][j] != '\0' && data->map.mapi[i][j] != '\n')
		{
			if (ft_strrchr("01CEP", data->map.mapi[i][j]) == 0)
				return (ft_printf("Error\nmauvais caratere dans la map\n"), -1);
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_check_rectangle(data) == -1 || ft_check_mur(data) == -1)
		return (-1);
	if (ft_check_cep(data) == -1)
		return (ft_printf("Error\nmauvais nombre de CEP dans la map\n"), -1);
	ft_player(data);
	return (1);
}
