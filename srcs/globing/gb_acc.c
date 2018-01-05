/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_acc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:44:11 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:33:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

char			**ft_split_acc_tab(char **tab)
{
	int		i;
	char	**res;
	char	**tmp;

	tmp = NULL;
	res = NULL;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tmp = ft_split_acc(tab[i], 0);
		res = ft_fusion_array(res, tmp);
		tmp = NULL;
		i++;
	}
	ft_free_array(tmp);
	ft_free_array(tab);
	return (res);
}

static void		init_ut(t_utils *ut, char *str)
{
	ut->j = 0;
	ut->i = 0;
	ut->tmp = NULL;
	ut->start = NULL;
	ut->res = NULL;
	ut->str = str;
	ut->tmp2 = ft_strdup("\0");
	ut->res2 = NULL;
}

static void		ft_create_res(t_utils *ut)
{
	if (ut->res == NULL)
	{
		ut->res = ft_strsplit(ut->tmp, ',');
		ft_strdel(&ut->tmp);
		ut->tmp = NULL;
		ut->res = ft_join_tab(ut->res, ut->start);
		ft_strdel(&(ut->start));
		if (ut->str[ut->i] != '\0')
		{
			ut->j = ut->i + 1;
			while (ut->str[ut->i])
				ut->i++;
			ut->tmp = ft_my_str_sub(ut->str, ut->j, ut->i);
			ut->res = ft_join_tab_end(ut->res, ut->tmp);
		}
	}
}

static void		ft_norme_acc_pl(t_utils *ut, int check)
{
	ft_strdel(&(ut->tmp));
	ft_strdel(&(ut->tmp2));
	ut->tmp2 = NULL;
	ut->tmp = NULL;
	ut->res = NULL;
	(void)check;
}

char			**ft_split_acc(char *str, int check)
{
	t_utils	ut;
	char	**res;

	init_ut(&ut, str);
	while (str && str[ut.i] != '\0')
	{
		if (str[ut.i] == '{')
		{
			ut.tmp = ft_my_str_sub(ut.str, 0, ut.i);
			ut.j = ut.i + 1;
			if (ut.tmp)
				ut.start = ft_strjoin(ut.tmp2, ut.tmp);
			ft_norme_acc_pl(&ut, check);
			while (str[ut.i] != '\0' && str[ut.i] != '}')
				ut.i++;
			ut.tmp = ft_my_str_sub(str, ut.j, ut.i);
			ft_create_res(&ut);
			ft_strdel(&(ut.tmp));
		}
		if (str[ut.i] == '\0')
			break ;
		ut.i++;
	}
	res = ut.res;
	return (res);
}
