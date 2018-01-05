/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_tools_match1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:11:36 by nbeny             #+#    #+#             */
/*   Updated: 2017/11/19 02:11:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		ft_ispunct(int c)
{
	if (c == '[' || c == '!' || c == '"' || c == '#' || c == '$' ||\
		c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' ||\
		c == '*' || c == '+' || c == ',' || c == '-' || c == '.' ||\
		c == '/' || c == ':' || c == ';' || c == '<' || c == '=' ||\
		c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' ||\
		c == ']' || c == '^' || c == '_' || c == '`' || c == '{' ||\
		c == '|' || c == '}' || c == '~' || c == ']')
		return (1);
	return (0);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' ||\
		c == '\v' || c == '\f')
		return (1);
	return (0);
}

int		ft_isword(int c)
{
	if (!ft_islower(c) || !ft_isupper(c) || !ft_isdigit(c))
		return (1);
	return (0);
}

int		ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_isxdigit(int c)
{
	(void)c;
	return (0);
}
