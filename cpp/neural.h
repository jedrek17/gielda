#define MAX_LAYERS		3

#define TYPE_LINEAR		0
#define TYPE_BIPOLAR	1
#define TYPE_SIGNUM		2

class Neuron{
public:
	int type;
	int inputs;
	
	double *x;	// inputs
	double *w;	// weights
	
	double y;	// output
	
	double e();		// funkcja sumujaca wejscia
	double f(double in);	// funkcja progujaca
	Neuron();
	Neuron(int t, int i, double *xx, double *ww);
	~Neuron();
};

class Network{
public:
	int layers;
	int size[MAX_LAYERS];			// size of each layer - number of neurons
	Neuron *n[MAX_LAYERS];			// neurons
	int inputs;
	double *in;						// array of inputs
	int outputs;
	double *out;						// array of outputs
	
	Network();
	int LoadFromFile(char *filename);
	int SaveToFile(char *filename);
};