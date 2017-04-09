//Damian Darczuk
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int ALFA = 26;
const int MAX = 80;

int szyfrowanie(int tryb, int klucz, char nazwa_in[], char nazwa_out[]) {
	
	char znak;
	klucz = klucz * tryb;
	
    ifstream plikIn(nazwa_in, ios::in);
    if(!plikIn) {
        cout << "Plik wejsciowy nie otwarty\n";
        return 0;
    }
    
    ofstream plikOut(nazwa_out, ios::out);
    if(!plikOut) {
        cout << "Plik wyjsciowy nie otwarty\n";
        return 0;
    }
    
    while(plikIn.get(znak)) {
    	if ((znak>='a')&&(znak<='z'))
    		{
    			znak -= 'a';
    			znak += klucz;
    			znak = znak%ALFA; 
    			if (znak < 0)
    				znak += ALFA;
    			znak += 'a';
    			plikOut.put(znak);

    		}
    		
    	else if ((znak>='A')&&(znak<='Z'))
    		{
    			znak -= 'A';
    			znak += klucz;
    			znak = znak%ALFA; 
    			if (znak < 0)
    				znak += ALFA;
    			znak += 'A';
				plikOut.put(znak);						    	
			}
    		else
    			plikOut.put(znak);	

    }
    plikOut.close();
    plikIn.close();
    return 0;
}

double najmniejszy_blad(double roznica[]) {
	double MIN;
	MIN = roznica[0];
	for (int i=0; i<ALFA; i++)
	{
		if (MIN > roznica[i])
		{
			MIN = roznica[i];
		}
	}
	
	return MIN;
}

int lamanie(char nazwa_in[], char nazwa_out[])
{	
	char znak;
	double litery[ALFA];
	double procent[ALFA];
	int	ilosc_liter=0;
	double procentowo_alfabet[]={8.91 , 1.47 , 3.96 , 3.25 , 7.66 , 0.30 , 1.42 , 1.08 , 8.21 , 2.28 , 3.51 , 2.10 , 2.80 , 5.52 , 7.75 , 3.13 , 0.14 , 4.69 , 4.32 , 3.98 , 2.50 , 0.04 , 4.65 , 0.02 , 3.76 , 5.64 };
	double roznica[ALFA];
	int przesuniecie=0;

    ifstream plikIn(nazwa_in, ios::in);
    if(!plikIn) {
        cout << "Plik wejsciowy nie otwarty\n";
        return 0;
    }
    
    for (int i = 0; i<ALFA; i++)
    {
  		litery[i] = 0;
    	procent[i] = 0; 
    	roznica[i] = 0;
   	}
    	
	while(plikIn.get(znak)) {
		if ((znak>='a')&&(znak<='z'))
    		{
    			znak -= 'a';
    			litery[znak]++;
				ilosc_liter++;
    		}
    		
    	else if ((znak>='A')&&(znak<='Z'))
    		{
    			znak -= 'A';
				litery[znak]++;	
				ilosc_liter++;					    	
			}
	}
	
	for (int j = 0; j<ALFA; j++)
    	procent[j] = litery[j]/ilosc_liter*100; 
    	
    for (int l=0; l<ALFA; l++)	
   		for (int k = 0; k<ALFA; k++)
    		roznica[l]+=abs(procent[k+l]-procentowo_alfabet[k]);
    
	for (int m=0; m<ALFA; m++)
	{
		if(roznica[m]==najmniejszy_blad(roznica))
			break;
		przesuniecie++;			
	}
	
	cout << "Przesuniecie wynosi: " << przesuniecie;
	szyfrowanie(-1, przesuniecie, nazwa_in, nazwa_out);
	
/* 	
	for (int i = 0; i<ALFA; i++)
		cout << roznica[i] << " ";
	cout << endl;
	for (int i = 0; i<ALFA; i++)
		cout << procent[i] << " ";
*/
    plikIn.close();
    return 0;
}

int bruteforce () {
	
}

void pisz(int nr)
{	
	switch (nr){

		case 1 :	{
			cout << endl;
			cout << "                 Szyfr Cezara" << endl;
			cout << "                 1 - Zaszyfruj plik tekstowy" << endl;
			cout << "                 2 - Oszyfruj plik tekstowy" << endl;
			cout << "                 3 - £amanie zaszyfrowanego tekst" << endl;	
			cout << "                 4 - £amanie zaszyfrowanego tekst metod¹ Brute force" << endl;
			cout << endl;
			cout << "          Podaj tryb : ";
			break;
		}
		case 2 :	{
			cout << endl;
			cout << "Podaj nazwê pliku wejsciowego:";
			break;
		}
		case 3 : {
			cout << "Podaj przesuniêcie :";
			break;
		}
		case 4 : {
			cout << "Podaj nazwê pliku wyjsciowego: ";
			break;
		}
	}
}

int main()
{
	int tryb, przesuniecie;
	char nazwa_in[MAX], nazwa_out[MAX];
	
	pisz(1);
	cin >> tryb;
	if (tryb != 3)
	{
		pisz(3);
		cin >> przesuniecie;
	}
	pisz(2);
	cin >> nazwa_in;
	pisz(4);
	cin >> nazwa_out;
	
	switch (tryb)
		{
			case 1 : {			
				szyfrowanie(1, przesuniecie, nazwa_in, nazwa_out);
				break;
			}
		
			case 2 : {
				szyfrowanie(-1, przesuniecie, nazwa_in, nazwa_out);
				break;
			}
		
			case 3 : {
				lamanie(nazwa_in, nazwa_out);
				break;
			}
		
			case 4 : {
				break;
			}
		
			default:  {  
				cout << endl;
				cout << "Podaj dobry tryb!" << endl;	
				break;
			}	
		}
		
	return 0;
}


