/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgenc <emgenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:35:20 by emgenc            #+#    #+#             */
/*   Updated: 2025/01/03 20:20:17 by emgenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*source_copy;

	source_copy = (char *)s;
	if (!s)
		return (NULL);
	while (*source_copy)
	{
		if (*source_copy == (unsigned char)c)
			return (source_copy);
		source_copy++;
	}
	if ((unsigned char)c == 0)
		return (source_copy);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!dstsize)
		return (ft_strlen(src));
	srclen = ft_strlen(src);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}

char	*ft_strjoin_strcat(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(str), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*to_be_returned;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		size = ft_strlen(s + start);
		if (size < len)
			len = size;
		to_be_returned = (char *)malloc((sizeof(char) * len) + 1);
		if (!to_be_returned)
			return (NULL);
		ft_strlcpy(to_be_returned, &s[start], len + 1);
		return (to_be_returned);
	}
}
