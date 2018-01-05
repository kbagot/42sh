/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_possibility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:10:53 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:10:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_glob	*accolade(t_glob *g, char *line, int *i)
{
	int		save;

	save = (*i);
	g->p[0] = ++(*i);
	while (line[*i] != '\0' && line[*i] != '}')
		(*i)++;
	g->p[1] = (*i);
	if (line[*i] != '\0' &&\
		(check_pointpoint(line, save) || check_comma(line, save)))
	{
		(*i)++;
		g = add_arg(g, line, 3);
	}
	else
	{
		g->p[0] = g->p[0] - 1;
		if (line[*i] == '}')
			g->p[1] = g->p[1];
		g = remake_arg(g, line);
	}
	return (g);
}

t_glob	*square_bracket(t_glob *g, char *line, int *i)
{
	g->p[0] = ++(*i);
	while (line && line[*i] != '\0' && line[*i] != ']')
	{
		if (line[*i] && line[*i] == '[')
			(*i) = check_is_posix(line, i);
		else
			(*i)++;
	}
	g->p[1] = (*i);
	if (line[*i] == '\0')
	{
		g->p[0]--;
		g = remake_arg(g, line);
	}
	else
	{
		(*i)++;
		g = add_arg(g, line, 2);
	}
	return (g);
}

t_glob	*interogation(t_glob *g, char *line, int *i)
{
	g->p[0] = *i;
	if (line && line[*i] != '\0')
		(*i)++;
	g->p[1] = *i;
	g = add_arg(g, line, 1);
	return (g);
}

t_glob	*part_arg(t_glob *g, char *line, int *i)
{
	g->p[0] = *i;
	while (line[*i] != '\0' && line[*i] != '[' &&\
		line[*i] != '{' && line[*i] != '?' && line[*i] != '/')
		(*i)++;
	g->p[1] = *i;
	g = add_arg(g, line, 0);
	return (g);
}

t_glob	*slash_gestion(t_glob *g, char *line, int *i)
{
	char	*tmp;

	tmp = NULL;
	if (line[0] == '/')
		g->slashzero = 1;
	while (line[*i] != '\0' && line[*i] == '/')
		(*i)++;
	if (g->arg != NULL)
	{
		g = add_glob_slash(g);
		g = g->slash;
		if (line[0] == '/')
			g->slashzero = 1;
	}
	return (g);
}
