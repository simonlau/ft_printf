/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/07 11:36:10 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list.
 *
 * @see raw/project-overview/libft-subject.md
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*prev;

	prev = lst;
	while (lst != NULL)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}
