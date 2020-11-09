/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:13:15 by asalvemi          #+#    #+#             */
/*   Updated: 2020/11/06 19:13:16 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		*ft_range(int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
	{
		return (0);
	}
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	i = 0;
	while (min < max)
	{
		tab[i] = min; 
		i++;
		min++;
	}
	return (tab);
}
