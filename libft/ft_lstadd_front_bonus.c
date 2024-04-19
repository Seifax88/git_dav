/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:34:05 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/21 09:52:38 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
int main()
{
	t_list *lst;
	t_list *node;
	char *content1;
	char *content2;

	content1 = "hola mundo";
	content2 = "hola";
	node = ft_lstnew(content2);
	lst = ft_lstnew(content1);
	ft_lstadd_front(&lst, node);
	while (lst != NULL)
	{
		printf("contenido de la lista: %s ", lst->content);
		lst = lst->next;
	}
	return (0);
}*/