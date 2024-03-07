#ifdef _APPLE_
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

    //declaracao das variaveis
int chutes = 0, ngols = 0, erros = 0;
float alpha = 40;
float beta = 0;
float delta = 0.8;
float x1 = 2.0;
float y1 = 2.0;
float z1 = 2.0;
float bolax = 0, bolay = 0.1, bolaz = 3;
float quadradoX = 1.0;
float quadradoZ = -8.0;
float cuboveloc = 0.1;
float sombrax = 0, sombray = -0.8, sombraz = 3;
bool animation = true, firstexe = true, entrou = false, fora = false, movimentou = false, cubeMovingRight = true;

void Init()
{
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-7, 6, -6, 8, -8, 8);
}

void RestartInicio()
{
    alpha = 40;
    beta = 0;
    delta = 0.8;
    x1 = 2.0;
    y1 = 2.0;
    z1 = 2.0;
    bolax = 0, bolay = 0.1, bolaz = 3;
    chutes = 0, ngols = 0, erros = 0;
}
GLfloat windowWidth;
GLfloat windowHeight;

void RestartPosGol(int value)
{
    x1 = 0.7;
    y1 = 0.7;
    z1 = 0.7;
    bolax = 0;
    bolay = 0.1;
    bolaz = 3;
    quadradoX = 0;
    animation = true, firstexe = true, entrou = false, fora = false;
    glutPostRedisplay();
}
    //palavra gol na tela informando que foi gol
