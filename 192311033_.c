#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 12

int main() {
    FILE *keyfile, *ciphertextfile, *decryptedfile;
    unsigned char key[KEY_LENGTH];
    unsigned char ciphertext, decrypted;
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

    // Open the ciphertext file
    ciphertextfile = fopen("ciphertext.txt", "r");
    if (ciphertextfile == NULL) {
        printf("Error opening ciphertext file!\n");
        return 1;
    }

    // Open the decrypted file
    decryptedfile = fopen("decrypted.txt", "w");
    if (decryptedfile == NULL) {
        printf("Error opening decrypted file!\n");
        return 1;
    }

    // Decrypt the ciphertext using the key
    while (fscanf(ciphertextfile, "%02X", &ciphertext) != EOF) {
        decrypted = ciphertext ^ key[i % KEY_LENGTH];
        fprintf(decryptedfile, "%c", decrypted);
        i++;
    }

    fclose(ciphertextfile);
    fclose(decryptedfile);
    return 0;
}

