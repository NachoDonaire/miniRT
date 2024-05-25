/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:06:29 by dexposit          #+#    #+#             */
/*   Updated: 2022/09/17 12:02:38 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bstadd(t_bst **bst, t_bst *new, int (*f)(void *, void *))
{
	int		num;
	char	*ch;

	if (bst && new)
	{
		num = (*f)((*bst)->content, new->content);
		ch = ft_itoa(num);
		write(1, ch, 1);
		free(ch);
	}	
}
