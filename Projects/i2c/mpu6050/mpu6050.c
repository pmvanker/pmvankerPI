#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <ioctl.h>
#include <linux/i2c-dev.h>

#define SLAVE_ADDR  0x68

/*sudo i2cget -y 1 0x68 0x75*/

int main() {
    int i, j, dev;
    char buf[2];

    if ((dev = open("/dev/i2c-1", O_RDWR)) < 0) {
        printf("open failed");
        exit(1);
    }

    if (ioctl(dev, I2C_SLAVE, SLAVE_ADDR) < 0) {
        printf("ioctl failed");
        close(dev);
        exit(1);
    }

    //buf[0] = 0x68;
    buf[0] = 0x75;

/*
    if (write(dev,buf,1) != 2) {
        printf("write failed");
        close(dev);
        exit(1);
    }
*/

    if (read(dev, buf, 1) != 1) {
        printf("read failed");
        close(dev);
        exit(1);
    }

    close(dev);

    printf("received data : 0x%X\n",buf[0]);

    exit(0);
}
