#include <bits/stdc++.h>

using namespace std;

int main()
{

	vector<long long int> v1 = {0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 17, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 24, 25, 25};
	vector<long long int> v2 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 16, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 24, 24, 24, 24, 24, 25};
	vector<long long int> v3 = {1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 16, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 19, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 23, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25};
	vector<long long int> v4 = {0, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 18, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 22, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 25, 26, 26, 26};
	vector<long long int> v5 = {25, 25, 25, 26};

	long long int t, m1, m2, y1, y2, r1, r2, n_cycles, res, id1, id2, id3, id4;

	//cout << v1[19] - v1[8] << endl;
	cin >> t;

	while(t--)
	{
		cin >> m1 >> y1 >> m2 >> y2;

		if(m1 > 2)
			y1++;

		if(m2 < 2)
			y2--;

		if(y1%100 ==0)
		{
			r1 = 99;
		}
		else
		{
			r1 = y1%100-1;
		}

		y1 -= r1;
		id1 = (y1/100)%4;

		r2 = y2%100;
		y2 -= r2;
		id2 = (y2/100)%4;		

		n_cycles = (y2-y1 + 1)/400;
		// rem = (y2-y1+1)%400;

		res = 101*n_cycles;
		//cout << "1 " << res << endl;

		if(r1 != 0)
		{
			if(id1 == 0)
				res -= v1[r1-1];
			else if(id1 == 1)
				res -= v2[r1-1];
			else if(id1 == 2)
				res -= v3[r1-1];
			else
				res -= v4[r1-1];
		}

		if(r2 != 0)
		{
			if(id2 == 0)
				res += v1[r2-1];
			else if(id2 == 1)
				res += v2[r2-1];
			else if(id2 == 2)
				res += v3[r2-1];
			else
				res += v4[r2-1];
		}

		//cout << "2 " << res << endl;

		y1 = y1 + n_cycles*400;


		if(y1 < y2)
		{
			id3 = (y1/100)%4;
			id4 = (y2/100)%4;
			
			if(id3 < id4)
			{
				for(int i=id3; i<id4; i++)
				{
					res += v5[i];
					//cout << "3 " << res << endl;
				}
			}
			else
			{
				for(int i=id3; i<4; i++)
					res += v5[i];
				//cout << "4 " << res << endl;

				for(int i=0; i<id4; i++)
				{
					res += v5[i];
					//cout << "5 " << res << endl;
				}
			}
		}

		cout << res << endl;

	}

	return 0;

}