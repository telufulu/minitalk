NAME				=	libftprintf.a
CC					=	cc
INC					=	../
CFLAGS				=	-Wall -Werror -Wextra -I $(INC)
SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_FILES			=	ft_printf.c libft_utils.c conv_funct.c
SRCS_DIR			=	srcs/
#SRCS				=	ft_printf.c libft_utils.c conv_funct.c
OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES			=	$(SRCS_FILES:%.c=%.o)
#OBJS_FILES			=	$(SRCS:%.c=%.o)
OBJS_DIR			=	objs/

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
#$(OBJS_DIR)%.o: %.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	find . -name "a.out" -delete
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJS) re clean fclean
.PHONY: all clean fclean re bonus 
