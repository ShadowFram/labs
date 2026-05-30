#pragma once

#define MAXNUM(arr, n) do { int maxnum = (arr)[0]; for(int i = 1; i <(n); i++) { if((arr)[i] > maxnum) { maxnum = (arr)[i]; } } printf("maximal number: %d", maxnum); } while(0)

void lab10();
