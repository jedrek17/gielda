#include "neural.h"
#include "string.h"
#include "stdio.h"

Neuron::Neuron(){
	type = TYPE_LINEAR;
	x = NULL;
	w = NULL;
	inputs = 0;
	y = 0;
}

Neuron::Neuron(int t, int in, double *xx, double *ww){
	type = t;
	inputs = in;
	x = new double[inputs];
	w = new double[inputs];
	for (int i=0; i<inputs; i++){
		x[i] = xx[i];
		w[i] = ww[i];
	}
}

Neuron::~Neuron(){
	delete[] x;
	delete[] w;
}

double Neuron::e(){
	double result = 0;
	for (int i=0; i<inputs; i++){
		result += x[i]*w[i];
	}
	return result;
}

double Neuron::f(double in){
	if (type == TYPE_LINEAR){
		return in;
	}
	else if (type == TYPE_BIPOLAR){
		if (in < 0) return -1;
		else return 1;
	}
	else if (type == TYPE_SIGNUM){
		if (in < 0) return -1;
		else if (in == 0) return 0;
		else return 1;
	}
	return 0;
}

Network::Network(){
	layers = 0;
	inputs = 0;
	in = NULL;
	outputs = 0;
	out = NULL;
}

int Network::LoadFromFile(char *filename){
	return 0;
}

int Network::SaveToFile(char *filename){
	char filename2[255];
	sprintf(filename2, "%s.ann", filename);
	
	FILE *file = fopen(filename, "w");
	FILE *file2 = fopen(filename2, "w");
	if (!out) return 1;
	
	fprintf(file, "%d\n", layers);
	fprintf(file2, "layers=%d\n",layers);
	fprintf(file, "%d\n", inputs);
	fprintf(file2, "inputs=%d\n",inputs);
	fprintf(file, "%d\n", outputs);
	fprintf(file2, "outputs=%d\n",outputs);
	
	int i;

	for (i=0; i<layers; i++){
		fprintf(file, "%d\n", size[i]);
		fprintf(file2, "size[%d]=%d\n", i, size[i]);
	}

	for (i=0; i<layers; i++){
		for (int j=0; j<size[i]; j++){
			fprintf(file, "%d\n", n[i][j].type);
			fprintf(file, "n[%d][%d].type=%d\n", i, j, n[i][j].type);
			fprintf(file, "%d\n", n[i][j].w);
			fprintf(file, "n[%d][%d].w=%d\n", i, j, n[i][j].w);
		}
	}	
	return 0;
}