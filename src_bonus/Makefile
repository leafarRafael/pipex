NAME			:= pipex_bonus.a

SRC_BONUS		:= funcoes_temp_bonus.c main_bonus.c about_struct_bonus.c about_nbr_args_bonus.c\
				about_envp_bonus.c about_command_bonus.c about_nbr_args_bonus.c about_command_bonus.c\
				about_files_bonus.c about_other_utilities_bonus.c about_free_memory_bonus.c\
				about_executable_bonus.c about_error_handling_bonus.c\
				about_first_children_bonus.c about_last_children_bonus.c about_midle_children_bonus.c\
				about_here_doc.c

NUM_FILES		:= $(words $(SRC_BONUS))
OBJS			:= ./objs_pipex_bonus
INCLUDES		:= -I ../include_bonus -I ../lib/lib_get_print/includes
O_FILE			:= $(SRC_BONUS:%.c=$(OBJS)/%.o)
CC				:= cc
CFLAGS 			:= -Wall -Werror -Wextra
O_FLAGS 		:= -c
CMD_CLEAN		:= rm -Rf
CMD_FCLEAN		:= rm -rf

all: $(NAME)

$(NAME): $(O_FILE)
	@echo "  *  [100%] pipex_bonus_a Progress *"
	@ar -rc $(NAME) $(O_FILE)

$(OBJS)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@echo "  *  [$(shell echo 	$$(($(COUNT) * 100 / $(NUM_FILES))))%] pipex_bonus Progress    *"

clean:
	$(CMD_CLEAN) $(OBJS)

fclean: clean
	$(CMD_FCLEAN) $(NAME)

re: fclean all

.PHONI: all clean fclean re bonus
