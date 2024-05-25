/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:22:00 by dexposit          #+#    #+#             */
/*   Updated: 2022/09/26 15:28:50 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bstiter(t_bst *bst, void (*f)(void *))
{
	t_bst	*aux;

	aux = bst;
	(*f)(aux->content);
	if (aux->left)
		ft_bstiter(aux->left, (f));
	if (aux->right)
		ft_bstiter(aux->right, (f));
}
