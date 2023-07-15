#include <GL/gl.h> //checkinfo
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h>
#define PI 3.1415926535897323846



float _move_sun = 1.00f;
float _move_cloud_1 = 0.00f;
float _move_cloud_2 = 0.00f;


float _move_car1_1 = -1.2f;////ME
float _move_boat_1 = -1.2f;////ME


float _speed_cloud_1 = 0.0025f;
float _speed_cloud_2 = 0.0025f;
float _move_plane_1 = 0.00f;
float _speed_plane_1 = 0.0025f;



float _speed_car1_1 = 0.0025f;////ME
float _speed_boat_1 = 0.0025f;////ME


GLfloat positionRain = 0.0f;
bool night = false;
bool rainday = false;
float _rain = 0.0f;//float speed = 0.1f;
GLfloat i = 0.0f;
GLfloat r = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.0025f;


void Rain()
{
if(rainday)
    {
    glPushMatrix();
    glTranslatef(0.0, 0.5f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0, -positionRain, 0.0f);
    GLfloat xR= -0.09;
    GLfloat yR = 2.45;

    glBegin(GL_LINES);
    glColor3ub(18, 18, 18);
    for(int i=0;i<=105;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.01,yR-.04);

    xR += .04;
    }
    glEnd();

    for(int j=0;j<=250;j++)
    {
    xR = -1.0;
    yR= yR-.09;
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<=250;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.04);

    xR += .02;
    }
    glEnd();
    }
    glPopMatrix();
    }
}


/// cloud part update

void update_cloud_1(int value) {
    if(_speed_cloud_1>1.00f || _speed_cloud_1<0.00f)    // loop means round kore move korte se plus time loop
    {
        _speed_cloud_1 = 0.0f;
    }
    _move_cloud_1 += _speed_cloud_1;
    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_1, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update_cloud_2(int value) {
    if(_speed_cloud_2>1 || _speed_cloud_2<0)
    {
        _speed_cloud_2 = 0.0f;
    }
    _move_cloud_2 -= _speed_cloud_2;
    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_2, 0); //Notify GLUT to call update again in 25 milliseconds
}

///sun update

void update_sun(int value)  // sun r position change with time
{
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < -1.0)
    {
        _move_sun = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_sun, 0);
}

void update_plane(int value)
{
    if(position > 1.6)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();

	glutTimerFunc(20, update_plane, 0);
}
void update_plane1(int value)
{
    if(position > 1.6)
        position = -1.2f;

    position -= speed;

	glutPostRedisplay();

	glutTimerFunc(20, update_plane1, 0);
}





  /// 2 car update
void update_car1_t43(int value)
{
    _move_car1_1 -= 0.0025f;
    if(_move_car1_1+1.1 < -1.0)
    {
        _move_car1_1 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car1_t43, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update1_car1_t43(int value)    // 2nd car up
{
    _move_car1_1 += 0.0025f;
    if(_move_car1_1+1.1 < -1.0)
    {
        _move_car1_1 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update1_car1_t43, 0); //Notify GLUT to call update again in 25 milliseconds
}
 /// boat update
void update_boat(int value)
{
    _move_boat_1 += 0.0025f;
    if(_move_boat_1+1.1 < -1.0)
    {
        _move_boat_1 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

	//glutTimerFunc(20, update_boat, 0); //Notify GLUT to call update again in 25 milliseconds
}











void star()
{
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
}
/// key for move car

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          update_car1_t43(0);


          break;
      case GLUT_KEY_DOWN:
          glutTimerFunc(20, update1_car1_t43, 0);
          break;
    }
}
///cloud and plane move with time loop
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
      case 65:
          _speed_cloud_1+=0.0025f;
          update_cloud_1(0);
          break;
      case 97:
          _speed_cloud_1-=0.0025f;
          update_cloud_1(0);

          break;
           case 100:
          _speed_cloud_2+=0.0025f;
          update_cloud_2(0);
          break;
      case 101:
          _speed_cloud_2-=0.0025f;
          update_cloud_2(0);

          break;
            case 67:
          _speed_plane_1+=0.0025f;
          update_plane(0);
          break;
      case 68:
          _speed_plane_1-=0.0025f;
          update_plane1(0);

          break; }

 if(key=='n')
    {
      night=true;
      glutPostRedisplay();
    }
    if(key=='o')
    {
      night=false;
      glutPostRedisplay();
    }


     if(key=='s')
    {
        glPushMatrix();
    rainday = true;
    Rain();
    glPopMatrix();
    glFlush();
     glutPostRedisplay();
    }

     if(key=='l')
    {
        glPushMatrix();
    rainday = false;
    Rain();
    glPopMatrix();
    glFlush();
     glutPostRedisplay();
    }

  if(key=='j')
    {
        _speed_boat_1+=0.0025f;
          update_boat(0);

    }


}




