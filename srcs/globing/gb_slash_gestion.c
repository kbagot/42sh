/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_slash_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:19 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:21 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*join_list(t_new *izi, t_new *rec_path)
{
	t_new	*s;

	s = izi;
	if (izi != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = rec_path;
	}
	else
	{
		izi = rec_path;
	}
	return (izi);
}

t_new	*add_path(t_new *st_path, char *path)
{
	t_new		*s;

	s = st_path;
	if (st_path != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(path);
	}
	else
	{
		st_path = init_new();
		st_path->str = ft_strdup(path);
	}
	return (st_path);
}

int		ft_listsize(t_new *e)
{
	t_new		*s;
	int			i;

	i = 0;
	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			i++;
			s = s->next;
		}
	}
	return (i);
}

char	**list_to_tab_new(t_new *e)
{
	char		**tab;
	t_new		*s;
	int			i;

	s = e;
	if (e == NULL)
		return (NULL);
	i = ft_listsize(e);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		tab[i] = ft_strdup(s->str);
		i++;
		s = s->next;
	}
	tab[i] = NULL;
	return (tab);
}
