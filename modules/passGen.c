#include <stdio.h>
#include "passGen.h"
#include <string.h>
#include <sys/random.h>

int PassGen(int lenght){
    const char charset[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789"
    "!@#$%&*´";

    unsigned char buffer[16];

    char senha[lenght +1];
    int charset_lenght = strlen(charset);
    
    if (getrandom(buffer, sizeof(buffer), 0) == -1){
        perror("getrandom");
        return 1;
    }

    for (int i = 0; i < lenght; i++){
        int index = buffer[i] % charset_lenght;
        senha[i] = charset[index];
    }
    
    senha[lenght] = '\0';

    printf("Your password: %s\n", senha);
    return 0;

}
