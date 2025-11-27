#include <fcntl.h>     // for open()
#include <unistd.h>    // for read(), write(), close()
#include <stdlib.h>    // for exit()
#include <stdio.h>     // for perror()

int main() {
    int src, dest;
    char buffer[1024];
    ssize_t bytesRead;

    // Open source file
    src = open("result.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening result.txt");
        exit(1);
    }

    // Open destination file (create if not exists, write-only)
    dest = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error creating copyresult.txt");
        close(src);
        exit(1);
    }

    // Copy content
    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }

    // Close files
    close(src);
    close(dest);

    write(1, "File copied successfully!\n", 26);
    return 0;
}
