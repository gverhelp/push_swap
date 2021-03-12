/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_struct(t_stack *ts)
{
	ts->astack = NULL;
	ts->bstack = NULL;
	ts->next = NULL;
	ts->number = 0;
	ts->line = NULL;
}

void	ft_exit(t_stack *ts, char *str, int fd)
{
	ft_putendl_fd(str, fd);
	free(ts->line);
	ft_delete_all_stack(&ts->astack);
	ft_delete_all_stack(&ts->bstack);
	exit(0);
}