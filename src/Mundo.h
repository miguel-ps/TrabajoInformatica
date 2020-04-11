#include "Tablero.h"
#include "ListaFichas.h"
#include "Movimientos.h"
#include "Interaccion.h"
class Mundo
{
private:
	ListaFichas lf;
	Tablero t;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 
	Mundo();
	virtual ~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void raton(float x, float y);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
};
