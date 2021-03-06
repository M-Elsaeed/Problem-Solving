#include <map>
#include <string>
#include <math.h>
#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



/*//Second sol A2

#include <bits/stdc++.h>
using namespace std;

int n[3];
int p[3];
int cnt[3];
long long r;
string s;

bool can(long long x) {
long long need = 0;
for(int i = 0 ; i < 3 ; i++) {
long long butuh = max(0ll,cnt[i]*x - n[i]);
need += butuh * p[i];
}
return need <= r;
}

int main() {
cin >> s;
for(char x : s) {
if(x == 'B') cnt[0]++;
else if(x == 'S') cnt[1]++;
else cnt[2]++;
}
for(int i = 0 ; i < 3 ; i++) cin >> n[i];
for(int i = 0 ; i < 3 ; i++) cin >> p[i];
cin >> r;

long long lo = 0, hi = 1e13;
while(lo < hi) {
long long mid = (lo + hi+1) / 2;
if(can(mid))
lo = mid;
else
hi = mid-1;
}

cout << lo << endl;
return 0;
}

*/





void probA() {

	string x;
	cin >> x;
	if (x[0] >= 97 && x[0] <= 122) {
		x[0] -= 32;
	}
	cout << x;
}

void probB() {
	int size;
	cin >> size;
	//cout << "size = " << size << " , size even " << size % 2 << endl;
	if (size > 2 && size % 2 == 0) {
		cout << "YES" << endl;
		return;
	}
	for (int i = 2; i < (size / 2) + 1; i += 2) {
		//cout << "i = " << i << " , size - i = " << size - i << endl;
		if (size - i % 2 == 0) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

void probC() {
	int numHotels = 0;
	int minDist = 0;
	int possible = 2;
	cin >> numHotels >> minDist;
	vector <int> hotels;
	for (int i = 0; i < numHotels; i++) {
		int temp;
		cin >> temp;
		hotels.push_back(temp);
	}
	for (int i = 0; i < numHotels - 1; i++) {
		int x1 = hotels[i];
		int x2 = hotels[i + 1];
		int middle = x1 + minDist;
		if (x2 - (x1 + minDist) >= minDist) {
			possible++;
		}
		if ((x2 - minDist) - x1 >= minDist && ((x2 - minDist) != middle)) {
			possible++;
		}
	}
	cout << possible << endl;
}

void probD() {
	int count = 0;
	int k = 0;
	int nominated = 0;
	cin >> count >> k;
	vector <int> contestants;
	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		contestants.push_back(temp);

	}

	if (contestants[0] > 0) {
		if (contestants[k - 1] > 0) {
			int last = contestants[k - 1];
			nominated = k;
			for (int i = k; i < contestants.size(); i++) {
				if (contestants[i] >= last) {
					nominated++;
				}
				else {
					break;
				}
			}
		}
		else {
			for (int i = 0; i < k; i++) {
				if (contestants[i] > 0) {
					nominated++;
				}
			}
		}
	}
	cout << nominated << endl;
}

void probE() {
	string word;
	cin >> word;
	if (word[0] == 104 && word[1] == 101 && word[2] == 108 &&
		word[3] == 108 && word[4] == 111) {
		cout << "YES" << endl;
		return;
	}
	if (word.length() < 5) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 104) {
			for (int j = i + 1; j < word.size(); j++) {
				if (word[j] == 101) {
					for (int k = j + 1; k < word.size(); k++) {
						if (word[k] == 108) {
							for (int l = k + 1; l < word.size(); l++) {
								if (word[l] == 108) {
									for (int m = l + 1; m < word.size(); m++) {
										if (word[m] == 111) {
											cout << "YES" << endl;
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "NO" << endl;
}

void probF() {
	int count = 0;
	cin >> count;
	vector <int> coins;
	int wholeSum = 0;
	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		wholeSum += temp;
		coins.push_back(temp);
	}
	sort(coins.begin(), coins.end());
	int myCoins = 0;
	int mySum = 0;
	for (int i = count - 1; i >= 0; i--) {
		if (mySum <= (wholeSum - mySum)) {
			mySum += coins[i];
			myCoins++;
		}
		else {
			break;
		}
	}
	cout << myCoins << endl;;

}

void probG() {
	int count = 0;
	cin >> count;
	map <string, int> users;
	string newUser;
	cin >> newUser;
	cout << "OK" << endl;
	users[newUser] = 1;

	for (int i = 1; i < count; i++) {
		cin >> newUser;
		if (users.count(newUser) == 0) {
			cout << "OK" << endl;
			users[newUser] = 1;
		}
		else {
			cout << newUser << users[newUser] << endl;
			users[newUser] ++;
		}

	}

}

void probH() {
	int nDays = 0;
	long long perPage = 0;
	cin >> nDays >> perPage;
	vector <long long> nNames;

	for (int i = 0; i < nDays; i++) {
		long long temp;
		cin >> temp;
		nNames.push_back(temp);
	}
	long long space = 0;
	for (int i = 0; i < nDays; i++) {
		long long x = nNames[i];
		// When I realised how stupid I am 
		/* https://hybridtechcar.com/wp-content/uploads/2018/03/download-85.jpg */
		space += x;
		cout << space / perPage << endl;
		space %= perPage;
	}
}

void probI() {
	int n = 0;
	int l = 0;
	cin >> n >> l;
	vector <double> lanterns;
	for (int i = 0; i < n; i++) {
		double temp;
		cin >> temp;
		lanterns.push_back(temp);
	}
	sort(lanterns.begin(), lanterns.end());
	double maxDist = 0;
	for (int i = 0; i < lanterns.size() - 1; i++) {
		if (maxDist < lanterns[i + 1] - lanterns[i])
		{
			maxDist = lanterns[i + 1] - lanterns[i];
		}
	}
	maxDist = maxDist / (double)2;
	if (((double)lanterns[0]) > maxDist)
		maxDist = (double)lanterns[0];
	if ((double)(l - lanterns[lanterns.size() - 1]) > maxDist)
		maxDist = (double)(l - lanterns[lanterns.size() - 1]);
	cout << fixed << maxDist << endl;

}

void probJ() {
	int n;
	int m;
	cin >> n >> m;
	vector<int>segments;
	vector<int> onLine(m + 1, 0);
	int count = 0;


	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;
		segments.push_back(x1);
		segments.push_back(x2);
	}


	for (int p = 1; p <= m; p++) {

		for (int j = 0; j < segments.size() - 1; j += 2) {
			int x1 = segments[j], x2 = segments[j + 1];
			if (p >= x1 && p <= x2) {
				if (onLine[p] == 0) {
					count++;
				}
				onLine[p]++;
				break;
			}
		}
	}


	cout << m - count << endl;
	for (int i = 1; i <= m; i++) {
		if (onLine[i] == 0) {
			cout << i << " ";
		}
	}
	cout << endl;

}




void probA2() {
	string recipe;
	long long  B = 0, C = 0, S = 0;
	long long  inB = 0, inC = 0, inS = 0;
	long long  pB = 0, pC = 0, pS = 0;
	long long money = 0;
	cin >> recipe;
	cin >> inB >> inS >> inC;
	cin >> pB >> pS >> pC;
	cin >> money;

	for (int i = 0; i < recipe.size(); i++) {
		if (recipe[i] == 66) {
			B++;
		}
		else if (recipe[i] == 67) {
			C++;
		}
		else if (recipe[i] == 83) {
			S++;
		}
	}
	long long cost = (B * pB) + (C * pC) + (S * pS);
	long long burgers = 0;
	while (money >= 0 || (inB >= B && inS >= S && inC >= C)) {

		long long burgersB = LLONG_MAX, burgersS = LLONG_MAX, burgersC = LLONG_MAX;
		long long toMake;

		if (inB >= B && inS >= S && inC >= C) {
			if (B > 0)
				burgersB = inB / B;
			if (S > 0)
				burgersS = inS / S;
			if (C > 0)
				burgersC = inC / C;

			toMake = min(burgersB, burgersS);
			toMake = min(toMake, burgersC);
			inB -= B * toMake;
			inS -= S * toMake;
			inC -= C * toMake;
			burgers += toMake;
		}

		toMake = money / cost;


		if (!(inB >= B) && ((B - inB)*pB <= money)) {
			if (toMake > 0) {
				money -= ((toMake*B) - inB)*pB;
				inB = (toMake*B);
			}
			else {

				money -= (B - inB)*pB;
				inB = B;
			}

		}
		if (!(inS >= S) && ((S - inS)*pS <= money)) {
			if (toMake > 0) {
				money -= ((toMake*S) - inS)*pS;
				inS = (toMake*S);
			}
			else {

				money -= (S - inS)*pS;
				inS = S;
			}
		}
		if (!(inC >= C) && ((C - inC)*pC <= money)) {
			if (toMake > 0) {
				money -= ((toMake*C) - inC)*pC;
				inC = (toMake*C);
			}
			else {

				money -= (C - inC)*pC;
				inC = C;
			}
		}
		if (inB >= B && inS >= S && inC >= C) {
			if (B > 0)
				burgersB = inB / B;
			if (S > 0)
				burgersS = inS / S;
			if (C > 0)
				burgersC = inC / C;
			toMake = min(burgersB, burgersS);
			toMake = min(toMake, burgersC);
			inB -= B * toMake;
			inS -= S * toMake;
			inC -= C * toMake;
			burgers += toMake;
		}
		else {
			//cout << burgers << endl;
			break;
		}

	}
	cout << burgers << endl;
}

void probB2() {
	int n;
	cin >> n;
	vector<int>prices;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		prices.push_back(temp);
	}

	int q;
	cin >> q;
	vector<long long>money;

	for (int i = 0; i < q; i++) {
		int temp;
		cin >> temp;
		money.push_back(temp);
	}

	sort(prices.begin(), prices.end());

	for (int i = 0; i < q; i++) {
		cout << (upper_bound(prices.begin(), prices.end(), money[i]) - prices.begin()) << endl;
	}
}

void probC2() {
	long long n = 0;
	int k = 0;
	cin >> n >> k;
	long long v, low = 1, high = n;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long quot = 1, sum = 0;
		while (sum < n && quot <= mid) {
			sum += mid / quot;
			quot *= k;
		}
		if (sum >= n) {
			v = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << v << endl;
}


void probD2() {
	long long x, y, m;
	cin >> x >> y >> m;
	long long count = 0;
	if (max(x, y) >= m) {
		cout << 0 << endl;
		return;
	}
	if (x > y)
		swap(x, y);
	if (y <= 0) {
		cout << -1 << endl;
		return;
	}

	if (x < 0) {
		count = abs(x / y);
		x += abs(x / y) * y;
	}
	while (!(max(x, y) >= m)) {
		x += y;
		count++;
		if (x > y)
			swap(x, y);
	}
	cout << count << endl;
}

//discrete double binary search
void probE2() {
	int n, k;
	cin >> n >> k;
	vector <double> Es;
	double max = DBL_MIN;
	for (int i = 0; i < n; i++) {
		double temp;
		cin >> temp;
		if (max < temp)
			max = temp;
		Es.push_back(temp);
	}

	double low = 0, high = max;
	double mid = 0;
	double energy = 0;
	while ((high - low) > (1E-9))
	{
		mid = low + (high - low) / 2;
		bool feasable = false;

		double needed = 0;
		double extra = 0;
		for (int i = 0; i < n; i++) {
			if (Es[i] < mid) {
				needed += (mid - Es[i]);
			}
			else {
				extra += (Es[i] - mid) - (((Es[i] - mid)*k) / 100);
			}
		}
		if (extra >= needed)
			energy = low = mid;
		else
			high = mid;
	}
	cout << fixed << energy << endl;
}

void probF2() {
	int n, m;
	cin >> n >> m;
	int count = 0;
	for (int a = 0; a <= sqrt(n); a++) {
		int b = 0;
		while (b <= sqrt(m)) {
			if (((a*a) + b == n) && (a + (b * b) == m))
				count++;
			b++;
		}
	}
	cout << count << endl;
}

//discrete integer binary and cumulative sum
void probG2() {
	int n, m;
	vector<int> a, q, cum, sol;
	cum.push_back(0);
	sol.push_back(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		cum.push_back(cum[cum.size() - 1] + temp);
		a.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		q.push_back(temp);
	}
	for (int i = 0; i < q.size(); i++) {
		int worm = q[i];
		int tempSol = 0, low = 0, high = cum.size() - 1;
		while (low <= high) {
			long long mid = low + ((high - low) / 2);
			if (cum[mid] >= worm) {
				tempSol = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		sol.push_back(tempSol);
	}
	for (int i = 1; i < sol.size(); i++) {
		cout << sol[i] << endl;
	}
}

void probH2() {
	int c1, c2, c3, c4, n, m;
	cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
	vector<int>bus, troll;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		bus.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		troll.push_back(temp);
	}
	long long busSum = 0;
	for (int i = 0; i < n; i++) {
		if ((bus[i] * c1) < c2) {
			busSum += bus[i] * c1;
		}
		else {
			busSum += c2;
		}
	}
	if (busSum > c3)
		busSum = c3;


	long long trollSum = 0;
	for (int i = 0; i < m; i++) {
		if ((troll[i] * c1) < c2) {
			trollSum += troll[i] * c1;
		}
		else {
			trollSum += c2;
		}
	}
	if (trollSum > c3)
		trollSum = c3;
	long long globalSum;
	if (trollSum + busSum > c4)
		globalSum = c4;
	else
		globalSum = trollSum + busSum;
	cout << globalSum << endl;
}

void probJ2() {
	long long n;
	long long t;
	cin >> n;
	cin >> t;
	vector<long long>books;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		books.push_back(temp);
	}
	int j = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && t >= books[j])
			t -= books[j++];
		sum = max(sum, j - i);
		t += books[i];
	}
	cout << sum << endl;
}


void probI2() {
	int n;
	long long d;
	cin >> n >> d;
	vector<pair <long long, long long>> comps;
	for (int i = 0; i < n; i++) {
		long long  mon, fact;
		cin >> mon >> fact;
		comps.push_back(make_pair(mon, fact));
	}
	sort(comps.begin(), comps.end());
	vector<long long> mon;
	vector<long long> cumFact;
	mon.push_back(comps[0].first);
	cumFact.push_back(comps[0].second);
	for (int i = 1; i < n; i++) {
		mon.push_back(comps[i].first);
		cumFact.push_back(comps[i].second + cumFact[cumFact.size() - 1]);
	}


	long long maxFactor = 0;
	for (int i = 0; i < n; i++) {

		auto ind = upper_bound(mon.begin(), mon.end(), comps[i].first + d);

		long long factor = cumFact[ind - mon.begin() - 1] - cumFact[i] + comps[i].second;
		if (maxFactor < factor)
			maxFactor = factor;
	}

	cout << maxFactor << endl;
}

/////////////////////////////


void Rnd508A() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector <int> v(k, 0);
	for (int i = 0; i < s.size(); i++) {
		v[s[i] - 65]++;
	}

	int m = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < m)
		{
			m = v[i];
		}
	}
	cout << m * k << endl;

}

long long gcd(long long a, long long b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
void Rnd508B() {
	int n;
	cin >> n;
	bool can = false;
	vector <long long> cumsum(n + 1, 0);
	vector <int> ns(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		ns[i] = i;
		cumsum[i] = (cumsum[i - 1] + i);
	}


	long long sum1, sum2;
	for (int size = 1; size < n; size++) {
		for (int start = 1; start <= n - size; start++) {
			int end = size + start - 1;
			sum1 = cumsum[end] - cumsum[start - 1];
			sum2 = cumsum[start - 1] + cumsum[n] - cumsum[end];
			//cout << sum1 << " " << sum2 << endl;
			if (gcd(sum1, sum2) > 1) {
				cout << "Yes" << endl;
				cout << size << " ";
				for (int i = start; i <= end; i++) {
					cout << i << " ";
				}
				cout << endl;
				cout << n - size << " ";
				for (int i = 1; i < start; i++) {
					cout << i << " ";
				}
				for (int i = end + 1; i <= n; i++) {
					cout << i << " ";
				}
				cout << endl;
				return;
			}
		}
	}

	cout << "No" << endl;

}

void Rnd508C() {
	int n;
	cin >> n;
	vector <int> A, B;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long scoreA = 0, scoreB = 0;
	while (A.size() > 0 || B.size() > 0) {

		if (A.size() > 0 && B.size() > 0 && A[A.size() - 1] > B[B.size() - 1]) {
			scoreA += A[A.size() - 1];
			A.pop_back();
		}
		else if (B.size() > 0) {
			//remove last B item
			B.pop_back();
		}
		else if (A.size() > 0) {
			scoreA += A[A.size() - 1];
			A.pop_back();
		}


		if (A.size() > 0 && B.size() > 0 && B[B.size() - 1] > A[A.size() - 1]) {
			scoreB += B[B.size() - 1];
			B.pop_back();
		}
		else if (A.size() > 0) {
			//remove last A item
			A.pop_back();
		}
		else if (B.size() > 0) {
			scoreB += B[B.size() - 1];
			B.pop_back();
		}
	}





	cout << scoreA - scoreB << endl;
}


void Rnd508D() {
	long long n;
	cin >> n;
	vector <long long> slimes;
	for (long long i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		slimes.push_back(temp);
	}

	for (int i = 0; i < n - 1; i++) {
		long long j = 0;
		long long midMin = j;
		for (j = 0; j < slimes.size(); j++) {
			if (slimes[j] < slimes[midMin])
				midMin = j;
		}


		if (midMin > 0 && midMin < n - 1) {

			if (slimes[midMin + 1] > slimes[midMin - 1]) {
				slimes[midMin] = slimes[midMin + 1] - slimes[midMin];
				slimes.erase(slimes.begin() + midMin + 1);
			}
			else {
				slimes[midMin] = slimes[midMin] - slimes[midMin - 1];
				slimes.erase(slimes.begin() + midMin - 1);
			}

		}
		else if (midMin == 0)
		{
			slimes[midMin] = slimes[midMin] - slimes[midMin + 1];
			slimes.erase(slimes.begin() + midMin + 1);
		}
		else
		{
			slimes[midMin] = slimes[midMin] - slimes[midMin - 1];
			slimes.erase(slimes.begin() + midMin - 1);
		}
		cout << "a" << endl;
	}
	cout << slimes[0] << endl;
}




//int main() {
//	return 0;
//}

int main()
{
	long long n;

	vector<pair<vector<long long>, long long>> nodes;
	vector <long long> dummy;
	cin >> n;
	nodes.assign(n, make_pair(dummy, 0));
	vector<long long> apples;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		apples.push_back(x);
	}
	for (int i = 0; i < n - 1; i++)
	{
		long long x;
		cin >> x;
		nodes[i + 1].first.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		nodes[i].second = apples[i];
	}

	return 0;
}