/// Sky

void sky()      /// sun r shate shate aky r colour change r code
{
    if(_move_sun<=1.00f && _move_sun>=0.90f)
    {
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
        night=false;
    }
    else if(_move_sun<0.90f && _move_sun>=0.55f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.55f && _move_sun>=0.35f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.961, 0.933);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.35f && _move_sun>=0.25f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.855, 0.725);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.25f && _move_sun>=0.10f)
    {
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.10f && _move_sun>=0.0f)
    {
        glBegin(GL_QUADS);
        glColor3f(1.000, 0.388, 0.278);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else

    {
        glBegin(GL_QUADS);
        glColor3f(0.412, 0.412, 0.412);

        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);

        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();

        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glTranslatef(0.80,1.05,0);
        glScalef(0.6,1,1);
        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);// moon
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }      /// night a star r asar jonno
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.95,0.95,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.75,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.65,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.60,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.93,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.10,0.67,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.15,0.67,0);

        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.35,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25,0.73,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.72,0.63,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.05,0.43,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(0.15,0.13,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-0.15,0.88,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.65,0.73,0);
        star();
        glPopMatrix();
        night=true;
    }
}

                                                   ///Field

void field_1()
{
    //field 1
    glBegin(GL_QUADS);

    if(night==true)
    {
         glColor3f(0.2,0.2,0.0);
    }
    else
  //  glColor3f(0.196, 0.804, 0.196);


    if(night==true)
    {
         glColor3f(0.2,0.2,0.0);
    }
    else
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(1.0, -0.60);

    if(night==true)
    {
         glColor3f(0.2,0.2,0.0);
    }
    else
    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.60);

    if(night==true)
    {
         glColor3f(0.2,0.2,0.0);
    }
    else
    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, 0.135);

    if(night==true)
    {
        glColor3f(0.2,0.2,0.0);
    }
    else
    //glColor3f(0.498, 1.000, 0.000);
    glColor3f(0.0, 0.0, 0.1);
    glVertex2f(1.0, 0.135);

    glEnd();}


    void roadStrips()       // majer sada dak
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.30);
    glVertex2f(-0.95, -0.32);
    glVertex2f(-0.65, -0.32);
    glVertex2f(-0.65, -0.30);
    glEnd();
}
    void road()
    {
    //Main road lane 1
    glBegin(GL_QUADS);
     if(night==true)
    {
        glColor3f(0.4,0.4,0.5);
    }
    else

    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-1.0, -0.50);
    glVertex2f(1.0, -0.50);
    glVertex2f(1.0, -0.12);
    glEnd();
    //Main Road Strips 1
    roadStrips();

    //Main Road Strips 2
    glPushMatrix();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glPopMatrix();
}



/// add car1 1,2, bort              ////ME
void car1(){



    glPushMatrix();
     glScalef(0.4, 0.4, 0.0);
         glTranslatef(0.0f,-0.4f, 0.0f);

    glTranslatef(_move_car1_1,0.0f, 0.0f);



    //car1  Body part -2
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3ub(110,44,0);
    }
    else

    glColor3ub(145,29,4);
    //glColor3ub(1,0,0);////////////////
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.55f,  0.0f);
    glVertex2f(0.35f,  0.0f);
    glEnd();

    //car1  Body part -3
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3ub(110,44,0);
    }
    else
    glColor3ub(145,29,4);
   // glColor3ub(1,0,0);////////////////
    glVertex2f(0.23f, -0.1f);
    glVertex2f(0.65f, -0.1f);
    glVertex2f(0.65f, -0.3f);
    glVertex2f(0.2f, -0.3f);
    glEnd();

   ///car1  Window -1
    glBegin(GL_QUADS);
   if(night==true)
    {
        glColor3ub(255, 243, 224);
    }
    else
    glColor3ub(33,33,33);
    glVertex2f(0.45f, -0.025f);
    glVertex2f(0.35f, -0.025f);
    glVertex2f(0.3f, -0.10f);
    glVertex2f(0.45f, -0.10f);
    glEnd();

    //car1  Window -2
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3ub(255, 243, 224);
    }
    else
    glColor3ub(33,33,33);
    glVertex2f(0.55f, -0.025f);
    glVertex2f(0.5f, -0.025f);
    glVertex2f(0.5f, -0.10f);
    glVertex2f(0.6f, -0.10f);
    glEnd();



    //car1  wheel -1
    int i;
    GLfloat x = 0.3f;//right , left
    GLfloat y = -0.326f;//69
    GLfloat radius = 0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);// triangle for circle
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),// CIRCLE
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //wheel -4
    x = 0.55f;
    y = -0.326f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
  //car1 wheel
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(0.2f, -0.31f);
    glVertex2f(0.65f, -0.31f);
    glEnd();
    glPopMatrix();



