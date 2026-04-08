#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Arma {
private:
string m_nombre;
string m_tipo;
int m_danoBase;

public:
Arma():m_nombre("Sin arma"), m_tipo("Ninguno"), m_danoBase(0){}

Arma(string nombre, string tipo, int danobase)
:m_nombre(nombre), m_tipo(tipo),m_danoBase(danobase){}

string getNombre() {
return m_nombre;
}
string getTipo() {
return m_tipo;
}

int getDanoBase()
{
return m_danoBase;
}
void mostrarArma() {
cout << "Arma:" << m_nombre << endl;
cout << "Tipo Arma:" << m_tipo << endl;
cout << "Dano Base:" << m_danoBase << endl;
}
};

class Dado
{
private:
int m_caras;

public:
Dado()
:m_caras(6)
{}
Dado(int caras)
:m_caras(caras)
{}
int tirar() {
return rand() % m_caras + 1;

}

};

class Personaje
{
private:
string m_nombre;
string m_raza;
string m_claseRol;
int m_vida;
int m_ataqueBase;
Arma m_arma;

public:
Personaje()
:m_nombre("Sin Nombre"),
m_raza("Desconocida"),
m_claseRol("Sin Clase"),
m_vida(0),
m_ataqueBase(0),
m_arma()
{}

Personaje(string nombre,string raza, string claseRol, int vida, int ataqueBase, Arma arma)
:m_nombre(nombre),
m_raza(raza),
m_claseRol(claseRol),
m_vida(),
m_ataqueBase(ataqueBase),
m_arma(arma)
{}

void mostrarFicha()
{
cout << "\n=====FICHA DEL PERSONAJE=====" << endl;
cout << "Nombre: " << m_nombre << endl;
cout << "Raza: " << m_raza << endl;
cout << "Clase: " << m_claseRol << endl;
cout << "Vida: " << m_vida << endl;
cout << "Ataque Base: " << m_ataqueBase << endl;
m_arma.mostrarArma();
cout << "==========================================" << endl;
}
int atacar(Dado dado)
{
int tirada = dado.tirar();
int danoTotal = m_ataqueBase + m_arma.getDanoBase() + tirada;
cout << "\n" << m_nombre << "ataca" << endl;
cout << "Tirada del dado " << tirada << endl;
cout << "Dano total: " << danoTotal << endl;
return danoTotal;
}

void recibirdano(int dano)
{
m_vida = m_vida - dano;
if (m_vida < 0)
{
m_vida = 0;
}
}

int getVida()
{
return m_vida;
}
string getNombre()
{
return m_nombre;
}
};

int main() {
srand(time(0));
Dado dado6(6);

Arma baston("Bston Arcano", "Magica", 4);
Arma espada("Espada Larga", "Fisica", 5);
Arma arco("Arco Elfico", "Distancia", 4);

Personaje p1("Aelion", "Elfo", "Mago", 30,3,baston );
Personaje p2("Ragnar", "Humano", "Espadachin", 35, 2, espada);
Personaje p3("Lyra", "Elfa", "Arquera", 28, 3, arco);

p1.mostrarFicha();
p2.mostrarFicha();
p3.mostrarFicha();

cout << "\n*****COMBATE*****" << endl;
int dano1 = p1.atacar(dado6);
p2.recibirdano(dano1);
cout << p2.getNombre() << "ahora tiene " << p2.getVida() << " de vida" << endl;

int dano2 = p2.atacar(dado6);
p1.recibirdano(dano2);
cout << p1.getNombre() << "ahora tiene " << p1.getVida() << " de vida" << endl;
cout << " * ***********************************"<< endl;

return 0;
}
