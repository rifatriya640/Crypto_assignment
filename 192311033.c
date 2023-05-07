#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 12

int main() {
    FILE *keyfile, *plaintextfile, *ciphertextfile;
    unsigned char key[KEY_LENGTH];
    unsigned char plaintext, ciphertext;
    int i;

    // Open the key file
    keyfile = fopen("key.txt", "r");
    if (keyfile == NULL) {
        printf("Error opening key file!\n");
        return 1;
    }

    // Read the key from the file
    for (i = 0; i < KEY_LENGTH; i++) {
        fscanf(keyfile, "%02X", &key[i]);
    }

    fclose(keyfile);

    // Open the plaintext file
    plaintextfile = fopen("plaintext.txt", "r");
    if (plaintextfile == NULL) {
        printf("Error opening plaintext file!\n");
        return 1;
    }

    // Open the ciphertext file
    ciphertextfile = fopen("ciphertext.txt", "w");
    if (ciphertextfile == NULL) {
        printf("Error opening ciphertext file!\n");
        return 1;
    }

    // Encrypt the plaintext using the key
    while (fscanf(plaintextfile, "%c", &plaintext) != EOF) {
        ciphertext = plaintext ^ key[i % KEY_LENGTH];
        fprintf(ciphertextfile, "%02X", ciphertext);
        i++;
    }

    fclose(plaintextfile);
    fclose(ciphertextfile);
    return 0;
}
