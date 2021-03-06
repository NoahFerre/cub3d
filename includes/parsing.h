/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:54:53 by nferre            #+#    #+#             */
/*   Updated: 2022/03/29 07:08:44 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "cube.h"

typedef struct s_coords
{
	int	i;
	int	j;

}	t_coords;

typedef struct s_texture_coords
{
	t_coords	no;
	t_coords	so;
	t_coords	ea;
	t_coords	we;
	t_coords	f;
	t_coords	c;

}	t_texture_coords;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	char	*path_to_north;
	t_color	north_texture;
	char	*path_to_south;
	t_color	south_texture;
	char	*path_to_east;
	t_color	east_texture;
	char	*path_to_west;
	t_color	west_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**map;
	char	**file;
	int		*int_map;
	int		x;
	int		y;
	char	player_direction;
}	t_data;

//parsing

t_data				*parse(int argc, char **argv);
char				**parse_map(char *file, int i);
char				**parse_file(char *path);
int					get_first_character_in_map(char *file, int i);
int					get_last_character_in_map(char *file, int i);

//checker

t_texture_coords	checker(char *path, t_data *data, int argc);
void				check_args(int argc);
int					check_texture(char *path, t_texture_coords *texture_coords);
void				check_map_extension(char *path);
void				check_map_existence(char *path);
void				check_characters(char *path, int i);
void				check_number_maps(char *path, int i);
void				check_walls(char *path, int i, t_data *data);
void				check_north(char **file, t_texture_coords *texture_coords);
void				check_south(char **file, t_texture_coords *texture_coords);
void				check_west(char **file, t_texture_coords *texture_coords);
void				check_east(char **file, t_texture_coords *texture_coords);
void				check_floor(char **file, t_texture_coords *texture_coords);
void				check_ceiling(char **file,
						t_texture_coords *texture_coords);
void				check_texture_existence(t_data *data);
void				check_colors(char *path, t_texture_coords texture_coords);
void				check_if_map_empty(char *path);
void				check_map(t_data *data);
void				get_textures(t_data *data);
void				get_int_map(t_data *data);

//utils

void				print_error(int i, char **file, int j);
void				print_tab(char **map);
int					get_size(char *path);
char				*get_file(char *path);
int					condition(char *file, int i);
void				init_coords(t_texture_coords *texture_coords);
void				print_color(t_color color);
void				print_int_tab(int *tab, int x, int y);

#endif