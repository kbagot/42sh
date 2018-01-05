/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_init1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:38:19 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 03:39:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*init_new(void)
{
	t_new	*new;

	if (!(new = (t_new *)malloc(sizeof(t_new))))
		return (NULL);
	new->str = NULL;
	new->i = 0;
	new->next = NULL;
	return (new);
}

t_new	*add_new(t_new *new)
{
	t_new	*s;

	s = new;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
	}
	else
	{
		s = init_new();
		return (s);
	}
	return (new);
}

t_glob	*add_sbplease(t_glob *g, char *str)
{
	t_new		*s;

	s = g->sb;
	if (s != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
	}
	else
	{
		g->sb = init_new();
		g->sb->str = ft_strdup(str);
	}
	return (g);
}
