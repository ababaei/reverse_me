

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ok(void) {
    printf("Good job.\n");
}

void no(void) {
    printf("Nope.\n");
    exit(1);
}

int main(void) {
    char input[24];       // str de l'utilisateur
    char key[9];          // str comparer au bon resultat
    int ret;
    unsigned int read_pos = 2;  // index de lecture
    int write_pos = 1;          // index d'ecriture
    size_t input_len;

    printf("Please enter key: ");
    ret = scanf("%s", input);  //

    if (ret != 1) {
        no();
    }

    // check que les deux premiers caracteres soient des 0
    if (input[0] != '0' || input[1] != '0') {
        no();
    }

    // insert un 'd' en pos 0
    memset(key, 0, sizeof(key));
    key[0] = 'd';

    // Boucle de remplissage avec le cast en charactere
    while (strlen(key) < 8 && read_pos + 2 < strlen(input)) {
        char triplet[4];
        triplet[0] = input[read_pos];
        triplet[1] = input[read_pos + 1];
        triplet[2] = input[read_pos + 2];
        triplet[3] = 0;

        int ascii_value = atoi(triplet);
        key[write_pos] = (char)ascii_value;

        read_pos += 3;
        write_pos++;
    }

    key[write_pos] = '\0';

    if (strcmp(key, "delabere") == 0) {
        ok();
    } else {
        no();
    }

    return 0;
}