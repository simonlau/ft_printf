/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/07 18:50:34 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node new at the beginning of the list.
 * @param lst Address of a pointer to the first node of a list.
 * @param new Address of a pointer to the node to be added.
 *
 * @see raw/project-overview/libft-subject.md
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	head = *lst;
	if (head == NULL)
	{
		new->next = NULL;
	}
	else
	{
		new->next = head;
	}
	*lst = new;
}
