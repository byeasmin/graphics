#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>   // for delay()

int main()
{
    int h = 400, k = 250, r = 120;
    float theta;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for(theta = 0; theta <= 6.28; theta += 0.01)
    {
        int x = h + r * cos(theta);
        int y = k + r * sin(theta);

        putpixel(x, y, GREEN);

        delay(1);   // animation speed
    }

    getch();
    closegraph();
}