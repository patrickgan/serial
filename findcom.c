// https://en.wikibooks.org/wiki/Serial_Programming/termios
// Patrick's attempt to learn serial programming :)

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// char *itoa (int val, char* buf, int base);

int main () {
    /*
    const char *device = "/dev/ttyS0";
    fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf( "failed to open port\n" );
    } else {
        close(fd);
    }
    */

    struct termios config;
    int fd;
    char *base="/dev/ttyUSB";
    char port[13]="/dev/ttyUSB1";
    char buffer[10]; 
    for (int i=0;i<6;i++) {
    //    itoa(i,buffer,10); 
    //    port[12]=buffer[0];
        sprintf(port, "%s%d", base, i);
    //    if (strcmp(port, "/dev/ttyUSB4")==0)
    //        break;
        printf("%s\n", port);
        fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
        if (fd==-1) {
            printf( "failed to open port %s\n", port );
        } else {
            if (!isatty(fd)) {
                printf("not a tty. trying next port.\n");
                continue;
            }
            if (tcgetattr(fd, &config) < 0) {
                printf("error: cannot access termios info.\n");
                continue;
            }
            //config.c_iflag &= ~()
            if(cfsetispeed(&config, B115200) < 0 || 
                 cfsetospeed(&config, B115200) < 0) {
                continue;
            }
                
            printf( "success!\n" );
            close(fd);
            break;
        } 
    }

}
