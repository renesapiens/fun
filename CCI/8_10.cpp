
//============================================================================
// Name        : floodfill.cpp
// Author      : Rene Sapiens
// Version     :
// Copyright   : Your copyright notice
// Description : Flooding example
//============================================================================

#include <iostream>
#include <ctime>

using namespace std;

#define SIZE 10
enum Color { Black, White, Red, Yellow, Green};


bool floodFill(int area[][SIZE], int r, int c, Color ocolor, Color ncolor);



void floodFillInit( int area[][SIZE], int r, int c, Color fcolor) {
    if(area[r][c] == fcolor)
        return;
    floodFill(area, r, c, (Color)area[r][c], fcolor);    
}

bool floodFill(int area[][SIZE], int r, int c, Color ocolor, Color ncolor) {
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE)
        return false;
    if(area[r][c] == ocolor) {
        area[r][c] = ncolor;
        floodFill(area, r - 1, c, ocolor, ncolor);
        floodFill(area, r + 1, c, ocolor, ncolor);
        floodFill(area, r, c  - 1, ocolor, ncolor);
        floodFill(area, r, c + 1, ocolor, ncolor);
    }
    return true;
}


void printArea(int area[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j =0; j < SIZE; j++) {
            cout << area[i][j] << " ";
            if (j == SIZE - 1)
                cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int area[SIZE][SIZE] = {0};

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
        area[rand()%10][rand()%10] = Green;
    printArea(area);
    floodFillInit(area, 2, 2, White);
    printArea(area);
    return 0;
}
