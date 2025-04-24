/*
---------------------------------------------
                                ___
|    O   |----  |----  |----   |  |   | | |----
|    |   |----  |----  |  __  ||_||  |||| |----
|__  |   |      |____  |___| ||  || | | | |----
---------------------------------------------
By Arabzz, go to line 33 if you want to make your own builds
*/
#include <stdio.h>
#include <windows.h>
int vida[10][10];
int nextvida[10][10];

int calcPopulation(int i, int j) {
int population = 0;
int ii = i, jj = j;
for(i = ii-1; i <= ii+1; i++) {
for(j = jj-1; j <= jj+1; j++) {
if(i != ii || j != jj) {
if(i < 10 && j < 10 && j >= 0 && i >= 0) {
if(vida[i][j] == 1) {
population++;
}
}
}
}
}
return population;
}
int main() {
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Edit here!!!
// Warning: Edit nextvida and vida, its important!
vida[0][0] = 1;
vida[0][2] = 1;
vida[1][1] = 1;
vida[1][2] = 1;
vida[2][1] = 1;
nextvida[0][0] = 1;
nextvida[0][2] = 1;
nextvida[1][1] = 1;
nextvida[1][2] = 1;
nextvida[2][1] = 1;
// Don't edit here!!!
while(1) {
int i;
int j;
int population;
Sleep(50);
system("cls");
for(i = 0; i < 10; i++) {
for(j = 0; j < 10; j++) {
population = calcPopulation(i, j);
if(population >= 2 && population <= 3) {
if(nextvida[i][j] != 1 && population == 3) {
nextvida[i][j] = 1;
}
} else {
nextvida[i][j] = 0;
}
if(nextvida[i][j] == 0) {
printf(".");
} else if (nextvida[i][j] == 1){
SetConsoleTextAttribute(hConsole, 11);
printf("#");
SetConsoleTextAttribute(hConsole, 7);
}
}
printf("\n");
}
for(i = 0; i < 10; i++) {
for(j = 0; j < 10; j++) {
vida[i][j] = nextvida[i][j];
}
}
}
}