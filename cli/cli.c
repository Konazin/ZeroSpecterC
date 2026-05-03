#include "cli.h"
#include "../modules/passGen.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Terminal(void) {
    char input[100];

    while (1) {
        printf("ZeroSpecter >> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        printf(input);
        input[strcspn(input, "\n")] = 0;

        char *cmd = strtok(input, " ");

        if (!cmd){
            return;
        }

        if (strcmp(cmd, "passgen") == 0) {

            char *flag = strtok(NULL, " ");
            char *arg = strtok(NULL, " ");

            if (flag && arg && strcmp(flag, "-l")==0){
                int len = atoi(arg);
                PassGen(len);
            }
        else{
            printf("usage: passgen -l <tamanho>\n");
        }
            
        }
        else if (strcmp(input, "zipcrack") == 0) {
            printf("zipcrack ainda não implementado\n");
        }
        else if (strcmp(input, "exit") == 0) {
            printf("Saindo...\n");
            break;
        }
        else {
            printf("No modules found...\n");
        }
    }
}