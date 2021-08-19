#include <iostream>
#include<cstdio>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.1f;
GLfloat speed1 = 0.1f;
GLfloat speed3 = 0.1f;
GLfloat i = 0.0f;

# define PI           3.14159265358979323846


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void demo_A();
//void demo_B(0);
//void demo_C();


void updateD(int value) {



	glutPostRedisplay();


	glutTimerFunc(100,updateD,0);
}

void Update(int value) {

    if(position >2.0)
        position = -2.0f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, Update, 0);
}

void UpdatePlane(int value) {

    if(position1 <-2.0)
        position1 = 2.0f;

    position1 -= speed1;

	glutPostRedisplay();


	glutTimerFunc(100, UpdatePlane, 0);
}

void line(GLfloat b1,GLfloat b2,GLfloat b3,GLfloat b4,GLubyte R,GLubyte G,GLubyte B){
    glBegin(GL_LINES);
    glColor3ub(R,G,B);
    glVertex2f(b1,b2);
    glVertex2f(b3,b4);
    glEnd();
}

void UpdateBlueTrain(int value) {

    if(position3 <-2.0)
        position3 = 2.0f;

    position3 -= speed3;

	glutPostRedisplay();


	glutTimerFunc(100, UpdateBlueTrain, 0);
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
        {
			speed += 0.1f;
        }
    if (button == GLUT_RIGHT_BUTTON)
	    {
            speed -= 0.1f;

        }
	glutPostRedisplay();
}



void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
             speed1=.5;
        break;

        case GLUT_KEY_DOWN:
             speed1=.2;
        break;

        case GLUT_KEY_LEFT:
             speed3=.5;
        break;

        case GLUT_KEY_RIGHT:
             speed3=.2;
        break;
    }
}



void DrawCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);

	}
	glEnd();
	//glFlush();
}

