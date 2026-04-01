#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>   // for delay()

int main()
{
    int x = 0, y, r = 120, p;
    int h = 400, k = 250;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    y = r;
    p = 1 - r;

    while(x <= y)
    {
        putpixel(x+h, y+k, 2);
        putpixel(y+h, x+k, 2);
        putpixel(-y+h, x+k, 3);
        putpixel(-x+h, y+k, 3);
        putpixel(-x+h, -y+k, 4);
        putpixel(-y+h, -x+k, 4);
        putpixel(y+h, -x+k, 5);
        putpixel(x+h, -y+k, 5);

        delay(20);   // animation speed

        x++;

        if(p < 0)
            p = p + 2*x + 1;
        else
        {
            y--;
            p = p + 2*(x - y) + 1;
        }
    }

    getch();
    closegraph();
}