/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgascoin <tgascoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:12:35 by tgascoin          #+#    #+#             */
/*   Updated: 2018/01/05 07:10:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "globing.h"
#include <fcntl.h>

static char	**get_avs(t_list *av)
{
	t_list	*tmp;
	char	**ret;
	int		len;

	len = 1;
	tmp = av;
	while (tmp && ++len)
		tmp = tmp->next;
	if (!(ret = malloc(sizeof(char *) * len)))
		return (NULL);
	ret[--len] = NULL;
	len = 0;
	tmp = av;
	while (tmp)
	{
		ret[len++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	return (ret);
}

static void	ast_freecmdavs(char **lst)
{
	char **fptr;

	fptr = lst;
	while (*fptr)
	{
		free(*fptr);
		fptr++;
	}
	if (lst)
		free(lst);
}

t_cmd		*ast_newcmd(t_list *av, t_ast *redir, t_envent *t)
{
	t_cmd	*new;
	char	**tt;
	char	**ff;

	(void)t;
	ff = NULL;
	tt = NULL;
	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	tt = get_avs(av);
	ast_lstfree(av);
	new->av = tt;
	new->next = NULL;
	new->sin = 0;
	new->sout = 0;
	new->pid = 0;
	new->flags = 0;
	new->redir = redir;
	return (new);
}

void		ast_freecmd(t_cmd *cmd)
{
	t_cmd	*fptr;
	t_ast	*fast;

	while (cmd)
	{
		fptr = cmd;
		cmd = cmd->next;
		ast_freecmdavs(fptr->av);
		fast = fptr->redir;
		ast_freeast(&fast);
		free(fptr);
	}
}