/////car1 2nd





     glPushMatrix();
     glScalef(0.4, 0.4, 0.0);
         glTranslatef(0.0f,-0.4f, 0.0f);

    glTranslatef(_move_car1_1,0.0f, 0.0f);



    //car1 Body part -2
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3ub(74, 20, 140 );
    }
    else
    glColor3ub(210,191,209);
    glVertex2f(0.3f+0.8f, -0.1f);
    glVertex2f(0.6f+0.8f, -0.1f);
    glVertex2f(0.55f+0.8f,  0.0f);
    glVertex2f(0.35f+0.8f,  0.0f);
    glEnd();

    //car1 Body part -3
    glBegin(GL_QUADS);
     if(night==true)
    {
        glColor3ub(74, 20, 140 );
    }
    else
    glColor3ub(168,13,167);
    glVertex2f(0.23f+0.8f, -0.1f);
    glVertex2f(0.65f+0.8f, -0.1f);
    glVertex2f(0.65f+0.8f, -0.3f);
    glVertex2f(0.2f+0.8f, -0.3f);
    glEnd();

   ///car1  Window -1
    glBegin(GL_QUADS);

    if(night==true)
    {
        glColor3ub(158, 158, 158);
    }
    else
    glColor3ub(210,224,190);
    glVertex2f(0.45f+0.8f, -0.025f);
    glVertex2f(0.35f+0.8f, -0.025f);
    glVertex2f(0.3f+0.8f, -0.10f);
    glVertex2f(0.45f+0.8f, -0.10f);
    glEnd();

    //car1  Window -2
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3ub(158, 158, 158);
    }
    else
    glColor3ub(210,224,190);
    glVertex2f(0.55f+0.8f, -0.025f);
    glVertex2f(0.5f+0.8f, -0.025f);
    glVertex2f(0.5f+0.8f, -0.10f);
    glVertex2f(0.6f+0.8f, -0.10f);
    glEnd();



    //car1wheel -1


   x = 0.3f+0.8f;

    y = -0.326f;

     radius = 0.06f;

    triangleAmount = 20;

    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //car1 wheel -4
    x = 0.55f+0.8f;
    y = -0.326f;
    radius = 0.06f;
    triangleAmount = 20;
    twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,60,43);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f
        (
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
  //car1 wheel -2
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(44,60,43);
    glVertex2f(0.2f+0.8f, -0.31f);
    glVertex2f(0.65f+0.8f, -0.31f);
    glEnd();
    glPopMatrix();



}
                                                       ///boat
void boat()
{

 glPushMatrix();
     glScalef(0.4, 0.4, 0.0);
         glTranslatef(0.0f,-0.4f, 0.0f);

    glTranslatef(_move_boat_1,0.0f, 0.0f);
//lower part
     glBegin(GL_POLYGON);
     if(night==true)
    {
        glColor3ub(62, 39, 35);
    }
    else
    glColor3ub(113,5,22);
    glVertex2f(0.2f, -0.8f-0.7f);
    glVertex2f(0.75f, -0.8f-0.7f);
    glVertex2f(0.7f,  -0.9f-0.8f);
    glVertex2f(0.25f,  -0.9f-0.8f);
    glEnd();

    //upper part
      glBegin(GL_POLYGON);
       if(night==true)
    {
        glColor3ub(102, 0, 0);
    }
    else
    glColor3ub(219,154,164);
    glVertex2f(0.3f, -0.7f-0.7f);
    glVertex2f(0.55f, -0.7f-0.7f);
    glVertex2f(0.55f,  -0.8f-0.8f);
    glVertex2f(0.3f,  -0.8f-0.8f);
    glEnd();
glPopMatrix();

}


