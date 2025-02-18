
#include <iostream>
using namespace std;

class Graph {
private:
    int size;
    int** arr;

public:
    Graph(int v) {
        this->size = v;
        arr = new int*[v];
        for (int i = 0; i < v; i++) {
            arr[i] = new int[v];
            for (int j = 0; j < v; j++) {
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v,int weight) {
        arr[u][v] = weight;
        arr[v][u] = weight;  // For undirected graph
    }

    void display() {
        cout << "Graph :" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
   
    void degree() {
        int count =0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (arr[i][j]!=0)
                count ++;
            }  
            
            cout << "Degree: "<<count<<endl;  count =0; 
        } 
        
    }

    bool adjacent(int a,int b)
    {
        return arr[a][b];
    }
};

int main() {
    int a,b;
    int size = 4;
    Graph g(size);

    g.addEdge(0, 1,5);
    g.addEdge(0, 2,1);
    g.addEdge(1, 2,9);
    g.addEdge(2, 3,6);

    g.display();
    g.degree();
    cout<<"Find Out the adjacency" <<endl;
    cout<<"Enter A: ";
    cin >> a;
    cout<<"Enter B: ";
    cin >> b;
    cout<< g.adjacent(a,b)<<endl;
    return 0;
}

