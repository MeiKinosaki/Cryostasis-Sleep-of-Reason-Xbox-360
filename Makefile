# Cryostasis360 v0.1b — initial scaffold only.
# Requires a compatible Free60/libXenon environment.
# This does not yet build the original game or guarantee XEX packaging.

TARGET := cryostasis360.elf
SOURCES := src/main.c
OBJECTS := $(SOURCES:.c=.o)

ifeq ($(DEVKITXENON),)
$(warning DEVKITXENON is not set; configure your Free60/libXenon toolchain before building.)
endif

CC := xenon-gcc
CFLAGS ?= -O2 -Wall -Wextra
CFLAGS += -Iinclude
LDFLAGS ?=

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
