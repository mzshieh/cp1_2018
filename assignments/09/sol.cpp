#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long lld;

const int N = 500000;

struct node
{
	node *l, *r;
	int siz;
	lld val;
	node()
	{
		memset(this, 0, sizeof(node));
	}
} *root;

int n, q;
lld m, a[N + 2];

node* build(int l, int r)
{
	node *res = new node;
	res->siz = r - l + 1;
	if (l < r)
	{
		int mid = (l + r) / 2;
		res->l = build(l, mid);
		res->r = build(mid + 1, r);
		res->val = res->l->val*res->r->val%m;
	}
	else
		res->val = a[l] % m;
	return res;
}

lld query(node *p, int l, int r)
{
	if (l == 1 && r == p->siz)
		return p->val;
	else if (r <= p->l->siz)
		return query(p->l, l, r);
	else if (p->l->siz < l)
		return query(p->r, l - p->l->siz, r - p->l->siz);
	return query(p->l, l, p->l->siz)*query(p->r, 1, r - p->l->siz) % m;
}

void update(node *p, int x, lld y)
{
	if (p->siz == 1)
	{
		p->val = y%m;
		return;
	}
	if (x <= p->l->siz)
		update(p->l, x, y);
	else
		update(p->r, x - p->l->siz, y);
	p->val = p->l->val*p->r->val%m;
}

lld ext_gcd(lld a, lld b, lld &x, lld &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	lld g = ext_gcd(b, a%b, y, x);
	y -= x*(a / b);
	return g;
}

int main()
{
	scanf("%d%d%lld", &n, &q, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	root = build(1, n);
	for (int t, l, r, x; q > 0; q--)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d%d", &l, &r);
			lld res = query(root, l, r);
			lld t, t2;
			res = ext_gcd(m, res, t, t2) > 1 ? -1 : (t2%m + m) % m;
			printf("%lld\n", res);
		}
		else
		{
			lld y;
			scanf("%d%lld", &x, &y);
			update(root, x, y);
		}
	}
}
