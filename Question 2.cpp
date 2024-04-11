/*
Problem Statement: Graph traversal: The area around the college and the prominent landmarks of it are represented using graphs. 
              Write a menu driven C++ program to represent this as a graph using adjacency matrix /list and perform DFS and BFS. 
*/

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class graph{
  public :
  int adjmatrix[100][100];
  int vertices;

  graph(int v) : vertices(v)
  {
    for(int i=0;i<vertices; i++)
    {
      for(int j=0;j<vertices;j++)
      {
        adjmatrix[i][j]=0;
      }
    }
  }

  void addEdge(int start, int end)
  {
    adjmatrix[start-1][end-1]=1;
    adjmatrix[end-1][start-1]=1;
  }

  void displayAdjmatrix()
  {
    cout<<"Adjacency matrix "<<endl;
    for(int i=0;i<vertices;i++)
    {
      for(int j=0;j<vertices;j++)
      {
        cout<<adjmatrix[i][j]<<" ";
      }
    cout<<endl;
    }
  }

  void displayadjlist(){
    cout<<"Adjacency List "<<endl;
    
    for( int i=1;i<=vertices;i++)
      { 
        cout<<i<<" ->";
        for(int j=1; j<=vertices;j++)
          {
            if(adjmatrix[i-1][j-1]==1)
             {
              cout<<j<<" ";
             }
          }
        cout<<endl;
      }
  }

  void BFS(int startvertex)
    {
      queue<int>q;
      int visited[100] ={0};
      
      cout<<" BFS : ";
      q.push(startvertex-1);
      visited[startvertex-1]= 1;

      while(!q.empty())
        {
          int current = q.front();
          cout<<current + 1<<" ";
          q.pop();  

          for(int i=0;i<vertices;i++)
          {
            if(adjmatrix[current][i] ==1 && !visited[i])
              {
                q.push(i);
                visited[i]=1;
              }
          }
        }
      cout<<endl;      
    }

    void DFS(int startvertex)
      {
        stack<int>s;
        int visited[100]={0};

        cout<<"DFS : ";
        s.push(startvertex-1);
        visited[startvertex-1]=1;

        while(!s.empty())
          {
            int current = s.top();
            cout<<current +1<<" ";
            s.pop();
            
            for(int i=0; i<vertices;i++)
            {
              if(adjmatrix[current][i]==1 && !visited[i])
                {
                  s.push(i);
                  visited[i]=1;
                }
            }
          }
      }
};

int main()
  {
    int vertices;
    cout<<"Enter no.of vertices : ";
    cin>>vertices;
    graph g(vertices);
    int choice;
    do{
      cout<<"\nMenu "
          <<"\n1.AddEdges "
          <<"\n2.Display Adjacency Matrix"
          <<"\n3.Display Adjacency List"
          <<"\n4.Perform DFS"
          <<"\n5.Perform BFS"
          <<"\n6.Exit";
          cout<<"\nEnter your choice : ";
          cin>>choice;
        
        switch(choice)
          {
            case 1:
              {
                for(int i=0;i<vertices;i++)
                {
                  int start,end;
                  cout<<"Edge "<<i+1<<" ->"<<endl;
                  cout<<"  Start vertex : ";
                  cin>>start;
                  cout<<"    End vertex : ";
                  cin>>end;

                  g.addEdge(start, end);
                }
               cout<<"Edges Added Successfully!"<<endl;
               break;
              }
            case 2:
              {
                g.displayAdjmatrix();
                break;
              }
            case 3:
              {
                g.displayadjlist();
                break;
              }
            case 4:
              {
                int startvertex;
                cout<<"Enter Start Vertex : ";
                cin>>startvertex;
                cout<<endl;
                g.DFS(startvertex);
                break;
              }
            case 5:
              {
                int vertex;
                cout<<"Enter Start vertex : ";
                cin>>vertex;
                cout<<endl;
                g.BFS(vertex);
                break;
              }
            case 6:
              {
                cout<<"Thank You"<<endl;
                break;
              }
            default:
              {
                cout<<"Please Enter Valid Choice"<<endl;
                break;
              }
          }
    }while(choice !=6);

    return 0;
  }

  /*
  Output: Enter no.of vertices : 4

Menu 
1.AddEdges 
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 1
Edge 1 ->
  Start vertex : 1
    End vertex : 2
Edge 2 ->
  Start vertex : 1
    End vertex : 3
Edge 3 ->
  Start vertex : 2
    End vertex : 4
Edge 4 ->
  Start vertex : 3
    End vertex : 5
Edges Added Successfully!

Menu
1.AddEdges
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 2
Adjacency matrix
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

Menu
1.AddEdges
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 3
Adjacency List
1 ->2 3
2 ->1 4
3 ->1
4 ->2

Menu
1.AddEdges
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 4
Enter Start Vertex : 1

DFS : 1 3 2 4
Menu
1.AddEdges
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 5
Enter Start vertex : 1

 BFS : 1 2 3 4

Menu
1.AddEdges
2.Display Adjacency Matrix
3.Display Adjacency List
4.Perform DFS
5.Perform BFS
6.Exit
Enter your choice : 6
  */