# makefile

WARN = -Wall -Wextra -Wshadow
SRC  = src

CPPFLAGS = -I.
CFLAGS   = $(WARN) $(CPPFLAGS) -Og -std=c99 -g

# this line should be uncommented if you want a debug build
#CFLAGS  = $(WARN) $(CPPFLAGS) -O3 -std=c99 -D NDEBUG

SRCR = $(SRC)/*.c
SRCS = $(wildcard $(SRCR))
OBJS = $(SRCS:.c=.o)

TARGET = frame

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
	@rm -vf $(OBJS) $(TARGET)
