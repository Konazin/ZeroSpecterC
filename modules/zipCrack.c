#include "passGen.h"
#include "zipCrack.h"
#include <string.h>
#include <zip.h>

void ZipCrack(int lenght, char path){
    int control = 1;
    while(control == 1){
        char senha[6767];
        zip_t *za = zip_fopen_encrypted(za, path, 0, senha);
    }
    
}