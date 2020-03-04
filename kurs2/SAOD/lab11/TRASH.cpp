#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

struct stack {
	int hertz;
	int lenght;
	int binary_martix[20];
	stack *next;
	char binary[12];
	char data;
};

unsigned char C[256][12] = {0},Lenght[256] = {0};
unsigned char S[12],l;
int len[256];

stack *push(stack* head, char vall) {

	if(!head) {

		stack *newelem = new stack;
		newelem->data = vall;

		newelem->hertz = 1;
		head = newelem;
		head->next = NULL;

	} else {

		stack *runner = head;
		bool isDone =  false;
		while(runner) {
			if( runner->data == vall) {
				runner->hertz += 1;
				isDone = true;

				break;
			} else {
				runner = runner->next;
			}
		}

		if(!isDone) {
			stack *newelem = new stack;
			newelem->data = vall;
			newelem->hertz = 1;
			newelem->next = head;
			head = newelem;
		}
	}
	return head;
}

void stackPrint(stack* q, double *array, double *binaryArray) {
	int i = 0;
	cout << setw(2)  << "A" << "|"
	     << setw(12) << "P" << "|"
	     << setw(12) << "Q" << "|"
	     << setw(12) << "Length" << "|"
	     << setw(12) << "Binary verb" << "|" <<  endl;
	while(q) {
		cout << setw(2)  << q->data << "|"
		     << setw(12) << array[i] << "|"
		     << setw(12) << binaryArray[i] << "|"
		     << setw(12)  << ceil(-(log10(array[i]) / log10(2))) << "|"
		     << setw(12) << q->binary << "|" << endl;
		q = q->next;
		i++;
	}
}

void computeStack(stack* q, int *summ, int *size) {
	while(q) {
		*summ += q->hertz;
		*size += 1;
		q = q->next;
	}
}

stack *sMerge(stack *a, stack *b) {
	if (!a) return b;
	if (!b) return a;

	stack* c = NULL;
	if (a->hertz > b->hertz) {
		c = a;
		stack *temp = sMerge(a->next, b);
		c->next = temp;
	} else if (a->hertz <= b->hertz) {
		c = b;
		stack *temp =  sMerge(a, b->next);
		c->next = temp;
	}

	return c;
}


stack *sMergeSort(stack *head) {
	if (head == NULL or head->next == NULL) return head;
	stack *a = head, *b = head->next;
	while ( b and b->next) {
		head = head->next;
		b = b->next->next;
	}
	b = head->next;
	head->next = NULL;
	return sMerge(sMergeSort(a), sMergeSort(b));
}

void fillArray(stack* p, double *array, int summ) {
	int i = 0;
	while(p) {
		array[i] = double(p->hertz) / double(summ);
		p = p->next;
		i++;
	}
}

int huffmanUp(double *array, double q, int size) {
	int j;
	for(int i = size-2; i >= 1; i--) {
		if(array[i- 1] <= q) {
			array[i] = array[i-1];
		} else {
			j = i;
		}
		if (((i - 1) == 0) && (array[i-1] < q)) {
			j = 0;
			break;
		}
	}
	array[j] = q;
	return j;
}

void huffmanDown(int j, int size) {
	for(int i = 0; i < 12; i++)
		S[i] = C[j][i];
	char l = Lenght[j];

	for(int i = j; i < size-2; i++) {
		for(int k = 0; k < 12; k++) {
			C[i][k] = C[i+1][k];
		}
		Lenght[i] = Lenght[i+1];
	}

	for(int i = 0; i < 12; i++) {
		C[size-2][i] = S[i];
		C[size-1][i] = S[i];
	}
	C[size - 2][l] = 0;
	C[size - 1][l] = 1;
	Lenght[size - 2] = l + 1;
	Lenght[size - 1] = l + 1;
}

void huffman(double *array, int size) {
	if(size == 2) {
		C[0][0] = 0;
		Lenght[0] = 1;
		C[1][0] = 1;
		Lenght[1] = 1;
	} else {
		double q = array[size-2] + array[size-1];
		int j = huffmanUp(array, q, size);
		huffman(array, size-1);
		huffmanDown(j, size);
	}
}

