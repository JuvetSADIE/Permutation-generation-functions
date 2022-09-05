#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>


void unrank(unsigned long int n, mpz_t rang, unsigned long int* pi){
unsigned long int temp, mod;
mpz_t a;   // Déclare deux variables grands entiers.
mpz_t b;
mpz_t q;  // Déclare deux autres  variables "grands entiers".
mpz_t r;
mpz_init( a );   // Les initialise (nécessaire)
mpz_init( b );
mpz_init( q );   // Les initialise (nécessaire)
mpz_init( r );

while(n>0){
  temp    = pi[n-1]; 
  // Calcule la division de a par b ( a = q * b + r )
    mpz_set (a , rang );
    mpz_set_ui (b , n );
    mpz_fdiv_qr( q, r, a, b );
  //pi[n-1] = pi[rang%n]; 
    mod = mpz_get_ui(r);    
    pi[n-1] = pi[mod]; 
  //pi[rang%n] = temp; 
    pi[mod] = temp; 

  //rang=rang/n;
    mpz_fdiv_qr( q, r, a, b );
    mpz_set(rang, q); 
    n=n-1; 
    
}
// Libère la mémoire
  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( q );
  mpz_clear( r );
}

void rank(unsigned long int n, unsigned long int* pi, unsigned long int* pi1){
 unsigned long int temp,s=0,i;
unsigned long int tabn[n];
unsigned long int tabs[n];
mpz_t st, nt, rang;
mpz_init( st );
mpz_init( nt );
mpz_init( rang );
mpz_set_ui (rang, 0);
  //if(n==1) return 0;
i=n;
while(n>1){
  s=pi[n-1];
  temp = pi[n-1];
  pi[n-1] = pi[pi1[n-1]];
  pi[pi1[n-1]] = temp;

  temp = pi1[s];
  pi1[s] = pi1[n-1];
  pi1[n-1] = temp;
 
  /*mpz_set_ui (st , s );
  mpz_set_ui (nt , i );
  mpz_addmul(st,nt, rang);
  mpz_set(rang, st); */
  tabn[n-1]=n;
  tabs[n-1]=s;
  //printf("\ns=%ld n=%ld",s,n);
  //return (s+n* rank(n-1, pi, pi1));
  //i++;
  n--;
}
n=i;
i=2;
while(i<=n){
  mpz_set_ui (st , tabs[i-1] );
  mpz_set_ui (nt , tabn[i-1] );
  mpz_addmul(st,nt, rang);
  mpz_set(rang, st); 
  //printf("\ns=%ld, n=%ld rank= %s\n",tabs[i-1], tabn[i-1], mpz_get_str (NULL, 10, rang));
  i++;
}
printf("\n\nrank= %s\n",mpz_get_str (NULL, 10, rang));
//return rang;
}



int main()
{
   	 
unsigned long int rep, n, i,f;
unsigned long int* pi;
unsigned long int* pi1;
unsigned long int temp;
mpz_t r;
mpz_init( r );

printf("1-----> RANK : \n");
printf("2-----> UNRANK : ");


scanf("%ld",&rep);

switch (rep){

case 1 : 
	printf("Number of elements = ");
	scanf("%ld",&n);
	
	pi  = (unsigned long int*) malloc(n*sizeof(unsigned long int));
	pi1 = (unsigned long int*) malloc(n*sizeof(unsigned long int));

	for(i=0;i<n;i++){
	  printf("permutation[%ld]= ",i);
	  scanf("%ld",&pi[i]);	  
	  pi1[pi[i]] = i;
	}
	rank(n,pi,pi1);
	//printf("\nrank= %s\n",mpz_get_str (NULL, 10, (mpz_t)rank(n,pi,pi1)));
	break; 
case 2 :
	printf("Number of elements = "); //nombre d'éléments
	scanf("%ld",&n);
	printf("rang = ");//rang
	//scanf("%ld",&r);
	gmp_scanf( "%Zd", r );
	
	pi = (unsigned long int*) malloc(n*sizeof(unsigned long int));
	for(i=0;i<n;i++){
	  pi[i] = i;
	}
	unrank(n,r,pi);
	for(i=0;i<n;i++){
	  printf(" %ld ",pi[i]);
	}
	printf("\n");
	break;

default : 
	printf("END ...");
}

    return 0;
}
