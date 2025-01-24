/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <dcampas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:48:20 by dcampas-          #+#    #+#             */
/*   Updated: 2025/01/24 11:22:05 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
		n--;
	}
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

//Recursive putstr
void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL || fd < 0)
		return ;
	len = 0;
	if (s[len] != 0)
		len++;	
	if (len > 0)
		write (fd, s, len);
}