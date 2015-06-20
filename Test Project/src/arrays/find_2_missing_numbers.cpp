#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	scanf("%d",&n);


	int Nsum = 0;
	int NSsum = 0;

	Nsum = (n*(n+1))/2;
	NSsum = n*(n+1)*(2*n+1)/6;

	vector < int > v (n+1, 0);

	int sum = 0;
	int Ssum = 0;

	for (int i=0; i<n-2; i++) {
		scanf("%d",&v[i]);
		sum = sum + v[i];
		Ssum = Ssum + v[i]*v[i];
	}

	int aplusb = Nsum - sum;
	int asqplusbsq = NSsum - Ssum;

	int twoab = aplusb * aplusb - asqplusbsq;
	int aminusb = int(sqrt(asqplusbsq - twoab));

	int x = (aplusb + aminusb)/2;
	int y = (aplusb - aminusb)/2;

	cout << x << "x " << y << "y " << endl;

	return 0;
}
