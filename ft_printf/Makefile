# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2022/11/30 18:09:23 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			=	libftprintf.a

SRCS 			=	ft_printf.c ft_printf_utils.c 

OBJS			=	$(SRCS:.c=.o)

CC 				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	../libft

INCLUDES		=	-I $(LIBFT) -L $(LIBFT) -l libft

all:			$(NAME)
$(NAME):		$(OBJS)
						$(MAKE) bonus -C ./$(LIBFT)
						cp $(LIBFT)/libft.a $(NAME)
						$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(MAKE) clean -C ./$(LIBFT)
						$(RM) $(OBJS)

fclean:			clean
						$(MAKE) fclean -C ./$(LIBFT)
						$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re