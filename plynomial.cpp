#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int h = 400, k = 250;  // center coordinates
    int r, x, y;

    // Animation loop: radius grows
    for(r = 10; r <= 120; r += 5)
    {
        cleardevice();  // clear previous circle

        // Use polynomial equation: x^2 + y^2 = r^2
        for(x = -r; x <= r; x++)
        {
            y = (int)sqrt(r*r - x*x);  // positive y
            putpixel(h + x, k + y, RED);  // top half
            putpixel(h + x, k - y, RED);  // bottom half
        }

        delay(50);  // control speed of animation
    }

    getch();
    closegraph();
}