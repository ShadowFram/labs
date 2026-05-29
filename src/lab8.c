#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/lab8.h"

int compareHumans(void *arg, const void *a, const void *b) {
    SortFields *fields = (SortFields *)arg;
    Human *h1 = (Human *)a;
    Human *h2 = (Human *)b;

    for (int i = 0; i < fields->count; i++) {
        switch (fields->order[i]) {
            case 1:
                if (h1->birthyear != h2->birthyear)
                    return h1->birthyear - h2->birthyear;
                break;
            case 2:
                if (strcmp(h1->surname, h2->surname) != 0)
                    return strcmp(h1->surname, h2->surname);
                break;
            case 3:
                if (strcmp(h1->name, h2->name) != 0)
                    return strcmp(h1->name, h2->name);
                break;
            case 4:
                if (strcmp(h1->sex, h2->sex) != 0)
                    return strcmp(h1->sex, h2->sex);
                break;
            case 5:
                if (h1->height != h2->height)
                    return (h1->height > h2->height) ? 1 : -1;
                break;
        }
    }
    return 0;
}

int readFile(Human people[]) {
    FILE *file = fopen("../data/names.txt", "r");
    if (!file) {
        printf("ERROR. WRONG FILE!\n");
        return 0;
    }

    int count = 0;

    while (fscanf(file, "%s %s %d %s %f",
                  people[count].surname,
                  people[count].name,
                  &people[count].birthyear,
                  people[count].sex,
                  &people[count].height) == 5) {
        count++;
    }

    fclose(file);
    return count;
}

void sortPeople(Human people[], int count) {
    SortFields fields;
    fields.count = 0;

    printf("\n1 - year\n");
    printf("2 - surname\n");
    printf("3 - name\n");
    printf("4 - sex\n");
    printf("5 - height\n");

    printf("\nEnter TWO sort filters (example: 2 3): ");

    scanf("%d %d", &fields.order[0], &fields.order[1]);

    fields.count = 2;

    qsort_s(people, count, sizeof(Human), compareHumans, &fields);
}

void printPeople(Human people[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s %d %s %.0f\n",
               people[i].surname,
               people[i].name,
               people[i].birthyear,
               people[i].sex,
               people[i].height);
    }
}

void lab8(){

    Human people[100];

    int count = readFile(people);

    sortPeople(people, count);

    printPeople(people, count);
}