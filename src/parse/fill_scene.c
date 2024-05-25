/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:10:24 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/04 14:17:50 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	error_id(int n_line, int ref)
{
	if (ref == 0)
	{
		error_msg("Error\nInvalid identifier in row: ");
		ft_putnbr_fd(n_line, 2);
		error_msg("\n");
		return (1);
	}
	else if (ref == 1)
	{
		error_msg("Error\nCapital letter elements in row: ");
		ft_putnbr_fd(n_line, 2);
		error_msg("\n");
		return (1);
	}
	return (1);
}

int	process_cy_id(char **line_content, int n_line, t_scene *scene)
{
	if (ft_strncmp(line_content[0], "cy", ft_strlen(line_content[0])) == 0)
	{
		if (cylinder_check(line_content, scene, n_line) == 1)
			return (1);
	}
	if (ft_strncmp(line_content[0], "pl", ft_strlen(line_content[0])) == 0)
	{
		if (plane_check(line_content, scene, n_line) == 1)
			return (1);
	}
	return (0);
}

int	process_id(char **line_content, int n_line, t_scene *scene)
{
	if (ft_strncmp(line_content[0], "A", ft_strlen(line_content[0])) == 0)
	{
		if (ambient(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "C", ft_strlen(line_content[0])) == 0)
	{
		if (camera(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "L", ft_strlen(line_content[0])) == 0)
	{
		if (light(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (ft_strncmp(line_content[0], "sp", ft_strlen(line_content[0])) == 0)
	{
		if (sphere_check(line_content, scene, n_line) == 1)
			return (1);
	}
	else if (process_cy_id(line_content, n_line, scene) == 1)
		return (1);
	return (0);
}	

int	split_line(char *line, int n_line, t_scene *scene)
{
	int		i;
	char	**line_content;
	char	*neo_line;

	i = 0;
	if (line[i] == '\n')
		return (free(line), 0);
	neo_line = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	line_content = ft_split(neo_line, ' ');
	free(neo_line);
	if (process_id(line_content, n_line, scene) == 1)
	{
		free_arg(line_content);
		return (1);
	}
	if (line_content)
		free_arg(line_content);
	return (0);
}

int	fill_scene(int fd, t_scene *scene)
{
	char	*line;
	int		n_line;

	n_line = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (split_line(line, n_line, scene) == 1)
			return (1);
		line = get_next_line(fd);
		n_line++;
	}
	return (0);
}
