/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:04:52 by cjang             #+#    #+#             */
/*   Updated: 2020/12/29 02:21:32 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s, char c, size_t index)
{
	if (index == 0 && *s != c)
		return (1);
	else if (index == 0 && *s == c)
		return (0);
	else if (index > 0 && s[index - 1] == c && s[index] != c)
		return (1);
	else
		return (0);
}

static int	find_end(char const *s, char c, size_t index)
{
	if (s[index] != c && (s[index + 1] == c || s[index + 1] == 0))
		return (1);
	else
		return (0);
}

static char	*word_maker(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	size;

	size = 0;
	while (!find_start(s, c, *i))
		*i += 1;
	while (!find_end(s, c, *i + size))
		size++;
	if (!(word = (char *)malloc(size + 2)))
		return (NULL);
	ft_strlcpy(word, &s[*i], size + 2);
	*i = *i + size + 1;
	return (word);
}

static void	free_book(char **book, size_t index)
{
	while (index > 0)
		free(book[--index]);
	free(book);
}

char		**ft_split(char const *s, char c)
{
	char	**book;
	size_t	i;
	size_t	num;
	size_t	index;

	i = 0;
	num = 0;
	index = 0;
	if (!s)
		return (NULL);
	while (s[i])
		if (find_end(s, c, i++))
			num++;
	if (!(book = (char **)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	i = 0;
	while (index < num)
		if (!(book[index++] = word_maker(s, c, &i)))
		{
			free_book(book, index);
			return (NULL);
		}
	book[num] = NULL;
	return (book);
}
