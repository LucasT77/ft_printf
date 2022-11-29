# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2022/11/29 17:31:12 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			=	libftprintf.a

SRCS 			=	ft_printf.c ft_printf_utils.c 

OBJS			=	$(SRCS:.c=.o)

CC 				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	./../libft/libft.a

INCLUDES		=	-I./includes

all:			$(NAME)
$(NAME):		$(OBJS)
						$(MAKE) -C ./../libft
						cp ../libft/libft.a $(NAME)
						$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(MAKE) clean -C ./../libft
						$(RM) $(OBJS)

fclean:			clean
						$(MAKE) fclean -C ./../libft
						$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re