#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void drawCircle(int h, int k, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r; 

    while (x <= y)
    {
        putpixel(x+h,y+k,2);
		putpixel(y+h,x+k,2);
        putpixel(-y+h,x+k,3);
		putpixel(-x+h,y+k,3);
		putpixel(-x+h,-y+k,4);
		putpixel(-y+h,-x+k,4);
		putpixel(y+h,-x+k,5);
		putpixel(x+h,-y+k,5);

        if (d < 0)
            d = d + 4*x + 6;
        else
        {
            d = d + 4*(x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int h = 400, k = 250;

    // Animation - radius gradually increases
    for(int r = 10; r <= 150; r += 5)
    {
        cleardevice();      // clear screen
        drawCircle(h, k, r);
        delay(50);          // control speed
    }

    getch();
    closegraph();
}