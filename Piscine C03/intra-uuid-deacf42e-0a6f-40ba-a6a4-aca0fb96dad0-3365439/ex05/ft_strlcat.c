/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:21:43 by asalvemi          #+#    #+#             */
/*   Updated: 2020/10/29 22:21:46 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	j;
	unsigned int	s;

	d = 0;
	j = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
		s++;
	if (size <= d)
		s += size;
	else
		s += d;
	while (src[j] && d + 1 < size)
		dest[d++] = src[j++];
	dest[d] = '\0';
	return (s);
}
