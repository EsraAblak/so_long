/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:41:04 by eablak            #+#    #+#             */
/*   Updated: 2023/01/16 12:02:34 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*alan;

	while (*s1 && ft_ft_strchr(set,*s1))
		s1++;
	len = ft_ft_strlen(s1);
	while (len && ft_ft_strchr(set, s1[len]))
		len--;
	alan = ft_substr(s1, 0, len + 1);
	return (alan);
}
