/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:10:51 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 11:57:26 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*a;
	int		i;

	len = ft_ft_strlen(s1);
	a = malloc(sizeof(char) * len + 1);
	if (!a)
		return (0);
	i = 0;
	while (i < len)
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
