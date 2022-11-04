#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define fprint(text, ...) printf(text "\n", __VA_ARGS__)
#define print(text) printf("%s\n", text)
#define cursor() printf("> ")
#define clear() printf("\033[H\033[J")

void output(double out, char type, const char* description){
    clear();
    print("------------------------------------------");
    fprint("[%c] Area de un %s: %.2f", type, description, out);
    print("------------------------------------------");
    print("Quieres regresar al menu principal?");
    print("1. Si");
    print("2. Salir");
    cursor();
    int o;
    scanf("%d", &o);
    clear();
    if(o != 1){
        exit(0);
    }
}

void error(const char* msg){
    print("------------------------------------------");
    print(msg);
    print("------------------------------------------");
    exit(0);
}

void square(){
    double l;

    print("------------------------------------------");
    print("Calcula el area de un cuadrado (L x L)");
    print("------------------------------------------");
    print("Indica la longitud");
    cursor();
    scanf("%lf", &l);

    if(l < 0){
        error("Los valores deben ser mayores a 0");
        return;
    }

    output(l*l, 'C', "Cuadrado");
}

void rectangle(){
    double b, h;

    print("------------------------------------------");
    print("Calcula el area de un rectangulo (B x H)");
    print("------------------------------------------");
    print("Indica el ancho");
    cursor();
    scanf("%lf", &b);
    print("Indica la altura");
    cursor();
    scanf("%lf", &h);

    if(b < 0 || h < 0){
        error("Los valores deben ser mayores a 0");
        return;   
    }

    output(b*h, 'R', "Rectangulo");
}

void trapeze(){
    double b1, b2, h;

    print("------------------------------------------");
    print("Calcula el area de un trapecio ((b + B) / 2 x H)");
    print("------------------------------------------");
    print("Indica la base menor");
    cursor();
    scanf("%lf", &b1);
    print("Indica la base mayor");
    cursor();
    scanf("%lf", &b2);
    print("Indica la altura");
    cursor();
    scanf("%lf", &h);

    if(b1 < 0 || b2 < 0 || h < 0){
        error("Los valores deben ser mayores a 0");
        return;   
    }

    output(((b1 + b2) / 2) * h, 'T', "Trapecio");
}

void menu(){

    print("------------------------------------------");
    print("Calcula el area de la figura seleccionada.");
    print("------------------------------------------");
    print("Indica la figura (C, R, T)");
    cursor();
    char l[2];
    scanf("%s", l);
    clear();
    switch(l[0]){
        case 'c':
        case 'C':
            square();
            break;
        case 'r':
        case 'R':
            rectangle();
            break;
        case 't':
        case 'T':
            trapeze();
            break;
        default:
            error("Ocurrio un error, no encontramos la figura que especificaste.");
    }
}

int main(){
    clear();
    while(true){
        menu();
    }
	return 0;
}
