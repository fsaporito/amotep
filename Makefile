# C compiler
CC=/usr/bin/gcc

# Output Path
OUT=./Bin

# Prefix Path
PREFIX=/usr/local


# Software Name
NAME=amotep


# Compiler Flags:
# -O3  =>  Maximum Optimisation Level
# -finline_functions =>  Consider All Functions For Inlining
# -findirect-inlining => 
# -fexpensive-optimizations => Add More Minor TIme Consuming Optimisations
# -g => Adds Debug Informations To The Executable File
# -Wall => Turns On Most Of Compiler Warnings
# -iquote => Add The Following Dir To The Source Code Path
CFLAGS=-O3 -finline-functions -findirect-inlining -fexpensive-optimizations


# Headers
HEADERS=./stringFunctions/spaces_dash.h \
	    ./stringFunctions/spaces_underscore.h \
	    ./stringFunctions/word_capitalise_first.h \
	    ./stringFunctions/word_lower.h \
	    ./stringFunctions/word_toggle.h \
	    ./stringFunctions/word_upper.h \
	    ./stringFunctions/usage.h
	    #./stringFunctions/word_substitute.h


# Source Code
SOURCE=./stringFunctions/spaces_dash.c \
	   ./stringFunctions/spaces_underscore.c \
	   ./stringFunctions/word_capitalise_first.c \
	   ./stringFunctions/word_lower.c \
	   ./stringFunctions/word_toggle.c \
	   ./stringFunctions/word_upper.c \
	   ./stringFunctions/usage.c \
	   ${NAME}.c
	   #./stringFunctions/word_substitute.c \

# Make
all:
	${CC} -o ${OUT}/${NAME}  ${SOURCE} ${HEADERS} ${CFLAGS}
	
clean:
	-rm -f ${BIN}/${NAME}

install:
	install -s ${OUT}/${NAME} ${PREFIX}/bin

uninstall:
	-rm -f ${PREFIX}/bin/${NAME}

