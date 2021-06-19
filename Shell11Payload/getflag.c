#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>

int main(void) {
    off_t offset = 0;
    int fd = open("/flag", O_RDONLY);
    int ofd = open("/tmp/output", O_CREAT | O_RDWR);
    sendfile(ofd, fd,  &offset, 1000);
    close(fd);
    close(ofd);
}
