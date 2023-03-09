#include <GL/glut.h>

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
}

void displayRect(){
    glClear(GL_COLOR_BUFFER_BIT);

    // glLoadIdentity(); 

    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);
        glScalef(1.0, 2.0, 1.0);
        glRecti(100, 0, 200, 100);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glScalef(2.0, 1, 1.0);
        glRecti(50, 0, 150, 100);
    glPopMatrix();

    glFlush();
}

void exit(unsigned char key, int x, int y){
    if(key == 'q' || key == 'Q') { exit(0); }
}

int main(int argc, char **argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("TRANSFOMACOES 3D");

    init();
    glutDisplayFunc(displayRect);
    glutKeyboardFunc(exit);

    glutMainLoop();

    return 0;
}
