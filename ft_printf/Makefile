# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:22:54 by luaraujo          #+#    #+#              #
#    Updated: 2022/11/25 17:52:33 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	libftprintf..a

SRCS 			=	

OBJS			=	$(SRCS:.c=.o)

CC 				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror


all:			$(NAME)
$(NAME):		$(OBJS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
						$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re