// #include <graphics.h>
// #include <conio.h>

// int main()
// {
//     int gd = DETECT, gm;
//     initgraph(&gd, &gm, "");

//     // Pipe stand
//     setcolor(DARKGRAY);
//     setlinestyle(SOLID_LINE,0,6);
//     line(400,150,400,420);

//     // Pipe curve
//     arc(300,150,0,180,100);

//     // Horizontal pipe
//     line(200,150,300,150);

//     // Shower head
//     setcolor(BLACK);
//     setfillstyle(SOLID_FILL, CYAN);
//     fillellipse(200,180,70,40);

//     // Bottom red part
//     setfillstyle(SOLID_FILL, RED);
//     bar(130,200,270,215);

//     // Water drops (small lines)
//     setcolor(CYAN);
//     for(int i=150;i<=250;i+=20)
//     {
//         line(i,220,i,240);
//         line(i-10,250,i-10,270);
//         line(i+10,250,i+10,270);
//     }

//     // Big drops
//     setfillstyle(SOLID_FILL, BLUE);
//     fillellipse(170,300,10,15);
//     fillellipse(210,310,10,15);
//     fillellipse(240,295,10,15);

//     // Base stand
//     setcolor(BLACK);
//     setfillstyle(SOLID_FILL, DARKGRAY);
//     fillellipse(400,430,40,10);

//     getch();
//     closegraph();
// }




#include <GL/glut.h>
#include <math.h>

void circle(float x, float y, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i=0;i<=100;i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        glVertex2f(x + cos(angle)*r, y + sin(angle)*r);
    }
    glEnd();
}

void drawDrop(float x,float y)
{
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y);
        glVertex2f(x-5, y-12);
        glVertex2f(x+5, y-12);
    glEnd();

    circle(x,y-12,5);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // pipe color
    glColor3f(0.0,0.6,0.5);

    // vertical pipe
    glLineWidth(18);
    glBegin(GL_LINES);
        glVertex2f(400,150);
        glVertex2f(400,450);
    glEnd();

    // horizontal pipe
    glBegin(GL_LINES);
        glVertex2f(220,150);
        glVertex2f(400,150);
    glEnd();

    // shower head
    glColor3f(0.0,0.7,0.6);
    circle(200,180,60);

    // bottom red strip
    glColor3f(1.0,0.3,0.3);
    glBegin(GL_QUADS);
        glVertex2f(140,200);
        glVertex2f(260,200);
        glVertex2f(260,220);
        glVertex2f(140,220);
    glEnd();

    // water drops
    glColor3f(0.0,0.7,0.7);
    drawDrop(170,260);
    drawDrop(200,260);
    drawDrop(230,260);

    drawDrop(160,300);
    drawDrop(200,300);
    drawDrop(240,300);

    // base stand
    glColor3f(0.0,0.5,0.5);
    circle(400,470,40);

    glFlush();
}

void init()
{
    glClearColor(0.95,0.95,0.95,1);
    gluOrtho2D(0,600,600,0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Shower Graphics");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}