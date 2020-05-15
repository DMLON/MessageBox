#include <stdio.h>
#include "cMessageBox.h"
#include <string>
#include <iostream>
using namespace std;

//Puntero a funcion
void funcion(void (*func)()) {
	cout << "Llamando a mi funcion" << endl;
	func();
}

//Recibe de primer parametro un puntero a funcion que recibe 2 parametros int y retorna int, además le debo pasar
//Tanto el primer parametro como el segundo
int funcion2Parametros(int (*func)(int,int),int PrimerArgumento, int SegundoArgumento) {
	cout << "Llamando a mi funcion con 2 parametros" << endl;
	return func(PrimerArgumento, SegundoArgumento);
}

void HacerAlgo() {
	printf("Hola mundo!\n");
}

void HacerOtraCosa() {
	printf("Haciendo otra cosa!\n");
}
int Sumar(int a, int b) {
	return a + b;
}

int Restar(int a, int b) {
	return a - b;
}

void main() {
	//Le paso la funcion como argumento
	funcion(HacerAlgo);
	funcion(HacerOtraCosa);
	//Puedo pasarle cualquier funcion que retorne void en este caso y sin argumentos
	cout << funcion2Parametros(Sumar, 5, 10) << endl;
	cout << funcion2Parametros(Restar, 10, 2) << endl;

	//Llamado a un messageBox
	auto resultado = cMessageBox::Show("Hola", "Mundo", cMessageBox::MessageBoxButton::YesNoCancel, cMessageBox::MessageBoxIcon::Error);

	switch (resultado) {
	case cMessageBox::DialogResult::Yes:
		//Si el resultado es Si, hago algo
		cout << "Yes" << endl;
		break;
	case cMessageBox::DialogResult::No:
		//Si el resultado es No, hago otra cosa
		cout << "No" << endl;
		break;
	case cMessageBox::DialogResult::Cancel:
		//Si el resultado es Cancel, hago otra cosa
		cout << "Cancel" << endl;
		break;
	}



	//Llamado a un messageBox2
	auto resultado2 = cMessageBox::Show("Mensaje del medio", "Titulo generico", cMessageBox::MessageBoxButton::OkCancel, cMessageBox::MessageBoxIcon::Warning);

	switch (resultado2) {
	case cMessageBox::DialogResult::Ok:
		//Si el resultado es Ok, hago algo
		cout << "Yes" << endl;
		break;
	case cMessageBox::DialogResult::Cancel:
		//Si el resultado es Cancel, hago otra cosa
		cout << "Cancel" << endl;
		break;
	}
	
}