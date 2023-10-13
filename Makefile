NAME					=	server
CLIENT					=	client
CC						=	cc
INC						=	inc/
CFLAGS					=	-Wall -Werror -Wextra -I $(INC)

FT_PRINTF_DIR			=	$(SRCS)ft_printf/
FT_PRINTF				=	$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))
FT_PRINTF_OBJS			=	$(FT_PRINTF_FILES:%.c=%.o)
FT_PRINTF_FILES			=	conv_funct_char.c conv_funct_num.c ft_printf.c \
							libft_utils.c

SERV_SRCS				=	$(addprefix $(SRCS_DIR), $(SERV_SRCS_FILES))
SERV_OBJS				=	$(addprefix $(OBJS_DIR), $(SERV_OBJS_FILES))
SERV_OBJS_FILES			=	$(SERV_SRCS_FILES:%.c=%.o)
SERV_SRCS_FILES			=	server.c

CLIENT_SRCS				=	$(addprefix $(SRCS_DIR), $(CLIENT_SRCS_FILES))
CLIENT_OBJS				=	$(addprefix $(OBJS_DIR), $(CLIENT_OBJS_FILES))
CLIENT_OBJS_FILES		=	$(CLIENT_SRCS_FILES:%.c=%.o)
CLIENT_SRCS_FILES		=	client.c

SRCS_DIR				=	srcs/
OBJS_DIR				=	objs/

all:	$(NAME) $(CLIENT)

$(NAME): $(SERV_OBJS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) $(SERV_OBJS) -o $(NAME)

$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF_OJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.SILENT: all $(NAME) $(CLIENT) $(SERV_OBJS) $(CLIENT_OBJS) re clean fclean
.PHONY: all bonus clean fclean re
