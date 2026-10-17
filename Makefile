# Cryostasis360 v0.5b — host-testable input/camera scaffold.
# A successful host build is not an Xbox 360 target build.

TARGET := cryostasis360.elf
SOURCES := src/main.c src/platform.c src/resource.c src/render.c src/input.c src/camera.c
OBJECTS := $(SOURCES:.c=.o)

ifeq ($(DEVKITXENON),)
$(warning DEVKITXENON is not set; configure your Free60/libXenon toolchain before building.)
endif

CC := xenon-gcc
CFLAGS ?= -O2 -Wall -Wextra
CFLAGS += -Iinclude
LDFLAGS ?= -lm

.PHONY: all clean toolchain-check
all: toolchain-check $(TARGET)

toolchain-check:
	@command -v $(CC) >/dev/null 2>&1 || { echo "ERROR: $(CC) not found. Configure a compatible libXenon toolchain."; exit 1; }

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
