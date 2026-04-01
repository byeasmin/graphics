#include <graphics.h>
#include <conio.h>

void thickEllipse(int x, int y, int rx, int ry) {
    for(int i = 0; i < 6; i++) {
        ellipse(x, y, 20, 160, rx+i, ry+i);
        ellipse(x, y, 200, 340, rx+i, ry+i);
    }
}

void thickLine(int x1, int y1, int x2, int y2) {
    for(int i = -3; i <= 3; i++) {
        line(x1+i, y1, x2+i, y2);
        line(x1, y1+i, x2, y2+i);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Background
    setbkcolor(WHITE);
    cleardevice();

    setcolor(BLACK);

    // Bold outer eye
    thickEllipse(320, 240, 200, 100);

    // Bold inner circle (pupil)
    for(int i = 0; i < 6; i++) {
        circle(320, 240, 60 + i);
    }

    // Bold slash
    thickLine(180, 380, 460, 100);

    getch();
    closegraph();
    return 0;
}