#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	//training data set
	//[2,1,3]
	//d1 -> Ans  d2 -> Ans :-> d--Ans
	
	map<int, int> corpus;
	corpus.insert(make_pair(0, 1));
	corpus.insert(make_pair(1, 2));
	corpus.insert(make_pair(2, 3));
	corpus.insert(make_pair(3, 4));
	corpus.insert(make_pair(4, 5));
	corpus.insert(make_pair(5, 6));
	corpus.insert(make_pair(6, 7));
	corpus.insert(make_pair(7, 8));
	corpus.insert(make_pair(8, 9));
	corpus.insert(make_pair(9, 10));
	
	vector<int> data {2, 1, 3};
	cout << data[0] << " --> " << data[2] << ": " << corpus[data[0]] << endl;
	cout << data[1] << " --> " << data[2] << ": " << corpus[data[1]] << endl;
	cout << data[2] << " --> " << data[2] << ": " << corpus[data[2]] << endl;
	
	//find the weighted value with enough power to cus a change in total data
	//incrementing by 1
	if(data[0]+1 + data[1] > data[2]) cout << "Weight for data[0] = ++" << endl;
	if(data[0] + data[1]+1 > data[2]) cout << "Weight for data[1] = ++" << endl;
	
	//check rate of change between input value and output value
	//in this case, input is changing with a constant of 1
	
	
	return 0;
}
