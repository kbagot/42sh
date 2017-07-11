/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:55:56 by acorbeau          #+#    #+#             */
/*   Updated: 2017/06/16 14:56:05 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ast_inright(t_ast **root, t_ast *elem)
{
	t_ast *tmp;

	if (!*root)
	{
		*root = elem;
		return ;
	}
	tmp = *root;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = elem;
}

void	ast_inleft(t_ast **root, t_ast *elem)
{
	t_ast *tmp;

	if (!*root)
		*root = elem;
	tmp = *root;
	while (tmp->left)
		tmp = tmp->left;
	tmp->left = elem;
}
