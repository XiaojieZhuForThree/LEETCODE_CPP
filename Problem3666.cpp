#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using std::string;
using std::vector;
using std::set;
using std::queue;

class Solution {
public:
    int minOperations(string s,int k){
        int n=s.size();
        int z0=0;
        for(char c:s) if(c=='0') ++z0;
        if(z0==0) return 0;

        vector<int> dist(n+1,-1);
        set<int> rem[2];
        for(int v=0;v<=n;++v) rem[v&1].insert(v);

        queue<int> q;
        dist[z0]=0;
        rem[z0&1].erase(z0);
        q.push(z0);

        auto push=[&](int v,int d){
            dist[v]=d;
            rem[v&1].erase(v);
            q.push(v);
        };

        while(!q.empty()){
            int z=q.front(); q.pop();
            int d=dist[z];

            int ilo=std::max(0, k-(n-z));
            int ihi=std::min(k, z);
            int L = z + k - 2*ihi;
            int R = z + k - 2*ilo;
            if(L<0) L=0;
            if(R>n) R=n;

            int parity=(z+k)&1;
            auto it=rem[parity].lower_bound(L);
            while(it!=rem[parity].end() && *it<=R){
                int v=*it;
                ++it;
                push(v,d+1);
                if(v==0) return d+1;
            }
        }
        return -1;
    }
};