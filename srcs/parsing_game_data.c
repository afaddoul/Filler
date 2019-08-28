/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_game_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/28 19:34:15 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_player(int *p)
{
	char	**arr;
	char	*line;
	int		check;
	int		i;

	i = 0;
	check = get_next_line(0, &line);
	if (check != 1)
		return (-1);
	if (!(arr = ft_strsplit(line, ' ')))
		return (-1);
	while ((i < 5) && arr[i])
		i++;
	if (i == 5)
	{
		if (ft_strnequ(line, "$$$ exec p", 10))
			*p = ft_atoi(arr[2] + 1);
		else
			return (-1);
	}
	else if ((i != 5) || check == -1)
	{
		free_two_dim_arr(arr, (i + 1));
		free(line);
		return (-1);
	}
	free_two_dim_arr(arr, (i + 1));
	free(line);
	return (1);
}

int			get_dim_board(int *x, int *y)
{
	char	**arr;
	char	*line;
	int		check;
	int		i;

	i = 0;
	check = get_next_line(0, &line);
	if (check != 1)
		return (-1);
	arr = ft_strsplit(line, ' ');
	while ((i < 3) && arr && arr[i])
		i++;
	if (i == 3)
	{
		if (ft_strnequ(line, "Plateau", 7))
		{
			*x = ft_atoi(arr[1]);
			*y = ft_atoi(arr[2]);
		}
		else
			return (-1);
	}
	else
	{
		free_two_dim_arr(arr, i + 1);
		free(line);
		return (-1);
	}
	free_two_dim_arr(arr, i + 1);
	free(line);
	return (1);
}

int			get_dim_token(int *x, int *y)
{
	char	**arr;
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	while ((i < 3) && arr[i])
		i++;
	if (i == 3)
	{
		if (ft_strnequ(line, "Piece", 5))
		{
			*x = ft_atoi(arr[1]);
			*y = ft_atoi(arr[2]);
		}
		else
			return (-1);
	}
	else
	{
		free_two_dim_arr(arr, i + 1);
		free(line);
		return (-1);
	}
	free_two_dim_arr(arr, i + 1);
	free(line);
	return (1);
}
