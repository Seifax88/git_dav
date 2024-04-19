/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:37:41 by dgargant          #+#    #+#             */
/*   Updated: 2024/02/22 14:55:06 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*aux;

	new_list = NULL;
	if (lst || f || del)
	{
		while (lst)
		{
			aux = f(lst->content);
			new_node = ft_lstnew(aux);
			if (!new_node)
			{
				del(aux);
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
	}
	else
		return (NULL);
	return (new_list);
}

/*#include <stdio.h>
void	*f3(void *content)
{
	char *new_content = (char *)content;
	for (int i = 0; new_content[i]; i++) {
        new_content[i] = ft_toupper(new_content[i]);
    }
	return (new_content);
}
void	del(void *content)
{
	free(content);
}
int main()
{
	t_list *lst;
	t_list *node;
	t_list *new_list;
	//char *content1;
	//char *content2;

	char content1[] = "hola mundo";
	char content2[] = "hola";
	node = ft_lstnew(content2);
	lst = ft_lstnew(content1);
	ft_lstadd_back(&lst, node);
	new_list = ft_lstmap(lst, f3, del);
	
	while (new_list != NULL)
	{
		printf("contenido de la lista: %s\n", new_list->content);
		new_list = new_list->next;
	}
}*/
