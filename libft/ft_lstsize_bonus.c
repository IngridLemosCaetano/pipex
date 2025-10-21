/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:07:32 by ingrid            #+#    #+#             */
/*   Updated: 2025/08/09 11:47:48 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *head = NULL;

	ft_lstadd_front(&head, ft_lstnew("A"));
	ft_lstadd_front(&head, ft_lstnew("B"));
	ft_lstadd_front(&head, ft_lstnew("C"));

	t_list	*temp = head;
	while (temp)
	{
		printf("[%s] -> ", (char *)temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
	printf("Length: %d\n", ft_lstsize(head));
	return (0);
}*/
