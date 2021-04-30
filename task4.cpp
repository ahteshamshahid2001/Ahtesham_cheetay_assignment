#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct meeting {
	int start;
	int end;
	int pos;
};

bool comparator(struct meeting m1, meeting m2)
{
	return (m1.end < m2.end);
}

void maxMeeting(int s[], int f[], int n)
{
	 meeting meet[6];
	for (int i = 0; i < 6; i++)
	{
		// Starting time of meeting i.
		meet[i].start = s[i];

		// Finishing time of meeting i
		meet[i].end = f[i];

		// Original position/index of meeting
		meet[i].pos = i + 1;
	}

	sort(meet, meet + 6, comparator);
	vector<int> m;
	m.push_back(meet[0].pos);
	int time_limit = meet[0].end;

	// Check for all meeting whether it
	// can be selected or not.
	for (int i = 1; i < n; i++) {
		if (meet[i].start >= time_limit)
		{
			// Push selected meeting to vector
			m.push_back(meet[i].pos);

			// Update time limit.
			time_limit = meet[i].end;
		}
	}
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

int main()
{
	// Starting time
	int s[] = { 1, 3, 0, 5, 8, 5 };

	// Finish time
	int f[] = { 2, 4, 6, 7, 9, 9 };

	// Number of meetings.
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	maxMeeting(s, f, n);

	return 0;
}