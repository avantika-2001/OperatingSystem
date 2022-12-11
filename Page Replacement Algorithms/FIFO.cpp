#include<iostream>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;
int pagefaults(int pages[], int n, int frames)
{
    unordered_set<int> s;
    queue<int> index;
    int pages_faults = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pages_faults++;
                index.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int curr = index.front();
                index.pop();
                s.erase(curr);
                s.insert(pages[i]);
                index.push(pages[i]);
                pages_faults++;
            }
        }
    }
    return pages_faults;
}
int main()
{
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    int pages[n];
    cout<<"Enter page references:"<<endl;
    for(int i=0;i<n;i++)
        cin>>pages[i];
    int frames = 3;
    cout << "pages faults = " << pagefaults(pages, n, frames);
    return 0;
}
