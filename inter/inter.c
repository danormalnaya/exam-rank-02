/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:46:34 by lloko             #+#    #+#             */
/*   Updated: 2022/02/23 17:12:19 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char b)
{
	write(1, &b, 1);
}

int	ft_neodin(char *s1, char b)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == b)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	itog[255];

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (!(ft_neodin(itog, s1[i])))
					itog[k++] = s1[i];
			}
			j++;
		}
		i++;
	}
	itog[k] = '\0';
	k = 0;
	while (itog[k])
		ft_putchar(itog[k++]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
