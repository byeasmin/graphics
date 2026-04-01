#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Background (optional white)
    setbkcolor(WHITE);
    cleardevice();

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    // Top oval (microphone head)
    fillellipse(250, 150, 60, 70);

    // Bottom oval (slightly overlapping)
    fillellipse(250, 220, 60, 70);

    // Middle cut (white rectangle)
    setfillstyle(SOLID_FILL, WHITE);
    bar(190, 180, 310, 200);

    // Side vertical rounded bars
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(160, 230, 10, 50);
    fillellipse(340, 230, 10, 50);

    // Bottom U-shape arc
    setcolor(BLACK);
    setlinestyle(SOLID_LINE, 0, 3);
    arc(250, 260, 200, 340, 120);

    // Stand line
    line(250, 340, 250, 390);

    // Base
    setfillstyle(SOLID_FILL, BLACK);
    bar(220, 390, 280, 410);

    getch();
    closegraph();
    return 0;
}