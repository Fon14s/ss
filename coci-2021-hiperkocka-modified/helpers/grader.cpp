#include "testlib.h"

bool hasEdgeOnHypercube(int a, int b)
{
	int v = a ^ b;
	return v && !(v & (v - 1));
}

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	std::vector<std::pair<int, int>> e;
	for (int i = 0; i < n; i++)
	{
		int u = inf.readInt();
		int v = inf.readInt();
		e.push_back({u, v});
	}
	std::set<std::pair<int, int>> edgeOnHypercube;
	int k = ouf.readInt(0, 1 << (n - 1));
	for (int i = 1; i <= k; i++)
	{
		std::vector<int> a(n + 1);
		std::set<int> S;
		for (int j = 0; j <= n; j++)
		{
			a[j] = ouf.readInt(0, (1 << n) - 1);
			S.insert(a[j]);
		}
		if (S.size() != n + 1)
			quitf(_wa, "Di tree %d: terdapat node yang terduplikasi", i);
		for (auto [u, v]: e)
		{
			if (!hasEdgeOnHypercube(a[u], a[v]))
				quitf(_wa, "Di tree %d: tidak terdapat edge antara %d dan %d pada kubus ajaib", i, a[u], a[v]);
			int p = a[u], q = a[v];
			if (p > q) std::swap(p, q);
			if (edgeOnHypercube.count({p, q}))
				quitf(_wa, "Di tree %d: edge antara %d dan %d digunakan dua kali", i, p, q);
			edgeOnHypercube.insert({p, q});
		}
	}
	if (k == 1 << (n - 1))
		quitf(_ok, "ok");
	double score = 70.0 * k / (1 << (n - 1));
	quitp(score, "ok");
	return 0;
}
