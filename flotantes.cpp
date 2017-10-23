#include <iostream> //para funciones principales como imprimir
#include <fstream> //para el manejo de archivos
#include <math.h> //para funciones matematicas
#include <stdlib.h> //para exit()
using namespace std;

int main(){
	int count=0;	
	float sum=0, sum2=0, mean, variance, standard_deviation;
	string word;

	
	ifstream infile;
	infile.open("cadenas.txt");
	if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

	while(infile >> word){
		count++;
	}
	
	infile.close();

	double number[count];

	infile.open("cadenas.txt");

	for(int i=0; i<count; i++)
    {
      infile >>  number[i]; // Reading from the file
    }

	infile.close();

	for(int i=0; i<count; i++)
		sum += number[i];
	mean = (float)sum/count;

	for(int i=0; i<count; i++)
		sum2 += (float)pow(number[i]-mean,2);
	variance = (float)sum2/(count-1);
	standard_deviation = sqrt(variance);

	printf("mean = %.4f\n", mean);
    printf("standard deviation = %.4f\n", standard_deviation);
	
    return 0;
}
