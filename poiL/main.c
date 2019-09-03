//
//  main.c
//  poiL
//
//  Created by Venkatesh B h on 1/14/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int x1,x2,y11,y2;

void myInit(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}
void draw_pixel(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1,int y11,int x2,int y2){
    //glClearColor(1.0, 0.0, 0.0, 1.0);
    int dx,dy;
    dx=x1-x2;
    dy=y11-y2;
    float incx;
    float incy;
    float div;
    div=(abs(dx)>abs(dy))? abs(dx):abs(dy);
    incx=dx/div;
    incy=dy/div;
   
    float x=x1,y=y11;
    draw_pixel(x, y);
    for(int i=0;i<div;i++){
        x+=incx;
        y+=incy;
        draw_pixel(floor(x+0.5),floor(y+0.5));
    }
    
}
void myDisplay(){
    draw_line(x1, y11, x2, y2);
    glFlush();
}
int main(int argc,char **argv){
    printf("ENter x1,y1,x2,y2\n");
    scanf("%d %d %d %d",&x1,&y11,&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello World!!");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
