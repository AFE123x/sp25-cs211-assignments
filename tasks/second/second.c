#include <stdio.h>
#include <assert.h>

/**
  * James wanted a system that'd read a textfile to get:
  * - The number of logins a user has made
  * - The person's name
  * - an ID number
  *
  * The previous interns implemented it, as shown below.
  * Unfortunately, the program seems to crash; find the
  * error and fix it.
  */
int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");

    int x, y;
    char buf[10];

    // Ensure fscanf successfully reads all three items
    while (fscanf(file, "%d %s %d", &x, buf, &y) == 3) {
        printf("%d %s %d\n", x, buf, y);
    }

    fclose(file);
    return 0;
}

