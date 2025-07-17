/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsharq <malsharq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:57:57 by malsharq          #+#    #+#             */
/*   Updated: 2024/09/10 19:46:35 by malsharq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

static int	countwords(char const *s, char c)
{
	int	n_words;

	n_words = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (*s == c)
		s++;
	while (ft_strlen(s) != 0)
	{
		if (*s == c && *(s - 1) != c)
			n_words++;
		s++;
	}
	if (ft_strlen(s) == 0 && *(s - 1) != c)
		n_words++;
	return (n_words);
}

static void	*ft_free(int allocated_words, char **a)
{
	while (allocated_words)
	{
		a--;
		free(*a);
		allocated_words--;
	}
	free(a);
	return (NULL);
}

static char	**allocate_and_copy(char const *s, char c, size_t i, char **a)
{
	size_t	start;
	int		allocated_words;

	start = i;
	allocated_words = 0;
	while (ft_strlen(s) >= i)
	{
		if (i > 0 && s[i - 1] != c && (s[i] == c || ft_strlen(s) == i))
		{
			*a = malloc(i - start + 1);
			if (!*a)
				return (ft_free(allocated_words, a));
			ft_strlcpy(*a++, s + start, i - start + 1);
			allocated_words++;
			while (s[i] == c)
				i++;
			start = i;
		}
		i++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	i;
	int		n_words;

	i = 0;
	if (!s)
		return (NULL);
	n_words = countwords(s, c);
	a = malloc((n_words + 1) * sizeof(char *));
	if (a == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	a = allocate_and_copy(s, c, i, a);
	if (a == NULL)
		return (NULL);
	*a = NULL;
	a = a - n_words;
	return (a);
}
