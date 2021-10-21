/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:59:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/21 11:22:33 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(size * count);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < size * count)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)ft_calloc(sizeof(char) * (len + 1), sizeof(char));
	if (str == NULL)
		return (0);
	if (len == 0)
		return (str);
	while (i < len && i + start < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	if (!s2 && !s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)ft_calloc(sizeof(char) * (s1len + s2len + 1), sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < s1len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2len)
		str[i + s1len] = s2[i];
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (lens1 + 1));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s1, lens1 + 1);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < (dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
