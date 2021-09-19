NAME = endgame

SRCS = src/main.c src/player.c src/draw_map.c src/menu.c
SRCSOB = main.c player.c draw_map.c menu.c
INC = inc/endgame.h
INCOB = endgame.h

CFLAGS = -std=c11 -lncurses 

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) $(SRCSOB) -I $(INCOB)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(INCOB)
	@rm -rf $(SRCSOB)
reinstall: uninstall clean all
