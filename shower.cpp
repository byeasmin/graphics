#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Sky background
    setbkcolor(CYAN);
    cleardevice();

    // Draw rocks (left side)
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    int rock1[] = {150,100, 250,100, 230,300, 130,300};
    fillpoly(4, rock1);

    int rock2[] = {250,100, 350,120, 330,300, 230,300};
    fillpoly(4, rock2);

    // Draw water falling animation
    for(int i = 0; i < 200; i++) {
        // Clear only water area
        setfillstyle(SOLID_FILL, CYAN);
        bar(180, 100, 320, 400);

        // Water stream (moving lines)
        setcolor(WHITE);
        for(int j = 0; j < 20; j++) {
            line(200 + j*5, 100 + i, 200 + j*5, 200 + i);
        }

        // Water splash at bottom
        setcolor(LIGHTBLUE);
        circle(250, 350, 20 + (i % 10));
        circle(230, 360, 10 + (i % 5));
        circle(270, 360, 10 + (i % 5));

        delay(50);
    }

    // Ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 400, 640, 480);

    getch();
    closegraph();
    return 0;
}