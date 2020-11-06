/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:53:27 by asalvemi          #+#    #+#             */
/*   Updated: 2020/10/28 19:53:29 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int dim;

	dim = 0;
	if (size == 0)
	{
		while (src[dim])
			dim++;
		return (dim);
	}
	while (dim < size - 1 && src[dim] != '\0')
	{
		dest[dim] = src[dim];
		dim++;
	}
	if (dim < size)
		dest[dim] = '\0';
	while (src[dim] != '\0')
		dim++;
	return (dim);
}
