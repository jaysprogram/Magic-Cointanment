#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define pi 3.14159265359

// basic swap function
void swap(double * x, double * y){
    double temp = * x;
    *x = *y;
    *y = temp;
}

//debug function
void printArray(double * list, int len){
    for ( int i = 0; i < len; i++)
        printf("%lf,",list[i]);
    printf("\n");

}

void shuffleList(double * list, int len){
    // get a random seed based on current time
    srand(time(NULL));

    for (int i = 0; i < len - 1; i++){
        // get a random number between i and len - 2
        int j = rand() % ( len - 1);

        // swap the two indexes
        swap(&list[i],&list[j]);
    }
}

int main(){
    int motes = 0;
    int devices = 0;
    double * motesVolume;
    double * deviceVolume;

    //getInputAndCalculate(&motes, &device, );

    // Shuffle for better averages
    shuffleList(motesVolume, motes);
    shuffleList(deviceVolume, devices);

    

}