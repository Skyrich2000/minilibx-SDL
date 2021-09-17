#ifndef MLX_INT_H
# define MLX_INT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# define MLX_MAX_EVENT 33

typedef struct s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
}	t_event_list;

typedef struct s_window_list
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	int					window_id;
	struct s_win_list	*next;
	t_event_list		hooks[MLX_MAX_EVENT];
}	t_window_list;

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
	t_window_list	*win_list;
	int				(*loop_hook)();
	void			*loop_param;
	int 			end_loop;
}	t_xvar;


#endif