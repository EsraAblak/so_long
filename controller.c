/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:22:50 by eablak            #+#    #+#             */
/*   Updated: 2023/01/12 20:36:33 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_xpm2(t_images *img, int flag)
{
	close(img->c);
	close(img->e);
	close(img->p1);
	close(img->p2);
	close(img->p3);
	close(img->p4);
	close(img->p5);
	close(img->w);
	close(img->z);
	if (flag)
		exit(1);
}

void	check_xpm(t_all *all)
{
	int	flag;

	all->img = malloc(sizeof(t_images));
	flag = 0;
	all->img->c = open("./textures/coin.xpm", O_RDWR);
	all->img->e = open("./textures/exit.xpm", O_RDWR);
	all->img->p1 = open("./textures/p_right.xpm", O_RDWR);
	all->img->p2 = open("./textures/p_left.xpm", O_RDWR);
	all->img->p3 = open("./textures/p_up.xpm", O_RDWR);
	all->img->p4 = open("./textures/p_down.xpm", O_RDWR);
	all->img->p5 = open("./textures/cry.xpm", O_RDWR);
	all->img->z = open("./textures/zero.xpm", O_RDWR);
	all->img->w = open("./textures/wall.xpm", O_RDWR);
	if (all->img->c <= 0 || all->img->e <= 0 || all->img->z <= 0
		|| all->img->p1 <= 0 || all->img->p2 <= 0 || all->img->p3 <= 0
		|| all->img->p4 <= 0 || all->img->p5 <= 0 || all->img->w <= 0)
	{
		write(1, "img error\n", 10);
		flag = 1;
	}
	check_xpm2(all->img, flag);
}

void	check_path(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (av[len - 1] != 'r' || av[len - 2] != 'e' || av[len - 3] != 'b' || av[len
			- 4] != '.')
	{
		write(1, "path error\n", 11);
		exit(1);
	}
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd <= 0)
	{
		write(1, "file error\n", 11);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	checkers(t_all *all, char *av)
{
	check_xpm(all);
	check_file(av);
	check_rectangle(all);
	check_diff(all);
	check_wall(all);
	check_personel(all);
	check_canplay(all);
}
