/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <dexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:30:39 by dexposit          #+#    #+#             */
/*   Updated: 2023/06/04 14:15:13 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	error_msg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
	return (1);
}