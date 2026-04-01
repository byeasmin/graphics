#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // ONLY background change
    setbkcolor(WHITE);   // <-- change this color as you want
    cleardevice();

    // Original drawing (unchanged)
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    bar(100, 100, 300, 140);
    arc(300, 140, 270, 360, 80);
    bar(300, 140, 340, 220);
    pieslice(320, 240, 0, 180, 80);

    int x, y;
    for (x = 260; x <= 380; x += 40) {
        for (y = 280; y <= 360; y += 40) {
            fillellipse(x, y, 8, 15);
        }
    }

    getch();
    closegraph();
    return 0;
}