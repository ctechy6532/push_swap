/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:35:33 by ctechy            #+#    #+#             */
/*   Updated: 2022/10/14 09:35:36 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_sorting(t_stack **pile_a, t_stack **pile_b)
{
	int	size;

	size = pile_size(*pile_a);
	if (size == 2 && !is_sorted(*pile_a))
		sa(pile_a);
	else if (size == 3 && !is_sorted(*pile_a))
		sort_tree(pile_a);
	else if (size == 4 && !is_sorted(*pile_a))
		sort_four(pile_a, pile_b);
	else if (size == 5 && !is_sorted(*pile_a))
		sort_five(pile_a, pile_b);
	else if (size > 5 && !is_sorted(*pile_a))
		sort_radix(pile_a, pile_b);
}

void	check_malloc(t_stack **pile_a, t_stack **pile_b)
{
	if (!pile_a && pile_b)
	{
		free_stack(pile_b);
		error_exit("malloc failed");
	}
	else if (pile_a && !pile_b)
	{
		free_stack(pile_a);
		error_exit("malloc failed");
	}
	else if (!pile_a && !pile_b)
		error_exit("malloc failed");
}

int	main(int argc, char **argv)
{
	t_stack	**pile_a;
	t_stack	**pile_b;

	if (argc < 2)
		return (0);
	check_argv(argv, argc);
	pile_a = malloc(sizeof(t_stack *));
	pile_b = malloc(sizeof(t_stack *));
	check_malloc(pile_a, pile_b);
	*pile_a = NULL;
	*pile_b = NULL;
	fill(pile_a, pile_b, argc, argv);
	choose_sorting(pile_a, pile_b);
	free_stack(pile_a);
	free_stack(pile_b);
	return (0);
}
