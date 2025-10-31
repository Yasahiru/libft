/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloutman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:34:09 by hloutman          #+#    #+#             */
/*   Updated: 2025/10/26 22:34:11 by hloutman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	del_lst(t_list *node, void (*del)(void *))
{
	t_list	*next;

	next = node;
	while (node)
	{
		del(node->content);
		next = node -> next;
		free(node);
		node = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next;
	t_list	*new_node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	next = lst->next;
	while (next != NULL)
	{
		temp = f(next->content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			del(temp);
			del_lst(head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		next = (next->next);
	}
	return (head);
}


void* ft_toupper2(void* c) {
    char *str = strdup((char*)c); 
    return str;
}

int main(){
	char* content1 = strdup("content1");
	char* content2 = strdup("content2");
	char* content3 = strdup("content3");

	t_list *lst1 = ft_lstnew(content1);
	t_list *lst2 = ft_lstnew(content2);
	t_list *lst3 = ft_lstnew(content3);
	lst1->next = lst2; 
	lst2->next = lst3;
	t_list *result = ft_lstmap(lst1, &ft_toupper2,&free);

	t_list *next = lst1;
	while (next){
		printf("%s\n",(char*)next->content);
		next = next->next;
	}

	del_lst(lst1, free);
	del_lst(result, free);
}