/// *********
void sun_circle()
{
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
}

                                               ///Sun and moon with time loop
void sun()
{

    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

    if(_move_sun<=1.00 && _move_sun>=0.90f)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.90f && _move_sun>=0.80f)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.80 && _move_sun>=0.65)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 1.000, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.65 && _move_sun>=0.45)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.45 && _move_sun>=0.25){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else if(_move_sun<0.25 && _move_sun>=0.0)
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.549, 0.000);
        sun_circle();
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.271, 0.000);
        sun_circle();
        glPopMatrix();
    }
}


void cloud_struct()
{
    if(NULL)
    {

    }
    else
    {

        if(night==true)
    {
        glColor3f(0.6,0.6,0.7);
    }
    else
         glColor3f(1.000, 1.000, 1.000);
    }
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

}


                                     ///Cloud

void cloud_left()
{
    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.78,0.82,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.74,0.87,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.70,0.91,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.65,0.88,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.61,0.80,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.68,0.77,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.75,0.78,0);
    cloud_struct();
    glPopMatrix();
}

void cloud_right()
{
    //Cloud on the right
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.78,0.70,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.74,0.75,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.70,0.79,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.65,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.61,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.68,0.65,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.63,0.66,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.75,0.66,0);
    cloud_struct();
    glPopMatrix();
}
                                           ///river
void river()
{
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.0,0.0,0.1);
    }
    else
    glColor3f(0.000, 1.000, 1.000);

    glVertex2f(1.0, -0.60);
   if(night==true)
    {
        glColor3f(0.0,0.0,0.5);
    }
    else
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-1.0, -0.60);

     if(night==true)
    {
        glColor3f(0.0,0.0,0.1);
    }
    else
    glColor3f(0.498, 1.000, 0.831);
    glVertex2f(-1.0, -1.0);

    if(night==true)
    {
        glColor3f(0.0,0.0,0.5);
    }
    else
    glColor3f(0.1, 0.820, 0.800);
    glVertex2f(1.0, -1.0);

    glEnd();
}
                                                     ///plane

void planeWindow()
{
   glBegin(GL_POLYGON);

    if(night==true)
    {
        (glColor3f(1.0,1.0,1.0));
    }
    else
    glColor3f(0.00, 0.00, 0.0);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, -0.1f);
   glEnd();
}

void plane()
{
    glBegin(GL_TRIANGLES);
     if(night==true)
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else

    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.9f, 0.0f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.2f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);          /// plane r body
     if(night==true)
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else
    glColor3f(1.00, 1.00, 1.0);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);         /// plane r dana

     if(night==true)
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else
    glColor3f(0.000, 0.5, 1.000);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);         /// plane r pakha
     if(night==true)
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else
    glColor3f(0.000, 0.5, 1.000);

    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.3f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
     if(night==true)
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else
    glColor3f(0.000, 0.5, 1.000);

   if(night==true)                         /// plane r pakha
    {
        (glColor3f(0.1,0.0,0.3));
    }
    else

    glColor3f(0.000, 0.5, 1.000);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(0.2f, 0.0f);
    glEnd();

    glPushMatrix();
    glScalef(0.2, 0.4, 0.0);
    glTranslatef( 0.3, 0.32, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glPopMatrix();
}


void red_building(){
                                          ///Red Building
    glBegin(GL_QUADS);
      if(night==true)
    {
        glColor3f(0.4,0.0,0.1);
    }
    else

    glColor3f(0.698, 0.133, 0.133);

    glVertex2f(-0.95, -0.05);
    glVertex2f(-0.75, -0.05);
    glVertex2f(-0.75, 0.45);
    glVertex2f(-0.95, 0.45);

    //Door of Red Building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.0,0.1,0.1);
    }
    else
    glColor3f(1.000,1.0,1.0);
    glVertex2f(-0.90, -0.05);
    glVertex2f(-0.80, -0.05);
    glVertex2f(-0.80, 0.15);
    glVertex2f(-0.90, 0.15);

    //2 Window of Red Building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(204.0,204.0,0.0);
    }
    else
    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(-0.93, 0.26);
    glVertex2f(-0.88, 0.26);
    glVertex2f(-0.88, 0.36);
    glVertex2f(-0.93, 0.36);

    glBegin(GL_QUADS);
    if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.82, 0.26);
    glVertex2f(-0.77, 0.26);
    glVertex2f(-0.77, 0.36);
    glVertex2f(-0.82, 0.36);

    //Roof top of red building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.93, 0.45);
    glVertex2f(-0.87, 0.45);
    glVertex2f(-0.87, 0.52);
    glVertex2f(-0.93, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.94, 0.52);
    glVertex2f(-0.86, 0.52);
    glVertex2f(-0.86, 0.54);
    glVertex2f(-0.94, 0.54);

    glEnd();
}                                                              ///Blue Building

