/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:08:48 by lloko             #+#    #+#             */
/*   Updated: 2022/02/23 16:45:07 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char b)
{
	write(1, &b, 1);
}

int	ft_neodin(char *s, char b)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == b)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *str1, char *str2)
{
	int		i;
	int		j;
	char	itog[255];

	i = 0;
	j = 0;
	while (str1[i])
	{
		if (!(ft_neodin(itog, str1[i])))
			itog[j++] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (!(ft_neodin(itog, str2[i])))
			itog[j++] = str2[i];
		i++;
	}
	itog[j] = '\0';
	j = 0;
	while (itog[j])
		ft_putchar(itog[j++]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
