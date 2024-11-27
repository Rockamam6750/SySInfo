SCR = main.cpp Structure/System/System.cpp Structure/GraphicInter/Gui.cpp Structure/Gotoxy/gotoxy.cpp Structure/Reader/Reader.cpp Structure/Getteres/Getter.cpp Structure/Control/Control.cpp -liphlpapi -lws2_32 -lpdh
NAME = SySInfo

all: $(NAME)

$(NAME):
	g++ -Wall $(SCR) $(KEY) -o $(NAME)

clean: 

fclean: clean
	rm $(NAME)

re: fclean all

