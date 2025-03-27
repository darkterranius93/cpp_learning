#include <iostream>
#include <cstdio>

int main() {
    char s[80];
    char y[80];
    char *p1, *p2;

    p1 = s;
    p2 = y;


    int x, *p, **q;
    x = 10;
    p = &x;
    q = &p;

    std::cout << *q <<  " " << q << std::endl;
    return 0;
}
