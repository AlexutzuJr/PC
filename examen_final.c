/* Să se creeze o aplicație pentru conversii de bază și manipularea vectorilor. Programul ar trebui să ofere următoarele opțiuni:
1. Citirea unui număr întreg n și a unui vector de lungime n (x) și afișarea elementelor vectorului.
2. Citirea unui număr întreg n și afișarea conversiei numărului în baza 2.
3. Citirea unui vector de lungime fixă 8 (v) și afișarea unui nou vector obținut prin schimbarea fiecărui element 0 cu 1 și invers.
4. Citirea unui vector de lungime fixă 8 (v) și afișarea conversiei vectorului în numărul său echivalent în baza 10. */


#include <stdio.h>
#include <stdlib.h>

void citire(int n,int x[100])
{
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
}

void afisare(int n,int x[100])
{
    for(int i=0;i<n;i++)
        printf("%d ",x[i]);
}

void baza (int n)
{
    int v[8],k=0;
    
    while(n>0)
    {
        v[k]=n%2;
        k++;
        n=n/2;
    }
  
    for(int i=k-1;i>=0;i--)
        printf("%d ",v[i]); 
}

void schimbare(int v[8])
{
    for(int i=0;i<=7;i++)
    {
        if(v[i]==0) 
            printf("1 ");
        else 
            printf("0 "); 
    }
    
}

void baza_zece(int v[8])
{
    int x=1,i,n=0;
  
    for(i=7;i>=0;i--)
    {
        n=n+(v[i]*x);
       
        x=x*2;
    }
        printf("%d ",n);
}


int main()
{
    int t;
    scanf("%d",&t);
  
  if(t==1) 
  {
      int n,x[100];
      scanf("%d",&n);
      citire(n,x);
          afisare(n,x);
  }
  
  if(t==2) 
  { 
      int n;
      scanf("%d",&n);
          baza(n);
  }
  
  if(t==3) 
  { 
      int v[8];
    
      for(int i=0;i<=7;i++)
      scanf("%d",&v[i]);
          schimbare(v);
  }
  
  if(t==4) 
  {
      int v[8];
    
      for(int i=0;i<=7;i++)
          scanf("%d",&v[i]);
          baza_zece(v);  
  }
  
    return 0;
}
