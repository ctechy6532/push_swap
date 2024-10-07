/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:33:23 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:33:24 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ra(t_stack **pile_a)
{
	rotate(pile_a);
	ft_putstr("ra\n");
}

void	rb(t_stack **pile_b)
{
	rotate(pile_b);
	ft_putstr("rb\n");
}

void	rr(t_stack **pile_a, t_stack **pile_b)
{
	if ((pile_size(*pile_a) < 2) || (pile_size(*pile_b) < 2))
		return ;
	rotate(pile_a);
	rotate(pile_b);
	ft_putstr("rr\n");
}
