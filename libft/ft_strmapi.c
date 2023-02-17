/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:14:41 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 11:57:48 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*dizi;

	i = 0;
	len = ft_ft_strlen(s);
	dizi = (char *)malloc(sizeof(char) * len + 1);
	if (dizi == NULL)
		return (0);
	while (i < len)
	{
		dizi[i] = f(i, s[i]);
		i++;
	}
	dizi[i] = 0;
	return (dizi);
}
