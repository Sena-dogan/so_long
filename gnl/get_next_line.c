/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:04:15 by zdogan            #+#    #+#             */
/*   Updated: 2023/03/15 16:29:23 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read return value = rv
int	ft_error_gnl(int rv, char *buff, char *str)
{
	if (rv == -1)
	{
		free (buff);
		free (str);
		return (1);
	}
	return (0);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rv;
	char	*tmp;

	if (!str)
		str = ft_strdup("");
	buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	rv = 1;
	while (!ft_strchr(str, '\n') && rv != 0)
	{
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv == 0)
			break ;
		if (ft_error_gnl(rv, buff, str))
			return (NULL);
		buff[rv] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	free(buff);
	return (str);
}

char	*ft_new_line(char *str)
{
	char	*ptr;
	int		len;

	if (!str || !*str)
		return (NULL);
	ptr = ft_strchr(str, '\n');
	if (!ptr)
		return (ft_strdup(str));
	ptr++;
	if (!*ptr)
		return (ft_strdup(str));
	len = ft_strlen(str) - ft_strlen(ptr);
	return (ft_substr(str, 0, len));
}

char	*ft_static_str(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	ptr++;
	if (!(*ptr))
	{
		free(str);
		return (NULL);
	}
	ptr = ft_strdup(ptr);
	free (str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_new_line(str);
	str = ft_static_str(str);
	return (line);
}
