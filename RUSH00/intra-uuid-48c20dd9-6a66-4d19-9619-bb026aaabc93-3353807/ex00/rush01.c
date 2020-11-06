/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:31:53 by asalvemi          #+#    #+#             */
/*   Updated: 2020/10/25 16:31:56 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_fr(int x);
void	print_cr(int x);
void	print_lr(int x);
void	rush(int x, int y);

void	print_fr(int x)
{
	int sx;

	sx = 1;
	while (sx <= x)
	{
		if (sx == 1)
		{
			ft_putchar('/');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('\\');
				ft_putchar('\n');
			}
			else
				ft_putchar('*');
		}
		sx++;
	}
}

void	print_cr(int x)
{
	int sx;

	sx = 1;
	while (sx <= x)
	{
		if (sx == 1 && sx != x)
		{
			ft_putchar('*');
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('*');
				ft_putchar('\n');
			}
			else
				ft_putchar(' ');
		}
		sx++;
	}
}

void	print_lr(int x)
{
	int sx;

	sx = 1;
	while (sx <= x)
	{
		if (sx == 1)
		{
			ft_putchar('\\');
			if (x == 1)
			{
				ft_putchar('\n');
			}
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('/');
				ft_putchar('\n');
			}
			else
				ft_putchar('*');
		}
		sx++;
	}
}

void	rush(int x, int y)
{
	int sy;

	sy = 1;
	while (sy <= y)
	{
		if (sy == 1)
		{
			print_fr(x);
		}
		else
		{
			if (sy == y)
			{
				print_lr(x);
			}
			else
				print_cr(x);
		}
		sy++;
	}
}
