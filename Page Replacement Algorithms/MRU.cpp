#include<bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
 set<int> s;
 map<int, int> indexes;
 int page_faults = 0;
 for (int i=0; i<n; i++)
 {
 if (s.size() < capacity)
 {
 if (s.find(pages[i])==s.end())
 {
 s.insert(pages[i]);
 page_faults++;
 }
 indexes[pages[i]] = i;
 }
 else
 {
 if (s.find(pages[i]) == s.end())
 {
 int mru = INT_MIN, val;
 for (auto it=s.begin(); it!=s.end(); it++)
 {
 if (indexes[*it]>mru)
 {
 mru = indexes[*it];
 val = *it;
 }
 }
 s.erase(val);
 s.insert(pages[i]);
 page_faults++;
 }
 indexes[pages[i]] = i;
 }
 }
 return page_faults;
}
int main()
{
 int pages[100];
 int n;
 cout<<"Enter number of elements"<<endl;
 cin>>n;
 cout<<"Enter the array"<<endl;
 for(int i=0;i<n;i++)
 {
 cin>>pages[i];
 }
 int m = sizeof(pages)/sizeof(pages[0]);
 int capacity;
 cout<<"Enter total number of frames"<<endl;
 cin>>capacity;
 cout <<"Total page faults are: "<< pageFaults(pages, n, capacity)<<"\n";
 return 0;
}
