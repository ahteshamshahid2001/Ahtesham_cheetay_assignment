#include <iostream>
using namespace std;

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
void activityselection(int s[], int f[], int n)
{
	int i, j;

	cout << " Selected activities are " << endl;

	i = 0;
	cout << " " << i;

	// Consider rest of the activities
	for (j = 1; j < n; j++)
	{

		if (s[j] >= f[i])
		{
			cout << " " << j;
			i = j;
		}
	}
}

int main()
{
	int s[] = { 1, 3, 2, 5 };
	int f[] = { 2, 4, 3, 6, };
	int n = sizeof(s) / sizeof(s[0]);
	activityselection(s, f, n);
	return 0;
}
