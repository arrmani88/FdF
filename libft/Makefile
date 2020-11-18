# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 11:22:12 by anel-bou          #+#    #+#              #
#    Updated: 2019/10/25 18:07:37 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra

OBJ = ft_abs.o\
		ft_atoi.o\
		ft_bzero.o\
		ft_clettercount.o\
		ft_cwordcount.o\
		ft_decilen.o\
		ft_del_char.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_islower.o\
		ft_isprint.o\
		ft_isupper.o\
		ft_iswhitespace.o\
		ft_itoa.o\
		ft_lst_nb_chr.o\
		ft_lst_nb_chr_n_add.o\
		ft_lstadd.o\
		ft_lstadd_end.o\
		ft_lstdel.o\
		ft_lstdelone.o\
		ft_lstiter.o\
		ft_lstmap.o\
		ft_lstnew.o\
		ft_lstsize.o\
		ft_memalloc.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memdel.o\
		ft_memmove.o\
		ft_memset.o\
		ft_printstr2.o\
		ft_putchar.o\
		ft_putchar_fd.o\
		ft_putcol.o\
		ft_putendl.o\
		ft_putendl_fd.o\
		ft_putnbr.o\
		ft_putnbr_fd.o\
		ft_putnchar.o\
		ft_putnchar_fd.o\
		ft_putnstr.o\
		ft_putnstr_fd.o\
		ft_putstr.o\
		ft_putstr_fd.o\
		ft_sort_int_tab.o\
		ft_stralloc.o\
		ft_strcat.o\
		ft_strchr.o\
		ft_strclr.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdel.o\
		ft_strdup.o\
		ft_strequ.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strjoin.o\
		ft_strlcat.o\
		ft_strlen.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strncat.o\
		ft_strncmp.o\
		ft_strncpy.o\
		ft_strnequ.o\
		ft_strnew.o\
		ft_strnjoin.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strsplit.o\
		ft_strstock.o\
		ft_strstr.o\
		ft_strsub.o\
		ft_strtrim.o\
		ft_table2_len.o\
		ft_table3_len.o\
		ft_tolower.o\
		ft_toupper.o\

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf libft.a

re: fclean all
