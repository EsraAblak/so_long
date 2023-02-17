/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:42:33 by eablak            #+#    #+#             */
/*   Updated: 2023/01/12 13:01:15 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define COIN_PATH "./textures/coin.xpm"
# define EXIT_PATH "./textures/exit.xpm"
# define WALL_PATH "./textures/wall.xpm"
# define CRY_PATH "./textures/cry.xpm"
# define P_DOWN_PATH "./textures/p_down.xpm"
# define P_UP_PATH "./textures/p_up.xpm"
# define P_RIGHT_PATH "./textures/p_right.xpm"
# define P_LEFT_PATH "./textures/p_left.xpm"
# define ZERO_PATH "./textures/zero.xpm"

typedef struct s_struct2
{
	void		*coin;
	void		*exit;
	void		*mario;
	int			c;
	int			e;
	int			p1;
	int			p2;
	int			p3;
	int			p4;
	int			p5;
	int			w;
	int			z;

}				t_images;
typedef struct s_struct
{
	char		*str_map;
	char		**map;
	char		**temp_map;
	int			vert;
	int			hori;
	t_images	*img;
	int			c_coin;
	int			c_exit;
	int			c_player;
	int			py;
	int			px;
	int			l_p_x;
	int			l_p_y;
	int			l_e_y;
	int			l_e_x;
	int			*l_c_y;
	int			*l_c_x;
	int			player_step;
	int			en;
	int			boy;
	int			img_h;
	int			img_w;
	void		*mlx;
	void		*win;
	void		*coin;
	void		*exit;
	void		*p_down;
	void		*p_up;
	void		*p_left;
	void		*p_right;
	void		*cry;
	void		*wall;
	void		*zero;
	int			ctrl_coin;
	int			case_right;
	int			case_left;
	int			case_up;
	int			case_down;
	int			case_cry;
	int			total_coin;
	int			total_exit;
}				t_all;

void			check_path(char *av);
void			clean_all(t_all *all);
void			checkers(t_all *all, char *av);
void			check_rectangle(t_all *all);
void			check_wall(t_all *all);
void			check_empty_line(char *str);
void			check_personel(t_all *all);
void			check_canplay(t_all *all);
void			check_canplay3(t_all *all, int y, int x);
void			check_canplay2(t_all *all, int y, int x);
void			open_window(t_all *all);
void			file_to_image(t_all *all);
void			put_image2(char c, t_all *all, int k, int m);
void			put_image(t_all *all);
void			open_window(t_all *all);
void			find_sizes(t_all *all);
int				ft_close(t_all *all);
int				ft_move(int keycode, t_all *all);
int				ft_move2(int keycode, t_all *all);
void			check_diff(t_all *all);
void			check_end(int y, int x, t_all *all);
int				ft_move2(int keycode, t_all *all);
void			ft_free(t_all *all);

#endif