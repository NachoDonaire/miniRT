/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:12 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/24 18:36:42 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	matrix_vector_product(t_vector *matrix, t_vector v)
{
	t_vector	new;

	new.x = matrix[0].x * v.x + matrix[0].y * v.y + matrix[0].z * v.z;
	new.y = matrix[1].x * v.x + matrix[1].y * v.y + matrix[1].z * v.z;
	new.z = matrix[2].x * v.x + matrix[2].y * v.y + matrix[2].z * v.z;
	return (new);
}

void	vectoflo(float f[3], t_vector v)
{
	f[0] = v.x;
	f[1] = v.y;
	f[2] = v.z;
}
