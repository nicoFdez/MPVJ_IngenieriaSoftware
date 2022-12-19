// Jueguito1D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>

constexpr unsigned int worldSize = 30;

int main()
{
    char world[worldSize];
    world[0] = 'A';

    for (int i = 1; i < worldSize; i++) {
        world[i] = '_';
    }

    char c = ' ';
    while (c != 'q') {

		if (_kbhit()) 
            c = _getch();

        int r = rand() % 7;
        if (r == 0) {
            world[worldSize - 1] = 'E';
        }

        if (c == 'l') {
            if(world[1] == 'E') world[1] = '_';
            else world[1] = '-';
        }

        if (world[1] == 'E') {
            c = 'q';
            continue;
        }

        for (int i = 1; i < worldSize; i++) {
            if (world[i] == '-') {
                world[i] = '_';
                if (i + 2 < worldSize && world[i + 2] == 'E') {
                    world[i + 2] = '_';
                }
                else if (i + 1 < worldSize && world[i + 1] == 'E') {
                    world[i + 1] = '_';
                }
                else if (i + 1 < worldSize) {
                    world[i + 1] = '-';
                    i++;
                }
            }
            else if (world[i] == 'E') {
                world[i - 1] = 'E';
                world[i] = '_';
            }
        }

        for (int i = 0; i < worldSize; i++) {
            printf("%c", world[i]);
        }

		if(c != 'q') c = ' ';
		Sleep(250);
		system("CLS");
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
