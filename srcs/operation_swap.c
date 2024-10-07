/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:33:07 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:33:09 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sa(t_stack **pile_a)
{
	swap(*pile_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **pile_b)
{
	swap(*pile_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **pile_a, t_stack **pile_b)
{
	if ((pile_size(*pile_a) < 2) || (pile_size(*pile_b) < 2))
		return ;
	swap(*pile_a);
	swap(*pile_b);
	ft_putstr("ss\n");
}
