/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:12:07 by dexposit          #+#    #+#             */
/*   Updated: 2022/09/17 12:07:04 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bst	*ft_bstsearch(t_bst **bst, void *cnt, int (*f)(void *, void *))
{
	t_bst	*aux;

	aux = *bst;
	while (aux && (*f)(aux->content, cnt))
	{
		if ((*f)(aux->content, cnt) > 0)
			aux = aux->right;
		else
			aux = aux->left;
	}
	return (aux);
}
