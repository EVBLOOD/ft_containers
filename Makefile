# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 13:16:24 by sakllam           #+#    #+#              #
#    Updated: 2022/09/30 13:49:39 by sakllam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./ft_containers

SRCSETSTD =	std_set.cpp
SRCSETFT =	ft_set.cpp
SRCMAPSTD =	std_map.cpp
SRCMAPFT =	ft_map.cpp
SRCVECTOR =	vector/main.cpp
SRCSTACK =	stack/main.cpp 

INC = additional/equal.hpp additional/iterators_traits.hpp additional/make_pair.hpp additional/my_vector_iters.hpp additional/enable_if.hpp additional/is_integral.hpp additional/lexicographical_compare.hpp additional/my_map_iters.hpp additional/pair.hpp additional/Red-Black-Tree/Tree_implemeted.hpp map/map.hpp set/set.hpp stack/stack.hpp vector/vector.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRCSETFT) $(SRCSETSTD) $(SRCMAPFT) $(SRCMAPSTD) $(SRCVECTOR) $(SRCSTACK) $(INC)
	(rm -rf $(NAME) && mkdir $(NAME))
	c++ $(FLAGS) $(SRCSETFT) -o $(NAME)/ft_set
	c++ $(FLAGS) $(SRCSETSTD) -o $(NAME)/std_set
	c++ $(FLAGS) $(SRCMAPFT) -o $(NAME)/ft_map
	c++ $(FLAGS) $(SRCMAPSTD) -o $(NAME)/std_map
	c++ $(FLAGS) $(SRCVECTOR) -o $(NAME)/vec
	c++ $(FLAGS) $(SRCSTACK) -o $(NAME)/stack

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re