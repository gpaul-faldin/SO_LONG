/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:25:42 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:03:20 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*re;

	if (lst)
	{
		re = ft_lstnew(f(lst->content));
		if (re == NULL)
			return (NULL);
		re->next = ft_lstmap(lst->next, f, del);
		return (re);
	}
	return (NULL);
}
