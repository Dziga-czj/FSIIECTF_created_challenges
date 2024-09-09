#include <stdio.h>
#include <stdlib.h>


int  compromising_function(int a, int b) {
    a = a + 1;
    b = b + 2;
    return a*b+a*a+b-5;
}

void other_compromising_function(char x){
    x = (x + rand())%255;
    putchar(x);
}

int main() {
    srand(43);
    int x = 5;
    int y = 10;
    int res = compromising_function(x, y);

    for (int i = 0; i < 258; i++)
    {
        other_compromising_function(rand()%255);
    }
    printf("leaving...\n");
    return 0;
}