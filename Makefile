CC = gcc
OBJ_DIR = bin/obj
BIN_DIR = bin
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
CFLAGS = -g -ansi -pedantic -Wall -Wextra
CPPFLAGS = -I ./include/dijkstra -I ./include/track -I ./include/utils -I ./include/graph
LDFLAGS = -lasan
TEAM = LesCaentractes

.PHONY = test_track clean distclean

include $(SRC_DIR)/Makefile

include $(SRC_DIR)/dijkstra/Makefile
include $(SRC_DIR)/track/Makefile
include $(SRC_DIR)/utils/Makefile

include $(TEST_DIR)/track/Makefile


clean:
	-@$(RM) $(OBJ_DIR)/dijkstra/*
	-@$(RM) $(OBJ_DIR)/track/*
	-@$(RM) $(OBJ_DIR)/utils/*
	-@$(RM) $(OBJ_DIR)/tests/*
	-@$(RM) $(OBJ_DIR)/main.o
	-@$(RM) $(OBJ_DIR)/mainPilote.o
	-@echo "object file remove"

distclean: clean
	-@$(RM) bin/prog
	-@$(RM) bin/LesCaentractes
	-@$(RM) bin/test/*
	-@echo "executable file remove"