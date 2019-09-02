#include <iostream>
using namespace std;
int main() {
    
    int n=0;
    cin>>n;
    while(n){
        int *a=new int[n];
        int sum=0;
        for(int i=0;i<n;i++){
            int z=0;
            cin>>z;
            a[i]=z;
        }
        int total = 0, ms = -9999999, h;
        
        
        int local_start = 0;
        
        for (h = 0; h < n; ++h)
        {
            total += a[h];
            if (total < 0)
            {
                total = 0;
                local_start = h + 1;
            }
            else if (total > ms)
            {
                ms = total;
            }
        }
        
        
        sum=ms;
        if(sum>0)
            cout<<"The maximum winning streak is "<<sum<<"."<<endl;
        else
            cout<<"Losing streak."<<endl;
        delete [] a;
        cin>>n;
        
    }
}
