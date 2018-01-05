/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_addword1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:07:53 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 04:07:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*add_squarebreak(t_new *new)
{
	t_new		*s;
	char		*w;
	char		*tmp;

	tmp = NULL;
	w = NULL;
	s = new;
	while (s != NULL)
	{
		tmp = ft_strdup(s->str);
		ft_strdel(&(s->str));
		w = creat_bracket(-42);
		s->str = ft_strjoin(tmp, w);
		ft_strdel(&tmp);
		ft_strdel(&w);
		s = s->next;
	}
	return (new);
}
