.PHONY:     			all $(NAME) inst sanit leaks clear mkbuild lib clear clean fclean re

#------------------------------------------LIBFT------------------------------------------

LIBFT					= libft.a
LIB_DIR					= libft/
LIB_DIR_INC				= libft/inc

#---------------------------------------COMPIL RULE------------------------------------------

GCC						= gcc
FLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(FLAGS) -g3 -fsanitize=address
RM 						= rm -rf
CLEAR					= clear

RL_RL					= -lreadline
RL_LIB					= -L ~/.brew/opt/readline/lib
RL_INC					= -I ~/.brew/opt/readline/include

#------------------------------------------MINISHELL------------------------------------------

NAME					= minishell
BUILD_DIR				= build/

MINI_INC_DIR			=
MINI_SRC_DIR			=

MINI_INC_FILE			= minishell struct
MINI_SRC_FILE 			= main main_exit

MINI_INC				= $(addsuffix .h, $(addprefix $(MINI_INC_DIR), $(MINI_INC_FILE)))
MINI_SRC 				= $(addsuffix .c, $(addprefix $(MINI_SRC_DIR), $(MINI_SRC_FILE)))

MINI_OBJECTS			= $(MINI_SRC:%.c=$(BUILD_DIR)%.o)

#------------------------------------------PARSING------------------------------------------

PARS_DIR				= Parsing

PARS_INC_DIR			= $(PARS_DIR)/includes
PARS_SRC_DIR			= $(PARS_DIR)/srcs

PARS_INC_FILE			= turtle_parsing
PARS_SRC_FILE 			= here_tools signal_docs signal redi_tools2 here_docs quotetrimer envi_tools prompt_loop proc_parsing err_manager splitpipe ext_inpipe splitinpipe redi_manager redi_tools prompt_syntax prompt_tools envi_dealer

PARS_INC				= $(addsuffix .h, $(addprefix $(PARS_INC_DIR)/, $(PARS_INC_FILE)))
PARS_SRC 				= $(addsuffix .c, $(addprefix $(PARS_SRC_DIR)/, $(PARS_SRC_FILE)))

PARS_OBJECTS			= $(PARS_SRC:%.c=$(BUILD_DIR)%.o)

#------------------------------------------EXEC------------------------------------------

EXEC_DIR				= Exec

EXEC_INC_DIR			= $(EXEC_DIR)/inc
EXEC_SRC_DIR			= $(EXEC_DIR)/src
EXEC_BIN_DIR			= $(EXEC_DIR)/built_in
EXEC_ENV_DIR			= $(EXEC_DIR)/env

EXEC_INC_FILE			= exec
EXEC_SRC_FILE 			= exec_pipe exec_env exec_cmd exec
EXEC_BIN_FILE 			= export_utils cd echo env exit export pwd unset
EXEC_ENV_FILE 			= env_add env_del env_get env_init env_to_str env_utils inc_shlvl env_sort env_cpy

EXEC_INC				= 	$(addsuffix .h, $(addprefix $(EXEC_INC_DIR)/, $(EXEC_INC_FILE)))
EXEC_SRC 				= 	$(addsuffix .c, $(addprefix $(EXEC_SRC_DIR)/, $(EXEC_SRC_FILE)))	\
							$(addsuffix .c, $(addprefix $(EXEC_BIN_DIR)/, $(EXEC_BIN_FILE)))	\
							$(addsuffix .c, $(addprefix $(EXEC_ENV_DIR)/, $(EXEC_ENV_FILE)))	\

EXEC_OBJECTS			= $(EXEC_SRC:%.c=$(BUILD_DIR)%.o)

#---------------------------------------COMPIL .o  ------------------------------------------

OBJECTS					= $(MINI_OBJECTS) $(EXEC_OBJECTS) $(PARS_OBJECTS)
INCS					= $(MINI_INC) $(EXEC_INC) $(PARS_INC)

$(BUILD_DIR)%.o:		%.c $(INCS)
						@echo -n .
						@mkdir -p $(@D)
						@$(GCC) $(FLAGS) -I$(LIB_DIR_INC) -I$(MINI_INC_DIR) -I$(EXEC_INC_DIR) $(RL_INC) -c $< -o $@

#-------------------------------------------RULES------------------------------------------

all: 					clear mkbuild lib $(NAME)

mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)

lib:
						@make -C $(LIB_DIR)

clean:
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:
						@make fclean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)
						@${RM} ${NAME}

re:						fclean all

#------------------------------------------------------------------------------------------------
#-------------------------------------------COMPILATION------------------------------------------
#------------------------------------------------------------------------------------------------

$(NAME): 				lib $(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(RL_LIB) $(RL_RL)
						@echo "\033[32m\n-- Done compiling exec $(NAME)--\033[0m"

inst: 					lib $(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(RL_LIB) $(RL_RL) -framework CoreFoundation
						@echo "\033[32m\n-- Done compiling exec $(NAME)--\033[0m"

sanit:					lib $(CLEAR) $(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(RL_LIB) $(RL_RL)
						@echo "\033[32m\n-- Done compiling sanit ./$(NAME)--\033[0m"

leaks:					$(CLEAR)
						make
						@sleep 0.5
						@echo "\n    ------------------------------------------------------------"
						@echo "\033[32m\n-- Starting ./$(NAME)--\n\n\n\033[0m"
						leaks --atExit -- ./$(NAME)

#------------------------------------------------------------------------------------------------