void circle(GLfloat X,GLfloat Y,GLfloat R,GLubyte r,GLubyte g,GLubyte b){

    int i;
    GLfloat x=X; GLfloat y=Y; GLfloat radius =R;
	int triangleAmount = 50;

    GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(r,g,b);

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(

                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void cloud(GLbyte r1,GLbyte g1,GLbyte b1){
        circle(.25,.85,.13,r1,g1,b1);
        circle(.05,.85,.13,r1,g1,b1);
        circle(.45,.85,.13,r1,g1,b1);
        circle(.0,.85,.1,r1,g1,b1);
        circle(.55,.85,.1,r1,g1,b1);


        circle(-.45,.75,.13,r1,g1,b1);
        circle(-.25,.75,.13,r1,g1,b1);
        circle(-.05,.75,.13,r1,g1,b1);
        circle(.15,.75,.1,r1,g1,b1);
        circle(-.65,.75,.1,r1,g1,b1);

}

void rain(){
    line(.98,.62,.98,.58,255,255,255);

    line(.93,.62,.93,.58,255,255,255);
    line(.88,.62,.88,.58,255,255,255);
    line(.83,.62,.83,.58,255,255,255);
    line(.78,.62,.78,.58,255,255,255);
    line(.73,.62,.73,.58,255,255,255);
    line(.68,.62,.68,.58,255,255,255);
    line(.63,.62,.63,.58,255,255,255);
    line(.58,.62,.58,.58,255,255,255);
    line(.53,.62,.53,.58,255,255,255);
    line(.48,.62,.48,.58,255,255,255);
    line(.43,.62,.43,.58,255,255,255);
    line(.38,.62,.38,.58,255,255,255);
    line(.33,.62,.33,.58,255,255,255);
    line(.28,.62,.28,.58,255,255,255);
    line(.23,.62,.23,.58,255,255,255);
    line(.18,.62,.18,.58,255,255,255);
    line(.13,.62,.13,.58,255,255,255);
    line(.08,.62,.08,.58,255,255,255);
    line(.03,.62,.03,.58,255,255,255);

    line(-.93,.62,-.93,.58,255,255,255);
    line(-.88,.62,-.88,.58,255,255,255);
    line(-.83,.62,-.83,.58,255,255,255);
    line(-.78,.62,-.78,.58,255,255,255);
    line(-.73,.62,-.73,.58,255,255,255);
    line(-.68,.62,-.68,.58,255,255,255);
    line(-.63,.62,-.63,.58,255,255,255);
    line(-.58,.62,-.58,.58,255,255,255);
    line(-.53,.62,-.53,.58,255,255,255);
    line(-.48,.62,-.48,.58,255,255,255);
    line(-.43,.62,-.43,.58,255,255,255);
    line(-.38,.62,-.38,.58,255,255,255);
    line(-.33,.62,-.33,.58,255,255,255);
    line(-.28,.62,-.28,.58,255,255,255);
    line(-.23,.62,-.23,.58,255,255,255);
    line(-.18,.62,-.18,.58,255,255,255);
    line(-.13,.62,-.13,.58,255,255,255);
    line(-.08,.62,-.08,.58,255,255,255);
    line(-.03,.62,-.03,.58,255,255,255);


}




void demo_back(int val) {

 glutDisplayFunc(demo_A);


}

void moonsoon(){

    glClearColor(0.0f,0.30f,.60f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
    glColor3ub(104, 194, 102);
    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();



    /* Blue Background */
    glBegin(GL_QUADS);
    glColor3ub(99, 161, 217);
    glVertex2f(-1,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd();

    /* Green Background for second Home */
    glBegin(GL_QUADS);
    glColor3ub(104, 194, 102);
    glVertex2f(0.7,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,0.0);
    glVertex2f(0.7,0.0);
    glEnd();


    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(227, 211, 176);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(205, 192, 162);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();


    /* Translation of The Building */

    glScalef(0.5,0.5,0);
    glTranslatef(1.35,0.1,0);

    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(229, 235, 55);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(219, 152, 133);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();

    glLoadIdentity();


    /* Rail Line */


    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.4);
    glVertex2f(-1,-0.4);
    glEnd();


    /* Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.8,-0.5);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.9,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.4,-0.5);
    glVertex2f(-0.4,-0.4);
    glVertex2f(-0.5,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.0,-0.5);
    glVertex2f(-0.0,-0.4);
    glVertex2f(-0.1,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.5);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.4,-0.4);
    glVertex2f(0.3,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.9,-0.5);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.8,-0.4);
    glEnd();

    /* Second Rail Line */

    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.9);
    glVertex2f(1,-0.9);
    glVertex2f(1,-0.8);
    glVertex2f(-1,-0.8);
    glEnd();

    /* Second Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.9,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.9);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.4,-0.8);
    glVertex2f(-0.5,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.8);
    glVertex2f(-0.1,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.9);
    glVertex2f(0.4,-0.9);
    glVertex2f(0.4,-0.8);
    glVertex2f(0.3,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.9);
    glVertex2f(0.9,-0.9);
    glVertex2f(0.9,-0.8);
    glVertex2f(0.8,-0.8);
    glEnd();


    /* Wild Mill Stick */

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
    glVertex2f(-0.73,-0.1);
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.73,0.3);
    glEnd();


    /* Tree */

    glBegin(GL_QUADS);
    glColor3ub (187, 188, 73);
    glVertex2f(-0.1,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.15,0.35);
    glVertex2f(-0.1,0.35);
    glEnd();

    /* Tree Leaves */


    glColor3ub (23, 204, 0);
    DrawCircle(-0.13,0.39,0.1,1000);
    glColor3ub (23, 204, 0);
    DrawCircle(-0.19,0.3,0.1,1000);
    glColor3ub (23, 204, 0);
    DrawCircle(-0.07,0.3,0.1,1000);




    /* The Train */

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(255, 102, 77);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.8,-0.0);
    glVertex2f(0.4,-0.0);
    glEnd();


    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(184, 79, 61);
    glVertex2f(0.2,-0.5);
    glVertex2f(0.39,-0.5);
    glVertex2f(0.39,-0.25);
    glVertex2f(0.2,-0.25);
    glEnd();



    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.03,-0.5);
    glVertex2f(0.19,-0.5);
    glVertex2f(0.19,-0.25);
    glVertex2f(-0.03,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.25,-0.5);
    glVertex2f(-0.045,-0.5);
    glVertex2f(-0.045,-0.25);
    glVertex2f(-0.25,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.45,-0.5);
    glVertex2f(-0.26,-0.5);
    glVertex2f(-0.26,-0.25);
    glVertex2f(-0.45,-0.25);
    glEnd();

    glPopMatrix();


    /* Wild Mill */



    glPushMatrix();

    glTranslatef(-0.7,0.3,0.0);
    glRotatef(i,0.0,0.0,0.1);


    glBegin(GL_TRIANGLES);          //Upper Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.3);
    glVertex2f(0.05,0.3);

    glEnd();

    glBegin(GL_TRIANGLES);          //Left Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.255,0.1);
    glVertex2f(-0.26,0.06);

    glEnd();

    glBegin(GL_TRIANGLES);          //Right Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.255,-0.1);
    glVertex2f(0.26,-0.06);

    glEnd();


    glBegin(GL_TRIANGLES);          //Left(Lower Left) Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.12,-0.3);
    glVertex2f(-0.1,-0.32);

    glEnd();

    glPopMatrix();
    i+=0.1f;



    /* Second Train */

    glPushMatrix();
    glTranslatef(position3, 0.0f, 0.0f);

    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(154, 29, 139);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.4,-0.55);
    glEnd();

    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.2,-0.9);
    glVertex2f(-0.39,-0.9);
    glVertex2f(-0.39,-0.7);
    glVertex2f(-0.2,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.19,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.7);
    glVertex2f(-0.19,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.01,-0.9);
    glVertex2f(0.2,-0.9);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.01,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.21,-0.9);
    glVertex2f(0.39,-0.9);
    glVertex2f(0.39,-0.7);
    glVertex2f(0.21,-0.7);
    glEnd();

    glPopMatrix();



    cloud(0,0,0);
    glTranslatef(.3,-.05,0);
    cloud(0,0,0);
    glLoadIdentity();

   // glTranslatef(-.8,.05,0);
    //cloud(0,0,0);
    //glLoadIdentity();
    //glTranslatef(-.9,.06,0);
    glPushMatrix();
    glTranslatef(-position,0.0,0.0);
    cloud(0,0,0);
    glPopMatrix();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.0,position1,0.0);
    rain();
    glTranslatef(.0,-.10,0);
    rain();

     glTranslatef(.0,-.10,0);
    rain();

     glTranslatef(.0,-.10,0);
    rain();

     glTranslatef(.0,-.10,0);
    rain();

     glTranslatef(.0,-.10,0);
    rain();

     glTranslatef(.0,-.10,0);
    rain();
     glTranslatef(.0,-.10,0);
    rain();
     glTranslatef(.0,-.10,0);
    rain();
     glTranslatef(.0,-.10,0);
    rain();
     glTranslatef(.0,-.10,0);
    rain();

    glPopMatrix();