void Gol()
{
    // g
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-1.3, 2.5, 0);
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-0.7, 0.2, 0);
    glScalef(0.35, 18, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-1, 2, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-1.1, 8, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-0.9, 4.2, 0);
    glScalef(0.5, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-1.2, -1.4, 0);
    glScalef(0.3, 1, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-2.7, -2, 0);
    glScalef(0.6, 0.3, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    //o

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(-0.3, 2.5, 0);
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(0.3, 2.5, 0);
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(0, 2, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(0, 7, 0);
    glScalef(1.2, 2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    // L
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(0.8, 3.0, 0);
    glScalef(0.4, 20, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslated(1, 2, 0);
    glScalef(1.3, 2.2, 0.1);
    glutSolidCube(0.5);
    glPopMatrix();
}
    //indicacao na tela dizendo que nao foi gol
void Errou()
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(0, 0, 0.8);
    glScalef(0.1, 8, -0.2);
    glutSolidCube(1.5);
    glPopMatrix();
}
    //verifica se a bola foi para fora ou se a bola entrou
void Verifica_Gol()
{
    if (bolaz <= -8)
    {
        animation = false;
        if (bolax < -2.5 || bolax > 2.5)
        {
            chutes++;
            animation = false, movimentou = false, fora = true;
            erros++;
            return;
        }
        if (bolax <= quadradoX + 0.5 && bolax >= quadradoX - 0.5)
        {
            chutes++;
            animation = false, firstexe = false, movimentou = false, fora = true;
            erros++;
            return;
        }
        if (bolax >= -2.5 && bolax <= 2.5)
        {
            animation = false, movimentou = false, entrou = true;
            chutes++;
            ngols++;
            return;
        }
    }
}
    //animacao do penalti
void Animacao(int value)
{

    if (!animation)
    {
        glutTimerFunc(400, RestartPosGol, 0);
        return;
    }
    if (animation)
    {
        bolaz -= 0.2, sombraz -= 0.2;
        Verifica_Gol();

        glutPostRedisplay();
        glutTimerFunc(16, Animacao, 0);
    }
}

void Cubo_Timer(int value)
{
    if (cubeMovingRight)
    {
        quadradoX += cuboveloc;
        if (quadradoX > 2.5f)
        {
            quadradoX = 2.5f;
            cubeMovingRight = false;
        }
    }
    else
    {
        quadradoX -= cuboveloc;
        if (quadradoX < -2.5f)
        {
            quadradoX = -2.5f;
            cubeMovingRight = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, Cubo_Timer, 0);
}

void DesenhaTexto(void *font, char *string)
{
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
}

void display()
{
    glClearColor(1.0, 0.5, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(beta, 0, 1, 0); //rotacao do eixo y
    glRotatef(alpha, 1, 0, 0);  //rotacao do eixo x
    glScalef(delta, delta, delta);
    glPushMatrix();

    //bola
    glPushMatrix();
    glTranslatef(bolax, bolay, bolaz);
    glColor3f(0, 1, 1);
    glutSolidSphere(0.5, 50, 20);
    glPopMatrix();

    //cubo
    glColor3f(1, 1, 1);
    glTranslatef(0, 1.6, 0.8);
    glTranslatef(quadradoX, -1, quadradoZ);
    glScalef(1.0f, 1.0f, 1.0f);
    glutSolidCube(1.3f);
    glPopMatrix();

    //gol
    glLineWidth(7);
    glBegin(GL_LINES);

    glVertex3f(3, -0.9, -7);
    glVertex3f(3, 4.1, -7);

    glVertex3f(3, 4, -7);
    glVertex3f(-3, 4, -7);

    glVertex3f(-3, -0.9, -7);
    glVertex3f(-3, 4.1, -7);

    //linha do gol
    glVertex3f(-6.0, -0.05, -7);
    glVertex3f(6.0, -0.05, -7);
    glEnd();

    //campo
    glTranslatef(0, -1, -2.5);
    glScalef(4, 0.6f, 4);
    glColor3f(0, 0.8, 0);
    glutSolidCube(3.0f);

    if (entrou)
        Gol();
    if (fora)
        Errou();

    //placar
    glPushMatrix();
    char n_gols_str[100], erros_str[100], chutes_str[100];
    sprintf(n_gols_str, "%d", ngols);
    sprintf(erros_str, "%d", erros);
    sprintf(chutes_str, "%d", chutes);
    float z = -2.0;
    glColor3f(0, 0, 0);
    glRasterPos3d(1.0, 5, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, "CHUTES: ");
    glRasterPos3d(1.35, 5, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, chutes_str);

    glRasterPos3d(1.0, 4, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, "GOLS: ");
    glRasterPos3d(1.35, 4, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, n_gols_str);

    glRasterPos3d(1.0, 3, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, "ERROS: ");
    glRasterPos3d(1.35, 3, z);
    DesenhaTexto(GLUT_BITMAP_HELVETICA_18, erros_str);
    glPopMatrix();

    glutSwapBuffers();
}
    //manipulacao de teclas
void listeningSpKey(GLint tecla, GLint x, GLint y)
{
    switch (tecla)
    {
    case GLUT_KEY_UP:
        alpha = alpha - 1;
        break;
    case GLUT_KEY_DOWN:
        alpha = alpha + 1;
        break;
    case GLUT_KEY_LEFT:
        beta = beta + 1;
        break;
    case GLUT_KEY_RIGHT:
        beta = beta - 1;
        break;
    }
    glutPostRedisplay();
}
    //lidar com eventos do teclado
void keyboard(unsigned char key, int x, int y)
{

    if (key == 'a' || key == 'A')
    {
        if (bolax > -5 && !movimentou && bolaz > -5)
            bolax -= 0.3;
    }
    if (key == 'd' || key == 'D')
    {
        if (bolax < 5 && !movimentou && bolaz > -5)
            bolax += 0.3;
    }
    if (key == 'r' || key == 'R')
        RestartInicio();

        if (key == 'c' || key == 'C')
        system("C:/MeuNome.exe");

    if (key == 27) //esc
        exit(0);

    if (key == ' ')
        if (firstexe == true)
        {
            firstexe = false;
            movimentou = true;
            glutTimerFunc(0, Animacao, 0);
        }
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(150, 100);
    glutCreateWindow("PENALTI - VINICIUS DIAS OLIVEIRA");
    Init();

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glEnable(GL_NORMALIZE);

    glutTimerFunc(0, Cubo_Timer, 0);

    glutMainLoop();
}
