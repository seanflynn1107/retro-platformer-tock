APP=retro_game

TOCK_USERLAND_BASE_DIR = ../libtock-c

C_SRCS := $(wildcard *.c)

APP_HEAP_SIZE := 20000

EXTERN_LIBS += $(TOCK_USERLAND_BASE_DIR)/u8g2

include $(TOCK_USERLAND_BASE_DIR)/AppMakefile.mk