#include <iostream>
#include <ctime>

using namespace std;

bool estaordenada(int lista[], int tamaño, int inicio=0) {
	for(int i = inicio+1; i <  tamaño; i++) {
		if(lista[i-1] > lista[i])
			return false;
	}
	return true;
}

int main() {

/*int cn, nt;
cout << "cantidad de numeros a meter: "; cin >> cn;
for (int n = 0; n < cn; n++) {
	cout << "pon un numero: "; cin >> nt;
	lista.push_back(nt);
}
prueba de rendimiento*/
int cn = 100000;
int lista[cn];
for (int c = 0; c < cn; c++)
	lista[c] = rand() % cn+1;

clock_t begin = clock();
int temp, nac = 0;//nac = numero a comprobar
while (not estaordenada(lista, cn, nac)) {
	int indicemenor = nac;
	int menor = lista[nac];
	for(int a = indicemenor; a < cn; a++) {
		if(lista[a] < menor) {
			menor = lista[a];
			indicemenor = a;
		}
	}
	if(menor != nac) {
		temp = lista[nac];
		lista[nac] = lista[indicemenor];
		lista[indicemenor] = temp;
	}
	nac++;
}
clock_t end = clock();

for (int elemento : lista)
	cout << elemento << ' ';
cout << endl;
cout << "\n" <<  double(end - begin) / CLOCKS_PER_SEC << "\n";
}
