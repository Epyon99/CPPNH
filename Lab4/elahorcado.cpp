#include <iostream>
#include <algorithm>

using namespace std;
struct Juego {
  string palabraSecreta;
  int vida = 10;
  string jugador;  
  bool conVida = true;

  void herir(){
    vida--;
  }
};
int main()
{
    Juego partido;
    cout << "Jugador escribe tu nombre:" << endl;
    cin >> partido.jugador;
    partido.palabraSecreta = "qwerqwtqr";
    char respuesta;
    while (partido.conVida)
    {
        cout << "Di una letra (muahaha):" << endl;
        cin >> respuesta;
        auto it = find(partido.palabraSecreta.begin(), partido.palabraSecreta.end(), respuesta);
        if (it != partido.palabraSecreta.end()){
            cout << "Sigues vivo";
        }
        else {
            partido.herir();
            cout << "Vida Restante:" << partido.vida << endl;
            if (partido.vida < 0){
                partido.conVida = false;
            }
        }
    }
}
