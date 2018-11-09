/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:21:37 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/06 09:18:44 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTER_H
# define COMPUTER_H

# include "../libft/libft.h"

typedef struct	s_values //passer ca en double
{
	int		a;
	int		b;
	int		c;
}				t_values;

int				main(int ac, char **ag);
int				parseur(char *str, t_values *v, t_values *r);
void			resolution(t_values *v, t_values *r);


#endif
