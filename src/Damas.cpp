#include "Mundo.h"
#include "glut.h"
//#include "ETSIDI.h"
Mundo mundo;
bool clic=false;
float x_, y_;
//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void onDraw(void); //esta funcion sera llamada para dibujar
void onTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial	
void mouse(int button, int state, int x, int y);//para el raton 

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(onDraw);
	glutTimerFunc(25,onTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);
	glutMouseFunc(mouse);
	mundo.inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void onDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mundo.dibuja();
	if (clic)
	{
		mundo.raton(x_, y_);
	}

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void onKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.tecla(key);

	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaEspecial(key);
}
void onTimer(int value)
{
//poner aqui el código de animacion
	mundo.mueve();

	//no borrar estas lineas
	glutTimerFunc(25,onTimer,0);
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//boton izquierdo una pulsacion 
	{
		//newModel = false;
		clic = true;
		x_ = (x-400)/33.3f;// ajuste de cordenadas del raton a coordenadas de dibujo X(0-800)
		y_ = (300-y)/33.3f;// ajuste de cordenadas del raton a coordenadas de dibujo Y(600-0)
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	 clic = false;

}
