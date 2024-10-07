/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:45 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/02 14:00:46 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	find_highest_index(t_stack *pile)
{
	int		index;

	index = pile->index;
	while (pile)
	{
		if (pile->index > index)
			index = pile->index;
		pile = pile->next;
	}
	return (index);
}

int	distance_index(t_stack *pile)
{
	int		index;
	int		lenght;

	index = find_highest_index(pile);
	lenght = 0;
	while (pile)
	{
		if (pile->index == index)
			break ;
		lenght++;
		pile = pile->next;
	}
	return (lenght);
}

void	free_stack(t_stack **pile)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = *pile;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	free(pile);
}
