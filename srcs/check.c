/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:02:32 by ctechy            #+#    #+#             */
/*   Updated: 2022/10/14 15:02:34 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	check_is_number(char *nb)
{
	int	i;

	i = 0;
	if ((nb[i] == '-' || nb[i] == '+') && nb[i + 1] != '\0')
		i++;
	while (nb[i] && ft_isdigit(nb[i]))
		i++;
	if (!ft_isdigit(nb[i]) && nb[i] != '\0')
		return (0);
	return (1);
}

static int	check_dupli(char **nb)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (nb[i])
	{
		j = 1;
		tmp = ft_atoi(nb[i]);
		while (nb[j])
		{
			if (tmp == ft_atoi(nb[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_argv(char **argv, int argc)
{
	int		i;
	long	tmp;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			error_exit("Malloc failed");
	}
	else
		i = 1;
	while (argv[i])
	{
		if (!check_is_number(argv[i]) || !check_dupli(&argv[i]) || !*argv[i])
			error_exit("Error");
		tmp = atoil(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error_exit("Error");
		i++;
	}
	if (argc == 2)
		free_tab(argv);
}
