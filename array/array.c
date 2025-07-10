#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct arrayClass;
typedef struct arrayClass
{   
    int size;
    int* ptr;
    void (*create)(struct arrayClass* ptr);
    int (*sizeArr)(struct arrayClass* ptr);
} arrayClass;

void createArr(arrayClass* item){
       item->ptr = (int*)calloc(item->size,sizeof(int));
       for (int i = 0; i < item->size; i++)
       {
          item->ptr[i] = i;
       }
       
}

int returnSize(arrayClass* item){
    int sizeOfTime = 0;
    sizeOfTime = sizeof(item->ptr)/sizeof(int);
    return sizeOfTime;
}

int main(){

    //function isnide struct
    arrayClass item;
    item.size = 10;
    item.create = createArr;
    item.ptr = NULL;
    item.create(&item);
    for (int i = 0; i < item.size; i++)
    {
        printf("this is %d\n", item.ptr[i]);
    }
    item.sizeArr = returnSize;
    printf("%d is the size \n",item.sizeArr(&item));
    
    
    //string 
    char charArr[] = "hello";

    //array decl
    int intArr[] = {1,4,5};
    int intArrSec[3];

    //pntr
    int* ptr = intArr;


    while(ptr<intArr+3)
    {
        printf("%d \n", *ptr);
        ptr++;
    }

    // for (int i = 0; i < (sizeof(intArr)/sizeof(char)); i++)
    // {
    //     printf("%c", intArr[i]);
    // }

    return 0;
}