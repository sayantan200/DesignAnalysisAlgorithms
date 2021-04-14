#include<bits/stdc++.h>
using namespace std;
# define INF 999


typedef pair<int, int> iPair;

class Graph
{
	int V;


	list< pair<int, int> > *adj;

public:
	Graph(int V); 
	void addEdge(int u, int v, int w);
	void primMST();

};


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}


void Graph::primMST()
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src =0; 
	int cost=0;
	vector<int> key(V, INF); 
	vector<int> parent(V, -1);
	vector<bool> inMST(V, false);   
	pq.push(make_pair(0, src));
    key[src] = 0;

	
	while (!pq.empty())
	{
		
		int u = pq.top().second;
		pq.pop();

		inMST[u] = true; 
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;         
			int weight = (*i).second;

		
			if (inMST[v] == false && key[v] > weight)
			{
			
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}



	for (int i = 1; i < V; ++i)
    {
        cout<<"\nEdge("<<i<<","<<parent[i]<<")"<<"\t"<<i<<"\t\t"<<parent[i]<<"\t\t"<<key[i]<<endl;

		cost=cost+key[i];

    }


cout<<"\nTOTAL WEIGHT (OR COST) OF THIS MINIMUM SPANNING TREE = "<<cost;
}


int main()
{
	int vertices,u,v,w;
	char ans;
	cout<<"Enter the number of vertices: ";
	cin>>vertices;
	Graph g(vertices);

do
{
    cout<<"\nEnter the source vertex and destination vertex for the edge  : ";
	cin>>u>>v;

	cout<<"Enter weight of this edge : ";
	cin>>w;

	g.addEdge(u,v,w);
	cout<<"Want to add more edges('Y'=yes / 'N'=no)? : ";
	cin>>ans;
}while(ans=='y'|| ans=='Y');

    cout<<"\nMIMIMUM SPANNING TREE USING PRIM's ALGORITHM:";
	cout<<"\n-----------------------------------------------------";
    cout<<"\nEdges    Source vertex   Destination vertex  Weight";
    cout<<"\n-----------------------------------------------------";
	g.primMST();

	return 0;
}
