/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:57:04 by ilemos-c          #+#    #+#             */
/*   Updated: 2025/08/09 11:47:25 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		(del)(lst->content);
	free(lst);
}
/*
void	ft_delete_content(void	*content)
{
	printf("Deletando: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*node = malloc(sizeof(t_list));
	node->content = ft_strdup("Bom Dia!");
	node->next = NULL;

	printf("Nó criado com conteúdo: %s\n", (char *)node->content);

	ft_lstdelone(node, ft_delete_content);

	printf("Nó deletado com sucesso!\n");

	return (0);
}*/
