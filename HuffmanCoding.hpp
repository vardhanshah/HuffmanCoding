#include<bits/stdc++.h>
#define ford(i,s,e) for(int i=s;i<e;i++)
using namespace std;

using byte = unsigned char;

constexpr size_t BITS_PER_BYTE = numeric_limits<byte>::digits;

using bits_in_byte = bitset<BITS_PER_BYTE>;


const int fqsz = 1 << BITS_PER_BYTE;


vector<int64_t>freq(fqsz);

struct node{
    int l;
    bool is_l;
    int bv;
    int height;
    int64_t freq;
    node *left;
    node *right;
};
node *construct(int l,int64_t freq)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->left=NULL;
    tmp->right = NULL;
    tmp->freq = freq;
    tmp->height =0;
    tmp->l = l;
    tmp->is_l=1;
    return tmp;
}


node *merge(node *a,node *b)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->left = a;
    tmp->right =b;
    tmp->freq = a->freq + b->freq;
    tmp->height = max(a->height,b->height) + 1;
    tmp->is_l = 0;
    return tmp;
}

struct comp  
{
    bool operator()(const node *a,const node *b)
    {
        if(a->freq==b->freq)
            return a->height > b->height;
        return a->freq > b->freq;
    }
};
void print(node *a)
{
    if(a->is_l)
        cout << a->l << endl;
}
node *configure()
{
    priority_queue<node *,vector<node *>,comp> pq;
    ford(i,1,freq.size())
        if(freq[i]!=0)
        {
            pq.push(construct(byte(i),freq[i]));
        }
    while(pq.size()!=1)
    {
        node *a = pq.top();
        pq.pop();
        node *b = pq.top();
        pq.pop();
        pq.push(merge(b,a));
    }
    node *root=pq.top();
    pq.pop();
    return root;
}
