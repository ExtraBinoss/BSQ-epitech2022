##
## EPITECH PROJECT, 2022
## B-PSU-100-MPL-1-1-bsmyls-alan.trebugeais
## File description:
## Makefile
##

CC = gcc
CFLAGS = -W
CPPFLAGS = -I.

SRC = $(wildcard *.c)
SRCH = include/bsqq.h
OBJ = $(SRC:.c=.o)
TARGET = bsq
TARGET_LIB = libmy.a

all : $(TARGET)

$(TARGET) : $(OBJ)
	ar rcs $(TARGET_LIB) $(OBJ)
	$(CC) $(SRC) -o $(TARGET) -lmy -L.
	rm -rf $(OBJ)
	rm -rf $(TARGET_LIB)

codingstyle :
	../../../coding-style-checker/coding-style.sh . .
	cat coding-style-reports.log
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)
	rm -rf $(TARGET_LIB)

re : fclean all
