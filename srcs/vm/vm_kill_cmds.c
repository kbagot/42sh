/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_kill_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgascoin <tgascoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:48:27 by tgascoin          #+#    #+#             */
/*   Updated: 2017/11/09 15:22:00 by tgascoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_kill_cmds(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->pid)
			kill(cmd->pid, SIGINT);
		cmd = cmd->next;
	}
}
