// #include <graphics.h>
// #include <conio.h>

// int main() {
//     int gd = DETECT, gm;
//     initgraph(&gd, &gm, "");

//     setbkcolor(WHITE);
//     cleardevice();

//     // Draw using pixels (exact reconstruction style)
//     // Adjust starting position
//     int startX = 150;
//     int startY = 120;

//     // 🔲 Manually plotting based on your figure

//     // Shower vertical part
//     setcolor(BLACK);
//     setfillstyle(SOLID_FILL, BLACK);
//     bar(startX + 80, startY, startX + 110, startY + 120);

//     // Rounded bottom
//     fillellipse(startX + 95, startY + 120, 15, 15);

//     // Slanted pipe
//     setlinestyle(SOLID_LINE, 0, 10);
//     line(startX, startY, startX + 80, startY + 80);

//     // ===== WATER DROPS (EXACT ALIGNMENT) =====

//     // Top half circles
//     pieslice(startX + 40, startY + 150, 0, 180, 12);
//     pieslice(startX + 95, startY + 150, 0, 180, 12);
//     pieslice(startX + 150, startY + 150, 0, 180, 12);

//     // Bottom full circles
//     fillellipse(startX + 40, startY + 185, 12, 12);
//     fillellipse(startX + 95, startY + 185, 12, 12);
//     fillellipse(startX + 150, startY + 185, 12, 12);

//     getch();
//     closegraph();
//     return 0;
// }




#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    setlinestyle(SOLID_LINE, 0, 8);
    line(150, 120, 380, 120);


    line(380, 250, 380, 120);


    pieslice(380, 250, 0, 180, 60);


    setlinestyle(SOLID_LINE, 0, 6);

    int xStart = 320;
    int yStart = 310;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            int x = xStart + i * 40;
            int y = yStart + j * 40;
            line(x, y, x, y + 15);
        }
    }

    getch();
    closegraph();
    return 0;
}