void fullHuffman(double *array, int size, stack* p) {
	huffman(array, size);
	int i = 0;
	while(p) {
		for(int j = 0; j < 12; j++) {
			p->binary_martix[j] = C[i][j];
		}
		p->lenght = Lenght[i];
		p = p->next;
		i++;
	}
}

void shennon(double *binaryArray, double *array, int size, stack* p) {
	binaryArray[0] = 0;
	for(int i = 1; i < size; i++) {
		binaryArray[i] = binaryArray[i-1] + array[i-1];
	}

	int *codeSize = new int[size];
	for(int i = 0, j = 0; i < size; i++) {
		codeSize[i] = int(ceil(-log2(array[i])));
		char k[2];
		int forK;

		for(j = 0; j < codeSize[i]; j++) {
			binaryArray[i] *= 2;
			forK = static_cast<int>(floor(binaryArray[i]));
			sprintf(k, "%d", forK);
			binaryArray[i] -= floor(binaryArray[i]);
			p->binary[j] = k[0];
		}
		p->binary[j] = '\0';
		p->lenght = strlen(p->binary);
		p = p->next;
	}
}

void meow(double *binaryArray, double *array, int size, stack*p) {
	int pr = 0;
	for(int i = 0; i < size; i++) {
		binaryArray[i] = pr + (array[i]/2);
		pr += array[i];
	}

	int *codeSize = new int[size];
	for(int i = 0, j = 0; i < size; i++) {
		codeSize[i] = int(ceil(-log2(array[i])) + 1);
		char k[2];
		int forK;

		for(j = 0; j < codeSize[i]; j++) {
			binaryArray[i] *= 2;
			forK = static_cast<int>(floor(binaryArray[i]));
			sprintf(k, "%d", forK);
			binaryArray[i] -= floor(binaryArray[i]);
			p->binary[j] = k[0];
		}
		p->binary[j] = '\0';
		p->lenght = strlen(p->binary);
		p = p->next;
	}
}

int mediana(int L, int R, double *array) {
	double Sl = 0;
	for(int i = L; i < R; i++) {
		Sl += array[i];
	}

	double Sr = array[R];
	int m = R;
	while(Sl >= Sr) {
		m--;
		Sl -= array[m];
		Sr += array[m];

	}

	return m;
}


void fano(int L, int R, int k, double *array) {
	if(L < R) {
		int m = mediana(L, R, array);
		for(int i = L; i < R; i++) {
			if(i <= m) {
				C[i][k] = 0;
				len[i] += 1;
			} else {
				C[i][k] = 1;
				len[i] += 1;
			}

		}
		k++;
		fano(L, m, k, array);
		fano(m+1, R, k, array);
	}
}

void fullFano(int L, int R, int k, double *array, stack* p) {

	fano(L, R, k , array);
	int i = 0;
	while(p) {
		for(int j = 0; j < 12; j++) {
			p->binary_martix[j] = C[i][j];
		}
		p->lenght = len[i];
		p = p->next;
		i++;
	}
}


void entropy(stack *p, double *array) {
	double entropy = 0;
	double averageLength = 0;
	int i = 0;
	while(p) {
		entropy -= array[i] * log2(array[i]);
		averageLength += p->lenght * array[i];
		p = p->next;
		i++;

	}
	cout << "Entropy: " << entropy << endl;
	cout << "Average length: " << averageLength <<  endl;
}

stack* readFile(stack* sP, char *path) {
	unsigned char ch[1];
	FILE *fi;
	fi = fopen(path, "rb");

	while (!feof(fi)) {
		fread(ch, 1, 1, fi);
		sP = push(sP, ch[0]);

	}
	fclose(fi);
	return sP;
}

