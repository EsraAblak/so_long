/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:32:08 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 11:34:54 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_all(t_all *all)
{
	all->c_coin = 0;
	all->c_exit = 0;
	all->c_player = 0;
	all->l_p_x = 0;
	all->l_p_y = 0;
	all->l_e_y = 0;
	all->l_e_x = 0;
	all->py = 0;
	all->px = 0;
	all->player_step = 0;
	all->en = 0;
	all->boy = 0;
	all->img_h = 1;
	all->img_w = 1;
	all->ctrl_coin = 0;
	all->case_right = 1;
	all->case_left = 0;
	all->case_up = 0;
	all->case_down = 0;
	all->case_cry = 0;
	all->total_coin = 0;
	all->total_exit = 0;
}

void	check_rectangle(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->vert)
	{
		j = 0;
		while (j < (int)(ft_strlen(all->map[i])))
			j++;
		if (j != all->hori)
		{
			write(1, "rectangle error\n", 16);
			exit(1);
		}
		i++;
	}
}

void	check_wall(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->hori)
	{
		if (all->map[0][i] != '1' || all->map[all->vert - 1][i] != '1')
		{
			write(1, "wall error\n", 11);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < all->vert)
	{
		if (all->map[i][0] != '1' || all->map[i][all->hori - 1] != '1')
		{
			write(1, "wall error\n", 11);
			exit(1);
		}
		i++;
	}
}

void	check_empty_line(char *str)
{
	if (str[0] == '\n')
	{
		write(1, "empty line\n", 11);
		exit(1);
	}
}

void	check_personel(t_all *all)
{
	int	i;

	i = 0;
	while (all->str_map[i])
	{
		if (all->str_map[i] == 'C')
			all->c_coin++;
		if (all->str_map[i] == 'E')
			all->c_exit++;
		if (all->str_map[i] == 'P')
			all->c_player++;
		i++;
	}
	if (all->c_player != 1 || all->c_exit != 1 || all->c_coin < 1)
	{
		write(1, "personel error\n", 15);
		exit(1);
	}
}
