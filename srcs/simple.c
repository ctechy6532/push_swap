/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:38 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/02 14:00:40 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tree(t_stack **pile)
{
	int		highest;

	if (is_sorted(*pile))
		return ;
	highest = find_highest_index(*pile);
	if (((*pile)->index == highest && !is_sorted(*pile)))
		ra(pile);
	else if (((*pile)->next->index == highest && !is_sorted(*pile)))
		rra(pile);
	if ((((*pile)->index > (*pile)->next->index) && !is_sorted(*pile)))
		sa(pile);
}

void	sort_four(t_stack **pile_a, t_stack **pile_b)
{
	int		dest_index;

	dest_index = distance_index(*pile_a);
	if (dest_index == 1)
		ra(pile_a);
	else if (dest_index == 2)
	{
		ra(pile_a);
		ra(pile_a);
	}	
	else if (dest_index == 3)
		rra(pile_a);
	pb(pile_a, pile_b);
	if (!is_sorted(*pile_a))
		sort_tree(pile_a);
	pa(pile_a, pile_b);
	ra(pile_a);
}

void	sort_five(t_stack **pile_a, t_stack **pile_b)
{
	int		dest_index;

	dest_index = distance_index(*pile_a);
	if (dest_index == 1)
		ra(pile_a);
	else if (dest_index == 2)
	{
		ra(pile_a);
		ra(pile_a);
	}	
	else if (dest_index == 3)
	{
		rra(pile_a);
		rra(pile_a);
	}
	else if (dest_index == 4)
		rra(pile_a);
	pb(pile_a, pile_b);
	if (!is_sorted(*pile_a))
		sort_four(pile_a, pile_b);
	pa(pile_a, pile_b);
	ra(pile_a);
}

void	sort_radix(t_stack **pile_a, t_stack **pile_b)
{
	int	i;
	int	j;
	int	size;

	size = pile_size(*pile_a);
	i = 0;
	while (!is_sorted(*pile_a))
	{
		j = 0;
		while (j < size)
		{
			if ((((*pile_a)->index >> i) & 1) == 1)
				ra(pile_a);
			else
				pb(pile_a, pile_b);
			j++;
		}
		while (pile_size(*pile_b) != 0)
			pa(pile_a, pile_b);
		i++;
	}
}
