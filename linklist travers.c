#include<stdio.h>
void bubbleshort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++){
            if(a[j]>a[j+1])
            {
                int tamp=a[j];
                a[j]=a[j+1];
                a[j+1]=tamp;

            }

        }

    }

}
void inershort(int a[],int size)
{
   for(int i=0;i<size;i++)
   {


  int tamp=a[i];
        int   j=i-1;
        while(j>=0&& a[j]>tamp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tamp;
    }
}
void slecation (int a[],int size ){
for(int i=0;i<size-1;i++){
    int minimum_index=i;
    for(int j=i+1;j<size;j++){
        if(a[j]<a[minimum_index])
        {
            minimum_index=j;

        }

    }
    int tamp=a[minimum_index];
    a[minimum_index]=a[i];
    a[i]=a[minimum_index];
}


}
int main ()
{
    int a [10];
    for(int i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
   // inershort(a,10);
   //bubbleshort(a,10);
     slecation (a,10);
    for(int i=0; i<10; i++)
    {
        printf("%d  ",a[i]);
    }

    return 0;
}