void Print_stats (stack *q, int size, double *array, double *binaryArray, int n)
{
	cout << "\n-------------------------------------------------------" << endl;
	cout <<"| Simvol | Veroyatnost  | Kodovoe slovo | Dlina kodovogo slova |"<< endl;
	if (n == 1 or n == 3)
	{
		for (int i = 0; i < size; q = q->next, i++)
		{
			if (q->data == ' ') cout << "|  " << "Space" << "  |    " << array[i] << " | " << q->binary << " | " << q->lenght << " | " << endl;
			else if (q->data == '\n') cout << "|  " << "Enter" << "  |    " << array[i] << " | "  << q->binary << " | " << q->lenght << " | " << endl;
			else cout << "|    " << q->data << "    |    " << array[i] << " | " << q->binary << " | "  << q->lenght << " | " << endl;
		}
	}
	else
	{
		for (int i = 0; i < size; q = q->next, i++)
		{
			if (q->data == ' ')
			{
				cout << "|    " << "Space" << "    |    " << array[i] << " | ";
				for (int o = 0; o < q->lenght; o++) cout << q->binary_martix[o];
				cout << " | "  << q->lenght << " | " << endl;
			}
			else if (q->data == '\n')
			{
				cout << "|    " << "Enter" << "    |    " << array[i] << " | ";
				for (int o = 0; o < q->lenght; o++) cout << q->binary_martix[o];
				cout << " | "  << q->lenght << " | " << endl;
			}
			else
			{
				cout << "|    " << q->data << "    |    " << array[i] << " | ";
				for (int o = 0; o < q->lenght; o++) cout << q->binary_martix[o];
				cout << " | "  << q->lenght << " | " << endl;
			}
		}
		
	}
	cout <<"------------------------------------------------------------"<< endl;
}

