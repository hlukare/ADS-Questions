/*
Problem Statement: Activity on vertex(AOV) network: Sandy is a well organized person. Every day he makes a list of things which need to be done and enumerates them from 
            1 to n. However, some things need to be done before others. Write a C++ code to find out whether Sandy can solve all his duties and if so, print the 
            correct order
*/

/*
// First Code
#include<iostream>
#include<queue>

using namespace std;

class graph 
{
    public:
        int adjmatrix[100][100];
        int inDegree[100];
        int vertices;

    graph(int v) : vertices(v) {
        for (int i = 0; i < vertices; i++) 
          {
            inDegree[i] = 0;
            for (int j = 0; j < vertices; j++) 
               {
                 adjmatrix[i][j] = 0;
               }
          }
    }

    void addEdge(int start, int end) 
      {
        adjmatrix[start - 1][end - 1] = 1;
        inDegree[end - 1]++;
      }

    void topologicalSort() 
    {
        queue<int> q;

        for (int i = 0; i < vertices; i++) 
          {
            if (inDegree[i] == 0) 
              {
                q.push(i);
              }
          }

        int count = 0;
        int order[100];

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();
            order[count++] = u + 1;

            for (int v = 0; v < vertices; v++) 
              {
                if (adjmatrix[u][v] == 1) 
                  {
                    if (--inDegree[v] == 0) 
                      {
                        q.push(v);
                      }
                  }
              }
        }

        if (count != vertices) {
            cout << "Sandy cannot solve all duties due to dependencies.\n";
            return;
        }

        cout << "Sandy can solve all duties in the following order :\n";
        for (int i = 0; i < count; i++) {
            cout << order[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n, m; 
    cout << "Enter the number of duties and dependencies: ";
    cin >> n >> m;

    graph g(n);

    cout << "Enter (dependency -> duty): \n";
    for (int i = 0; i < m; i++) 
      {
        int start, end;
        cin >> start >> end;
        g.addEdge(start, end);
      }

    g.topologicalSort();

    return 0;
}

*/
// Second Code
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int index=0;
stack<int> s;
vector<int> ans;
vector<bool> visited;
void display()
{
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for(int it : ans)
    {
        cout<<" "<<it<<endl;
    }
}

void TOPO(vector<int> v[],int start)
{
    cout<<" "<<start<<endl;
    for(auto it : v[start])
    {
        if(!visited[it])
        {
            visited.at(it) = true;
            TOPO(v,it);
        }
    }
    index++;
    s.push(start);
    
}

int main()
{
    
    int ver1,ver2,edg,len,start;
    cout<<"ENTER THE NO OF EDGES"<<endl;
    cin>>edg;
    vector<int> v[10];
    cout<<"ENTER THE NO OF VERTICES "<<endl;
    cin>>len;

    
    for(int i=0;i<edg;i++)
    {
        cout<<"VERTEX 1 "<<endl;
        cin>>ver1;
        cout<<"VERTEX 2 "<<endl;
        cin>>ver2;
        v[ver1].push_back(ver2);
        
    }
    cout<<"TEST 1"<<endl;
    
    
    cout<<"ENTER THE START "<<endl;
    cin>>start;
    for(int i=0;i<=len;i++)
    {
        visited.push_back(false);
    }

    visited.at(start) = true;
    TOPO(v,start);
    if(index==len)
    {
        cout<<"Duties can be solved by following order:"<<endl;
        display();
    }
    else
    {
        cout<<"NO ORDER TO SOLVE THE DUTIES"<<endl;
    }
    


    return 0;
}

/*
Output: ENTER THE NO OF EDGES
8
ENTER THE NO OF VERTICES 
6
VERTEX 1
1
VERTEX 2
2
VERTEX 1
1
VERTEX 2
3
VERTEX 1
2
VERTEX 2
4
VERTEX 1
2
VERTEX 2
5
VERTEX 1
3
VERTEX 2
4
VERTEX 1
3
VERTEX 2
6
VERTEX 1
4
VERTEX 2
5
VERTEX 1
4
VERTEX 2
6
TEST 1
ENTER THE START
1
 1
 2
 4
 5
 6
 3
Duties can be solved by following order:
 1
 3
 2
 4
 6
 5
*/
