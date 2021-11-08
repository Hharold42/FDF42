/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 05:32:00 by hharold           #+#    #+#             */
/*   Updated: 2021/11/08 19:02:16 by hharold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_checkmap_aux(int fd)
{
	int		x;
	int		check;
	int		result;
	char	*line;

	check = 0;
	while (get_next_line(fd, &line))
	{
		x = 0;
		result = 0;
		while (line[x] == ' ')
			x++;
		while (line[x] != '\0')
		{
			if (line[x] == ' ' && line[x + 1] != ' ')
				result++;
			x++;
		}
		if (result != check && check > 0)
			ft_maperror(2);
		check = result;
		free(line);
	}
	free (line);
}

static void	ft_checkmap(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_maperror(1);
	ft_checkmap_aux(fd);
	close(fd);
}

void	ft_put_pixel(t_data *d, int x, int y, int color)
{
	char	*dest;

	dest = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		x;

	if (argc != 2)
		ft_maperror(0);
	ft_checkmap(argv[1]);
	x = 0;
	d.w = ft_w(argv[1]);
	d.l = ft_l(argv[1]);
	d.matrix = (t_pixel **)malloc(ft_l(argv[1]) * sizeof(t_pixel *));
	while (x < ft_l(argv[1]))
		d.matrix[x++] = malloc(sizeof(t_pixel) * ft_w(argv[1]));
	ft_fill(&d, argv[1]);
	ft_init_win(&d);
	return (0);
}
