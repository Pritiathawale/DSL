#include<bits/stdc++.h>
using namespace std;
#define max 3

class airport
{
    string cities[max];
    int dist[max][max];
    public:
    int n;
    void input();
    void display();
    airport();
};

airport::airport()
{
    n=0;
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        dist[i][j]=0;
    }
    for(int i=0;i<max;i++)
    cities[i]='NULL';
}

void airport::input()
{
    int i,j,k;
    cout<<"Enter the total number of the cities: ";
    cin>>n;
    for(k=0;k<n;k++)
    {
        cout<<"Enter the city name: ";
        cin>>cities[k];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<max;j++)
        {
            cout<<"Enter the distance between "<<cities[i]<<" to "<<cities[j]<<endl;
            cin>>dist[i][j];
            dist[j][i]=dist[i][j];
        }
    }
}

void airport::display()
{
    int i,j,k;
    cout<<"\t";
    for(k=0;k<n;k++)
    cout<<cities[k]<<"\t";
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<cities[i]<<"\t";
        for(j=0;j<n;j++)
        cout<<dist[i][j]<<"\t";
        cout<<"\t";
        cout<<"\n";
    }
}

int main()
{
    airport x;
    time_t start,end;
    double time_req;
    time(& start);
    x.input();
    x.display();
    time(& end);
    time_req=difftime(end,start);
    cout<<"\nTime Required is : "<<time_req<<endl;
    return 0;
}
