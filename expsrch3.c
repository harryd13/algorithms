#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include  <string.h>
#include  <sys/types.h>
#include <sys/wait.h>
#define SZ 20
struct tup{
    int l;
    int r;
};

int data[SZ] = {1,3,2,4,6,7,8,12,32,44,21,322,111,54,56,76,98,87,55,66};
int key = 6;
int ans = 0;
int countex= 0;
int countb = 0;
int exponentialSearch();
int bSearch();

int min(int a,int b){
    if(a<b)
    return a;
    else
    {
        return b;
    }
    
}

int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 
int printarr(int st,int en)
{
    for (int  i = st; i < en; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    
}
void * binarySearch(void * para); // int l, int r

int main()
{
    qsort(data, SZ, sizeof(int), compare); 
    printarr(0,SZ);
    exponentialSearch();
    printf("time = %d\n",countb);
    printf("the key %d is present at %d\n",key,ans);
    sleep(2);
    countb = 0;
    bSearch();
    printf("time = %d\n",countb);
    printf("the key %d is present at %d\n",key,ans);

    return 0;
}
int exponentialSearch(){
    
    // If x is present at firt location itself 
    if (data[0] == key) 
        return 0; 

    // Find range for binary search by 
    // repeated doubling 
    int i = 1; 
    while (i < SZ && data[i] <= key) 
        i = i*2; 
    //put i/2 and min of i and SZ in l ans r
    int len = min(i,SZ) - i/2;
    int j = len/4;
    printf("%d,%d,%d,%d,%d\n",i/2,len,i/2 + j,i/2 + j + j + j,min(i,SZ));

    struct tup * tp1 = (struct tup*)malloc(sizeof(struct tup));
    tp1->l = i/2;
    tp1->r = i/2 + j;
    struct tup * tp2 = (struct tup*)malloc(sizeof(struct tup));
    tp2->l = i/2 + j + 1;
    tp2->r = i/2 + j + j;
    struct tup * tp3 = (struct tup*)malloc(sizeof(struct tup));
    tp3->l = i/2 + j + j + 1;
    tp3->r = i/2 + j + j + j;
    struct tup * tp4 = (struct tup*)malloc(sizeof(struct tup));
    tp4->l = i/2 + j + j + j +1;
    tp4->r = min(i,SZ);
    //  Call binary search for the found range. using threads
    pthread_t tid[4];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid[0],&attr,binarySearch,tp1);
    pthread_create(&tid[1],&attr,binarySearch,tp2);
    pthread_create(&tid[2],&attr,binarySearch,tp3);
    pthread_create(&tid[3],&attr,binarySearch,tp4);
    
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    pthread_join(tid[3],NULL);
    
    //ans = binarySearch(i/2, min(i, SZ)); 
    
}
void * binarySearch(void * para) // int l, int r
{ 
    countb ++;
    struct tup* tp = para;
    int l = tp->l;
    int r = tp->r;
    if (r >= l) 
    { 
        int mid = l + (r - l)/2; 
        printf("~~~~~");
        printarr(l,r);
        // If the element is present at the middle 
        // itself 
        if (data[mid] == key){
            ans = mid;
            return mid; 
        }
        // If element is smaller than mid, then it 
        // can only be present n left subarray 
        if (data[mid] > key) {
            struct tup * t = (struct tup*)malloc(sizeof(struct tup));
            t->l = l;
            t->r = mid -1 ;
            return binarySearch( t); 
        }
        // Else the element can only be present 
        // in right subarray 
        else{
            struct tup * t = (struct tup*)malloc(sizeof(struct tup));
            t->l = mid+1;
            t->r = r;
            return binarySearch(t); 
        }
    } 
  
    // We reach here when element is not present 
    // in array 
    return -1; 
    pthread_exit(NULL);
} 
int bSearch()
{
    
    struct tup * tp = (struct tup*)malloc(sizeof(struct tup));
    tp->l = 0;
    tp->r = SZ;
    
    //  Call binary search for the found range. using threads
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,binarySearch,tp);
    
    pthread_join(tid,NULL);
    


}