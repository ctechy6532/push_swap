/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:32:42 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:32:47 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*fill(t_stack **pile_a, t_stack **pile_b, int argc, char **argv)
{
	t_stack		*new_pile;
	int			i;

	new_pile = NULL;
	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			error_exit_free("Malloc failed", pile_a, pile_b);
	}
	else
		i = 1;
	while (argv[i])
	{
		new_pile = new_stack(ft_atoi(argv[i]));
		if (!new_pile)
			error_exit_free("Malloc failed", pile_a, pile_b);
		new_pile = get_last(new_pile);
		fill_stack(pile_a, new_pile);
		i++;
	}
	fill_plus(pile_a, argv, argc);
	return (new_pile);
}

void	fill_plus(t_stack **pile_a, char **argv, int argc)
{
	add_index(pile_a);
	if (argc == 2)
		free_tab(argv);
}

t_stack	*get_last(t_stack *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}

void	fill_stack(t_stack **pile_a, t_stack *new_pile)
{
	t_stack	*node;

	if (!new_pile)
		return ;
	if (*pile_a)
	{
		node = get_last(*pile_a);
		node->next = new_pile;
	}
	else
		*pile_a = new_pile;
}

t_stack	*new_stack(int number)
{
	t_stack	*new_pile;

	new_pile = malloc(sizeof(t_stack));
	if (!new_pile)
		return (NULL);
	new_pile->value = number;
	new_pile->index = 0;
	new_pile->next = NULL;
	return (new_pile);
}
