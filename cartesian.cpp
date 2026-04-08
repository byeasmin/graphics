#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int h = 400, k = 250;
    int r = 120;

    int x;
    for(x = -r; x <= r; x++)
    {
        int y = sqrt(r*r - x*x);

        // upper half
        putpixel(h + x, k + y, GREEN);

        // lower half
        putpixel(h + x, k - y, GREEN);
    }

    getch();
    closegraph();
}