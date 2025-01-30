/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgenc <emgenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:36:00 by emgenc            #+#    #+#             */
/*   Updated: 2025/01/03 20:21:52 by emgenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(char *retain, int fd)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (!ft_strchr(retain, '\n') && ++i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1 || (i == 0 && ft_strlen(retain) == 0))
		{
			if (retain)
				free(retain);
			return (free(temp), NULL);
		}
		temp[i] = '\0';
		retain = ft_strjoin_strcat(retain, temp);
		i--;
	}
	return (free(temp), retain);
}

static void	ft_assign(char **retain, char **line)
{
	int		i;
	char	*initial_retain;

	i = 0;
	initial_retain = *retain;
	while ((*retain)[i] != '\n' && (*retain)[i] != '\0')
		i++;
	*line = ft_substr(*retain, 0, i + 1);
	if (!**retain)
		return (*retain = NULL, free(*retain));
	*retain = ft_substr(*retain, i + 1,
			ft_strlen(ft_strchr(*retain, '\n')));
	free(initial_retain);
}

char	*get_next_line(int fd)
{
	static char	*retain[1903];	// En büyük Beşiktaş!
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1903)
		return (NULL);
	retain[fd] = ft_read_file(retain[fd], fd);
	if (!retain[fd] || !*retain[fd])
		return (NULL);
	ft_assign(&retain[fd], &line);
	return (line);
}
