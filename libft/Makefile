# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:23:47 by tquere            #+#    #+#              #
#    Updated: 2023/01/18 16:57:14 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) spinner bonus clean fclean re

NAME				= 	libft.a
HEADER				= 	libft.h

BUILD_DIR			= 	build/
HEADER_DIR			= 	inc/

FT_GNL 				= 	get_next_line_utils get_next_line
FT_IS 				= 	ft_is_double ft_isnum ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint
FT_LS 				= 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
FT_MEM 				= 	ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_calloc
FT_PRINTF 			= 	ft_printf ft_write_protect
FT_PUT 				= 	ft_put_base_long ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
FT_STR 				= 	ft_strmapi ft_striteri ft_strjoin ft_strtrim ft_strcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_strnstr ft_strdup ft_substr
FT_STRS 			= 	ft_split ft_free_tab ft_count_tab ft_sort_tab ft_print_tab
FT_TO 				= 	ft_toupper ft_tolower ft_atoi ft_itoa
FT_MAX 				= 	ft_strcat ft_strcpy ft_strncpy ft_memdel ft_isinset ft_isspace ft_strdel ft_strnew ft_strsdel ft_strsnew

SOURCE 				= 	$(addsuffix .c, $(addprefix ft_gnl/, $(FT_GNL))) 		\
						$(addsuffix .c, $(addprefix ft_is/, $(FT_IS))) 			\
						$(addsuffix .c, $(addprefix ft_ls/, $(FT_LS))) 			\
						$(addsuffix .c, $(addprefix ft_mem/, $(FT_MEM))) 		\
						$(addsuffix .c, $(addprefix ft_printf/, $(FT_PRINTF))) 	\
						$(addsuffix .c, $(addprefix ft_put/, $(FT_PUT))) 		\
						$(addsuffix .c, $(addprefix ft_str/, $(FT_STR))) 		\
						$(addsuffix .c, $(addprefix ft_strs/, $(FT_STRS))) 		\
						$(addsuffix .c, $(addprefix ft_to/, $(FT_TO))) 			\
						$(addsuffix .c, $(addprefix ft_max/, $(FT_MAX))) 		\

OBJECTS			    	= $(SOURCE:%.c=$(BUILD_DIR)%.o)

GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
LIB 					= ar -crs
RM 						= rm -rf

all: 					$(NAME)

$(BUILD_DIR)%.o:		%.c $(HEADER_DIR)$(HEADER)
						@echo -n .
						@mkdir -p $(@D)
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(NAME): 				${OBJECTS} $(HEADER_DIR)$(HEADER)
						@${LIB} ${NAME} ${OBJECTS}
						@echo "\033[32m\n-- Done compiling $(NAME)--\033[0m"

clean:
						@${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:					clean
						@${RM} ${NAME}
						@${RM} build

re:						fclean all

					# echo -n $$i
					#