void blue_building(){

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex2f(-0.65, -0.05);
    glVertex2f(-0.45, -0.05);
    glVertex2f(-0.45, 0.45);
    glVertex2f(-0.65, 0.45);

    //Door of blue building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.0,0.1,0.1);
    }
    else
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.63, -0.05);
    glVertex2f(-0.57, -0.05);
    glVertex2f(-0.57, 0.15);
    glVertex2f(-0.63, 0.15);

    //Little window of blue building
    glBegin(GL_QUADS);
     if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.53, 0.03);
    glVertex2f(-0.48, 0.03);
    glVertex2f(-0.48, 0.13);
    glVertex2f(-0.53, 0.13);

    //Big window of blue building
    glBegin(GL_QUADS);

     if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-0.63, 0.25);
    glVertex2f(-0.47, 0.25);
    glVertex2f(-0.47, 0.36);
    glVertex2f(-0.63, 0.36);

    glBegin(GL_QUADS);

    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.63, 0.31);
    glVertex2f(-0.63, 0.30);
    glVertex2f(-0.47, 0.30);
    glVertex2f(-0.47, 0.31);

    glBegin(GL_QUADS);

    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.555, 0.36);
    glVertex2f(-0.555, 0.25);
    glVertex2f(-0.545, 0.25);
    glVertex2f(-0.545, 0.36);

    //Roof top of blue building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.46, 0.45);
    glVertex2f(-0.52, 0.45);
    glVertex2f(-0.52, 0.52);
    glVertex2f(-0.46, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.45, 0.52);
    glVertex2f(-0.53, 0.52);
    glVertex2f(-0.53, 0.54);
    glVertex2f(-0.45, 0.54);

    glEnd();
}




///  tree


void tree()
{
  glBegin(GL_QUADS);

   // glColor3f();

    if(night==true)
    {
        glColor3f(0.4,0.1,0.0);
    }
    else

    glColor3f(0.4,0.1,0.0);
    glVertex2f(-0.02, -0.05);
    glVertex2f(-0.01, -0.05);
    glVertex2f(-0.01, 0.15);
    glVertex2f(-0.02, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);

   // glColor3f();
    if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
     glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08,0.10);
    glVertex2f(0.06,0.10);
    glVertex2f(-0.01,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06,0.15);
    glVertex2f(0.04,0.15);
    glVertex2f(-0.015,0.25 );

    glEnd();

  ////////////


  glBegin(GL_QUADS);

   // glColor3f();
    glColor3ub(90.0,28.0,28.0);
    glVertex2f(-0.02+0.08, -0.05);
    glVertex2f(-0.01+0.08, -0.05);
    glVertex2f(-0.01+0.08, 0.15);
    glVertex2f(-0.02+0.08, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08+0.08,0.10);
    glVertex2f(0.06+0.08,0.10);
    glVertex2f(-0.01+0.08,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
   glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06+0.08,0.15);
    glVertex2f(0.04+0.08,0.15);
    glVertex2f(-0.015+0.08,0.25 );

    glEnd();

