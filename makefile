GCC=gcc
PREFIX=/usr/local
NAME=amotep
BIN =./Bin

all:
	${GCC} -o ${BIN}/${NAME} amotep.c usage.c word_lower.c word_upper.c word_capitalise_first.c word_toggle.c
	#${GCC} -o amotep amotep.c usage.c word_lower.c word_upper.c word_capitalise_first.c word_toggle.c word_substitute.c
clean:
	-rm -f ${BIN}/${NAME}
install:
	install -s ${NAME} ${PREFIX}/bin
uninstall:
	-rm -f ${PREFIX}/bin/${NAME}
