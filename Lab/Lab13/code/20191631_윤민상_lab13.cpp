#include <iostream>
#include <fstream>

using namespace std;

class ShPath {
private:
	bool *found;	
	int *distance;	
	int **cost;
	int numOfVertex;	
	int MAX;	
public:
	ShPath() {
		found = new bool[100];
		distance = new int[100];
	}
	void initCostMatrix1();	
	void initCostMatrix2();	
	void printCostMatrix();
	void printDistance();
    void shortestPath1(int v);
	void shortestPath2(int v);	
    int chooseNode1();
	int chooseNode2();
};

void ShPath::initCostMatrix1() {
	ifstream infile;
	infile.open("data.txt", ios::in);

	infile >> numOfVertex;

	cost = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) {
			infile >> cost[i][j];
		}
	}
	MAX = 999;
	infile.close();
}

void ShPath::initCostMatrix2() {
	ifstream infile;
	infile.open("data.txt", ios::in);

    infile >> numOfVertex;

	cost = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) {
			infile >> cost[i][j];
		}
	}
	MAX = 999;

	infile >> numOfVertex;

	cost = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		cost[i] = new int[numOfVertex];
		for (int j = 0; j < numOfVertex; j++) {
			infile >> cost[i][j];
		}
	}
	MAX = 999;
	infile.close();
}

void ShPath::printCostMatrix() {
	cout << "\t";
	for (int i = 0; i < numOfVertex; i++) {
		cout << "V" << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < numOfVertex; i++) {
		cout << "V" << i << "\t";
		for (int j = 0; j < numOfVertex; j++) {
			cout << cost[i][j] << "\t";
		}
		cout << endl;
	}
}

void ShPath::printDistance() {
	for (int i = 0; i < numOfVertex; i++) {
		cout << distance[i] << " ";
	}
}

void ShPath::shortestPath1(int v) {
	int i, u, w;
	for (i = 0; i < numOfVertex; i++) {
		found[i] = false;
		distance[i] = cost[v][i];
	}

	found[v] = true;
	distance[v] = 0;
	cout << "start from vertex 0 :    Distance ->    ";
	for (i = 0; i < numOfVertex - 1; i++) {
		printDistance();
		cout << endl;

		u = chooseNode1();
		found[u] = true;

		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
			}
		}
		cout << "Select Node : " << u << "    Distance ->    ";
	}
	printDistance();
	cout << endl;
}

void ShPath::shortestPath2(int v) {
	int i, u, w;
	for (i = 0; i < numOfVertex; i++) {
		found[i] = false;
		distance[i] = cost[v][i];
	}

	found[v] = true;
	distance[v] = 0;
	cout << "start from vertex 0 :    Distance ->    ";
	for (i = 0; i < numOfVertex - 1; i++) {
		printDistance();
		cout << endl;

		u = chooseNode2();
		found[u] = true;

		for (w = 0; w < numOfVertex; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
			}
		}
		cout << "Select Node : " << u << "    Distance ->    ";
	}
	printDistance();
	cout << endl;
}

int ShPath::chooseNode1() {
	int min, minNode;
	min = MAX;

	for (int i = 0; i < numOfVertex; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minNode = i;
		}
	}
	return minNode;
}

int ShPath::chooseNode2() {
	int min, minNode;
	min = MAX;

	for (int i = 0; i < numOfVertex; i++) {
		if (distance[i] <= min && !found[i]) {
			min = distance[i];
			minNode = i;
		}
	}
	return minNode;
}

int main() {
	ShPath sh, sh1;
	cout << "***** Adjacency matrix *****" << endl;
    cout << endl;
	sh.initCostMatrix1();
	sh.printCostMatrix();
    cout << endl;
	cout << "***** Shortest Path *****" << endl;
    cout << endl;
	sh.shortestPath1(0);

	cout << endl;

	cout << "***** Adjacency matrix *****" << endl;
    cout << endl;
	sh1.initCostMatrix2();
	sh1.printCostMatrix();
    cout << endl;
	cout << "***** Shortest Path *****" << endl;
    cout << endl;
	sh1.shortestPath2(0);
}