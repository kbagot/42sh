/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:35:32 by nbeny             #+#    #+#             */
/*   Updated: 2017/12/18 12:36:37 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globing.h"

char	*gb_get_env(char **env)
{
	size_t	i;
	char	*home;

	home = NULL;
	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "HOME=", 5) && ft_strlen(env[i]) > 5)
		{
			home = ft_strdup(&env[i][5]);
			return (home);
		}
		i++;
	}
	return (NULL);
}
