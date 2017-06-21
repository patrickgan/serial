// https://en.wikibooks.org/wiki/Serial_Programming/termios
// Patrick's attempt to learn serial programming :)

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

const char *device = "/dev/ttyS0";
fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
if (fd == -1) {
    printf( "failed to open port\n" );
} else {
    close(fd);
}
