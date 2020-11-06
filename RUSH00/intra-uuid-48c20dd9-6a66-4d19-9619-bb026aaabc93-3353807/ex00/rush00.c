/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:47:19 by asalvemi          #+#    #+#             */
/*   Updated: 2020/10/25 13:47:27 by asalvemi         ###   ########.fr       */
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
		if (sx == 1 && sx != x)
		{
			ft_putchar('o');
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('o');
				ft_putchar('\n');
			}
			else
				ft_putchar('-');
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
			ft_putchar('|');
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('|');
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
		if (sx == 1 && sx != x)
		{
			ft_putchar('o');
		}
		else
		{
			if (sx == x)
			{
				ft_putchar('o');
				ft_putchar('\n');
			}
			else
				ft_putchar('-');
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
		if (sy == 1 && sy != y)
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
