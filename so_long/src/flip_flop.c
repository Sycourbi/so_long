/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_flop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:28 by sycourbi          #+#    #+#             */
/*   Updated: 2023/03/22 17:20:18 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_change_zero(int i, int j, char **tmp)
{
	if (tmp[i - 1][j] == '0' || tmp[i - 1][j] == 'C'
		|| tmp[i - 1][j] == 'P')
	{
		tmp[i - 1][j] = '2';
		ft_change_zero(i - 1, j, tmp);
	}
	if (tmp[i][j - 1] == '0' || tmp[i][j - 1] == 'C'
		|| tmp[i][j - 1] == 'P')
	{
		tmp[i][j - 1] = '2';
		ft_change_zero(i, j - 1, tmp);
	}
	if (tmp[i + 1][j] == '0' || tmp[i + 1][j] == 'C'
		|| tmp[i + 1][j] == 'P')
	{
		tmp[i + 1][j] = '2';
		ft_change_zero(i + 1, j, tmp);
	}
	if (tmp[i][j + 1] == '0' || tmp[i][j + 1] == 'C'
		|| tmp[i][j + 1] == 'P')
	{
		tmp[i][j + 1] = '2';
		ft_change_zero(i, j + 1, tmp);
	}
}

int	ft_verif_exit(char **tmp, int i, int j)
{
	if (tmp[i - 1][j] == '2' || tmp[i + 1][j] == '2'
		|| tmp[i][j - 1] == '2' || tmp[i][j + 1] == '2')
		return (1);
	else
		return (-1);
}

int	ft_verif_possible(char **tmp)
{
	int	i;
	int	j;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (ft_strchr("CP", tmp[i][j]))
				return (-1);
			if (tmp[i][j] == 'E')
			{
				if (ft_verif_exit(tmp, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_flip_flop(t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (data->map.nbr_line + 1));
	if (!tmp)
		return (-1);
	while (i < data->map.nbr_line)
	{
		tmp[i] = ft_strdup(data->map.mapi[i]);
		i++;
	}
	tmp[i] = NULL;
	ft_change_zero(data->p_i, data->p_j, tmp);
	if (ft_verif_possible(tmp) == -1)
		return (ft_free(tmp), ft_printf("Error\nmap impossible\n"), -1);
	ft_free(tmp);
	return (1);
}
