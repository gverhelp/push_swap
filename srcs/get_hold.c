/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:58:00 by gverhelp          #+#    #+#             */
/*   Updated: 2021/03/08 18:00:48 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_between_numbers(t_stack *ts)
{
    int pos;
    int count;
    t_stack *stack;

    pos = 0;
    count = 0;
    stack = ts->bstack;
    while (stack && stack->next)
    {
        if (ts->astack->number > stack->number && ts->astack->number < stack->next->number)
            pos = count;
        stack = stack->next;
        count++;
    }
//    printf("OK3\n");
    ft_r_or_rr(ts, pos, 2);
    ft_print_op(ts, "pb");
    return (0);
}

int ft_check_stackb(t_stack *ts)
{
    if (!ts->bstack)
        ft_print_op(ts, "pb");
    if (ts->astack->number < ft_get_lower_number(ts->bstack))
    {
//        printf("OK1\n");
        ft_r_or_rr(ts, ft_get_pos_lower_number(ts->bstack), 2);
        ft_print_op(ts, "pb");
    }
    if (ts->astack->number > ft_get_higher_number(ts->bstack))
    {
//        printf("OK2\n");
        ft_r_or_rr(ts, ft_get_pos_higher_number(ts->bstack), 2);
        ft_print_op(ts, "pb");
    }
//    else
//        ft_between_numbers(ts);
    return (0);
}

int ft_compare_hold(t_stack *ts)
{
    int a;
    int lena;
    int holdsecond;
    int countsec;

    a = 0;
    lena = ts->lena;
    countsec = 0;
    holdsecond = ts->holdsecond;
//    printf("holdfirst : %d\n", ts->holdfirst);
//    printf("holdsecond : %d\n", ts->holdsecond);
    while (a < ts->holdfirst)
        a++;
    while (lena > holdsecond)
    {
        countsec++;
        lena--;
    }
    if (a > countsec)
    {
//        printf("holdsecond\n");
//        printf("holdsecond : %d\n", ts->holdsecond);
        ft_r_or_rr(ts, ts->holdsecond, 1);
    }
    else
    {
//        printf("holdfirst\n");
        ft_r_or_rr(ts, ts->holdfirst, 1);
    }
    ft_check_stackb(ts);
    return (0);
}

int ft_get_hold_second(t_stack *ts, int start, int end)
{
    int len;
    int tmp;
    int *stackintab;

    len = ts->lena - 1;
    tmp = start;
    if (!(stackintab = ft_get_mystack_in_tab(ts->astack)))
        return (-1);
    while (len >= 0)
    {
//        printf("stackintab[len] S : %d\n", stackintab[len]);
        tmp = start;
        while (tmp <= end)
        {
            if (stackintab[len] == ts->sortedstack[tmp])
            {
//                printf("stackintab[len] S : %d\n", stackintab[len]);
                ts->holdsecond = len + 1;
//                printf("holdsecond 2 : %d\n", ts->holdsecond);
                free(stackintab);
                return (0);
            }
            tmp++;
        }
        len--;
    }
//    ts->holdsecond = -1;
    free(stackintab);
    return (-1);
}

int ft_get_hold_first(t_stack *ts, int start, int end)
{
    int     pos;
    int     tmp;
    t_stack *stack;

    pos = 0;
    stack = ts->astack;
    tmp = start;
    while (stack)
    {
        tmp = start;
        while (tmp <= end)
        {
//            printf("stack->number : %d\n", stack->number);
            if (stack->number == ts->sortedstack[tmp])
            {
//                printf("stack->number f : %d\n", stack->number);
                ts->holdfirst = pos + 1;
                return (0);
            }
            tmp++;
        }
        stack = stack->next;
        pos++;
    }
//    ts->holdfirst = -1;
//    printf("ts->holdfirst f : %d\n", ts->holdfirst);
    return (-1);
}

int ft_first_or_second(t_stack *ts, int start, int end)
{
    int tmp;

    tmp = start;
    while (tmp <= end)
    {
        ft_get_hold_first(ts, start, end);
        ft_get_hold_second(ts, start, end);
        ft_compare_hold(ts);
        tmp++;
    }
    return (0);
}

/*
int ft_get_hold(t_stack *ts, int stacknumber, int start, int end)
{
    while (start < end)
    {
        if (stacknumber == ts->sortedstack[start])
            return (0);
        start++;
    }
    return (-1);
}
*/

/*
int ft_first_or_second(t_stack *ts, int start, int end)
{
    int *stackintab;
    int len;
    t_stack *stack;

    len = 0;
    stack = ts->astack;
    while (stack)
    {
        if (ft_get_hold(ts, stack->number, start, end) != -1)
        {
            ts->holdfirst = len;
            break ;
        }
        stack = stack->next;
        len++;
    }
    if (!(stackintab = ft_get_mystack_in_tab(ts->astack)))
        return (-1);
    len = ts->lena;
    while (len)
    {
//        printf("stacknumber : %d\n", stackintab[len]);
        if (ft_get_hold(ts, stackintab[len], start, end) != -1)
        {
            ts->holdsecond = len;
            break ;
        }
        len--;
    }
    free(stackintab);
    ft_compare_hold(ts);
    return (0);
}

*/