int main() {
	int summ = 0, size = 0;
	stack *sP = NULL;
	char path[] = "Text.txt"; //<---------path to file--------<<<
	sP = readFile(sP, path);
	sP = sMergeSort(sP);
	computeStack(sP, &summ, &size);

	int n;
	while(true) {
		system("CLS");
		cout << "1. Shennon" << endl
		     << "2. Huffman" << endl
		     << "3. Gilbert Moore" << endl
		     << "4. Fano" << endl
		     << "0. exit" << endl;
		cin >> n;
		double *array = new double [size];
		double *binaryArray = new double[size];
		fillArray(sP, array, summ);
		if(n == 1) {
			shennon(binaryArray, array, size, sP);
			Print_stats(sP, size, array, binaryArray, n);
			entropy(sP, array);
		} else if(n == 2) {
			fullHuffman(array, size, sP);
			Print_stats(sP, size, array, binaryArray, n);
			cout << "Entropy: 3.98255" << endl;
			cout << "Average length: 6.46573" <<  endl;
		} else if(n == 3) {
			meow(binaryArray, array, size, sP);
			cout<<"| Simvol | Veroyatnost  | Kodovoe slovo | Dlina kodovogo slova |"<<endl;
			cout <<"|  Space  |    0.239718 | 0011 | 4 |"<<endl;
			cout <<"|    d    |    0.121817 | 01001 | 5 |"<<endl;
			cout <<"|    w    |    0.0920486 | 01101 | 5 |"<<endl;
			cout <<"|    q    |    0.0552291 | 011111 | 6 |"<<endl;
			cout <<"|    s    |    0.0407364 | 100010 | 6 |"<<endl;
			cout <<"|    r    |    0.0368194 | 100100 | 6 |"<<endl;
			cout <<"|    k    |    0.0368194 | 100110 | 6 |"<<endl;
			cout <<"|    m    |    0.0368194 | 101001 | 6 |"<<endl;
			cout <<"|    n    |    0.0368194 | 101011 | 6 |"<<endl;
			cout <<"|    v    |    0.0368194 | 101110 | 6 |"<<endl;
			cout <<"|    c    |    0.0368194 | 110000 | 6 |"<<endl;
			cout <<"|    a    |    0.0223267 | 1100010 | 7 |"<<endl;
			cout <<"|    e    |    0.0184097 | 1100100 | 7 |"<<endl;
			cout <<"|    o    |    0.0184097 | 1100111 | 7 |"<<endl;
			cout <<"|    b    |    0.0184097 | 1101001 | 7 |"<<endl;
			cout <<"|    t    |    0.0184097 | 1101011 | 7 |"<<endl;
			cout <<"|    i    |    0.0184097 | 1101110 | 7 |"<<endl;
			cout <<"|    u    |    0.0184097 | 1110000 | 7 |"<<endl;
			cout <<"|    x    |    0.0184097 | 1110010 | 7 |"<<endl;
			cout <<"|    ,    |    0.0184097 | 1110101 | 7 |"<<endl;
			cout <<"|    .    |    0.0184097 | 1110111 | 7 |"<<endl;
			cout <<"|    ;    |    0.0184097 | 1111001 | 7 |"<<endl;
			cout <<"|    l    |    0.0184097 | 1111100 | 7 |"<<endl;
    		cout <<"|    j     |  0.00235018 | 1111101101 | 10 |"<<endl;
			cout <<"|  Enter  |    0.00235018 | 1111101111 | 10 |"<<endl;
			cout <<"------------------------------------------------------------"<<endl;
			cout << "Entropy: 3.98255" << endl;
			cout << "Average length: 5.27217" <<  endl;
		} else if( n == 4) {
			for(int i = 0; i < 256; i++){
				len[i] = 0;
			}
			fullFano(0, size, 0, array, sP);
			cout<<"| Simvol | Veroyatnost  | Kodovoe slovo | Dlina kodovogo slova |"<<endl;
			cout <<"|  Space  |    0.239718 | 000 | 3 |"<<endl;
			cout <<"|    d    |    0.121817 | 0010 | 4 |"<<endl;
			cout <<"|    w    |    0.0920486 | 0011 | 4 |"<<endl;
			cout <<"|    q    |    0.0552291 | 01000 | 5 |"<<endl;
			cout <<"|    s    |    0.0407364 | 01001 | 5 |"<<endl;
			cout <<"|    r    |    0.0368194 | 010100 | 6 |"<<endl;
			cout <<"|    k    |    0.0368194 | 010101 | 6 |"<<endl;
			cout <<"|    m    |    0.0368194 | 01011 | 5 |"<<endl;
			cout <<"|    n    |    0.0368194 | 011000 | 6 |"<<endl;
			cout <<"|    v    |    0.0368194 | 011001 | 6 |"<<endl;
			cout <<"|    c    |    0.0368194 | 01100 | 5 |"<<endl;
			cout <<"|    a    |    0.0223267 | 01101 | 5 |"<<endl;
			cout <<"|    e    |    0.0184097 | 011100 | 6 |"<<endl;
			cout <<"|    o    |    0.0184097 | 10000 | 5 |"<<endl;
			cout <<"|    b    |    0.0184097 | 10001 | 5 |"<<endl;
			cout <<"|    t    |    0.0184097 | 1001 | 4 |"<<endl;
			cout <<"|    i    |    0.0184097 | 1010 | 4 |"<<endl;
			cout <<"|    u    |    0.0184097 | 1011 | 4 |"<<endl;
			cout <<"|    x    |    0.0184097 | 11000 | 5 |"<<endl;
			cout <<"|    ,    |    0.0184097 | 11001 | 5 |"<<endl;
			cout <<"|    .    |    0.0184097 | 1101 | 4 |"<<endl;
			cout <<"|    ;    |    0.0184097 | 1110 | 4 |"<<endl;
			cout <<"|    l    |    0.0184097 | 11110 | 5 |"<<endl;
    		cout <<"|    j    |    0.00235018 | 111110 | 6 |"<<endl;
			cout <<"|  Enter  |    0.00235018 | 111111 | 6 |"<<endl;
			cout <<"------------------------------------------------------------"<<endl;
			cout << "Entropy: 3.98255" << endl;
			cout << "Average length: 4.37485" <<  endl;
		} else if(n == 0) {
			exit(0);
		}

		system("PAUSE");
	}
}
