CC=gcc
CFLAGS=-O3 -g

TARGET=mandel

all: $(TARGET)

libppm.so: ppm.c
    $(CC) $(CFLAGS) -fpic -shared $^ -o $@

mandel: mandel.c libppm.so
    $(CC) $(CFLAGS) -o $@ $< -lppm -L.

clean:
    rm -f $(TARGET) *.so
