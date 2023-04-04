/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:16:22 by sycourbi          #+#    #+#             */
/*   Updated: 2023/02/02 13:34:28 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

/* Fonction exit, malloc, free */
# include <stdlib.h>

/* Fonction open */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* Fonction mlx */
# include <X11/keysym.h>
# include <X11/X.h>

/* image */
# define PLAYER "image/player2.xpm"
# define MUR "image/mur.xpm"
# define SOL "image/sol.xpm"
# define EXIT "image/exit.xpm"
# define ITEM "image/item2.xpm"
# define NOIR "image/noir.xpm"

typedef struct s_img
{
	void	*mlx_img;
	void	*player;
	void	*mur;
	void	*noir;
	void	*sol;
	void	*exit;
	void	*item;
	int		line_len;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	char	**mapi;
	char	*ber;
	int		fd;
	int		nbr_line;
	int		len_line;
	int		nbr_c;
	int		nbr_e;
	int		nbr_p;
}	t_map;

typedef struct s_data
{
	int		p_i;
	int		p_j;
	int		step;
	int		item;
	int		flag_exit;
	char	*move;
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_witdth;
	t_map	map;
	t_img	img;
}	t_data;

int		main(int ac, char **av);
void	ft_free(char **tab);
int		ft_check_erreur(char *ber);
int		ft_create_map(char *ber, t_data *data);
void	ft_mise_zero(t_data *data);
void	ft_player(t_data *data);
int		ft_check_map(t_data *data);
int		ft_graphic_win(t_data *data);
int		ft_file_to_image(t_data *data);
int		ft_render(t_data *data);
void	ft_destroy_img_display(t_data *data);
void	ft_move_player(t_data *data, char dir);
void	ft_loop_hook(t_data data);
int		handle_dest_win(t_data *data);
int		handle_keypress(int key, t_data *data);
int		ft_flip_flop(t_data *data);
void	ft_destroy_img_bug(t_data *data);

#endif
