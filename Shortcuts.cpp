// Shortcuts for "common" data types in contests
typedef long long	ll;
typedef pair<int, int>	ii;
typedef vector<ii>	vii;
typedef vector<int>	vi;

#define INF 1000000000		// 1 billion, safer than 2B for Floyd Warshall's

// Common memset settings
memset(memo, -1, sizeof mem);	// initialize DP memoization table with -1
memset(arr, 0, sizeof arr);		// clear an array of integers

index = (index + 1) %n;			// ++index; if (index >= n) index = 0;
index = (index + n - 1) %n);		// --index; if (index < 0) index = n - 1;
int ans = (int)((double)d + 0.5);	// for rounding to nearest integer
ans = min(ans, new_computation);	// min/max shortcut

