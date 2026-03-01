#include <stdio.h>
void addone(int number[], int add[], int sizeNum); 
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int sizeNum, int pos[][2], int sizePos);
void printAr(int myAr[], int size);
int findMax(int num[], int size);

int main() {
    int number[5] = {20,50,100,99,9};
    int add[5] = {1,2,3,4,5};          
    int pos[] = {0,2,4};               
    int pos2[][2] = {{1,10},{3,20}};   
    int max;

    printAr(number,5);


    addone(number,add,5);
    printAr(number,5);


    addtwo(number,pos,5,5,3);
    printAr(number,5);

    addthree(number,5,pos2,2);
    printAr(number,5);

    max = findMax(number,5);
    printf("Maximum of these numbers is %d\n",max);

    return 0;
}

void addone(int number[], int add[], int sizeNum){
    for(int i=0;i<sizeNum;i++){
        number[i] += add[i];
    }
}


void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos){
    for(int i=0;i<sizePos;i++){
        int index = pos[i];
        if(index>=0 && index<sizeNum){
            number[index] += x;
        }
    }
}


void addthree(int number[], int sizeNum, int pos[][2], int sizePos){
    for(int i=0;i<sizePos;i++){
        int index = pos[i][0];
        int value = pos[i][1];
        if(index>=0 && index<sizeNum){
            number[index] += value;
        }
    }
}

void printAr(int myAr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",myAr[i]);
    }
    printf("\n");
}

int findMax(int num[], int size){
    int maximum = num[0];
    for(int i=1;i<size;i++){
        if(num[i] > maximum)
            maximum = num[i];
    }
    return maximum;
}