/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:16:55 by hharold           #+#    #+#             */
/*   Updated: 2021/11/03 21:16:56 by hharold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *as)
{
	while (*as)
	{
		*as = 0;
		as++;
	}
}