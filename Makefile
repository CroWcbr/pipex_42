# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 16:20:28 by cdarrell          #+#    #+#              #
#    Updated: 2021/10/24 14:26:24 by cdarrell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a

MAND_DIR	=	mandatory
BON_DIR		=	bonus

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

#COLORS
C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all:	
		@make -C ${LIBFT_DIR}/ all
		@make -C ${MAND_DIR}/ all
		@cp ${MAND_DIR}/${NAME} ${NAME} 

bonus:	
		@make -C ${LIBFT_DIR}/ all
		@make -C ${BON_DIR}/ all
		@cp ${BON_DIR}/${NAME} ${NAME}

clean:
		@make -C ${LIBFT_DIR}/ clean
		@make -C ${MAND_DIR}/ clean
		@make -C ${BON_DIR}/ clean
		
fclean:	
		@make -C ${LIBFT_DIR}/ fclean	
		@make -C ${MAND_DIR}/ fclean
		@make -C ${BON_DIR}/ fclean
		@${RM_FILE} $(NAME)
		
re:		fclean all

.PHONY: all bonus clean fclean re

