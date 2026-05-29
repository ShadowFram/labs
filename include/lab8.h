#pragma once

typedef struct {
    int order[5];
    int count;
} SortFields;

typedef struct {
    char surname[50];
    char name[50];
    int birthyear;
    char sex[10];
    float height;
} Human;

int compareHumans(void *arg, const void *a, const void *b);
int readFile(Human people[]);
void sortPeople(Human people[], int count);
void printPeople(Human people[], int count);
void lab8();