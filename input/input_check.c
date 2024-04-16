/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:34 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/20 16:59:05 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* hacks if the arguments are valid */
int	valid_args(int *argc, char **argv, char ***array)
{
	int	i;

	if (*argc < 2)
		ft_error(NULL, 0);
	if (!argv[1][0])
		ft_error("Error\n", 1);
	i = 0;
	if (!(make_array(argc, argv, array)))
		ft_error("Error\n", 1);
	while ((*array)[i])
	{
		if (!(is_valid((*array)[i], *array)))
			ft_error("Error\n", 1);
		i++;
	}
	return (1);
}

/*Reads the input, based on wheter it's beteween quotes or not,
then parses it on to an array*/
int	make_array(int *argc, char **argv, char ***array)
{
	int	i;

	i = 0;
	if (*argc == 2)
	{
		*array = ft_split(argv[1], ' ');
		if (!(**array))
			return (free(*array), 0);
	}
	else
	{
		*array = malloc(sizeof(char *) * (*argc));
		if (!(*array))
			return (0);
		while (i < ((*argc) - 1))
		{
			(*array)[i] = ft_strdup(argv[i + 1]);
			if (!(*array)[i])
				return (ft_free_array(*array), 0);
			i++;
		}
		(*array)[i] = NULL;
	}
	return (1);
}

/* cheks if th contents of the array are valid.
If not, it frees the array*/
int	is_valid(char *str, char **array)
{
	int	i;

	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (ft_free_array(array), 0);
		i = 1;
	}
	else
		i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ft_free_array(array), 0);
		i++;
	}
	if (!(fit_in_int(str)))
		return (ft_free_array(array), 0);
	return (1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

/* Checks if the number fits in an integer */
int	fit_in_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	if ((res < -2147483648) || (res > 2147483647))
		return (0);
	else
		return (1);
}
