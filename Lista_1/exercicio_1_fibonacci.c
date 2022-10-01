#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// imprimir os n primeiros numeros de Fibonacci

unsigned int n = 40;



void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}




unsigned int fib_linear(unsigned int n){
    
    int a=0;
    int b=1;

    int n_fib = 0;
    
    for(int i=0;i<n;i++){

        n_fib = a+b;        
        a=b;
        b=n_fib;
        delay(1);

    }

    return n_fib;
}

int main(){


    FILE *f;

    f = fopen("tempos_por_n.csv", "w+");

    clock_t start_t, end_t;
    double total_t;

    unsigned int v[n];

    fprintf(f, "tempo\n");
    for(int i=0;i<n;i++){

        start_t = clock();

        v[i] = fib_linear(i);

        end_t = clock();

        total_t = (double) ((end_t - start_t) / (CLOCKS_PER_SEC/100));

        fprintf(
            f,
            "%f\n", 
            total_t
        );

        
    } 

    fclose(f);
    
}