//    glutTimerFunc(10000,winter,0);
     glutTimerFunc(1500,demo_back,0);

    glFlush();


}

void demo_C(int val) {

 glutDisplayFunc(moonsoon);


}

void night()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Green Background */
    glBegin(GL_QUADS);
    glColor3ub(128, 168, 142);
    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();



    /* Blue Background */
    glBegin(GL_QUADS);
    glColor3ub(115, 114, 116);
    glVertex2f(-1,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd();

    /* Green Background for second Home */
    glBegin(GL_QUADS);
    glColor3ub(104, 194, 102);
    glVertex2f(0.7,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,0.0);
    glVertex2f(0.7,0.0);
    glEnd();


    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(227, 211, 176);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(205, 192, 162);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();


    /* Translation of The Building */

    glScalef(0.5,0.5,0);
    glTranslatef(1.35,0.1,0);

    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(229, 235, 55);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(219, 152, 133);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();

    glLoadIdentity();


    /* Rail Line */


    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.4);
    glVertex2f(-1,-0.4);
    glEnd();


    /* Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.8,-0.5);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.9,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.4,-0.5);
    glVertex2f(-0.4,-0.4);
    glVertex2f(-0.5,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.0,-0.5);
    glVertex2f(-0.0,-0.4);
    glVertex2f(-0.1,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.5);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.4,-0.4);
    glVertex2f(0.3,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.9,-0.5);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.8,-0.4);
    glEnd();

    /* Second Rail Line */

    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.9);
    glVertex2f(1,-0.9);
    glVertex2f(1,-0.8);
    glVertex2f(-1,-0.8);
    glEnd();

    /* Second Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.9,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.9);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.4,-0.8);
    glVertex2f(-0.5,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.8);
    glVertex2f(-0.1,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.9);
    glVertex2f(0.4,-0.9);
    glVertex2f(0.4,-0.8);
    glVertex2f(0.3,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.9);
    glVertex2f(0.9,-0.9);
    glVertex2f(0.9,-0.8);
    glVertex2f(0.8,-0.8);
    glEnd();


    /* Wild Mill Stick */

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
    glVertex2f(-0.73,-0.1);
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.73,0.3);
    glEnd();


    /* Tree */

    glBegin(GL_QUADS);
    glColor3ub (187, 188, 73);
    glVertex2f(-0.1,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.15,0.35);
    glVertex2f(-0.1,0.35);
    glEnd();

    /* Tree Leaves */


    glColor3ub (128, 168, 142);
    DrawCircle(-0.13,0.39,0.1,1000);
    glColor3ub (128, 168, 142);
    DrawCircle(-0.19,0.3,0.1,1000);
    glColor3ub (128, 168, 142);
    DrawCircle(-0.07,0.3,0.1,1000);




    /* The Train */



    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(255, 102, 77);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.8,-0.0);
    glVertex2f(0.4,-0.0);
    glEnd();


    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(184, 79, 61);
    glVertex2f(0.2,-0.5);
    glVertex2f(0.39,-0.5);
    glVertex2f(0.39,-0.25);
    glVertex2f(0.2,-0.25);
    glEnd();



    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.03,-0.5);
    glVertex2f(0.19,-0.5);
    glVertex2f(0.19,-0.25);
    glVertex2f(-0.03,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.25,-0.5);
    glVertex2f(-0.045,-0.5);
    glVertex2f(-0.045,-0.25);
    glVertex2f(-0.25,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.45,-0.5);
    glVertex2f(-0.26,-0.5);
    glVertex2f(-0.26,-0.25);
    glVertex2f(-0.45,-0.25);
    glEnd();



    /* Wild Mill */



    glTranslatef(-0.7,0.3,0.0);
    //glRotatef(i,0.0,0.0,0.1);


    glBegin(GL_TRIANGLES);          //Upper Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.3);
    glVertex2f(0.05,0.3);

    glEnd();

    glBegin(GL_TRIANGLES);          //Left Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.255,0.1);
    glVertex2f(-0.26,0.06);

    glEnd();

    glBegin(GL_TRIANGLES);          //Right Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.255,-0.1);
    glVertex2f(0.26,-0.06);

    glEnd();


    glBegin(GL_TRIANGLES);          //Left(Lower Left) Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.12,-0.3);
    glVertex2f(-0.1,-0.32);

    glEnd();

    glLoadIdentity();

    /* Second Train */



    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(154, 29, 139);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.4,-0.55);
    glEnd();

    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.2,-0.9);
    glVertex2f(-0.39,-0.9);
    glVertex2f(-0.39,-0.7);
    glVertex2f(-0.2,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.19,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.7);
    glVertex2f(-0.19,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.01,-0.9);
    glVertex2f(0.2,-0.9);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.01,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.21,-0.9);
    glVertex2f(0.39,-0.9);
    glVertex2f(0.39,-0.7);
    glVertex2f(0.21,-0.7);
    glEnd();


    glColor3ub (254, 252, 215);
    DrawCircle(0.9,0.94,0.05,1000);


    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.1,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.03,0.03,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(-0.1,-0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

     glTranslatef(-0.15,-0.15,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(-0.2,-0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.1,-0.05,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.15,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.17,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.19,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.21,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(0.25,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

     glTranslatef(-0.25,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();

    glTranslatef(-0.29,0.1,0);

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.0,0.8);
    glVertex2f(0.01,0.8);
    glEnd();



    glLoadIdentity();

    glutTimerFunc(1500,demo_C,0);

	glFlush();

}



void demo_B(int val) {

 glutDisplayFunc(night);


}


void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Green Background */
    glBegin(GL_QUADS);
    glColor3ub(104, 194, 102);
    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();



    /* Blue Background */
    glBegin(GL_QUADS);
    glColor3ub(99, 161, 217);
    glVertex2f(-1,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd();

    /* Green Background for second Home */
    glBegin(GL_QUADS);
    glColor3ub(104, 194, 102);
    glVertex2f(0.7,-0.1);
    glVertex2f(1,-0.1);
    glVertex2f(1,0.0);
    glVertex2f(0.7,0.0);
    glEnd();


    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(227, 211, 176);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(205, 192, 162);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();


    /* Translation of The Building */

    glScalef(0.5,0.5,0);
    glTranslatef(1.35,0.1,0);

    /* Lower Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(229, 235, 55);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.3);
    glVertex2f(0.1,0.3);
    glEnd();

    /* Upper Side of The Building */
    glBegin(GL_QUADS);
    glColor3ub(219, 152, 133);
    glVertex2f(0.2,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.6,0.6);
    glVertex2f(0.2,0.6);
    glEnd();

    /* Upper Side Window */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,0.38);
    glVertex2f(0.45,0.38);
    glVertex2f(0.45,0.48);
    glVertex2f(0.3,0.48);
    glEnd();

    /* Building Gate */
    glBegin(GL_QUADS);
    glColor3ub(24, 17, 1);
    glVertex2f(0.3,-0.1);
    glVertex2f(0.5,-0.1);
    glVertex2f(0.5,0.2);
    glVertex2f(0.3,0.2);
    glEnd();

    glLoadIdentity();


    /* Rail Line */


    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.4);
    glVertex2f(-1,-0.4);
    glEnd();


    /* Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.8,-0.5);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.9,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.4,-0.5);
    glVertex2f(-0.4,-0.4);
    glVertex2f(-0.5,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.0,-0.5);
    glVertex2f(-0.0,-0.4);
    glVertex2f(-0.1,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.5);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.4,-0.4);
    glVertex2f(0.3,-0.4);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.9,-0.5);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.8,-0.4);
    glEnd();

    /* Second Rail Line */

    glBegin(GL_QUADS);
    glColor3ub(221, 233, 232);
    glVertex2f(-1,-0.9);
    glVertex2f(1,-0.9);
    glVertex2f(1,-0.8);
    glVertex2f(-1,-0.8);
    glEnd();

    /* Second Rail Line Zebra */

    glBegin(GL_QUADS);          //First Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.9,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.9,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Second Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.5,-0.9);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.4,-0.8);
    glVertex2f(-0.5,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Third Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(-0.1,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.8);
    glVertex2f(-0.1,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fourth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.3,-0.9);
    glVertex2f(0.4,-0.9);
    glVertex2f(0.4,-0.8);
    glVertex2f(0.3,-0.8);
    glEnd();

    glBegin(GL_QUADS);          //Fifth Zebra from left hand side
    glColor3ub(20, 26, 26);
    glVertex2f(0.8,-0.9);
    glVertex2f(0.9,-0.9);
    glVertex2f(0.9,-0.8);
    glVertex2f(0.8,-0.8);
    glEnd();


    /* Wild Mill Stick */

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
    glVertex2f(-0.73,-0.1);
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.73,0.3);
    glEnd();


    /* Tree */

    glBegin(GL_QUADS);
    glColor3ub (187, 188, 73);
    glVertex2f(-0.1,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.15,0.35);
    glVertex2f(-0.1,0.35);
    glEnd();

    /* Tree Leaves */


    glColor3ub (23, 204, 0);
    DrawCircle(-0.13,0.39,0.1,1000);
    glColor3ub (23, 204, 0);
    DrawCircle(-0.19,0.3,0.1,1000);
    glColor3ub (23, 204, 0);
    DrawCircle(-0.07,0.3,0.1,1000);




    /* The Train */

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(255, 102, 77);
    glVertex2f(0.4,-0.5);
    glVertex2f(0.8,-0.5);
    glVertex2f(0.8,-0.0);
    glVertex2f(0.4,-0.0);
    glEnd();


    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(184, 79, 61);
    glVertex2f(0.2,-0.5);
    glVertex2f(0.39,-0.5);
    glVertex2f(0.39,-0.25);
    glVertex2f(0.2,-0.25);
    glEnd();



    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.03,-0.5);
    glVertex2f(0.19,-0.5);
    glVertex2f(0.19,-0.25);
    glVertex2f(-0.03,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.25,-0.5);
    glVertex2f(-0.045,-0.5);
    glVertex2f(-0.045,-0.25);
    glVertex2f(-0.25,-0.25);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(184, 79, 61);
    glVertex2f(-0.45,-0.5);
    glVertex2f(-0.26,-0.5);
    glVertex2f(-0.26,-0.25);
    glVertex2f(-0.45,-0.25);
    glEnd();

    glPopMatrix();


    /* Wild Mill */



    glPushMatrix();

    glTranslatef(-0.7,0.3,0.0);
    glRotatef(i,0.0,0.0,0.1);


    glBegin(GL_TRIANGLES);          //Upper Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.3);
    glVertex2f(0.05,0.3);

    glEnd();

    glBegin(GL_TRIANGLES);          //Left Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.255,0.1);
    glVertex2f(-0.26,0.06);

    glEnd();

    glBegin(GL_TRIANGLES);          //Right Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(0.255,-0.1);
    glVertex2f(0.26,-0.06);

    glEnd();


    glBegin(GL_TRIANGLES);          //Left(Lower Left) Hand Side Fan
    glColor3ub(224, 224, 224);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.12,-0.3);
    glVertex2f(-0.1,-0.32);

    glEnd();

    glPopMatrix();
    i+=0.1f;

    /* Aircraft */


    glPushMatrix();
    glTranslatef(position1, 0.0f, 0.0f);

    glBegin(GL_QUADS);          //Plane Body
    glColor3ub(205, 214, 214);
    glVertex2f(0.75,0.7);
    glVertex2f(1,0.7);
    glVertex2f(1,0.8);
    glVertex2f(0.75,0.8);
    glEnd();


    glBegin(GL_TRIANGLES);      //Plane Head!
    glColor3ub(222, 69, 88);
    glVertex2f(0.7,0.75);
    glVertex2f(0.75,0.7);
    glVertex2f(0.75,0.8);
    glEnd();

    glBegin(GL_TRIANGLES);      //Plane Tail!
    glColor3ub(222, 69, 88);
    glVertex2f(0.9,0.8);
    glVertex2f(1,0.8);
    glVertex2f(1,0.9);
    glEnd();

    glBegin(GL_QUADS);      //Plane Wing!
    glColor3ub(222, 69, 88);
    glVertex2f(0.82,0.67);
    glVertex2f(0.86,0.67);
    glVertex2f(0.89,0.72);
    glVertex2f(0.83,0.72);

    glEnd();
    glPopMatrix();

    /* Second Train */

    glPushMatrix();
    glTranslatef(position3, 0.0f, 0.0f);

    glBegin(GL_QUADS);          //Train First Body
    glColor3ub(154, 29, 139);
    glVertex2f(-0.4,-0.9);
    glVertex2f(-0.8,-0.9);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.4,-0.55);
    glEnd();

    glBegin(GL_QUADS);          //Train Second Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.2,-0.9);
    glVertex2f(-0.39,-0.9);
    glVertex2f(-0.39,-0.7);
    glVertex2f(-0.2,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Third Body
    glColor3ub(191, 105, 180);
    glVertex2f(-0.19,-0.9);
    glVertex2f(-0.0,-0.9);
    glVertex2f(-0.0,-0.7);
    glVertex2f(-0.19,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fourth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.01,-0.9);
    glVertex2f(0.2,-0.9);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.01,-0.7);
    glEnd();

    glBegin(GL_QUADS);          //Train Fifth Body
    glColor3ub(191, 105, 180);
    glVertex2f(0.21,-0.9);
    glVertex2f(0.39,-0.9);
    glVertex2f(0.39,-0.7);
    glVertex2f(0.21,-0.7);
    glEnd();

    glPopMatrix();

    glColor3ub (243, 114, 32);
    DrawCircle(0.9,0.94,0.05,1000);


    glutTimerFunc(1500,demo_B,0);

	glFlush();

}






void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 'p':
            speed = 0.0f;
            break;
        case 'g':
            speed = 0.1f;
        break;

        case 's':
            speed3 = 0.0f;
            break;
        case 'o':
            speed3 = 0.1f;
        break;


        case 'd':

        glutDisplayFunc(display);
        glutPostRedisplay();

        break;
        case 'r':
        glutDisplayFunc(moonsoon);
        glutPostRedisplay();
        break;

        case 'n':
        glutDisplayFunc(night);
        glutPostRedisplay();
        break;


        glutPostRedisplay();
	}
}

void demo_A()
{
       glutDisplayFunc(display);
}





int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Happy World");
   glutDisplayFunc(demo_A);
   glutTimerFunc(100, updateD, 0);
   //glutReshapeFunc(reshape);
   //initGL();

   glutMouseFunc(handleMouse);
   glutKeyboardFunc(handleKeypress);
   glutSpecialFunc(SpecialInput);

   glutTimerFunc(100,Update,0);
   glutTimerFunc(100, UpdatePlane,0);
   glutTimerFunc(100, UpdateBlueTrain,0);

   glutIdleFunc(Idle);
   glutMainLoop();
   return 0;
}
