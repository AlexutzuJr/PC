/* Să se realizeze un program care să determine:
1. Media a trei valori întregi a, b, c.
2. Suma tuturor numerelor prime mai mici decat un număr arbitrar m.
3. Valoarea y calculată astfel:
   y= -x+3, pentru x=0
      3, pentru x=[1,4]
      3x-9, pentru x>4  
4. Calcularea sumei numerelor mai mici decât un număr dat și care sunt multiplu de 3 sau 5. */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    //alegem optiunea 
    int optiune;
    scanf("%d", &optiune);
    
    if(optiune==1)
    {
        int a;
        int b;
        int c;
        float media;
        
        //citim de la tastatura valorile a, b si c
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        
        media=(float)(a+b+c)/3;
        printf("%.4f", media);
    }
    
    if(optiune==2)
    {
        int i;
        int j;
        int m; //limita
        int prim;
        int suma=0;
        
        //citim de la tastatura numarul m care este limita
        scanf("%d", &m);
        
        //gasim numerele prime pana la m
        for(i=2;i<m;i++)
        {
            prim=1;
            
            //verificam daca numarul este prim sau nu
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    //i nu este prim
                    prim=0;
                    break;
                }
            }
            
            //este prim deci adaugam la suma
            if(prim==1)
            {
                suma=suma+i;
                printf("%d", i);
            }
        }
        
        //afisam suma
        printf("\n%d", suma);
    }
    
    if(optiune==3)
    {
        int x;
        int y;
        
        //citim de la tastatura x
        scanf("%d", &x);
        
        if(x==0)
        y=-(x)+3;
        
        if(x>=1 && x<=4)
        y=3;
        
        if(x>4)
        y=3*x-9;
        
        printf("%d", y);
    }
    
    if(optiune==4)
    {
        int n;
        int suma=0;
        int i;
        
        //citim de la tastura n
        scanf("%d", &n);
        
        //aflam numerele mai mici decat n care sunt multiplu de 3 sau 5
        for(i=3;i<n;i++)
        {
            //verificam daca este multiplu de 3 sau 5
            if(i%3==0 || i%5==0)
            //adaugam la suma
            suma=suma+i;
        }
        
        printf("%d", suma);
    }
    
    return 0;
}
