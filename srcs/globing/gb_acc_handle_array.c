/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_acc_handle_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidzik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:45:00 by nidzik            #+#    #+#             */
/*   Updated: 2018/01/05 11:21:11 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

char			**ft_join_tab_end(char **tab, char *end)
{
	int		i;
	char	**res;
	int		len_tab;

	len_tab = 0;
	if (!tab)
		return (NULL);
	while (tab[len_tab])
		len_tab++;
	res = NULL;
	if (!(res = (char **)malloc(sizeof(char *) * (len_tab + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strjoin(tab[i], end);
		i++;
	}
	res[i] = NULL;
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
	return (res);
}

void			ft_free_array(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

static char		**check_valid_array(char **tab1, char **tab2)
{
	if (!tab1 && tab2)
		return (tab2);
	else if (tab1 && !tab2)
		return (tab1);
	else if (!tab1 && !tab2)
		return (NULL);
	return (NULL);
}

static void		init_fus(t_fus *fu, char **tab1, char **tab2)
{
	fu->len_tab = 0;
	fu->len_tab2 = 0;
	fu->i = 0;
	while (tab1[fu->len_tab])
		fu->len_tab++;
	while (tab2[fu->len_tab2])
		fu->len_tab2++;
	fu->res = NULL;
}

char			**ft_fusion_array(char **tab1, char **tab2)
{
	t_fus	fu;
	char	**res;

	if (!tab1 || !tab2)
		return (check_valid_array(tab1, tab2));
	init_fus(&fu, tab1, tab2);
	if (!(fu.res = (char **)malloc(sizeof(char *) *\
					(fu.len_tab + fu.len_tab2 + 1))))
		return (NULL);
	while (tab1[fu.i])
	{
		fu.res[fu.i] = ft_strdup(tab1[fu.i]);
		fu.i++;
	}
	fu.len_tab = 0;
	while (tab2[fu.len_tab])
	{
		fu.res[fu.i] = ft_strdup(tab2[fu.len_tab]);
		fu.len_tab++;
		fu.i++;
	}
	fu.res[fu.i] = NULL;
	free_two_tab(tab1, tab2);
	res = fu.res;
	return (res);
}