////////


  glBegin(GL_QUADS);

   // glColor3f();
    glColor3ub(90.0,28.0,28.0);
    glVertex2f(-0.02+0.3, -0.05);
    glVertex2f(-0.01+0.3, -0.05);
    glVertex2f(-0.01+0.3, 0.15);
    glVertex2f(-0.02+0.3, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
   glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08+0.3,0.10);
    glVertex2f(0.06+0.3,0.10);
    glVertex2f(-0.01+0.3,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06+0.3,0.15);
    glVertex2f(0.04+0.3,0.15);
    glVertex2f(-0.015+0.3,0.25 );

    glEnd();

    //////

     glBegin(GL_QUADS);

   // glColor3f();
    glColor3ub(90.0,28.0,28.0);
    glVertex2f(-0.02+0.4, -0.05);
    glVertex2f(-0.01+0.4, -0.05);
    glVertex2f(-0.01+0.4, 0.15);
    glVertex2f(-0.02+0.4, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
   glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08+0.4,0.10);
    glVertex2f(0.06+0.4,0.10);
    glVertex2f(-0.01+0.4,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06+0.4,0.15);
    glVertex2f(0.04+0.4,0.15);
    glVertex2f(-0.015+0.4,0.25 );

    glEnd();


    ///

        glBegin(GL_QUADS);

   // glColor3f();
    glColor3ub(90.0,28.0,28.0);
    glVertex2f(-0.02+0.7, -0.05);
    glVertex2f(-0.01+0.7, -0.05);
    glVertex2f(-0.01+0.7, 0.15);
    glVertex2f(-0.02+0.7, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
     glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08+0.7,0.10);
    glVertex2f(0.06+0.7,0.10);
    glVertex2f(-0.01+0.7,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
     glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06+0.7,0.15);
    glVertex2f(0.04+0.7,0.15);
    glVertex2f(-0.015+0.7,0.25 );

    glEnd();

    ///
        glBegin(GL_QUADS);

   // glColor3f();
    glColor3ub(90.0,28.0,28.0);
    glVertex2f(-0.02-0.7, -0.05);
    glVertex2f(-0.01-0.7, -0.05);
    glVertex2f(-0.01-0.7, 0.15);
    glVertex2f(-0.02-0.7, 0.15);
    glEnd();

     glBegin(GL_TRIANGLES);
if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.08-0.7,0.10);
    glVertex2f(0.06-0.7,0.10);
    glVertex2f(-0.01-0.7,0.20 );

    glEnd();

      glBegin(GL_TRIANGLES);
   if(night==true)
    {
        glColor3f(0.0,0.3,0.0);
    }
    else
   // glColor3f();
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-0.06-0.7,0.15);
    glVertex2f(0.04-0.7,0.15);
    glVertex2f(-0.015-0.7,0.25 );

    glEnd();
}
                                                      ///phone_box
void phone_box(){
    //Phone Box
    glBegin(GL_QUADS);
     if(night==true)
    {
        glColor3f(0.3,0.0,0.2);
    }
    else
   glColor3f(1,0,0);

    glVertex2f(-0.41, -0.05);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.41, 0.15);

    //Window of Phone Box
    glBegin(GL_QUADS);
     if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(1,1,1);

    glVertex2f(-0.40, 0.02);
    glVertex2f(-0.35, 0.02);
    glVertex2f(-0.35, 0.13);
    glVertex2f(-0.40, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(-0.38, 0.02);
    glVertex2f(-0.38, 0.13);

    glVertex2f(-0.37, 0.02);
    glVertex2f(-0.37, 0.13);

    glVertex2f(-0.40, 0.07);
    glVertex2f(-0.35, 0.07);

    glVertex2f(-0.40, 0.08);
    glVertex2f(-0.35, 0.08);
    glEnd();

    //Top of Phone Box
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    glVertex2f(-0.41, 0.15);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.36, 0.17);
    glVertex2f(-0.39, 0.17);
    glEnd();

}
                                                           ///twin tower

void tower(){
    glBegin(GL_QUADS);

    if(night==true)
    {
        glColor3f(204.0,204.0,0.0);
    }
    else
    glColor3f(1.0, 1.0, 1.0);
    if(_move_sun<0.10 || _move_sun>0.90)
    {
        glColor3f(2.0, 2.0, 2.0);
    }
    glVertex2f(-0.28, -0.03);
    glVertex2f(-0.20, -0.03);
    glVertex2f(-0.20, 0.05);
    glVertex2f(-0.28, 0.05);
    glEnd();

}

void twin_tower(){
    //Tower 1 of twin tower
    glBegin(GL_QUADS);
   if(night==true)
    {
        glColor3f(0.4,0.1,0.0);
    }
    else
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.30, -0.05);
    glVertex2f(-0.08, -0.05);
    glVertex2f(-0.08, 0.60);
    glVertex2f(-0.30, 0.60);
    glEnd();

    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.4,0.1,0.0);
    }
    else
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.31, 0.60);
    glVertex2f(-0.07, 0.60);
    glVertex2f(-0.07, 0.62);
    glVertex2f(-0.31, 0.62);
    glEnd();
    //Roof top of tower 1


    //1st floor window of tower 1
    tower();

   glPushMatrix();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.10,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();


    //Tower 2 of twin tower
    glBegin(GL_QUADS);

    if(night==true)
    {
        glColor3f(0.4,0.1,0.0);
    }
    else
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.08, -0.05);
    glVertex2f(0.30, -0.05);
    glVertex2f(0.30, 0.60);
    glVertex2f(0.08, 0.60);
    glEnd();

    //Roof top of tower 2
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(0.31, 0.60);
    glVertex2f(0.07, 0.60);
    glVertex2f(0.07, 0.62);
    glVertex2f(0.31, 0.62);
    glEnd();


    glPushMatrix();
    glTranslatef(0.38,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    //Joining of twin tower

    glEnd();
}

                                                         ///green building
