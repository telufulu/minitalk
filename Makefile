NAME					=	server
CLIENT					=	client
CC						=	cc
INC						=	inc/
CFLAGS					=	-Wall -Werror -Wextra -I $(INC)

SERV_SRCS				=	$(addprefix $(SRCS_DIR), $(SERV_SRCS_FILES))
SERV_OBJS				=	$(addprefix $(OBJS_DIR), $(SERV_OBJS_FILES))
SERV_OBJS_FILES			=	$(SERV_SRCS_FILES:%.c=%.o)
SERV_SRCS_FILES			=	server.c utils.c

SERV_BONUS_SRCS			=	$(addprefix $(SRCS_DIR), $(SERV_SRCS_BONUS_FILES))
SERV_BONUS_OBJS			=	$(addprefix $(OBJS_DIR), $(SERV_OBJS_BONUS_FILES))
SERV_OBJS_BONUS_FILES	=	$(SERV_SRCS_BONUS_FILES:%.c=%.o)
SERV_SRCS_BONUS_FILES	=	server_bonus.c utils_bonus.c

CLIENT_SRCS				=	$(addprefix $(SRCS_DIR), $(CLIENT_SRCS_FILES))
CLIENT_OBJS				=	$(addprefix $(OBJS_DIR), $(CLIENT_OBJS_FILES))
CLIENT_OBJS_FILES		=	$(CLIENT_SRCS_FILES:%.c=%.o)
CLIENT_SRCS_FILES		=	client.c utils.c

CLIENT_BONUS_SRCS		=	$(addprefix $(SRCS_DIR), $(CLIENT_SRCS_BONUS_FILES))
CLIENT_BONUS_OBJS		=	$(addprefix $(OBJS_DIR), $(CLIENT_OBJS_BONUS_FILES))
CLIENT_OBJS_BONUS_FILES	=	$(CLIENT_SRCS_BONUS_FILES:%.c=%.o)
CLIENT_SRCS_BONUS_FILES	=	client_bonus.c utils_bonus.c

SRCS_DIR				=	srcs/
OBJS_DIR				=	objs/

all:	$(NAME) $(CLIENT)

$(NAME): $(SERV_OBJS)
	$(CC) $(CFLAGS) $(SERV_OBJS) -o $(NAME)
	
$(CLIENT):	$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

bonus:	name_bonus client_bonus

name_bonus: $(SERV_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERV_BONUS_OBJS) -o $(NAME)
	
client_bonus:	$(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT)

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

.SILENT: bonus name_bonus client_bonus all $(NAME) $(CLIENT) $(SERV_OBJS) \
	$(CLIENT_OBJS) $(SERV_BONUS_OBJS) $(CLIENT_BONUS_OBJS) re clean fclean
.PHONY: all bonus clean fclean re
