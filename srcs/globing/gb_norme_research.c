/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_norme_research.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:37:34 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:39:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

void	go_to_zoom_research(t_zoom *z)
{
	z->i = 0;
	while (z->split && z->split[z->i])
	{
		if (z->g == NULL)
			z->g = init_glob(z->env);
		z->g->home = gb_get_env(z->env);
		if (check_isglob(z->split[z->i]))
		{
			z->g = zoom_research(z->g, z->split[z->i]);
			z->s = z->g;
			while (z->s->slash)
				z->s = z->s->slash;
			if (z->s->resforever)
				z->res = join_list(z->res, z->s->resforever);
			else
				z->res = add_path(z->res, z->split[z->i]);
		}
		else
			z->res = add_path(z->res, z->split[z->i]);
		free_glob_slash(z->g);
		z->g = NULL;
		z->i++;
	}
}

void	go_to_acc(t_zoom *z)
{
	if (check_is_acc(z->cmd))
	{
		z->split = ft_split_acc(z->cmd, 1);
		while (check_res(z->split))
			z->split = ft_split_acc_tab(z->split);
		go_to_zoom_research(z);
		ft_free_array(z->split);
	}
	else
	{
		go_to_zoom(z);
	}
}

void	init_z(t_zoom *z, char *cmd, char **env)
{
	z->split = NULL;
	z->i = 0;
	z->j = 0;
	z->g = NULL;
	z->res = NULL;
	z->cmd = cmd;
	z->env = env;
}

void	go_to_zoom(t_zoom *z)
{
	z->g->home = gb_get_env(z->env);
	z->g = zoom_research(z->g, z->cmd);
	z->s = z->g;
	while (z->s->slash)
		z->s = z->s->slash;
	if (z->s->resforever)
		z->res = join_list(z->res, z->s->resforever);
	else
		z->res = add_path(z->res, z->cmd);
	free_glob_slash(z->g);
	z->g = NULL;
}
