#include "../header/lab7.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct humen{
    char hsurname[50];
    char hname[50];
    int hbirthdate;
};

int compare_by_date(const void *a, const void *b){
    struct humen *humen_a = (struct humen *)a;
    struct humen *humen_b = (struct humen *)b;
    return humen_a->hbirthdate - humen_b->hbirthdate;
}

void lab7(){
    struct humen array1[4];
    struct humen array2[4];

    FILE *rfile = fopen("../data/names.txt", "r");

    char s[100], secondname[50];
    fgets(s, 100, rfile);

    for (int i = 0; i < 4; i++) {
        if (fscanf(rfile, "%s %s %s %d", array1[i].hsurname, array1[i].hname, secondname, &array1[i].hbirthdate) != 4) {

            fclose(rfile);
            return;
        }
    }
    fclose(rfile);

    for (int i = 0; i < 4; i++) {
        strcpy(array2[i].hsurname, array1[i].hsurname);
        strcpy(array2[i].hname, array1[i].hname);
        array2[i].hbirthdate = array1[i].hbirthdate;
    }

    qsort(array2, 4, sizeof(struct humen), compare_by_date);

    for (int i = 0; i < 4; i++) {
        printf("%d. %s %s, %d\n", i + 1,
               array2[i].hsurname, array2[i].hname, array2[i].hbirthdate);
    }
}