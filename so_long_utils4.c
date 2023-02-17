/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:35:32 by eablak            #+#    #+#             */
/*   Updated: 2023/01/12 18:35:33 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->vert)
	{
		free(all->temp_map[i]);
		free(all->map[i]);
	}
	free(all->l_c_x);
	free(all->l_c_y);
	free(all->str_map);
	free(all->temp_map);
	free(all->map);
	free(all->img);
	free(all);
}
