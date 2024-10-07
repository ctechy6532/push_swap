/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:34:25 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/02 13:34:27 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *pile)
{
	int	tmp;

	if (!pile || pile->next == NULL)
		return ;
	if (pile_size(pile) < 2)
		return ;
	tmp = pile->value;
	pile->value = pile->next->value;
	pile->next->value = tmp;
}

void	push(t_stack **pile_src, t_stack **pile_dst)
{
	t_stack	*tmp;

	if (pile_size(*pile_src) == 0)
		return ;
	tmp = (*pile_src)->next;
	(*pile_src)->next = *pile_dst;
	*pile_dst = *pile_src;
	*pile_src = tmp;
}

void	rotate(t_stack **pile)
{
	t_stack	*tmp;
	t_stack	*top_pile;

	if (pile_size(*pile) < 2)
		return ;
	tmp = get_last(*pile);
	top_pile = *pile;
	*pile = (*pile)->next;
	tmp->next = top_pile;
	top_pile->next = NULL;
}

void	reverse(t_stack **pile)
{
	t_stack	*bottom;
	t_stack	*tmp;
	t_stack	*prev;

	if (pile_size(*pile) < 2)
		return ;
	prev = *pile;
	while (prev->next->next)
		prev = prev->next;
	bottom = get_last(*pile);
	tmp = *pile;
	*pile = bottom;
	(*pile)->next = tmp;
	prev->next = NULL;
}
