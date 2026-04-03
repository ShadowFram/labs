#include "../include/lab6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lab6(){

    char s[200], surname[50], name[50], second_name[50];
    int birthdate;

    FILE *rfile = fopen("../data/names.txt", "r");
    FILE *wfile = fopen("../data/boomers.txt", "w");

    while(fgets(s, 100, rfile) != NULL) {
        if (fscanf(rfile, "%s %s %s %d", surname, name, second_name, &birthdate) == 4) {
            if (birthdate > 1980) {
                fprintf(wfile, "%s %s %s %d\n", surname, name, second_name, birthdate);
                }
            }
        }
    fclose(rfile);

}