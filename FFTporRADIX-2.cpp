//
//                   CÁLCULO DE FFT PELO ALGORITMO RADIX-2
//
// 	Por: Heitor Lemos
//	12/08/2021
//
//________________________________________________________________________________________

#include <iostream>
#include <iomanip> // biblioteca para manipulação de valores de entrada e saída
#include <cmath>
#include <complex.h> //biblioteca para utilização de números complexos

#define PI 3.14159

using namespace std;

int main()
{
//________________________________________________________________________________________
//             P A R T E  I  (E N C O N T R A N D O  x[N])

	int fs = 8000; // frequência de amostragem (Hz)
	int f1 = 1000; // frequência 1 (Hz)
	int f2 = 2000; // frequência 2 (Hz)
	int N = 16; // número de amostras
	double x[N]; // sinal
	
		for(int n = 0; n<N; n++) //encontrando os valores de x[n]
		{
			x[n]=sin(2*PI*n*f1*1/fs) + 0.5*sin(2*PI*f2*n*1/fs + 3*PI/4);

			
		}

//_____________________________________________________________________________________
//            P A R T E  II  (E N C O N T R A N D O  A  FFT)

	int N2 = N/2;
	int N4 = N/4;
	_Complex double	WN[N];
    _Complex double	B[N2];
    _Complex double	A[N2];
    _Complex double Xm[N];

	

	for(int m = 0; m < N; m++)//Encontrando WN
	{
		
		WN[m] = cos(2*PI*m/N) -1.0*sin(2*PI*m/N)*_Complex_I;
		

				
	}
	
	for(int m = 0; m < N2; m++)//Encontrando B(m)
		{
			B[m]=0 + 0*_Complex_I;
		
		for(int n = 0; n < N4; n++)
		{
			B[m]+=x[4*n+1]*cos(2*PI*2*n*m/N2)+x[4*n+3]*1.0*cos(2*PI*(2*n+1)*m/N2) - (x[4*n+1]*(-1.0)*sin(2*PI*2*n*m/N2)+x[4*n+3]*sin(2*PI*(2*n+1)*m/N2))*_Complex_I;
			

	}	

}
	for(int m = 0; m < N2; m++)//Encontrando A(m)
		{
			A[m]=0 + 0*_Complex_I;
		
		for(int n = 0; n < N4; n++)
		{
			A[m]+=x[4*n]*cos(2*PI*2*n*m/N2)+x[4*n+2]*1.0*cos(2*PI*(2*n+1)*m/N2) - (x[4*n]*(-1.0)*sin(2*PI*2*n*m/N2)+x[4*n+2]*sin(2*PI*(2*n+1)*m/N2))*_Complex_I;
			

	}	


}
	
	for(int m = 0; m < N2; m++)// Encontrando a saída X(m)
	{
		Xm[m]=A[m]+WN[m]*B[m];
		Xm[m+N2]=A[m]-WN[m]*B[m];


		
		
	}
	for(int m = 0; m<N; m++)
	{
		cout<<setprecision(3)<<fixed; //Necessita da biblioteca iomanip
		cout<<cabsf(Xm[m])<<endl;//Valor absoluto de X(m) utilizando a funcao cabsf() da biblioteca complex.h
	}
	
	return 0;	
	
}
