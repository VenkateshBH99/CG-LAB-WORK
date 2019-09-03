
#include<stdio.h>
#include<GLUT/GLUT.h>
#include<iostream>

GLfloat x[10],y[10];
int n;
void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re)
{
    float mx,x,temp;
    int i;
    if((y2-y1)<0)
    {
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    if((y2-y1)!=0)
        mx=(x2-x1)/(y2-y1);
    else
        mx=x2-x1;
    x=x1;
    for(i=(int)y1;i<(int)y2;i++)
    {
        if(x<(float)le[i])
            le[i]=(int)x;
        if(x>(float)re[i])
            re[i]=(int)x;
        x+=mx;
    }
}

void drawpixel(int x,int y)
{
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void scanfill(GLfloat *x,GLfloat *y)
{
    int le[500],re[500];
    int i,j;
    for(i=0;i<500;i++)
    {
        le[i]=500;
        re[i]=0;
    }
    
    for(int k=0;k<n-1;k++)
    {
        edgedetect(x[k],y[k],x[k+1],y[k+1],le,re);
    }
    edgedetect(x[n-1],y[n-1],x[0],y[0],le,re);
    
    for(j=0;j<500;j++)
    {
        if(le[j]<=re[j])
            for(i=le[j]+1;i<re[j];i++)
                drawpixel(i,j);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int k=0;k<n;k++)
    {
        glVertex2f(x[k],y[k]);
    }
    glEnd();
    
    scanfill(x,y);
    
    glFlush();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    gluOrtho2D(0,499,0,499);
}

using namespace std;

int main(int argc,char **argv)
{
    cout<<"Enter the number of edges of the polygon : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("Enter line %d co-ordinates :  ",(i+1));
        cin>>x[i]>>y[i];
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scaline Polyfill");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
