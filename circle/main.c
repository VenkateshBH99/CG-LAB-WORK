
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int r,x1,y1;


void myInit(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,500.0,0.0,500.0);
    
}

void draw_pixel(int x, int y) {
    
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x+x1, y+y1);
    glEnd();
}

void draw_line() {
    float h=5/4-r;
    int x=0,y=r;
    draw_pixel(x, y);
    while(y>x){
        if(h<0){
            x++;
            h+=2*x+3;
        }
        else{
            x++;
            y--;
            h+=2*x-2*y+5;
        }
        draw_pixel(x, y);
        draw_pixel(x, -y);
        draw_pixel(-x, y);
        draw_pixel(-x, -y);
        draw_pixel(y, x);
        draw_pixel(-y, x);
        draw_pixel(y, -x);
        draw_pixel(-y, -x);
    }
}

void myDisplay(void) {
    
    draw_line();
    glFlush();
}

int main(int argc, char **argv) {
    
    printf( "Enter r x1 y1\n");
    scanf("%d%d%d", &r,&x1,&y1);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
   
    
    
    glutMainLoop();
    return 0;
}
/***int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);
    
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    
    midPointCircleAlgo();
    
    glFlush ();
}

void main(int argc, char** argv)
{
    printf("ENtre r,x,y\n");
    scanf("%d%d%d",&r,&pntX1,&pntY1);
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Line Drawing Alogrithms");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
    
}***/

