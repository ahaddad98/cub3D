/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:24:52 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 17:31:08 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include "./libft/libft.h"
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFFER_SIZE 32

typedef	struct			s_pos
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	int					mapx;
	int					mapy;
	double				camerax;
	double				olddirx;
	double				oldplanex;
}						t_pos;

typedef struct			s_pars
{
	int					screenw;
	int					screenh;
	char				**line_r;
	char				**line_no;
	char				*path_no;
	char				**line_so;
	char				**line_we;
	char				**line_ea;
	char				**line_s;
	char				**line_c;
	char				**line_f;
	char				*path_so;
	char				*path_we;
	char				*path_ea;
	char				*path_s;
	int					r_f;
	int					g_f;
	int					b_f;
	int					r_c;
	int					g_c;
	int					b_c;
	int					fl_color;
	int					cl_color;
	char				**rgb;
	int					i;
	int					nbr_col;
	int					nbr_line;
	char				**tab;
	int					check_m;
	char				c;
	int					v_m;
	char				*p;
}						t_pars;

typedef	struct			s_sprite
{
	int					spriteorder[100];
	double				sprited[2560];
	double				spx[100];
	double				spy[100];
	double				zbuff[2560];
	int					color;
	double				sprx;
	double				spry;
	double				invdet;
	double				transformx;
	double				transformy;
	int					sprscreenx;
	int					sprheight;
	int					sprwidth;
	int					drstarty;
	int					drstartx;
	int					drendy;
	int					drendx;
	int					texx;
	int					texy;
	int					d;
	int					stripe;
	int					y;
	int					i;
	int					numsprite;
}						t_sprite;

typedef	struct			s_tex
{
	int					wi[10];
	int					hi[10];
	int					*texture;
	int					bpp;
	int					s_line;
	int					endian;
	int					texx;
	int					texy;
	double				texpos;
	double				wallx;
	void				*imgw[4];
	int					*data[4];
	void				*imgs;
	int					*datas;
}						t_tex;

typedef	struct			s_dir
{
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltasistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	double				step;
	int					side;
}						t_dir;

typedef	struct			s_draw
{
	int					lineheight;
	int					drawstart;
	int					drawend;
	unsigned int		color;
	int					x;
	int					y;
}						t_draw;

typedef	struct			s_cub
{
	t_sprite			sp;
	t_pos				pos;
	t_tex				tex;
	t_dir				dir;
	t_draw				dr;
	t_pars				pars;
	int					fd;
	int					lenstring;
	int					screenwed;
	int					screenhei;
	int					number_sprite;
	int					number_path;
	int					map_height;
	void				*win_ptr;
	void				*mlx_ptr;
	void				*img_ptr;
	int					*data;
	int					key_l;
	int					key_r;
	int					key_left;
	int					key_right;
	int					s_bmp;
}						t_cub;

int						ft_error_alert(int err);
void					calc_direction(t_cub *cub);
void					calc_sidedist(t_cub *cub);
void					calc_side(t_cub *cub);
void					pos_draw(t_cub *cub);
void					ft_set_textures(t_cub *cub);
void					other_sides(t_cub *cub);
void					ceil_color(t_cub *cub);
void					floor_color(t_cub *cub);
void					ft_walls_casting(t_cub *cub);
void					draw_game(t_cub *cub);
void					move_keys(int key, t_cub *cub);
int						deal_key(int key, t_cub *cub);
void					ft_upload_textures(t_cub *cub);
void					init(t_cub *cub);
void					ft_init_sprite_vars(t_cub *cub);
void					ft_swap_s_distance(int i, int j, t_cub *cub);
void					ft_swap_s_order(int i, int j, t_cub *cub);
void					ft_sort_sprites(t_cub *cub, int amount);
void					ft_put_sprites_1_(t_cub *cub);
void					ft_put_sprites_2_(t_cub *cub);
int						key_exit();
char					*ft_substr(const char *s,
		unsigned int start, size_t len);
char					*ft_strjoin_free(char *s1, char const *s2);
int						get_next_line(int fd, char **line);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					**ft_split(char const *s, char c);
int						ft_atoi(char *str);
void					pars_resol(char *line, t_cub *cub);
void					pars_text_no(char *line, t_cub *cub);
void					pars_text_so(char *line, t_cub *cub);
void					pars_text_we(char *line, t_cub *cub);
void					pars_text_ea(char *line, t_cub *cub);
void					pars_text_s(char *line, t_cub *cub);
void					pars_fl(char *line, t_cub *cub);
void					pars_cl(char *line, t_cub *cub);
int						count_line(char **tab);
int						skip_spaces(char *line, t_cub *cub);
void					pars(char *line, t_cub *cub);
int						check_extension(char *line);
void					get_map(t_cub *cub);
void					free_tab(char *tab);
int						check_err(int i, char *line);
void					check_map(t_cub *cub);
char					*ft_strtrim(char const *s1, char const *set);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					map_trans_check(t_cub *cub);
void					check_pos_tex(t_cub *cub);
int						create_bmp(t_cub *rt);
void					ft_free2d(char **ptr);
void					ft_stringdel(char **string);
void					*ft_memset(void *s, int c, size_t len);
void					ft_bzero(void *s, size_t n);
int						ft_strchr1(const char *str, char c);
void					ft_putstr1(char *s);
#endif
