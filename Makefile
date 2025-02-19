NAME	:= minirt
LIBFT_DIR	:= libft
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIB_URL := https://github.com/codam-coding-college/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR)
LIBS	:= $(LIBMLX)/build/libmlx42.a

OBJ_DIR			:= obj
SRCS	:= src/main.c src/error.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS	:= ${SRCS:.c=.o}
LIBFT			:= -L$(LIBFT_DIR) -lft

all: libmlx libft $(NAME)

libft:
	@echo "building libft"
	@make -C $(LIBFT_DIR) 

libmlx: $(LIBS)

$(LIBS): $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBMLX):
	@git clone $(LIB_URL) $(LIBMLX)
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -ldl -lglfw -pthread -lm -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)
	@make -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
