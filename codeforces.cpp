#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll M = 998244353;

ll powerm(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} return res%M; }
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x); y=y>>1; x=(x*x);} return res; }

const int N = 5e5 + 5;
ll fact[N], inv[N];
 
void pre(int n){fact[0] = inv[0] = 1;for(ll i=1;i<=n;i++){fact[i] = (fact[i-1]*i)%M;inv[i] = powerm(fact[i],M-2);}}
 
ll C(ll n,ll r){ll ans = ((fact[n]*inv[r])%M + M)%M;ans = ((ans*inv[n-r])%M + M)%M;return ans;}

struct linklist{
    int data;
    linklist* next;
    linklist(){
        
    }
    linklist(int x){
        data=x;
        next=NULL;
    }
};

void make_linklist(linklist* &head,int val){
    linklist* temp=new linklist(val);
    if(head==NULL){
        head=temp;
        return;
    }
    linklist* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m;
        vector<linklist*> v(n);
        for(int i=0;i<n;i++){
            linklist* head=NULL;
            for(int j=0;j<m;j++){
                cin>>k;
                make_linklist(head,k);

            }
            v[i]=head;
        }
        // cout<<"here"<<endl;
        map<int,vector<vector<int>>> mp;
        for(int i=0;i<n;i++){
            linklist* head=v[i],*curr=v[i],*prev;
            int st=0,count=1,counter=0;
            while(curr!=NULL){
                // cout<<"here is "<<curr->data<<endl;
                counter++;
                prev=curr;
                curr=curr->next;
                if(curr==NULL) break;
                if(prev->data==curr->data) count++;
                else{
                    if(prev->data==1){
                        mp[1].push_back({i,st,st+count-1});
                    }
                    else mp[0].push_back({i,st,st+count-1});
                    st=counter;
                    count=1;
                }
                // cout<<"here i am nnnnn"<<endl;
                
            }
            // cout<<"here i am"<<endl;
            if(prev->data==1){
                mp[1].push_back({i,st,st+count-1});
            }
            else mp[0].push_back({i,st,st+count-1});
            // cout<<"reach hre"<<endl;
        }
        for(auto x:mp){
            cout<<x.first<<": ";
            for(auto y:x.second){
                cout<<"( ";
                for(auto p:y) cout<<p<<" ";
                cout<<")";
            }
            cout<<endl;
        }

    }
}