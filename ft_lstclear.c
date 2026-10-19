/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/07 11:35:30 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Deletes and frees the given node and every successor
 * using del and free(). Sets *lst to NULL.
 * @param lst Address of a pointer to a node.
 * @param del Address of the function used to delete the content of the node.
 *
 * @see raw/project-overview/libft-subject.md
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	if (lst == NULL || del == NULL)
	{
		return ;
	}
	head = *lst;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		ft_lstdelone(current, del);
	}
	*lst = NULL;
}
