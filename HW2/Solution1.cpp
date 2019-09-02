#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int N, M;
    
    while (cin >> N){
        vector<int> books(N);
        for (int i = 0; i < N; ++i)
            cin >> books[i];
        
        sort(books.begin(), books.end());
        
        cin >> M;
        int ans = 10000;
        int indexi = 0;
        int indexj = 0;
        int i = 0;
        for (int i = 0; i < books.size(); ++i){
            auto it = books.begin();
            if(binary_search(books.begin(), it + i - 1, M - books[i]) || binary_search(it + i + 1, books.end(), M - books[i])){
                int x = books[i];
                int y = M - books[i];
                if(abs(x - y) < ans){
                    ans = abs(x - y);
                    indexi = books[i];
                    indexj = M - books[i];
                }
            }
        }
        if(indexj < indexi)
            swap(indexi, indexj);
        cout << "Mohammad should buy books whose prices are " << indexi << " and " << indexj << ".\n\n";
    }
}
