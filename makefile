# MakeFile for Tic-Tac-Toe

NAME = TICE
DESCRIPTION = "Tic-Tac-Toe v 1.0"
COMPRESSED = YES
COMPRESSED_MODE = zx7
ARCHIVED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

include $(shell cedev-config --makefile)