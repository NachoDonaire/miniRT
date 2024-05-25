/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:30:23 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/03 17:41:44 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	check_res(t_inters *res, t_scene *scene)
{
	t_util_plane	camera_plane;

	if (!res->point)
		return ;
	camera_plane = pleq(v_gen(scene->c.vec), v_gen(scene->c.coord));
	if (subs_in_plane(camera_plane, v_gen(res->point)) <= EPSILON)
	{
		res->type = 3;
		res->obj = NULL;
		free(res->point);
		res->point = NULL;
		res->len_c = -1.0;
		res->cy = NULL;
	}
}

int	isinscreen(float *in, t_scene *scene)
{
	t_util_plane	camera_plane;

	if (!in)
		return (0);
	camera_plane = pleq(v_gen(scene->c.vec), v_gen(scene->c.coord));
	if (subs_in_plane(camera_plane, v_gen(in)) <= EPSILON)
		return (0);
	return (1);
}
