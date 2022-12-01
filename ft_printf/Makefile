# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2022/12/01 17:27:27 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			=	libftprintf.a

SRCS 			=	ft_printf.c \
					printstr.c  printundec.c \
					printhex.c  printpointer.c \
					numlength.c  printchr.c  printdec.c \
					ft_putchar_fd.c  ft_putnbr_fd.c  ft_putstr_fd.c  ft_strlen.c \

OBJS			=	$(SRCS:.c=.o)

CC 				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

all:			$(NAME)
$(NAME):		$(OBJS)
						$(CC) $(CFLAGS) $(SRCS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re