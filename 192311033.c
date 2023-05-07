
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 12

int main() {
    FILE *outfile;
    unsigned char key[KEY_LENGTH];
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random bytes for the key
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }

    // Write the key to a file
    outfile = fopen("key.txt", "w");
    if (outfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < KEY_LENGTH; i++) {
        fprintf(outfile, "%02X", key[i]);
    }

    fclose(outfile);
    return 0;
}
