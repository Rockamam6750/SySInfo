SCR = main.cpp Structure/System/System.cpp Structure/GraphicInter/Gui.cpp Structure/Gotoxy/gotoxy.cpp Structure/Reader/Reader.cpp Structure/Getteres/Getter.cpp

NAME = SySInfo

all: $(NAME)

$(NAME):
	g++ -Wall $(SCR) -o $(NAME)

clean: 

fclean: clean
	rm $(NAME)

re: fclean all