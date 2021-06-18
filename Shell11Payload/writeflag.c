/*
 * This exists because shellcoding challenge 11 closes all file descriptors
 * This will hopefully be bypassed by reading the file, and then writing to a file somewhere
 * THIS DID NOT GET USED
 */ 
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

extern int errno;

int main(void) {
    // set to a static 4096 because the flag has a set size
    char text[4096];
    // open the flag file
    int flag_file = open("./flag", O_RDONLY);

    if (flag_file == -1) {
        printf("Error Number %d\n", errno);
        perror("[ERROR]");
    }
    // open the output file
    int output_file = open("./the_flag", O_RDWR | O_CREAT);

    if (output_file == -1) {
        printf("Error Number %d\n", errno);
        perror("[ERROR]");
    }
    // read the the flag from "/flag"
    read(flag_file, &text, 4096);
    // write the contents of the flag file to the output file
    write(output_file, &text, 4096);
    // close the files
    close(flag_file);
    close(output_file);

    return 0;
}
