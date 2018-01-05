/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_matchrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:10:47 by nbeny             #+#    #+#             */
/*   Updated: 2018/01/05 10:20:35 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

char	*tri_join(int zero, char *path, char *str)
{
	char	*join;
	char	*tmp;

	(void)zero;
	if (ft_strlen(path) == 1 && path[0] == '/')
		tmp = ft_strdup(path);
	else
		tmp = ft_strjoin(path, "/");
	join = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	return (join);
}

t_new	*match_rep(t_glob *g, char *path)
{
	t_new				*new_path;
	t_new				*s;
	char				*str;

	str = NULL;
	s = g->new;
	new_path = NULL;
	while (s != NULL)
	{
		new_path = match_rep_end(g, path, s, new_path);
		s = s->next;
	}
	return (new_path);
}

char	*found_path(int zero, char *path, char *dname)
{
	char		*new_path;
	char		*tmp;

	new_path = NULL;
	if (zero == 0)
		new_path = found_path_zero(path, dname);
	else
	{
		if (ft_strcmp(path, "/"))
		{
			tmp = ft_strjoin(path, "/");
			new_path = ft_strjoin(tmp, dname);
			ft_strdel(&tmp);
			ft_strdel(&dname);
		}
		else
		{
			new_path = ft_strjoin(path, dname);
			ft_strdel(&dname);
		}
	}
	return (new_path);
}

t_glob	*match_file(t_glob *g, t_new *st_path)
{
	t_new				*s;
	struct dirent		*d;
	DIR					*dir;
	char				*tmp;

	tmp = NULL;
	s = g->new;
	while (s != NULL)
	{
		dir = opendir(st_path->str);
		while ((d = readdir(dir)) != NULL)
			if (nmatch(d->d_name, s->str, g->sb) != 0)
				if (d->d_name[0] != '.' || !ft_strncmp(s->str, "..\0", 3 ||\
					!ft_strncmp(s->str, ".\0", 2)))
				{
					s->i = 1;
					tmp = found_path(g->slashzero,\
								st_path->str, ft_strdup(d->d_name));
					g->resforever = add_path(g->resforever, tmp);
					ft_strdel(&tmp);
				}
		closedir(dir);
		s = s->next;
	}
	return (g);
}
