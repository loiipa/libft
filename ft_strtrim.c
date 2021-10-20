/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:33:51 by cjang             #+#    #+#             */
/*   Updated: 2020/12/28 21:59:50 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	n;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	n = ft_strlen(s1);
	while (n > 1 && ft_strrchr(set, s1[n - 1]))
		n--;
	if (!(trim = (char *)malloc(n + 1)))
		return (NULL);
	ft_strlcpy(trim, s1, n + 1);
	return (trim);
}
