# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 23:25:19 by gda-cruz          #+#    #+#              #
#    Updated: 2022/12/19 14:44:11 by gda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -fr

NAME			= libft.a
HEADER			= libft.h

SOURCES			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_striteri.c\
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
					ft_putchar_fd.c ft_putendl_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
					ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
					ft_tolower.c ft_toupper.c ft_putnbr_fd.c get_next_line.c
BONUS_SOURCES	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
					ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SOURCES_O		= $(SOURCES:.c=.o)
BONUS_O			= $(BONUS_SOURCES:.c=.o)

all:			$(NAME)

$(NAME):		$(SOURCES_O) $(HEADER)
	ar -rcs $(NAME) $(SOURCES_O)
	ranlib $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I/$(HEADER) -fPIE -c $< -o $(<:.c=.o)

bonus:			$(NAME) $(BONUS_O)
	ar -rcs $(NAME) $(BONUS_O)

clean:
	$(RM) $(SOURCES_O) $(BONUS_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean all

rebonus:		fclean bonus

.PHONY:			all clean fclean re bonus rebonus
