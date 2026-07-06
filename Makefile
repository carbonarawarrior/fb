CC := gcc

CFLAGS := -Wall -Wextra -Iinclude
DEBUGFLAGS := -g -O0
RELEASEFLAGS := -O2 -flto

MODE ?= debug
ifeq (${MODE}, release)
	OPTFLAGS := ${RELEASEFLAGS}
	BUILD := build/release
else
	OPTFLAGS := ${DEBUGFLAGS}
	BUILD := build/debug
endif

LDLIBS := 

TARGET := ${BUILD}/gd

SRC := ${wildcard src/*.c}
OBJS := ${patsubst src/%.c,${BUILD}/%.o,${SRC}}
DEPS := ${OBJS:.o=.d}

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} ${OPTFLAGS} ${LDLIBS} -o $@

${BUILD}/%.o: src/%.c | ${BUILD}
	${CC} ${CFLAGS} ${OPTFLAGS} -MMD -MP -c $< -o $@

${BUILD}:
	mkdir -p $@

clean:
	rm -rf build/

-include ${DEPS}

.PHONY: all clean
