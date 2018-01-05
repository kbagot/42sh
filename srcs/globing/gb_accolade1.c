/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_accolade1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:09:37 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:18:40 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*make_comma(t_new *new, char *str)
{
	char	**split;
	t_new	*s;
	t_new	*izi;
	int		i;

	izi = NULL;
	s = new;
	if (!(split = ft_strsplit(str, ',')))
		return (new);
	if (s != NULL)
	{
		while (s != NULL)
		{
			i = 0;
			while (split && split[i])
				izi = add_joinaccolade(izi, s->str, split[i++]);
			s = s->next;
		}
		free_new(new);
	}
	else
		izi = make_commadup(split);
	free_split(split);
	return (izi);
}

int		check_rebuild_path(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == -42)
			return (1);
		i++;
	}
	return (0);
}
