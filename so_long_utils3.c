/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:17:26 by eablak            #+#    #+#             */
/*   Updated: 2023/01/12 18:29:23 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_end(int y, int x, t_all *all)
{
	int	chr_y;
	int	chr_x;

	chr_y = 0;
	chr_x = 0;
	if (all->c_coin == all->ctrl_coin)
	{
		chr_y = 64 * y;
		chr_x = 64 * x;
		all->map[all->l_p_y][all->l_p_x] = 'P';
		all->player_step++;
		ft_printf("adim sayisi: %d\n", all->player_step);
		ft_close(all);
		exit(1);
	}
	else
		all->case_cry = 1;
}

int	last_dance(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		ft_close(all);
		exit(1);
	}
	return (keycode);
}

int	ft_move2_continue(int keycode, t_all *all)
{
	if (keycode == 1 && all->map[all->l_p_y + 1][all->l_p_x] != '1')
	{
		if (all->map[all->l_p_y + 1][all->l_p_x] == 'C')
			all->ctrl_coin++;
		if (all->map[all->l_p_y + 1][all->l_p_x] == 'E')
			check_end(all->l_p_y + 1, all->l_p_x, all);
		else
		{
			all->player_step++;
			all->map[all->l_p_y + 1][all->l_p_x] = 'P';
			all->map[all->l_p_y][all->l_p_x] = '0';
			all->py += 64;
			all->l_p_y++;
			all->case_up = 0;
			all->case_down = 1;
			all->case_left = 0;
			all->case_right = 0;
			all->case_cry = 0;
		}
	}
	last_dance(keycode, all);
	return (keycode);
}

int	ft_move2(int keycode, t_all *all)
{
	if (keycode == 13 && all->map[all->l_p_y - 1][all->l_p_x] != '1')
	{
		if (all->map[all->l_p_y - 1][all->l_p_x] == 'C')
			all->ctrl_coin++;
		if (all->map[all->l_p_y - 1][all->l_p_x] == 'E')
			check_end(all->l_p_y - 1, all->l_p_x, all);
		else
		{
			all->player_step++;
			all->map[all->l_p_y - 1][all->l_p_x] = 'P';
			all->map[all->l_p_y][all->l_p_x] = '0';
			all->py -= 64;
			all->l_p_y--;
			all->case_up = 1;
			all->case_down = 0;
			all->case_left = 0;
			all->case_right = 0;
			all->case_cry = 0;
		}
	}
	ft_move2_continue(keycode, all);
	return (keycode);
}
