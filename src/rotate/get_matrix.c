/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:48 by ndonaire          #+#    #+#             */
/*   Updated: 2023/06/01 22:54:41 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	*obtain_y(t_vector	v)
{
	float		theta;
	t_vector	*matrix;

	matrix = malloc(sizeof(t_vector) * 4);
	theta = atan2(-v.x, v.z);
	matrix[0].x = cos(theta);
	matrix[0].y = 0;
	matrix[0].z = sin(theta);
	matrix[1].x = 0;
	matrix[1].y = 1;
	matrix[1].z = 0;
	matrix[2].x = -sin(theta);
	matrix[2].y = 0;
	matrix[2].z = cos(theta);
	return (matrix);
}

t_vector	*obtain_x(t_vector v)
{
	float		phi;
	t_vector	*m;

	m = malloc(sizeof(t_vector) * 4);
	phi = M_PI / 2 - atan2(sqrt(v.x * v.x + v.z * v.z), v.y);
	m[0].x = 1;
	m[0].y = 0;
	m[0].z = 0;
	m[1].x = 0;
	m[1].y = cos(phi);
	m[1].z = -sin(phi);
	m[2].x = 0;
	m[2].y = sin(phi);
	m[2].z = cos(phi);
	return (m);
}

t_vector	rotate_yaxis(t_vector v)
{
	t_vector	*m;
	t_vector	t;

	m = malloc(sizeof(t_vector) * 3);
	m[0].x = cos(M_PI);
	m[0].y = 0;
	m[0].z = -sin(M_PI);
	m[1].x = 0;
	m[1].y = 1;
	m[1].z = 0;
	m[2].x = sin(M_PI);
	m[2].y = 0;
	m[2].z = cos(M_PI);
	t = matrix_vector_product(m, v);
	free(m);
	return (t);
}

int	check_camera(t_camera C)
{
	t_vector	v;

	v = v_gen(C.vec);
	if (v.x == 0 && v.y == 0 && v.z == -1)
		return (0);
	return (1);
}	
