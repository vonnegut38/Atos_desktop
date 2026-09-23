# Build DESKTOP.PRG with the m68k-atari-mint cross toolchain.
# Requirements: m68k-atari-mint-gcc in PATH (prebuilt from vincent.riviere.free.fr
# or freemint/m68k-atari-mint-build).
CC      ?= m68k-atari-mint-gcc
CFLAGS  ?= -mshort -O2 -Wall
DESKTOP  = DESKTOP.PRG

all: $(DESKTOP)

$(DESKTOP): desktop_mint.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(DESKTOP)
