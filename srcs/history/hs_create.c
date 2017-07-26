/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgascoin <tgascoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:39:53 by tgascoin          #+#    #+#             */
/*   Updated: 2017/07/11 13:30:57 by tgascoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "vm.h"

t_hs	*hs_create_node(char *str, int m, t_hs *prev)
{
	t_hs	*n;

	n = NULL;
	n = malloc(sizeof(t_hs));
	n->m = m;
	n->cmd = ft_strdup(str);
	n->next = NULL;
	n->prev = prev;
	return (n);
}

t_hs	*ft_create_history(void)
{
	int		fd;
	char	*line;
	int		i;
	t_hs	*n;

	i = 0;
	fd = ft_open_history(NULL, 'r');
	n = NULL;
	while (fd > 0 && get_next_line(fd, &line))
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			if (i == 0)
				n = hs_create_node(line, 0, NULL);
			else
			{
				n->next = hs_create_node(line, 0, n);
				n = n->next;
			}
			i++;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	fd = close(fd);
	return (n);
}