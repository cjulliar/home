/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:25:00 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/06 09:23:49 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **ag)
{
	t_values *v;
	t_values *r;

	if ((v = (t_values *)malloc(sizeof(t_values))) == NULL)
		return (0);
	if ((r = (t_values *)malloc(sizeof(t_values))) == NULL)
		return (0);
	v->a = 0;
	v->b = 0;
	v->c = 0;
	r->a = 0;
	r->b = 0;
	r->c = 0;
	if (ac == 1 || parseur(ag[1], v, r) == 0)
		ft_putstr("You have to note an equation.\n\nLike this: a * X ^ 2 + b * X ^ 1 + c * X ^ 1.i\nwith a, b and c numeric numbers.\n");
	
	// traitement  mathematique
	printf("%d x2 + %d x + %d = ",v->a,v->b,v->c);
	printf("%d x2 + %d x + %d\n",r->a,r->b,r->c);

	return (0);
}
