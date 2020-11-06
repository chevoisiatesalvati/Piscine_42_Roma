/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:17:48 by asalvemi          #+#    #+#             */
/*   Updated: 2020/10/29 20:17:51 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ret;

	ret = dest;
	while (*dest)
		dest++;
	while (nb--)
		if (!(*dest++ = *src++))
			return (ret);
	*dest = 0;
	return (ret);
}
