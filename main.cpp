// Ejemplo de programa en C que NO cumple el principio de diseño Abierto/Cerrado
#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 10
#define ELEMENTOS 5

enum TipoFigura {
    circulo, cuadrado, triangulo
};

struct Figura {
    TipoFigura Tipo;
};

struct Punto {
    float x, y;
};

struct Circulo {
    TipoFigura Tipo; // Programación Estructurada TIPIFICA, No válido en POO
    float Radio;
    struct Punto Centro;
};

struct Cuadrado {
    TipoFigura Tipo; // Programación Estructurada TIPIFICA, No válido en POO
    float Lado;
    struct Punto SuperiorIzquierda;
};

struct Triangulo {
    TipoFigura Tipo;
    float Lado1;
    float Lado2;
    float Lado3;
    struct Punto Superior;
};

typedef struct Figura *PunteroFigura;

void DibujaCuadrado(struct Cuadrado *c) {
    printf("\n\nCuadrado");
    printf("\nPunto superior izquierda: %f %f", c->SuperiorIzquierda.x,
            c->SuperiorIzquierda.y);
    printf("\nLongitud del lado : %f", c->Lado);
}

void DibujaCirculo(struct Circulo *c) {
    printf("\n\nCírculo");
    printf("\nCentro: %f %f", c->Centro.x, c->Centro.y);
    printf("\nLongitud del radio: %f", c->Radio);
}

void DibujaTriangulo(struct Triangulo *t) {
    printf("\n\nTriangulo");
    printf("\nPunto superior: %f %f", t->Superior.x,
            t->Superior.y);
    printf("\nLongitud del lado 1: %f", t->Lado1);
    printf("\nLongitud del lado 2: %f", t->Lado2);
    printf("\nLongitud del lado 3: %f", t->Lado3);
}

void DibujaFiguras(PunteroFigura lista[], int n) {
    int i;
    struct Figura *f;
    // Típico switch para identificar el tipo en programación estructurada
    // No válido en POO
    for (i = 0; i < n; i++) {
        f = lista[i];
        switch (f->Tipo) {
            case cuadrado:
                DibujaCuadrado((struct Cuadrado*) f);
                break;
            case circulo:
                DibujaCirculo((struct Circulo*) f);
                break;
            case triangulo:
                DibujaTriangulo((struct Triangulo*) f);
                break;
                
        }
    }
}

int main() {
    struct Cuadrado *c1;
    struct Circulo *c2;
    struct Triangulo *c3;
    int i;
    PunteroFigura lista[MAXIMO];
    for (i = 0; i < ELEMENTOS; i++) {
        if (i % 2 == 0) {
            if (i == ELEMENTOS - 1) {
                c3 = (struct Triangulo*) malloc(sizeof (struct Triangulo));
                c3->Tipo = triangulo;
                c3->Superior.x = c3->Superior.y = 4 * i;
                c3->Lado1 = i * 4.5;
                c3->Lado2 = i * 4.4;
                c3->Lado3 = i * 4.3;
                lista[i] = (struct Figura *) c3;
            } else {
                c1 = (struct Cuadrado *) malloc(sizeof (struct Cuadrado));
                c1->Tipo = cuadrado;
                c1->SuperiorIzquierda.x = c1->SuperiorIzquierda.y = i * 2;
                c1->Lado = i * 2.5;
                lista[i] = (struct Figura *) c1;
            }
        } else {

            c2 = (struct Circulo *) malloc(sizeof (struct Circulo));
            c2->Tipo = circulo;
            c2->Centro.x = c2->Centro.y = 5.0 + i;
            c2->Radio = 10.0 / i;
            lista[i] = (struct Figura *) c2;

        }
    }
    DibujaFiguras(lista, ELEMENTOS);

    getchar();
    getchar();
    return 0;
}
