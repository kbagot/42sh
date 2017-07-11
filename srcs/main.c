/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:36:23 by acorbeau          #+#    #+#             */
/*   Updated: 2017/06/16 16:36:26 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "term.h"

/*
** BASH +- posix
** Based on bash 4.3 --posix, debian
*/

int		get_cmd_flags(int ac, char **av)
{
	int	ret;

	ret = 0;
	while (--ac)
	{
		if (ft_strequ(av[ac], "--lex"))
			ret |= EF_PRINTLEX;
		else if (ft_strequ(av[ac], "--ast"))
			ret |= EF_PRINTAST;
	}
	return (ret);
}

int		main(int ac, char **av, char **env)
{
	t_engine	*engine;

	ft_errset("minishell");
	tc_check_sin();
	tc_listen_signals();
	engine = en_init(get_cmd_flags(ac, av), env);
	en_loop(engine);
	en_free(&engine);
	ft_putchar('\n');
}
