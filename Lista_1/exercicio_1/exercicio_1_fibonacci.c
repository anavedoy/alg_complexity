#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// imprimir os n primeiros numeros de Fibonacci

unsigned int n = 45;

double d = 0.001;



void delay(double milliseconds)
{
    long pause;
    clock_t now,then;

    pause = (double) milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = (double)clock();
    
    while( (now-then) < pause ) now = clock();
}

unsigned int fib_recursiva(unsigned int n){
    
    if (n < 2){
        return n;
    }
    
    return fib_recursiva (n-2) + fib_recursiva (n-1);
}



unsigned int fib_linear(unsigned int n){
    
    int a=0;
    int b=1;

    int n_fib = 0;
    
    for(int i=0;i<n;i++){

        n_fib = a+b;        
        a=b;
        b=n_fib;
        delay(d);

    }

    return n_fib;
}

int main(){


    FILE *f;

    f = fopen("tempos_por_n.csv", "w+");

    clock_t start_t, end_t;
    double total_t_linear, total_t_recursiva;

    unsigned int v_linear[n], v_recursiva[n];

    fprintf(f, "tempo_linear, tempo_recursiva\n");

    for(int i=0;i<n;i++){

        start_t = clock();

        v_linear[i] = fib_linear(i);

        end_t = clock();

        total_t_linear = (double) ((end_t - start_t) / (CLOCKS_PER_SEC/100));


        start_t = clock();

        v_recursiva[i] = fib_recursiva(i);

        end_t = clock();

        total_t_recursiva = (double) ((end_t - start_t) / (CLOCKS_PER_SEC/100));


        fprintf(
            f,
            "%f, %f\n", 
            total_t_linear,
            total_t_recursiva
        );

        
    } 

    fclose(f);
    
}