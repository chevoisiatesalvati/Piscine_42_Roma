/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:10:41 by asalvemi          #+#    #+#             */
/*   Updated: 2020/11/03 14:10:45 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char *c)
{
	unsigned int	i;

	i = 0;
	if (*c == ' ' || *c == '\t'
			|| *c == '\n' || *c == '\v'
			|| *c == '\r' || *c == '\f')
		return (1);
	return (0);
}

int		parse_int(char *str, unsigned int i)
{
	int res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	unsigned int	i;
	int				sign;
	int				res;

	i = 0;
	sign = 0;
	res = 0;
	if (!str[0])
		return (0);
	while (is_space(&str[i]))
		i++;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	res = parse_int(str, i);
	if (sign % 2)
		res *= -1;
	return (res);
}
