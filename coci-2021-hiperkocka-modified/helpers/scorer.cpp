#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

std::ifstream inp;
std::ifstream out;
std::ifstream con;

void ac() {
  std::cout << "AC\n";
  exit(0);
}

void wa() {
  std::cout << "WA\n";
  exit(0);
}

void ok(int points) {
  std::cout << "OK\n";
  std::cout << points;
  exit(0);
}

void registerScorer(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Must be run with arguments [input-file] [output-file] "
                 "[contestant-output]\n";
    exit(0);
  }

  inp = std::ifstream(argv[1]);
  out = std::ifstream(argv[2]);
  con = std::ifstream(argv[3]);
}

template <class T>
inline void readStream(std::ifstream& ifs, T& t) {
  if (!(ifs >> t))
    wa();
}

int N, U, V, k;

bool hasEdgeOnHypercube(int a, int b)
{
	int v = a ^ b;
	return v && !(v & (v - 1));
}

int main(int argc, char *argv[]) {
    registerScorer(argc, argv);

    readStream(inp, N);
    std::vector<std::pair<int, int>> e;
    for(int i = 0; i < N; i++){
        readStream(inp, U);
        readStream(inp, V);
        e.push_back({U, V});
    }

    std::set<std::pair<int, int>> edgeOnHypercube;
    readStream(con, k);
    if(k < 0 || k > (1 << (N - 1)))
        wa();
	for (int i = 1; i <= k; i++)
	{
		std::vector<int> a(N + 1);
		std::set<int> S;
		for (int j = 0; j <= N; j++)
		{
			readStream(con, a[j]);
			if(a[j] < 0 || a[j] > (1 << (N - 1)))
                wa();
            S.insert(a[j]);
		}
		if (S.size() != N + 1)
			wa();
		for (auto [u, v]: e)
		{
			if (!hasEdgeOnHypercube(a[u], a[v]))
				wa();
			int p = a[u], q = a[v];
			if (p > q) std::swap(p, q);
			if (edgeOnHypercube.count({p, q}))
				wa();
			edgeOnHypercube.insert({p, q});
		}
	}

    if (k == 1 << (N - 1))
		ac();
    
	int score = 70.0 * k / (1 << (N - 1));
	ok(score);

    return 0;
}
