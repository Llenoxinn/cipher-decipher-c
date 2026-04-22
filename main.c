#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *text, int shift) {
    for(int i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26-shift);
}

int main() {
    char text[10000];
    int choice, shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift(1-25): ");
    scanf("%i", &shift);

    printf("\t1 - Encrypt\n\t2 - Decrypt\nChoice: ");
    scanf("%i", &choice);

    switch(choice) {
        case 1:
            encrypt(text,shift);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            decrypt(text,shift);
            printf("Decrypted text: %s\n", text);
            break;
    }
    return 0;
}
