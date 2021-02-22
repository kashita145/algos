#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
using namespace std;
typedef long long ll;
#define int long long
#pragma GCC optimize("O2")
#define CLR(s) memset(&s, 0, sizeof(s))
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a,x) for (auto& a : x)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
const int MOD = 1e9 + 7;
#define hmap        unordered_map
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll a,ll b,ll m=MOD){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

const int MAXN = 2e5+ 10;
const ll inf = 1e18;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
void read(vi & a) { for (int i = 0; i < sz(a); ++i) cin >> a[i];}
const int mod=1e9+7;

struct node{
    int data;
    node* next;

    node(int x){ //constructor- function with the same name 
        data=x;
        next=NULL;
    }
};

node* insertbegin(node* head, int x){
    // node* temp= new node(x);
    // temp->next=head;

    node* temp;
    temp->data=x; temp->next=head;
    return temp;

}

node* insertend(node* head, int x){
    node* temp=new node(x);
    
    while(head->next!=NULL)
        head=head->next;
    
    head->next=temp;
    return head;
}

void printll(node* head){

    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

}

void printllr (node* head){
    if(head->next==NULL)
        return;
    cout<<head->data<<" ";
    printllr(head->next);

}

int isearch(node* head, int x){
    int pos=1;
    
    while(head->next!=NULL){
        if(head->data==x)
            return pos;
        else{
            pos++;
            head=head->next;
       }
    }
    return -1;
}

int rsearch(node* head, int x){
    if(head->next==NULL)
        return -1;
    
    if(head->data==x)
        return 1;
    else{
        int pos=search(head->next,x);
        if(pos==-1)
            return -1;
        else return pos+1;
    }
}

node* delbegin(node* head){
    if(head->next==NULL)
        return NULL;
    else{
        node* temp=head->next;
        delete head;
        return temp;
    }
}

node* delend(node* head){
    if(head==NULL) // if the list is empty 
        return NULL;

    if(head->next=NULL) // only one node in the list 
        delete head;

    node* temp;
    while(head->next!=NULL){
        temp=head;
        head=head->next;
    }
    delete head;
    temp->next=NULL;
    return temp; // new end
}

node* insertat(node* head, int pos, int x){
    node* temp=new node(x); // temp is a pointer pointing to the new node we're creating 

    int i=1;
    node* curr=head;

    if(pos==1){ // insert in the begining 
        temp->next=head;
        return temp;
    }

    while(i!=pos-1 && curr->next!=NULL){
        i++;
        curr=curr->next;
    }
    if(curr->next==NULL){
        curr->next=temp;
        temp->next=NULL;

    }
    
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

node* sortedinsert(node* head, int x){
    node* temp=new node(x);
    node* curr=head;
    if(curr==NULL) //ll is empty 
        return temp;
    if(curr.data>x){
        temp->next=head;
        return temp;
    }
    while(curr->next!=NULL && curr->next<x){
        curr=curr->next;
    }

    temp->next=curr->next;
    curr->next=temp;

    return head;

}

void printmid(node* head){
    node* slow=head, fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    cout<<slow->data<<endl;

}

void printnnode(node* head, int n){
    node* first=head, second=head;

    if(first==NULL) // empty 
        return;
    
    while(first!=NULL)
        first=first->next;
    if(first==NULL)
        return ;
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }

    cout<<second->data<<endl;
}

node* reversell( node* head){
    node* curr=head, prev=NULL, next=NULL;
    
    if(curr->next==NULL || curr==NULL) //1 node or empty 
        return head;
    
    while(curr->next!=NULL){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }

    return prev;
}

node* recrevll(node* head){
    if(head==NULL || head->next==NULL)
        return head;
    
    node* resthead=recrevll(head->next), resttail=head->next;

    resttail->next=head;
    head->next=NULL;

    return resthead;
}

void removedups(node* head){
    node* curr=head;

    if(curr->next==NULL || curr==NULL) // empty or size=1;
        return ;

    while(curr->next!=NULL && curr->!=NULL){
        
        if(curr->data==curr->next->data){
            node* temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        } else curr=curr->next;

    }
}

int32_t main(){

    return 0;
}
