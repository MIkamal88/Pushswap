/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:22:42 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/12 13:42:08 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdlib.h>

static void free_data(t_data *data)
{
  free(data->merged_data);
  free(data->arr);
  free(data);
}

static void free_stack(t_stack **stack)
{
  t_stack *temp;

  if (!stack || !(*stack))
    return ;
  while (*stack)
  {
    temp = (*stack)->next;
    free(*stack);
    *stack = temp;
  }
  *stack = NULL;
}

void  free_all(t_pushswap *ps)
{
  free_data(ps->data);
  free_stack(&ps->stack_a);
  free_stack(&ps->stack_b);
  free(ps);
}

void  exit_err(char *err)
{
  perror(err);
  exit(EXIT_FAILURE);
}

void	err_hndl(char *err, t_pushswap *ps)
{
  if (ps->stack_a != NULL)
    free_stack(&ps->stack_a);
  if (ps->stack_b != NULL)
    free_stack(&ps->stack_b);
	perror(err);
	exit(EXIT_FAILURE);
}
