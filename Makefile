NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
OS				= $(shell uname)
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER  	    = -lft -L $(LIBFT_DIR)

INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h \

SRCS_DIR		= srcs/
SRC_FILES		= main.c \
				  utils.c \
				  hook_event.c \
				  rendering.c \
			 	  fractal.c \
				  foundation.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))

OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

ifeq ($(OS), Linux)
	MLX_DIR			= mlx_linux
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
else
	MLX_DIR			= mlx_macos
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
endif


all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@$(MAKE) $(LIBFT_DIR)

$(MLX) :
	@$(MAKE) $(MLX_DIR)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
