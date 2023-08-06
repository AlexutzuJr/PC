/* Să se implementeze o aplicație care să ofere următoarele funcționalități:
1. Citirea și afișarea unei matrice de caractere de dimensiune 26x26.
2. Opțiunea de a introduce două șiruri de caractere M și S, reprezentând mesajul clar și, respectiv, mesajul secret.
3. Opțiunea de a citi un șir de caractere A și o valoare întreagă k și de a crea un nou șir A_nou care conține caracterele din A și repetă secvența de la început când ajunge la sfârșitul șirului.
4. Opțiunea de a citi un șir de caractere A și de a afișa lungimea acestuia.
5. Opțiunea de a cripta mesajul M utilizând mesajul secret S și algoritmul cifrului Vigenère, afișând mesajul criptat. */


#include<stdio.h>
#include<stdlib.h>

//functia pentru citire MATRICE
void citire_matrice(char v[100][100]){
    
    int i;
    int j;
    
    //stocam valori in matrice
    for(i=0; i<26; i++){
        
        for(j=0; j<26; j++){
            
            scanf(" %c", &v[i][j]);
        }
        
    }
    
}

//functia pentru afisare MATRICE   
void afisare_matrice(char v[100][100]){
            
    int i;
    int j;
        
    //afisam matricea
    for(i=0; i<26; i++){
                
        for(j=0; j<52; j++){
                    
            printf("%c", v[i][j]);
                    
        }
                    
    }
        
}

//functia pentru lungime sir
int str_length(char sir[]){
    
    int i=0;
    
    //cat timp e diferit de NULL
    while(sir[i] != '\0')
        i++;
        
    return i;

}


//functia pentru creare sir de caractere
void creare_sir(char sir[], char sir_nou[], int k){
    
    
    int s;      //lungime sir
    int i;
    int j;
    
    //calculam lungimea sirului
    s = str_length(sir);
    
    //punem termenii intr-un sir de dimensiunea k
    for(i=0, j=0; i<k && j<s; i++, j++){
        
        
        //punem termenii din sirul initial si ii resetam daca se termina
        sir_nou[i]=sir[j];
        
        //reinitializam valoarea lui j cu -1 ca sa porneasca de la 0 in loop    
        if(j == s-1)
            j=-1;
        
    }
   
    
}

//functia pentru criptarea Vigenere
void vigenere(char sir_clar[], char sir_secret[], char sir_nou[], char v[100][100] ){
    
    int i;
    int j;
    int z;                      //constanta pentru iterare in for
    int q;                      //constanta pentru iterare in for
    int m;                      //constanta care ne ajuta la afisare
    int n;                      //constanta care ne ajuta la afisare
    char litera_cod;            //litera pentru a forma codul secret
    
    
   //iteram prin matrice pentru a gasi indicele literei din sir_clar in prima linie din sir
    for(i=0; i<str_length(sir_clar) ; i++){
        
        //cautam pe linie litera din sir_clar
        for(j=0; j<26; j++){
            
            if (v[0][j] == sir_clar[i]){
                
                m=j;
                break;  //terminare for cand gaseste val egala
                
            }
            
        }
        
        //cautam pe coloana litera din sir_secret
        for(z=0; z<26; z++){
            
            if(v[z][0] == sir_secret[i]){
                
                n=z;
                break;  //terminare for cand gaseste val egala
                
            }  
            
        }
        
        //pozitia i din sir primeste caracterul de pe pozitia v[m][n]
        sir_nou[i]=v[m][n];
        
    }
    sir_nou[i] = '\0';
    
    
    
}


//functia main 
int main(){
    
    //declarare date
    char M[100];                    //mesajul in clar M
    char S[100];                    //mesajul secret S
    char v[100][100];               //matricea  de caractere
    int k;                          //valoarea lui k
    int optiune;
    int a;                          //lungime sir A
    
   
    //citire si afisare matrice
    citire_matrice(v);
    
    
    //alegem optiunea
    scanf("%d", &optiune);
    
   
    //optiunea 1 
    if(optiune == 1){
        
        scanf("%s", M);
        scanf("%s", S);
    
        printf("%s\n", M);
        printf("%s", S);
       
    }
    
    //optiunea 2
    if(optiune == 2){
        
        char A[100];
        char A_nou[100];
        
        scanf("%s", &A);
        scanf("%d", &k);
      
        creare_sir(A,A_nou,k);
        printf("%s", A_nou);
      
    }
    
    //optiunea 3
    if(optiune == 3){
        
        char A[100];
        int a;
        
        scanf("%s", A);
        a = str_length(A);
        printf("%d", a);
        
    }
    
    //optiunea 4
    if(optiune == 4){
        
        char A_nou[100];
        
        scanf("%s", M);
        scanf("%s", S);
        
        vigenere(M,S,A_nou,v);
        
        printf("%s", A_nou);
       
    }
    
    //optiunea 5
    if(optiune == 5){
        char A_nou[100];
        char A_criptat[100];
        
        scanf("%s", M);
        scanf("%s", S);
    
        creare_sir(S,A_nou,str_length(M));
        vigenere(M,A_nou,A_criptat,v);
        printf("%s", A_criptat);
    }
    
    return 0;
}
