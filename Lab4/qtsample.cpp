#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QLabel etiqueta("Hola mundo");
    etiqueta.show();
    return app.exec();
}