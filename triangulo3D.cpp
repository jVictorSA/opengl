#include <GL/glut.h>

float angulo = 0.0;

void render(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
            0.0f, 0.0f, 10.0f,
			0.0f, 0.0f,  0.0f,
			0.0f, 1.0f,  0.0f);

    glRotatef(angulo, 0, 1, 0);

    //glEnable(GL_MULTISAMPLE);

    //Se retirar os glBegin(GL_TRIANGLES), o que de errado pode acontecer??
    glBegin(GL_POLYGON);
        glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);           //Vermelho
        glVertex3f(-2, -2, 0.0);

        glColor3f(0,1,0);           //Verde
        glVertex3f(2, -2.0, 0.0);

        glColor3f(0,0,1);           //Azul
        glVertex3f(0.0, 2.0, -1.0);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);           //Vermelho
        glVertex3f(-2, -2, 0.0);

        glColor3f(1,1,0);           //Amarelo
        glVertex3f(0, -2.0, -3.0);

        glColor3f(0,0,1);           //Azul
        glVertex3f(0.0, 2.0, -1.0);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);           //Verde
        glVertex3f(2, -2, 0.0);

        glColor3f(1,1,0);           //Amarelo
        glVertex3f(0, -2.0, -3.0);

        glColor3f(0,0,1);           //Azul
        glVertex3f(0.0, 2.0, -1.0);
        glEnd();

    glEnd();

    angulo += .8;

    glutSwapBuffers();
}

void inicializar(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void mudaTamJanela(int largura, int altura){

    if(altura == 0){
        altura = 1;
    }

    float aspecto = largura * 1.0 / altura;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, largura, altura);

    gluPerspective(45, aspecto, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
}

void sair(unsigned char tecla, int x, int y){
    if(tecla == 'q'){
        exit(0);
    }
}

int main (int argc, char **argv){

    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Tut 1");

    inicializar();

    glutDisplayFunc(render);
    glutKeyboardFunc(sair);
    glutReshapeFunc(mudaTamJanela);

    glutIdleFunc(render);

    glutMainLoop();



    return 0;
}
