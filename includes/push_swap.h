/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:37:45 by ctechy            #+#    #+#             */
/*   Updated: 2022/10/14 09:37:46 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

t_stack		*check_index(t_stack **pile);
void		fill_plus(t_stack **pile_a, char **argv, int argc);
void		error_exit(char *mess);
int			pile_size(t_stack *pile);
int			is_sorted(t_stack *pile);
int			find_highest_index(t_stack *pile);
int			distance_index(t_stack *pile);
void		ft_putstr(char *str);
void		check_argv(char **argv, int argc);
void		free_tab(char **argv);
void		free_stack(t_stack **stack);
void		error_exit_free(char *mess, t_stack **pile_a, t_stack **pile_b);

void		pb(t_stack **pile_a, t_stack **pile_b);
void		pa(t_stack **pile_a, t_stack **pile_b);
void		rrb(t_stack **pile_b);
void		rrr(t_stack **pile_a, t_stack **pile_b);
void		rra(t_stack **pile_a);
void		rb(t_stack **pile_b);
void		ra(t_stack **pile_a);
void		rr(t_stack **pile_a, t_stack **pile_b);
void		sa(t_stack **pile_a);
void		sb(t_stack **pile_b);
void		ss(t_stack **pile_a, t_stack **pile_b);

void		swap(t_stack *pile);
void		push(t_stack **pile_src, t_stack **pile_dst);
void		rotate(t_stack **pile);
void		reverse(t_stack **pile);

void		add_index(t_stack **pile);
t_stack		*new_stack(int number);
void		fill_stack(t_stack **pile_a, t_stack *new_pile);
t_stack		*get_last(t_stack *pile);
t_stack		*fill(t_stack **pile_a, t_stack **pile_b, int argc, char **argv);

void		sort_tree(t_stack **pile);
void		sort_four(t_stack **pile_a, t_stack **pile_b);
void		sort_five(t_stack **pile_a, t_stack **pile_b);
void		sort_radix(t_stack **pile_a, t_stack **pile_b);
long long	atoil(const char *str);

#endif
