/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:09:56 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 12:13:31 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_all *all)
{
	all->p_down = mlx_xpm_file_to_image(all->mlx, P_DOWN_PATH, &all->img_w,
			&all->img_h);
	all->p_up = mlx_xpm_file_to_image(all->mlx, P_UP_PATH, &all->img_w,
			&all->img_h);
	all->coin = mlx_xpm_file_to_image(all->mlx, COIN_PATH, &all->img_w,
			&all->img_h);
	all->exit = mlx_xpm_file_to_image(all->mlx, EXIT_PATH, &all->img_w,
			&all->img_h);
	all->wall = mlx_xpm_file_to_image(all->mlx, WALL_PATH, &all->img_w,
			&all->img_h);
	all->cry = mlx_xpm_file_to_image(all->mlx, CRY_PATH, &all->img_w,
			&all->img_h);
	all->p_left = mlx_xpm_file_to_image(all->mlx, P_LEFT_PATH, &all->img_w,
			&all->img_h);
	all->p_right = mlx_xpm_file_to_image(all->mlx, P_RIGHT_PATH, &all->img_w,
			&all->img_h);
	all->zero = mlx_xpm_file_to_image(all->mlx, ZERO_PATH, &all->img_w,
			&all->img_h);
}

void	put_score(t_all *all)
{
	char	*score;

	score = ft_itoa(all->player_step);
	mlx_string_put(all->mlx, all->win, 20, 20, 0X0FFFFFF, score);
	free(score);
}

void	put_image2(char c, t_all *all, int k, int m)
{
	mlx_put_image_to_window(all->mlx, all->win, all->zero, k, m);
	if (c == '1')
		mlx_put_image_to_window(all->mlx, all->win, all->wall, k, m);
	if (c == '0')
		mlx_put_image_to_window(all->mlx, all->win, all->zero, k, m);
	if (c == 'E')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, k, m);
	if (c == 'P')
	{
		k = all->px;
		m = all->py;
		if (all->case_right == 1)
			mlx_put_image_to_window(all->mlx, all->win, all->p_right, k, m);
		if (all->case_left == 1)
			mlx_put_image_to_window(all->mlx, all->win, all->p_left, k, m);
		if (all->case_down == 1)
			mlx_put_image_to_window(all->mlx, all->win, all->p_down, k, m);
		if (all->case_up == 1)
			mlx_put_image_to_window(all->mlx, all->win, all->p_up, k, m);
		if (all->case_cry == 1)
			mlx_put_image_to_window(all->mlx, all->win, all->cry, k, m);
	}
	if (c == 'C')
		mlx_put_image_to_window(all->mlx, all->win, all->coin, k, m);
	put_score(all);
}

void	put_image(t_all *all)
{
	int	i;
	int	j;
	int	k;
	int	m;

	i = 0;
	j = 0;
	k = 0;
	m = 0;
	while (i < all->vert)
	{
		j = 0;
		while (j < all->hori)
		{
			put_image2(all->map[i][j], all, k, m);
			j++;
			k += 64;
		}
		i++;
		k = 0;
		m += 64;
	}
}

void	open_window(t_all *all)
{
	file_to_image(all);
	put_image(all);
	mlx_hook(all->win, 2, (1L << 0), ft_move, all);
	mlx_hook(all->win, 17, 0, ft_close, all);
}
