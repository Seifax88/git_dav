/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:20:12 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/16 12:29:25 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*aux;

	head = *lst;
	while (head != NULL)
	{
		aux = head->next;
		if (del != NULL)
			del(head->content);
		free(head);
		head = aux;
	}
	*lst = (NULL);
}
