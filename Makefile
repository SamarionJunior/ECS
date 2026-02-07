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
	dependencies/my/dynamicarray/*.c \
	src/architecture/components/*.c \
	src/architecture/entities/*.c \
	src/architecture/systems/*.c \
	src/manager/*.c \
	src/utilities/*.c \
	src/engine/*.c \
	src/loader/*.c \
	src/*.c
# 	dependencies/my/matrix/*.c \
# 	dependencies/my/dynamicvectors/*.c \
# 	dependencies/my/dynamicvectors/components/*.c \
# 	dependencies/my/dynamicvectors/entities/*.c \
# 	dependencies/pure/glad/src/*.c \

MY_OPT=-o

MY_PATH=build
MY_TARGET=app
MY_APP=$(MY_PATH)/$(MY_TARGET)

# SDL2
# MY_LIBS=\
# 	-I/usr/local/include \
# 	-L/usr/local/lib \
# 	-lSDL2_image \
# 	-Wl,-rpath,/usr/local/lib \
# 	-Wl,--enable-new-dtags \
# 	-lSDL2 \
# 	-lGL
# 	-I./glad/include/glad/glad.h

# SDL3 + GLAD
# MY_LIBS=-I./glad/include/glad/glad.h `pkg-config --libs --cflags sdl3 sdl3-image gl`
# -I./glad/include/glad/glad.h 

# SDL3
MY_LIBS=-lSDL3 -lGL -lSDL3_image -L/usr/local/lib/libSDL3_image.so.0

myall:	mybuild myrun

mybuild:
	$(MY_CC) $(MY_CCFLAGS) $(MY_SRCS) $(MY_OPT) $(MY_APP) $(MY_LIBS)

myrun: 
	@$(MY_APP)

# ///////////////////////////////////////////////////////////////////

MY_TEST_NAME=tests

MY_TEST_PROJECT_NAME=opengl# MODIFY HERE
MY_TEST_PROJECT_FILE_NAME=main
MY_TEST_PROJECT_FILE_EXTENSION=c
MY_TEST_INPUT_PATH=$(MY_TEST_NAME)/$(MY_TEST_PROJECT_NAME)/$(MY_TEST_PROJECT_FILE_NAME).$(MY_TEST_PROJECT_FILE_EXTENSION)

MY_TEST_BUILD_NAME=build
MY_TEST_BUILD_FILE_NAME=$(MY_TEST_PROJECT_NAME)_$(MY_TEST_PROJECT_FILE_NAME)
MY_TEST_BUILD_FILE_EXTENSION=exe
MY_TEST_OUTPUT_PATH=$(MY_TEST_NAME)/$(MY_TEST_BUILD_NAME)/$(MY_TEST_BUILD_FILE_NAME).$(MY_TEST_BUILD_FILE_EXTENSION)

# MY_TEST_BUILD=$(MY_TEST_NAME)/build
# MY_TEST_TARGET=tree.exe
# MY_TEST_APP=$(MY_TEST_BUILD)/$(MY_TEST_TARGET)

mytestall:	mytestbuild mytestrun

mytestbuild:
	$(MY_CC) $(MY_CCFLAGS) glad.c $(MY_TEST_INPUT_PATH) $(MY_OPT) $(MY_TEST_OUTPUT_PATH) $(MY_LIBS)

mytestrun: 
	$(MY_TEST_OUTPUT_PATH)