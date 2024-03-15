NAME = offer_book
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include

SRCS_DIR 	= src/
UTILS_DIR		= utils/
BOOK_DIR		= book/
ACTIONS_DIR	= actions/
HANDLE_FREE_DIR = handle_free/

OBJS_DIR 	= obj/

FILES = \
	main \
	$(BOOK_DIR)init_book \
	$(ACTIONS_DIR)init_actions $(ACTIONS_DIR)insert_property \
	$(ACTIONS_DIR)validate_property \
	$(HANDLE_FREE_DIR)handle_free \
	$(UTILS_DIR)print_book \

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

clean:
	$(RM) -r $(OBJS_DIR) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
