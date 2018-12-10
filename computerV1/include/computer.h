/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:21:37 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 12:19:46 by cjulliar         ###   ########.fr       */
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
int				parseur(char *str, t_values *v, t_values *r);
void			resolution(t_values *v, t_values *r);
char			*ft_nospace(char *str);
int				isolation(char *str, int i, double n, t_values *v);
void			reduced_forme(double a, double b, double c);
void			reponse(double a, double b, double c, t_values *v);
void			degre2(double a, double b, double c);
int				xalone(char *str, int i, t_values *v);
int				analyse(char *str, int i, t_values *v);

#endif
