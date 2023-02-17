/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:11:57 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 12:16:08 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_continue(int keycode, t_all *all)
{
	if ((keycode == 0) && all->map[all->l_p_y][all->l_p_x - 1] != '1')
	{
		if (all->map[all->l_p_y][all->l_p_x - 1] == 'C')
			all->ctrl_coin++;
		if (all->map[all->l_p_y][all->l_p_x - 1] == 'E')
			check_end(all->l_p_y, all->l_p_x - 1, all);
		else
		{
			all->player_step++;
			all->map[all->l_p_y][all->l_p_x - 1] = 'P';
			all->map[all->l_p_y][all->l_p_x] = '0';
			all->l_p_x--;
			all->px -= 64;
			all->case_up = 0;
			all->case_down = 0;
			all->case_left = 1;
			all->case_right = 0;
			all->case_cry = 0;
		}
	}
	ft_move2(keycode, all);
	return (keycode);
}

int	ft_move(int keycode, t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (keycode == 2 && all->map[all->l_p_y][all->l_p_x + 1] != '1')
	{
		if (all->map[all->l_p_y][all->l_p_x + 1] == 'C')
			all->ctrl_coin++;
		if (all->map[all->l_p_y][all->l_p_x + 1] == 'E')
			check_end(all->l_p_y, all->l_p_x + 1, all);
		else
		{
			all->player_step++;
			all->map[all->l_p_y][all->l_p_x + 1] = 'P';
			all->map[all->l_p_y][all->l_p_x] = '0';
			all->px += 64;
			all->l_p_x++;
			all->case_up = 0;
			all->case_down = 0;
			all->case_left = 0;
			all->case_right = 1;
			all->case_cry = 0;
		}
	}
	ft_move_continue(keycode, all);
	put_image(all);
	ft_printf("adim sayisi: %d\n", all->player_step);
	return (keycode);
}

int	ft_close(t_all *all)
{
	mlx_destroy_image(all->mlx, all->p_right);
	mlx_destroy_image(all->mlx, all->p_left);
	mlx_destroy_image(all->mlx, all->p_up);
	mlx_destroy_image(all->mlx, all->p_down);
	mlx_destroy_image(all->mlx, all->exit);
	mlx_destroy_image(all->mlx, all->wall);
	mlx_destroy_image(all->mlx, all->zero);
	mlx_destroy_image(all->mlx, all->coin);
	mlx_destroy_image(all->mlx, all->cry);
	mlx_destroy_window(all->mlx, all->win);
	ft_free(all);
	exit(1);
	return (1);
}
