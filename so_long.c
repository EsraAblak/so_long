/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:06:43 by eablak            #+#    #+#             */
/*   Updated: 2023/01/12 18:41:30 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*take_map(char *av, t_all *all)
{
	int		fd;
	int		i;
	char	*line;
	char	*all_line;

	fd = open(av, O_RDONLY);
	i = 0;
	all_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			all->hori = ft_strlen(line);
		i++;
		check_empty_line(line);
		all_line = ft_strjoin(all_line, line);
		free(line);
	}
	all->vert = i;
	return (all_line);
}

void	copy_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all->temp_map = (char **)malloc(sizeof(char *) * (all->vert + 1));
	while (i < all->vert)
	{
		all->temp_map[i] = malloc(sizeof(char) * (all->hori + 1));
		while (j < all->hori)
		{
			all->temp_map[i][j] = all->map[i][j];
			j++;
		}
		all->temp_map[i][j] = '\0';
		j = 0;
		i++;
	}
}

void	arg_loc2(t_all *all, int i, int j)
{
	static int	s;

	s = 0;
	if (all->map[i][j] == 'E')
	{
		all->l_e_y = i;
		all->l_e_x = j;
	}
	if (all->map[i][j] == 'C')
	{
		all->l_c_y[s] = i;
		all->l_c_x[s] = j;
		s++;
	}
}

void	arg_loc(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	all->l_c_x = malloc(all->hori * sizeof(int *));
	all->l_c_y = malloc(all->vert * sizeof(int *));
	while (++i < all->vert)
	{
		j = -1;
		while (++j < all->hori)
		{
			if (all->map[i][j] == 'P')
			{
				all->l_p_y = i;
				all->l_p_x = j;
				all->py = i * 64;
				all->px = j * 64;
			}
			arg_loc2(all, i, j);
		}
	}
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (ac != 2)
	{
		write(1, "ac error\n", 9);
		exit(1);
	}
	all->mlx = mlx_init();
	check_path(av[1]);
	clean_all(all);
	all->str_map = take_map(av[1], all);
	all->map = ft_split(all->str_map, '\n');
	copy_map(all);
	checkers(all, av[1]);
	all->en = all->hori * 64;
	all->boy = all->vert * 64;
	all->win = mlx_new_window(all->mlx, all->en, all->boy, "so_long");
	arg_loc(all);
	open_window(all);
	mlx_loop(all->mlx);
}
