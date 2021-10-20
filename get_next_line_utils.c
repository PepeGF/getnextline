/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:59:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/10/20 17:10:07 by josgarci         ###   ########.fr       */
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
