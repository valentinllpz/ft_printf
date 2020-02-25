# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 14:45:39 by vlugand-          #+#    #+#              #
#    Updated: 2020/02/26 00:43:04 by vlugand-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= .
SRCS	= 	ft_printf.c\
			conv_di.c\
			conv_c.c\
			conv_p.c\
			conv_s.c\
			conv_u.c\
			conv_x.c\
			parsing.c\
			parsing_2.c\
			ft_printf_utils.c\
			ft_printf_utils_2.c\
			ft_printf_utils_3.c\
			
OBJS		= ${SRCS:.c=.o}
OPTION		= -I${HEADER}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rc

.c.o:
			${CC} ${CFLAGS} ${OPTION} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re