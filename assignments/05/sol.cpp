#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int NIL=1234567890;

struct heap
{
    struct node
    {
        int key;
        node *l=NULL, *r=NULL;
        node(int _key=0) : key(_key){}
    } *root=NULL;
    
    static node* merge(node* l, node* r)
    {
        if( l==NULL )
            return r;
        else if( r==NULL )
            return l;
        else if( l->key>r->key )
            swap(l, r);
        
        if( rnd() )
            l->r=merge(l->r, r);
        else
            l->l=merge(l->l, r);
        
        return l;
    }
    
    void insert(int x)
    {
        root=merge(root, new node(x));
    }
    
    int query() const
    {
        return root==NULL ? NIL : root->key;
    }
    
    int erase()
    {
        if( root==NULL )
            return NIL;
        
        int ans=root->key;
        root=merge(root->l, root->r);
        return ans;
    }
    
    static bool rnd()
    {
        static int p, i=0;
        
        if( i<=0 )
            p=rand()&0xFFFF, i=16;
        
        return (p>>--i)&1;
    }
} h[1<<20];

int main()
{
    int m;
    
    for(scanf("%*d%d", &m); m>0; m--)
    {
        int x, y;
        char s[8];
        scanf("%s%d%d", s, &x, &y);
        
        if( s[0]=='i' )
            h[x].insert(y);
        else if( s[0]=='j' )
        {
            h[x].root=heap::merge(h[x].root, h[y].root);
            h[y].root=NULL;
        }
        else
        {
            int ans=s[0]=='l' ? h[x].query() : h[x].erase();
            printf(ans==NIL ? "NULL\n" : "%d\n", ans);
        }
    }
}

