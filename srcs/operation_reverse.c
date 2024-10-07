/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:33:36 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:33:38 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rra(t_stack **pile_a)
{
	reverse(pile_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **pile_b)
{
	reverse(pile_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **pile_a, t_stack **pile_b)
{
	if ((pile_size(*pile_a) < 2) || (pile_size(*pile_b) < 2))
		return ;
	reverse(pile_a);
	reverse(pile_b);
	ft_putstr("rrr\n");
}
