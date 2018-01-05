/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_matchrep1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 04:22:38 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 04:22:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"
#include <sys/types.h>
#include <sys/dir.h>

t_new	*match_rep_end(t_glob *g, char *path, t_new *s, t_new *new_path)
{
	DIR					*dir;
	struct dirent		*d;
	char				*str;

	str = NULL;
	dir = opendir(path);
	while ((d = readdir(dir)) != NULL)
	{
		str = tri_join(g->slashzero, path, d->d_name);
		if (nmatch(d->d_name, s->str, g->sb) != 0)
		{
			if (!access(str, R_OK) && d->d_type == 4 &&\
				(d->d_name[0] != '.' || !ft_strncmp(s->str, "..\0", 3) ||\
				!ft_strncmp(s->str, ".\0", 2)))
			{
				ft_strdel(&str);
				str = tri_join(g->slashzero, path, d->d_name);
				new_path = add_path(new_path, str);
			}
		}
		ft_strdel(&str);
	}
	closedir(dir);
	return (new_path);
}

char	*found_path_zero(char *path, char *dname)
{
	char		*new_path;
	char		*found;
	char		*tmp;
	int			len[2];

	new_path = NULL;
	tmp = getcwd(NULL, 1024);
	len[0] = ft_strlen(tmp);
	len[1] = ft_strlen(path);
	ft_strdel(&tmp);
	if (len[0] <= len[1] && path[len[0]] != '\0' && path[len[0] + 1] != '\0')
	{
		tmp = ft_my_str_sub(path, (len[0] + 1), len[1]);
		found = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		new_path = ft_strjoin(found, dname);
		ft_strdel(&dname);
		ft_strdel(&found);
	}
	else
	{
		new_path = ft_strdup(dname);
		ft_strdel(&dname);
	}
	return (new_path);
}
