//
//  main.c
//  ellipse
//
//  Created by Venkatesh B h on 2/9/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
static int x1,y1,a,b;
void myInit(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
    
}
void draw_pixel(int x,int y){
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x+x1,y+y1);
    glEnd();
}
void points(int x,int y){
    draw_pixel(x, y);
    draw_pixel(x, -y);
    draw_pixel(-x, -y);
    draw_pixel(-x, y);
    
}
void draw_ellipse(){
    double d2;
    int x=0,y=b;
    int sa=a*a;
    int sb=b*b;
    double d1=sb-sa*b+0.25*sa;
    points(x, y);
    while(sa*(y-0.5)>sb*(x+1)){
        if(d1<0){
            d1+=sb*((x<<1)+3);
        }
        else{
            d1+=sb*((x<<1)+3)+sa*(-(y<<1)+2);
            y--;
        }
        x++;
        points(x, y);
    }
    d2=sb*(x)*(x)+sa*(y)*(y)-sa*sb;
    while(y>0){
        if(d2<0){
            d2+=sb*((x<<1)+2)+sa*(-(y<<1)+3);
            x++;
        }
        else{
            d2+=sa*(-(y<<1)+3);
        }
        y--;
        points(x, y);
    }
    
}
void myDisplay(void){
    
    draw_ellipse();
    glFlush();
}
int main(int argc,char **argv){
    printf("Enter a,b,x1,y1\n");
    scanf("%d%d%d%d",&a,&b,&x1,&y1);
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


