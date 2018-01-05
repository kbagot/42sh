/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_recupchartab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:43:01 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				return (1);
			i++;
		}
	return (0);
}

void	reverse_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == 42)
				s[i] = -42;
			i++;
		}
}

void	get_char42(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == -42)
				s[i] = 42;
			i++;
		}
}

void	get_slashzero_home(t_glob *g)
{
	t_glob	*s;

	s = g;
	if (g)
		while (s)
		{
			s->slashzero = 1;
			s = s->slash;
		}
}
