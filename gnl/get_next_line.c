/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:29:45 by lloko             #+#    #+#             */
/*   Updated: 2022/02/23 19:47:13 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	char	b;
	char	*buf;
	int		i;
	int		itog;

	i = 0;
	buf = malloc(1000000000);
	while ((itog = read(0, &b, 1) > 0) && b != '\n')
		buf[i++] = b;
	buf[i] = '\0';
	*line = buf;
	return (itog);
}
