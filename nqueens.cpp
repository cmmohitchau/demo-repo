#include <iostream>
#include <vector>
using namespace std;

void display(int X[] , int n)
{
    for(int i = 1 ; i <= n ; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
    return;
}
bool Place(int i , int k , int n , int X[])
{
    for(int j = 1 ; j <= k - 1 ; j++)
    {
        if(X[j] == i || (abs(X[j] - i) == abs(j-k)))
        return false;
    }
    return true;
}

void nqueens(int k , int n , int X[])
{
    for(int i = 1 ; i <= n ; i++)
    {
        if(Place(i,k,n,X))
        {
            X[k] = i;
            if(k == n){
                display(X,n);
                return ;
            }
            else nqueens(k+1,n,X);
        }
    }
}
int main()
{
    int n ;
    cout << "Enter the number of queens : ";
    cin >> n;
    int X[n+1];
    nqueens(1,n,X);


    return 0;
}