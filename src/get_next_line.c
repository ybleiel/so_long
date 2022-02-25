/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:13:39 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 12:07:46 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file(int fd, char *file)
{
	char	*buf;
	int		rd;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd = 1;
	while (!(ft_strchr(file, '\n')) && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		file = ft_strjoin(file, buf);
	}
	free(buf);
	return (file);
}

static char	*get_line(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (file[0] == '\0')
		return (NULL);
	while (file[i] != '\n' && file[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (file[++i] && file[i] != '\n')
		line[i] = file[i];
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*modify_file(char *file)
{
	char	*newfile;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (file[i] == '\0')
	{
		free(file);
		return (0);
	}
	newfile = malloc(ft_strlen(file) - i + 1);
	if (!newfile)
		return (NULL);
	i++;
	while (file[i])
		newfile[a++] = file[i++];
	newfile[a] = '\0';
	free(file);
	return (newfile);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	file = read_file(fd, file);
	if (!file)
		return (NULL);
	line = get_line(file);
	file = modify_file(file);
	return (line);
}

// int main()
// {
// 	char *line;
// 	int fd = open("file", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	return 0;
// }