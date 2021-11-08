#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, ".1251");
    FILE* f = fopen("1.txt", "r");
    char* wave;
    char ch[100];
    int c = -1,
        max = strtoll(argv[2], &wave, 20);
    cout << "Authentic file:\n";
    while (true)
    {
        c++;
        ch[c] = fgetc(f);
        if (ch[c] == EOF)
            break;
        cout << ch[c] << " ";
    }
    fclose(f);
    f = fopen("2.txt", "w");
    cout << "\nUpdated file:\n";
    for (int i = 0; i < c; i++) {
        if (i == max) {
            fprintf(f, "Y");
            cout << "Y";
        }
        fprintf(f, "%c", ch[i]);
        cout << ch[i] << " ";
    }
    if (c <= max) {
        fprintf(f, "Y");
        cout << "Y";
    }
    fclose(f);
    return 0;
}