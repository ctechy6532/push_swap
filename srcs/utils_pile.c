/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:36:53 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:36:54 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	is_sorted(t_stack *pile)
{
	while (pile->next)
	{
		if (pile->value > pile->next->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	pile_size(t_stack *pile)
{
	int	size;

	size = 0;
	if (!pile)
		return (0);
	while (pile)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	add_index(t_stack **pile)
{
	int		size;
	t_stack	*highest;

	size = pile_size(*pile);
	highest = check_index(pile);
	while (highest)
	{
		highest->index = size;
		highest = check_index(pile);
		size--;
	}
}

t_stack	*check_index(t_stack **pile)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	tmp = *pile;
	value = INT_MIN;
	highest = NULL;
	while (tmp)
	{
		if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
		if (tmp->value > value && tmp->index == 0)
		{
			value = tmp->value;
			highest = tmp;
			tmp = *pile;
		}
		else
			tmp = tmp->next;
	}
	return (highest);
}
