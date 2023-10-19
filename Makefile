NAME					=	server
CLIENT					=	client
CC						=	cc
INC						=	inc/
CFLAGS					=	-Wall -Werror -Wextra -I $(INC)

SERV_SRCS				=	$(addprefix $(SRCS_DIR), $(SERV_SRCS_FILES))
SERV_OBJS				=	$(addprefix $(OBJS_DIR), $(SERV_OBJS_FILES))
SERV_OBJS_FILES			=	$(SERV_SRCS_FILES:%.c=%.o)
SERV_SRCS_FILES			=	server.c utils.c

CLIENT_SRCS				=	$(addprefix $(SRCS_DIR), $(CLIENT_SRCS_FILES))
CLIENT_OBJS				=	$(addprefix $(OBJS_DIR), $(CLIENT_OBJS_FILES))
CLIENT_OBJS_FILES		=	$(CLIENT_SRCS_FILES:%.c=%.o)
CLIENT_SRCS_FILES		=	client.c utils.c

SRCS_DIR				=	srcs/
OBJS_DIR				=	objs/

FT_PRINTF				=	$(FT_PRINTF_DIR)libftprintf.a
FT_PRINTF_DIR			=	$(INC)ft_printf/

all:	$(NAME) $(CLIENT)

$(NAME): $(SERV_OBJS) $(CLIENT_OBJS)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(SERV_OBJS) $(FT_PRINTF) -o $(NAME)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF) -o $(CLIENT)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	find . -name "*.swap" -delete
	find . -name ".DS_Store" -delete

fclean: clean
	rm -f $(NAME) $(CLIENT)

re: fclean all

.SILENT: all $(NAME) $(SERV_OBJS) $(CLIENT_OBJS) re clean fclean
.PHONY: all bonus clean fclean re
