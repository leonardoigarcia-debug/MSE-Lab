#include <stdint.h>
#include <stdio.h>

#define SIZE      (40)

typedef void (*sort_func_t)(unsigned char arr[], unsigned int size);

typedef struct lista {
    uint8_t length;
    uint8_t *data;
    char *name;
    sort_func_t sort;
} lista_t;

typedef enum colour{
    GREEN,
    YELLOW,
    RED,
    BLACK,
    PINK,
    BLUE,
    TOTAL_COLORS
} colour_t;


 typedef struct tractor{
    char *brand;
    uint16_t hp;
    colour_t color;
    uint16_t weight;
} tractor_t;

void print_tractor(struct tractor *t) {

    printf("\n\nTractor brand: %s\n", t->brand);
    printf("Tractor horsepower: %d\n", t->hp);
    printf("Tractor color: %d\n", t->color);
    printf("Tractor weight: %d\n", t->weight);

}

void sort_array(unsigned char arr[], unsigned int size) {
    unsigned char output[size];
    unsigned int count[256] = {0};
    
    /* Se cuenta la frecuencia del i-ésimo valor de arr[] */
    for (unsigned int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    /* Se actualiza la suma acumulada del valor de cada conteo */
    for (unsigned int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    
    /* Se construye el arreglo ordenado y se asigna a output[] */
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    /* Se copia el array ordenado a arr[] de forma descendente */
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = output[size - 1 - i];
    }
}

    int main(void) {

        tractor_t t1 = {
            "John Deere",
            870,
            GREEN,
            22400
        };

        print_tractor(&t1);

        t1.brand = "LO CAMBIA TODO\nNUNCA FUE BUENO";
        t1.hp = 900;
        t1.color = YELLOW;
        t1.weight = 23000;

        print_tractor(&t1);

        uint8_t test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                    114, 88,   45,  76, 123,  87,  25,  23,
                                    200, 122, 150, 90,   92,  87, 177, 244,
                                    201,   6,  12,  60,   8,   2,   5,  67,
                                    7,  87, 250, 230,  99,   3, 100,  90};

        
        lista_t l1 = {
            SIZE,
            test,
            "test",
            sort_array
        };

        l1.sort(l1.data , l1.length);

        printf("\n\nArreglo ordenado:\n");
        for (unsigned int i = 0; i < l1.length; i++) {
            printf("%d ", l1.data[i]);
        }

        printf("Datos de objeto lista:\n");
        printf("Nombre: %s\n", l1.name);
        printf("Longitud: %d\n", l1.length);
        printf("Primer elemento del arreglo: %d\n", l1.data[0]);
        printf("Último elemento del arreglo: %d\n", l1.data[l1.length - 1]);

        return 0;
    }
