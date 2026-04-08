#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void drawCircle(int h, int k, int r){
    int x = 0, y = r;
    int p = 1 - r;
    while(x <= y){
        putpixel(x + h, y + k, 2);
        putpixel(y + h, x + k, 2);
        putpixel(-y + h, x + k, 3);
        putpixel(-x + h, y + k, 3);
        putpixel(-x + h, -y + k, 4);
        putpixel(-y + h, -x + k, 4);
        putpixel(y + h, -x + k, 5);
        putpixel(x + h, -y + k, 5);

        if (p < 0)
            p = p + 2 * x + 1;
        else{
            y--;
            p = p + 2 * (x - y) + 1;
        }
        x++;


    }
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int h = 400, k = 250;

    for(int r = 10; r <= 150; r += 5){
        cleardevice();        // clear screen
        drawCircle(h, k, r);  // draw circle
        delay(50); 
    }
    getch();
    closegraph();
}