#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define pi 3.141592653589793

double calculateSphere(int radius){
    double volume = (double) (4.0/3.0) * pi * radius * radius * radius;
    return volume;
}

double calculateBox(int h, int l, int w){
    double volume = (double) h * l * w;
    return volume;
}

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
        int j = rand() % ( len);

        // swap the two indexes
        swap(&list[i],&list[j]);
    }
}


void quickSort(double * array, int len){
    // base case
    if (len <= 1) return;

    double pivot = array[0];
    int fptr = 1; //front pointer
    int bptr = len - 1; // back
    for (int i = 0; i < len -1; i++){
        if (array[fptr] < pivot){
        //needs to go into smaller partition
        fptr++;

    } else {
        //int is greater in this move towards the right partition
        swap(&array[fptr], &array[bptr]);
        bptr--;
    }
    }
    // at the end swap pivot to right location
    swap(&array[0],&array[fptr-1]);

    //soritng the left side of the partition
    quickSort(array,fptr - 1);
    //sorting the right partition
    quickSort(array + fptr,len - fptr);
    
}

void getInputAndCalculate(double ** moteArr, double ** deviceArr, int * motes, int * devices){
    //input 
    scanf("%d", motes);
    scanf("%d", devices);

    // make an array
    *moteArr = malloc(sizeof(double) * (*motes)); // spheres
    *deviceArr = malloc(sizeof(double) * (*devices)); // boxes
    if (*moteArr == NULL || *deviceArr == NULL)
        printf("Allocation error...");

    // storing and calculations for motes
    int radius;
    for (int i = 0; i < *motes; i++){
        scanf("%d", &radius);
        (*moteArr)[i] = calculateSphere(radius);
    }

    //storing and calculating for devices
    int l, w, h;
    for (int i = 0; i < *devices; i++){
        scanf("%d %d %d", &l, &w, &h);
        (*deviceArr)[i] = calculateBox(h,l,w);
    }

}


double calculateUncontainedVol(double * motesArr, double * deviceArr, int motesLen, int devLen){
    //int used[devLen];
    // like a for loop setting all values to 0
    //memset(used, 0, sizeof(int) * devLen);
    double sum = 0;
    for( int i = motesLen - 1; i >= 0; i--){
        if(devLen > 0 && motesArr[i] <=deviceArr[devLen - 1]){ 
            //used largest availlabe device
            devLen--; // KEEPS TRACK OF UNUSED DEVICE BY DECREMENTING DEVICES ARRAY
        }
        else{
            //add uncontained value to sum
            sum += motesArr[i];
        }
    }

    return sum;
}

int main(){
    int motes = 0;
    int devices = 0;
    double * motesVolume;
    double * deviceVolume;

    getInputAndCalculate(&motesVolume, &deviceVolume, &motes, &devices);
    

    // shuffled for better average cases
    shuffleList(motesVolume,motes);
    shuffleList(deviceVolume,devices);
    printf("\n");
    // sorted array
    quickSort(motesVolume, motes);
    quickSort(deviceVolume,devices);
    printf("\n");

    double res = calculateUncontainedVol(motesVolume,deviceVolume,motes,devices);
    printf("%lf\n", res);

    free(motesVolume);
    free(deviceVolume);

    /*dummy array 
    double arr[7] = {8,7,6,0,4,5,8};
    shuffle(arr,7);
    printArray(arr, 7);
    quickSort(arr, 7);
    printArray(arr, 7);
    */


    

}