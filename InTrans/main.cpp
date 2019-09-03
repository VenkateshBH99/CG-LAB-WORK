
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<GLUT/glut.h>

using namespace std;

int pntX1, pntY1,choice=0,edges;
vector<int> pntX;
vector<int> pntY;
double angle,angleRad;
//GLfloat transX, transY;
int transX,transY;
float scaleX,scaleY,shearingX,shearingY;
char reflectionAxis,shearingAxis;

void drawPolygon()
{
    glBegin(GL_POLYGON);
    for (int i=0;i<edges;i++)
    {
        glVertex2i(pntX[i],pntY[i]);
    }
    glEnd();
}


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
   
    gluOrtho2D(-640.0,640.0,-480.0,480.0);
}
void drawPolygonMirrorReflection(char reflectionAxis)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    if(reflectionAxis=='x'||reflectionAxis=='X')
    {
        for(int i=0;i<edges;i++)
        {
            glVertex2i(round(pntX[i]),round(pntY[i]*-1));
            
        }
    }
    else if(reflectionAxis=='y'||reflectionAxis=='Y')
    {
        for(int i=0;i<edges;i++)
        {
            glVertex2i(round(pntX[i]*-1),round(pntY[i]));
        }
    }
    glEnd();
}
void drawPolygonShearing(char shearingAxis)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    
    if(shearingAxis=='x'||shearingAxis=='X')
    {
        glVertex2i(pntX[0], pntY[0]);
        glVertex2i(pntX[1] + shearingX, pntY[1]);
        glVertex2i(pntX[2] + shearingX, pntY[2]);
        glVertex2i(pntX[3], pntY[3]);
    }
    else if (shearingAxis == 'y' || shearingAxis == 'Y')
    {
        glVertex2i(pntX[0], pntY[0]);
        glVertex2i(pntX[1], pntY[1]);
        glVertex2i(pntX[2], pntY[2] + shearingY);
        glVertex2i(pntX[3], pntY[3] + shearingY);
    }
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    if(choice==1)
    {
        
        drawPolygon();
        
        glTranslatef(transX,transY,0.0);
        glColor3f(0.0,1.0,0.0);
        drawPolygon();
       
    }
    if(choice==2)
    {
        drawPolygon();
        glRotatef(angleRad,0.0,0.0,1.0);
        glColor3f(0.0,1.0,0.0);
        drawPolygon();
        
        
    }
    if(choice==3)
    {
        drawPolygon();
        glScalef(scaleX, scaleY, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        drawPolygon();
        
    }
    if(choice==4)
    {
        drawPolygon();
        drawPolygonMirrorReflection(reflectionAxis);
    }
    else if(choice==5)
    {
        drawPolygon();
        drawPolygonShearing(shearingAxis);
    }
     glPopMatrix();
    glFlush();
}

int main(int argc,char**argv)
{
    cout<<"Enter your choice:\n\n"<<endl;
    cout<<"1. Translation"<<endl;
    cout<<"2. Rotation"<<endl;
    cout<<"3.Scaling"<<endl;
    cout<<"4.Reflection"<<endl;
    cout<<"5.Shearing"<<endl;
    cout<<"6. Exit"<<endl;
    cin >> choice;
    if(choice==6)
    {
        return 0;
    }
    cout<<"\n\nFor Polygon:\n"<<endl;
    cout<<"Enter no of edges : ";
    cin>>edges;
    
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter co-ordinates for vertex "<<i+1<<" : ";
        cin>>pntX1>>pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }
    if(choice==1)
    {
        cout<<"Enter the translation factor for X and Y : ";
        cin>>transX>>transY;
    }
    if(choice==2)
    {
        cout<<"Enter the angle of rotation : ";
        cin>>angle;
        angleRad=angle;
    }
    if(choice==3)
    {
        cout<<"Enter the scaling factors:";
        cin>>scaleX>>scaleY;
        
    }
    if(choice==4)
    {
        cout<<"Enter reflection axis ( x or y ) : ";
        cin>>reflectionAxis;
    }
    else if(choice==5)
    {
        cout<<"Enter shearing axis ( x or y ) : ";
        cin>>shearingAxis;
        if(shearingAxis=='x'||shearingAxis=='X')
        {
            cout<<"Enter the shearing factor for X : ";
            cin>>shearingX;
        }
        else
        {
            cout<<"Enter the shearing factor for Y : ";
            cin>>shearingY;
        }
    }
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,150);
    glutCreateWindow("Basic Transformations Using Inbuilt Functions");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
