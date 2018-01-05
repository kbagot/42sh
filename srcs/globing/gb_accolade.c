/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_accolade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:08:31 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/27 00:44:23 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_pointpoint(char *line, int i)
{
	i++;
	if (line && ft_isalnum(line[i]))
		if (line[i + 1] == '.')
			if (line[i + 2] == '.')
				if (ft_isalnum(line[i + 3]))
					return (1);
	return (0);
}

int		check_comma(char *line, int i)
{
	int	count;

	count = 0;
	i++;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			count = 1;
		if (line[i] == '}' && count == 1)
			return (1);
		i++;
	}
	return (0);
}

t_new	*add_joinaccolade(t_new *new, char *s1, char *s2)
{
	t_new	*s;

	s = new;
	if (new != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strjoin(s1, s2);
	}
	else
	{
		new = init_new();
		new->str = ft_strjoin(s1, s2);
	}
	return (new);
}

t_new	*add_dupaccolade(t_new *new, char *str)
{
	t_new	*s;

	s = new;
	if (new != NULL)
	{
		while (s->next != NULL)
			s = s->next;
		s->next = init_new();
		s = s->next;
		s->str = ft_strdup(str);
	}
	else
	{
		new = init_new();
		new->str = ft_strdup(str);
	}
	return (new);
}

t_new	*make_pointpoint(t_new *new, char *str)
{
	t_new	*s;
	t_new	*izi;
	int		c;
	char	*w;

	izi = NULL;
	c = str[0];
	s = new;
	if (new != NULL)
	{
		while (s != NULL)
		{
			while (c <= str[3])
			{
				w = creat_bracket(c++);
				izi = add_joinaccolade(izi, s->str, w);
				ft_strdel(&w);
			}
			s = s->next;
		}
		free_new(new);
	}
	else
		izi = make_pointpointdup(str);
	return (izi);
}
