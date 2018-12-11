/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:44:23 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/05 12:18:06 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <SDL2/SDL.h>
# include <math.h>
# include <fcntl.h>

# define HBLOC 100

typedef struct			s_fenetre
{
	int					hauteur;
	int					largeur;
}						t_fenetre;

typedef struct			s_wolf3d
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	SDL_Event			event;
	SDL_Texture			*texture;
	SDL_Renderer		*renderer;
	int					**map;
	int					ymamax;
	int					xmamax;
	int					xmapmax;
	int					ymapmax;
	int					color;
	double				xposjoueur;
	double				yposjoueur;
	double				orientation;
	double				distancehoriz;
	double				distanceverti;
	double				truedistance;
	double				ax;
	double				ay;
	double				bx;
	double				by;
	int					level;
	int					tunel;
	int					tunel10;
	int					tcheat;
	int					hardcord;
	t_fenetre			*f;
	const Uint8			*keys;
}						t_wolf3d;

int						main(int argc, char **atgv);
void					ft_fenetre(t_wolf3d *w);
int						ft_initialisation(t_wolf3d *w);
void					ft_loop_event(t_wolf3d *w);
int						ft_loop_suite(t_wolf3d *w);
void					ft_put_pixel(int x, int y, int color, t_wolf3d *w);
void					ft_premieraffichage(t_wolf3d *w);
void					ft_affichermur(int x, int color, t_wolf3d *w);
void					ft_croisehoriz(t_wolf3d *w, double orientation);
void					ft_croiseverti(t_wolf3d *w, double orientation);
double					ft_divinf(int val, int div);
double					ft_radian(double degre);
double					ft_degre(double radian);
int						ft_lectmap(t_wolf3d *w);
int						ft_lectprincipal(t_wolf3d *w);
int						ft_mouvements(t_wolf3d *w, int sens);
void					ft_laby1(t_wolf3d *w);
void					ft_laby2(t_wolf3d *w);
void					ft_laby3(t_wolf3d *w);
void					ft_laby4(t_wolf3d *w);
void					ft_mhori(int x, int y, int xmax, t_wolf3d *w);
void					ft_mverti(int x, int y, int ymax, t_wolf3d *w);
int						ft_palette(t_wolf3d *w, int orientation);

#endif
