# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:58:11 by emiro-co          #+#    #+#              #
#    Updated: 2023/07/12 19:02:24 by emiro-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c\
					ft_isprint.c\
					ft_memcmp.c\
					ft_putchar_fd.c\
					ft_split.c\
					ft_strlcat.c\
					ft_strncmp.c\
					ft_substr.c\
					ft_atoi.c\
					ft_isalpha.c\
					ft_itoa.c\
					ft_memcpy.c\
					ft_putendl_fd.c\
					ft_strchr.c\
					ft_strlcpy.c\
					ft_strnstr.c\
					ft_tolower.c\
					ft_bzero.c\
					ft_isascii.c\
					ft_memmove.c\
					ft_putnbr_fd.c\
					ft_strdup.c\
					ft_strlen.c\
					ft_strrchr.c\
					ft_toupper.c\
					ft_calloc.c\
					ft_isdigit.c\
					ft_memchr.c\
					ft_memset.c\
					ft_putstr_fd.c\
					ft_strjoin.c\
					ft_strmapi.c\
					ft_strtrim.c\
					ft_striteri.c\
					ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c \
					ft_lstiter.c\
					ft_lstmap.c

OBJS			= $(SRCS:.c=.o)

PRINTF 			= ./printf/

FILESPRINTF		=	ft_digit.c\
					ft_hexnum.c\
					ft_printf.c\
					ft_ptr.c\
					ft_ui.c\
					utils.c

SRCPRINTF 		=	$(addprefix $(PRINTF),$(FILESPRINTF))

OBJSPRINTF		= 	$(SRCPRINTF:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

LIB_H			= libft.h

all:			$(NAME)

%.o:		 	%.c $(LIB_H)
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):		$(OBJS) $(OBJSPRINTF)
				ar rcs $(NAME) $(OBJS) $(OBJSPRINTF)

clean:
				$(RM) $(OBJS) $(OBJSPRINTF)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re