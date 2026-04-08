#include<graphics.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");

    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0,5);

    // microphone head (ellipse)
    ellipse(300,180,0,360,50,80);

    // mic inner lines
    line(270,160,330,160);
    line(270,180,330,180);
    line(270,200,330,200);

    // holder curve
    arc(300,230,200,340,70);

    // stand
    line(300,300,300,360);

    // base
    line(260,360,340,360);

    getch();
    closegraph();
}