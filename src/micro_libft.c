/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:28:19 by misaac-c          #+#    #+#             */
/*   Updated: 2024/06/23 22:35:32 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	count = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\r'
		|| str[count] == '\n' || str[count] == '\v' || str[count] == '\f')
		count++;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while (str[count] >= '0' && str[count] <= '9' && str[count] != '\0')
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * sign);
}

int	ft_isdigit(int dig)
{
	if ((dig >= 48) && (dig <= 57))
	{
		return (dig);
	}
	else
	{
		return (0);
	}
}
