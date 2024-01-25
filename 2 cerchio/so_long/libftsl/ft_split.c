/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:36:17 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/23 15:39:36 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	n_parole(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (++i);
}

static char	*word_dup(char const *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a;
	char	**split;

	a = 0;
	if (!(s))
		return (0);
	split = (char **) malloc (sizeof(char *) * (n_parole(s, c) + 1));
	if (!(split))
		return (NULL);
	i = 0;
	while (s[a])
	{
		if (s[a] && (a == 0 || is_sep(s[a - 1], c)))
		{
			split[i] = word_dup(&s[a], c);
			i++;
		}
		a++;
	}
	split[i] = 0;
	return (split);
}
/*
int main (void)
{
	char	**s2;
	char	*s1 = "mi chiamo andrea";
	int	i = 0;

	s2 = ft_split(s1, ' ');
	while (s2[i])
	{
		printf ("%s\n", s2[i]);
		i++;
	}
	return (0);
}*/