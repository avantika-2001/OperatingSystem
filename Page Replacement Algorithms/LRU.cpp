#include<bits/stdc++.h>
using namespace std;
int pageFaults(int pages[],int n,int frames)
{
    unordered_set<int> s;
    unordered_map<int,int> index;
    int pages_fault = 0;
    for(int i=0;i<n;i++)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pages_fault++;
            }
            index[pages[i]] = i;
        }
        else
        {
             if (s.find(pages[i]) == s.end())
            {
                 int lru = INT_MAX, val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {
                    if (index[*it] < lru)
                    {
                        lru = index[*it];
                        val = *it;
                    }   
                }
                 s.erase(val);
                 s.insert(pages[i]);
                 pages_fault++;
            }
            index[pages[i]] = i;
        }
    }
 
    return pages_fault;
}
int main()
{
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    int pages[n];
    cout<<"Enter pages:"<<endl;
    for(int i=0;i<n;i++)
        cin>>pages[i];
    int frames = 3;
    cout << "pages faults = " << pageFaults(pages, n, frames);
    return 0;
}
