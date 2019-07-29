# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpastukh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 10:26:29 by kpastukh          #+#    #+#              #
#    Updated: 2019/07/29 15:03:02 by moverton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUTPUT = bsq

FLAGS = -Wall -Wextra -Werror

SRC = src/*.c

OBJECTS =  *.o

HEADERS = includes/*.h

all: $(OUTPUT)
	gcc -o $(OUTPUT) $(OBJECTS)

$(OUTPUT): $(SRC) $(HEADERS)
	gcc $(FLAGS) -I$(HEADERS) -c $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(OUTPUT)

re: fclean all
