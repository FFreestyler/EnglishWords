CC = g++
CFLAGS = -Wall -Werror -c
SFML = -lsfml-graphics -lsfml-window -lsfml-system
SFML2 = -I SFML-2.5.1/include -L SFML-2.5.1/lib
OUT = out
DIR = build
DIR2 = bin
DIR3 = source
PRE = cxxtestgen --error-printer
RUN = runner
.PHONY: all prog runprog clean
all: prog
prog:
		$(CC) -o $(DIR)/$(DIR3)/menu.o $(SFML2) $(CFLAGS) $(DIR3)/menu.cpp
		$(CC) $(DIR)/$(DIR3)/*.o -o $(DIR2)/$(OUT) $(SFML2) $(SFML)
runprog:
		./$(DIR2)/$(OUT)
clean:
		rm -rf $(DIR2)/$(OUT) $(DIR2)/$(RUN)
		rm -rf $(DIR)/$(DIR3)/*.o $(DIR)/$(DIR4)/*.cpp