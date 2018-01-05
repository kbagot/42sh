/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_accolade2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:39:24 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 03:39:27 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

t_new	*make_pointpointdup(char *str)
{
	t_new		*izi;
	int			c;
	char		*w;

	w = NULL;
	c = str[0];
	while (c <= str[3])
	{
		w = creat_bracket(c);
		izi = add_dupaccolade(izi, w);
		ft_strdel(&w);
		c++;
	}
	return (izi);
}

t_new	*make_commadup(char **split)
{
	t_new		*izi;
	int			i;

	i = 0;
	izi = NULL;
	while (split && split[i])
	{
		izi = add_dupaccolade(izi, split[i]);
		i++;
	}
	return (izi);
}
