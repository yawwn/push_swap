#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcathery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 19:44:43 by mcathery          #+#    #+#              #
#    Updated: 2019/09/06 19:45:24 by mcathery         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
        		ft_isprint ft_itoa ft_memalloc ft_memccpy ft_memchr ft_memcmp \
        		ft_memcpy ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
        		ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat \
        		ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdup ft_strequ \
        		ft_striter ft_striteri ft_strlcat ft_strlen ft_strncat ft_strncmp \
        		ft_strncpy ft_strnequ ft_strnlen ft_strnstr ft_strrchr ft_strstr \
        		ft_tolower ft_toupper ft_memdel ft_strmap ft_strmapi ft_strjoin \
        		ft_strdel ft_strnew ft_strsub ft_strtrim ft_strsplit ft_lstadd \
        		ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew get_next_line \
        		ft_printf digit_work ft_ftoa itoa_base string_ft work_s_c \
        		work_specifications work_variable \

SRC = $(addsuffix .c, $(FILES))
OBJECTS = $(addsuffix .o, $(FILES))

FLAGS = -Wall -Wextra -Werror -c

HEADER = libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I $(HEADER) $(SRC)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
