/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_resultsb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:27:17 by nbeny             #+#    #+#             */
/*   Updated: 2018/01/04 15:27:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

int		check_shoot_more(int c, t_new *sb)
{
	int		ret;
	char	ct;

	ret = 0;
	if (ft_isprint(sb->str[sb->i]) && sb->str[sb->i + 1] &&\
		sb->str[sb->i + 1] == '-' && sb->str[sb->i + 2] &&\
		ft_isprint(sb->str[sb->i + 2]))
	{
		ct = sb->str[sb->i];
		while (ct < sb->str[sb->i + 2])
			if (c == ct)
				return (1);
			else
				ct++;
	}
	if (sb->str[sb->i] == '[' && sb->str[sb->i + 1] != '\0')
		if (check_name_pos(&(sb->str)[sb->i]))
			ret = sb_classmatch(c, sb);
		else
			ret = sb__match_no(c, sb);
	else
		ret = sb__match(c, sb);
	return (ret);
}

int		check_shoot_exclam(int c, t_new *sb)
{
	int		ret;
	char	ct;

	ret = 0;
	if (ft_isprint(sb->str[sb->i]) && sb->str[sb->i + 1] &&\
		sb->str[sb->i + 1] == '-' && sb->str[sb->i + 2] &&\
		ft_isprint(sb->str[sb->i + 2]))
	{
		ct = sb->str[sb->i];
		while (ct < sb->str[sb->i + 2])
			if (c == ct)
				return (1);
			else
				ct++;
	}
	if (sb->str[sb->i] == '[' && sb->str[sb->i + 1] != '\0')
		if (check_name_pos(&(sb->str)[sb->i]))
			ret = sb_classmatch(c, sb);
		else
			ret = sb__match_no(c, sb);
	else
		ret = sb__match(c, sb);
	return (ret);
}
