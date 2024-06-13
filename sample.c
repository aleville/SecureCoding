#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    static char ok_chars[] = "abcdefghijklmnopqrstuvwxyz"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "1234567890_-.@";
    const char *argOne = argv[1] + strlen(argv[1]);
    char help[BUFSIZE-8]={0};
    char *cp = argv[1];
    for (help += strspn(cp, ok_chars); cp != argOne; cp += strspn(cp, ok_chars)) {
      *help = '_';
    }
    strncat(cmd, help, BUFSIZE-8);
    system(cmd);
}
