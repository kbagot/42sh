/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:12:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:14:16 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	ft_listsize(t_envent *e)
{
	t_envent	*s;
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

char		**env_to_tab_envglob(t_envent *e)
{
	char		**tstr;
	char		*stock;
	t_envent	*s;
	int			i;

	s = e;
	if (e == NULL)
		return (NULL);
	i = ft_listsize(e);
	if (!(tstr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		stock = ft_strjoin(s->name, "=");
		tstr[i] = ft_strjoin(stock, s->value);
		ft_strdel(&stock);
		i++;
		s = s->next;
	}
	tstr[i] = NULL;
	return (tstr);
}
