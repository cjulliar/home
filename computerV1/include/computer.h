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

typedef struct	s_values
{
	double		a;
	double		b;
	double		c;
}				t_values;

int				main(int ac, char **ag);
int				parseur(char *str, t_values *v);

#endif
