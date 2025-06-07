MY_CC=gcc

MY_DEBUG=-ggdb
MY_WARN=-w
# MY_WARN=-Wall -Wextra -Werror
MY_SANITIZE_ADDRESS=-fsanitize=address
MY_CCFLAGS= $(MY_DEBUG) \
			$(MY_WARN) \
			$(MY_SANITIZE_ADDRESS)

MY_SRC=main.c
# src/*.c
MY_SRCS=$(MY_SRC) \
	dependencies/mycustom/*.c \
	dependencies/pure/*.c \
	dependencies/my/matrix/*.c \
	src/architecture/components/*.c \
	src/architecture/entities/*.c \
	src/architecture/systems/*.c \
	src/manager/*.c \
	src/utilities/*.c \
	src/engine/*.c \
	src/loader/*.c \
	src/*.c

MY_OPT=-o

MY_PATH=build
MY_TARGET=app
MY_APP=$(MY_PATH)/$(MY_TARGET)

MY_LIBS=`pkg-config --libs --cflags sdl3`

myall:	mybuild myrun

mybuild:
	@$(MY_CC) $(MY_CCFLAGS) $(MY_SRCS) $(MY_OPT) $(MY_APP) $(MY_LIBS)

myrun: 
	@$(MY_APP)

MY_TEST_PATH=tests
MY_TEST_SRC=$(MY_TEST_PATH)/testArrayDynamic.c
MY_TEST_BUILD=$(MY_TEST_PATH)/build
MY_TEST_TARGET=testArrayDynamic.exe
MY_TEST_APP=$(MY_TEST_BUILD)/$(MY_TEST_TARGET)

mytestall:	mytestbuild mytestrun

mytestbuild:
	@$(MY_CC) $(MY_CCFLAGS) $(MY_TEST_SRC) $(MY_OPT) $(MY_TEST_APP) $(MY_LIBS)

mytestrun: 
	@$(MY_TEST_APP)