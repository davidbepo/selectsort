#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <future>

using namespace std;

vector <int> selectsort(vector <int> lista) {
	int nac = 0; //nac = numero a comprobar
	while (not is_sorted(lista.begin() + nac-1, lista.end())) {
		auto indicemenor = min_element(lista.begin() + nac, lista.end()); //coje el menor numero de la lista
		if (distance(lista.begin(), indicemenor) != nac)
			iter_swap(lista.begin() + nac, indicemenor); //si no es nac los intercambia
		nac++;
	}
	return lista;
}

int main() {
vector <int> lista;
/* modo usuario
int cn, nt;
cout << "cantidad de numeros a meter: "; cin >> cn;
for (int n = 0; n < cn; n++) {
	cout << "pon un numero: "; cin >> nt;
	lista.push_back(nt);
}
*/

//prueba de rendimiento
int cn = 100000;
for (int c = 0; c < cn; c++)
	lista.push_back(rand() % cn+1);

clock_t begin = clock();
const size_t cuarto = lista.size() / 4;
vector <int> lista1(lista.begin(), lista.begin() + cuarto);
vector <int> lista2(lista.begin() + cuarto, lista.begin() + cuarto*2);
vector <int> lista3(lista.begin() + cuarto*2, lista.begin() + cuarto*3);
vector <int> lista4(lista.begin() + cuarto*3, lista.end());
lista.clear();
auto futuro1 = async(selectsort, lista1);
auto futuro2 = async(selectsort, lista2);
auto futuro3 = async(selectsort, lista3);
auto futuro4 = async(selectsort, lista4);
lista1 = futuro1.get();
lista2 = futuro2.get();
lista3 = futuro3.get();
lista4 = futuro4.get();
vector <int> listat1,listat2;
merge(lista1.begin(), lista1.end(), lista2.begin(), lista2.end(), back_inserter(listat1));
lista1.clear(); lista2.clear();
merge(lista3.begin(), lista3.end(), lista4.begin(), lista4.end(), back_inserter(listat2));
lista3.clear(); lista4.clear();
merge(listat1.begin(), listat1.end(), listat2.begin(), listat2.end(), back_inserter(lista));
listat1.clear(); listat2.clear();
clock_t end = clock();

for (int elemento : lista)
	cout << elemento << ' ';
cout << endl;
cout << "\n" <<  double(end - begin) / CLOCKS_PER_SEC << "\n";
}
