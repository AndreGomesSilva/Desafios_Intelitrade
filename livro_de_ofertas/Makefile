NAME = offer_book
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include

SRCS_DIR 	= src/
UTILS_DIR		= utils/
BOOK_DIR		= book/
ACTIONS_DIR	= actions/
NOTIFICATION_DIR = notifications/
HANDLE_FREE_DIR = handle_free/

OBJS_DIR 	= obj/

FILES = \
	main \
	$(BOOK_DIR)handle_book \
	$(ACTIONS_DIR)handle_operations $(ACTIONS_DIR)insert_property \
	$(ACTIONS_DIR)validate_property $(ACTIONS_DIR)modify_property \
	$(ACTIONS_DIR)delete_property \
	$(NOTIFICATION_DIR)handle_notifications \
	$(HANDLE_FREE_DIR)handle_free \
	$(UTILS_DIR)print_book  $(UTILS_DIR)ft_strlen \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) $(INC) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(BOOK_DIR)
	@mkdir -p $(OBJS_DIR)$(ACTIONS_DIR)
	@mkdir -p $(OBJS_DIR)$(HANDLE_FREE_DIR)
	@mkdir -p $(OBJS_DIR)$(UTILS_DIR)
	@mkdir -p $(OBJS_DIR)$(NOTIFICATION_DIR)

clean:
	$(RM) -r $(OBJS_DIR) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
