/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:27:40 by ctechy            #+#    #+#             */
/*   Updated: 2022/11/04 12:27:43 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(char *mess)
{
	ft_putendl_fd(mess, 2);
	exit(EXIT_FAILURE);
}

void	error_exit_free(char *mess, t_stack **pile_a, t_stack **pile_b)
{
	if (pile_a == NULL || *pile_a != NULL)
		free_stack(pile_a);
	if (pile_b == NULL || *pile_b != NULL)
		free_stack(pile_b);
	ft_putendl_fd(mess, 2);
	exit(EXIT_FAILURE);
}
