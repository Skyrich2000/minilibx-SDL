#ifndef MLX_INT_H
# define MLX_INT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# define OK	1
# define ERROR 0

# define MLX_MAX_EVENT 40
# define MLX_MAX_WINDOW 20

# define PREFIX "minilibx-SDL"

# define GUARD(test) \
    if ((test)) {}

# define RETURN(string) \
	fprintf(stderr, "[%s] %s \n", PREFIX, (string)); \
	return (ERROR);

# define THROW(string) \
	mlx_error = (string); \
    return (ERROR);

typedef struct s_event
{
	int		mask;
	int		(*hook)();
	void	*param;
}	t_event;

typedef struct s_win_list
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	int					id;
	t_event				hooks[MLX_MAX_EVENT];
	struct s_win_list	*next;
}	t_win_list;

typedef struct s_img
{
	SDL_Surface		*surface;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	void			*data;
}	t_img;

typedef struct s_xvar
{
	t_win_list		*win_id[MLX_MAX_WINDOW];
	t_win_list		*win_list;
	int				win_count;
	int				(*loop_hook)();
	void			*loop_param;
}	t_xvar;

void	mlx_free(t_xvar *mlx);

void    mlx_key_press_handler(t_xvar *mlx, int win_id, int keycode);
void    mlx_key_release_handler(t_xvar *mlx, int win_id, int keycode);

#endif