void green_building()
{




    glBegin(GL_QUADS);
      if(night==true)
    {
        glColor3f(0.2,0.2,0.2);
    }
    else
    glColor3f(0.2,0.4,0.4);
    glVertex2f(0.65, -0.05);
    glVertex2f(0.45,-0.05);
    glVertex2f(0.45, 0.50);
    glVertex2f(0.65, 0.50);

    //Door of blue building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.0,0.1,0.1);
    }
    else
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(0.63, -0.05);
    glVertex2f(0.57, -0.05);
    glVertex2f(0.57, 0.15);
    glVertex2f(0.63, 0.15);

    //Little window of blue building
    glBegin(GL_QUADS);
     if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.53,0.03);
    glVertex2f(0.48,0.03);
    glVertex2f(0.48, 0.13);
    glVertex2f(0.53, 0.13);

    //Big window of blue building
    glBegin(GL_QUADS);

     if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(0.63, 0.25);
    glVertex2f(0.47, 0.25);
    glVertex2f(0.47, 0.36);
    glVertex2f(0.63, 0.36);

    glBegin(GL_QUADS);

    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.63, 0.31);
    glVertex2f(0.63, 0.30);
    glVertex2f(0.47, 0.30);
    glVertex2f(0.47, 0.31);

    glBegin(GL_QUADS);

    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.555, 0.36);
    glVertex2f(0.555, 0.25);
    glVertex2f(0.545, 0.25);
    glVertex2f(0.545, 0.36);


}
                                                         ///light blue building 2
void lightblue_building2(){

    glBegin(GL_QUADS);
      if(night==true)
    {
        glColor3f(0.1,0.2,0.3);
    }
    else

    glColor3f(0.1, 0.4, 0.7);




    glVertex2f(0.96, -0.05);
    glVertex2f(0.75, -0.05);
    glVertex2f(0.75, 0.55);
    glVertex2f(0.96, 0.55);

    //Door of  Building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(204.0,204.0,0.0);
    }
    else
    glColor3f(1.000,1.0,1.0);
    glVertex2f(0.90, -0.05);
    glVertex2f(0.80, -0.05);
    glVertex2f(0.80, 0.15);
    glVertex2f(0.90, 0.15);


//2 Window of  Building
    glBegin(GL_QUADS);
    if(night==true)
    {
        glColor3f(0.0,0.0,0.0);
    }
    else
    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(0.95, 0.26);
    glVertex2f(0.88, 0.26);
    glVertex2f(0.88, 0.45);
    glVertex2f(0.95, 0.45);

    glBegin(GL_QUADS);
    if(night==true)
    {
        (glColor3f(204.0,204.0,0.0));
    }
    else
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.84, 0.26);
    glVertex2f(0.77, 0.26);
    glVertex2f(0.77, 0.45);
    glVertex2f(0.84, 0.45);





    glEnd();
}





void airplane()
{
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glScalef(0.2, 0.2, 0.0);
    glTranslatef(0.0, 4.0, 0.0);
    plane();
    glPopMatrix();
}


void BuildingAtNight()
{

}


void myDisplay(void)
{
       glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    sky();
    sun();
    field_1();
Rain();
    cloud_left();
    cloud_right();
     red_building();
    blue_building();
    green_building();
    phone_box();
    twin_tower();

    lightblue_building2();
    road();
  car1();////ME
    river();
    airplane();
    tree();
    boat();
    glFlush();

}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1920, 1080);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Project");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);

    glutTimerFunc(20, update_car1_t43, 0);
    glutTimerFunc(20, update1_car1_t43, 0);

    glutTimerFunc(20, update_plane, 0);
    glutTimerFunc(20, update_plane1, 0);
    myInit ();
    glutMainLoop();

}
