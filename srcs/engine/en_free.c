/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:29:18 by acorbeau          #+#    #+#             */
/*   Updated: 2017/06/16 15:29:21 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		en_free(t_engine **en)
{
	if (!*en)
		return ;
	if ((*en)->vm)
		vm_free(&(*en)->vm);
	if ((*en)->buffer)
		free((*en)->buffer);
	free(*en);
	*en = NULL;
}
