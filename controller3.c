/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:32:44 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 11:35:12 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_canplay3(t_all *all, int y, int x)
{
	if (all->temp_map[y][x + 1] == '0' || all->temp_map[y][x + 1] == 'C'
		|| all->temp_map[y][x + 1] == 'E')
	{
		if (all->temp_map[y][x + 1] == 'C')
			all->total_coin += 1;
		if (all->temp_map[y][x + 1] == 'E')
			all->total_exit += 1;
		all->temp_map[y][x + 1] = 'x';
		check_canplay2(all, y, x + 1);
	}
	if (all->temp_map[y - 1][x] == '0' || all->temp_map[y - 1][x] == 'C'
		|| all->temp_map[y - 1][x] == 'E')
	{
		if (all->temp_map[y - 1][x] == 'C')
			all->total_coin += 1;
		if (all->temp_map[y - 1][x] == 'E')
			all->total_exit += 1;
		all->temp_map[y - 1][x] = 'x';
		check_canplay2(all, y - 1, x);
	}
}

void	check_canplay2(t_all *all, int y, int x)
{
	if (all->temp_map[y][x - 1] == '0' || all->temp_map[y][x - 1] == 'C'
		|| all->temp_map[y][x - 1] == 'E')
	{
		if (all->temp_map[y][x - 1] == 'C')
			all->total_coin += 1;
		if (all->temp_map[y][x - 1] == 'E')
			all->total_exit += 1;
		all->temp_map[y][x - 1] = 'x';
		check_canplay2(all, y, x - 1);
	}
	if (all->temp_map[y + 1][x] == '0' || all->temp_map[y + 1][x] == 'C'
		|| all->temp_map[y + 1][x] == 'E')
	{
		if (all->temp_map[y + 1][x] == 'C')
			all->total_coin += 1;
		if (all->temp_map[y + 1][x] == 'E')
			all->total_exit += 1;
		all->temp_map[y + 1][x] = 'x';
		check_canplay2(all, y + 1, x);
	}
	check_canplay3(all, y, x);
}

void	check_total(t_all *all)
{
	if (all->c_coin != all->total_coin || all->c_exit != all->total_exit)
	{
		write(1, "map can't play\n", 15);
		exit(1);
	}
}

void	check_canplay(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->vert)
	{
		j = 0;
		while (j < all->hori)
		{
			if (all->temp_map[i][j] == 'P')
			{
				all->l_p_y = i;
				all->l_p_x = j;
			}
			j++;
		}
		i++;
	}
	check_canplay2(all, all->l_p_y, all->l_p_x);
	check_total(all);
}

void	check_diff(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->vert)
	{
		j = 0;
		while (j < all->hori)
		{
			if (all->map[i][j] != 'C' && all->map[i][j] != 'E'
				&& all->map[i][j] != '0' && all->map[i][j] != '1'
				&& all->map[i][j] != 'P')
			{
				write(1, "diff arg error\n", 15);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
