#include<bits/stdc++.h>
using namespace std;


long long toh(int N, string from, string to, string aux) {
    
    if(N==1)
    {
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        
        return 1;
    }
    
    int count = 0;
    count = toh(N-1, from, aux, to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    count = count + 1;
    
    count = count + toh(N-1, aux, to, from);
    
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << "Total operations is: "<< toh(n,"[Source]","[Destination]","[auxilary]");
    return 0;
}
