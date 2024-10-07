/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:32:01 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:32:07 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	pa(t_stack **pile_a, t_stack **pile_b)
{
	push(pile_b, pile_a);
	ft_putstr("pa\n");
}

void	pb(t_stack **pile_a, t_stack **pile_b)
{
	push(pile_a, pile_b);
	ft_putstr("pb\n");
}
