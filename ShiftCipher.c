#include<stdio.h>

#include<ctype.h>


int main() {

    char text[500], ch;

    int key;

    // Taking user input.
    printf("Enter a message to encrypt: ");

    scanf("%s", text);

    printf("Enter the key: ");

    scanf("%d", & key);

    // Visiting character by character.

    for (int i = 0; text[i] != '\0'; ++i) {

        ch = text[i];
        // Check for valid characters.
        if (isalnum(ch)) {

            //Lowercase characters.
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            // Uppercase characters.
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }

        }
        // Invalid character.
        else {
            printf("Invalid Message");
            break;
        }

        // Adding encoded answer
        text[i] = ch;

    }
    char text2[500], ch2;

    int key2;

    // Taking user input.
    printf("Enter a message to decrypt: ");

    scanf("%s", text2);

    printf("Enter the key: ");

    scanf("%d", & key2);
    for (int i = 0; text2[i] != '\0'; ++i) {

            ch2 = text2[i];
            // Check for valid characters.
            if (isalnum(ch2)) {
                //Lowercase characters.
                if (islower(ch2)) {
                    ch2 = (ch2 - 'a' - key2 + 26) % 26 + 'a';
                }
                // Uppercase characters.
                if (isupper(ch2)) {
                    ch2 = (ch2 - 'A' - key2 + 26) % 26 + 'A';
                }
                // Numbers.
                if (isdigit(ch2)) {
                    ch2 = (ch2 - '0' - key2 + 10) % 10 + '0';
                }
            }
            // Invalid characters.
            else {
                printf("Invalid Message");
            }
            // Adding decoded character back.
            text2[i] = ch2;

        }
    

    

    printf("Encrypted message: %s\n", text);
    printf("Decrypted message: %s", text2);
    

    return 0;
}
