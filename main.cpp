#include <iostream>
#include <string>
using namespace std;


//start the creation of my horrendous, 1024 digit integer.
//named col, short for colossal.
struct col {
	char vals[1000];
	const int totalSize = sizeof(vals)/sizeof(char);
	col(int inp){
		int cur = inp;
		for(int x = 0; x < totalSize; x++){
			vals[x]=cur%10;
			cur=cur/10;
		}
	}
	int findLen(){
		int x = totalSize-1;
		for(; x >= 0; x--){
			if(vals[x] != 0){
				break;
			}
		}
		return x+1;
	}
	string toString(){
		string s = "";
		for(int x = findLen()-1; x >=0; x--){
			s+=to_string(vals[x]);
		}
		return s;
	}
	void upShift(int start) {
		if (start > findLen())
			return;
		while (vals[start] / 10 > 0) {
			vals[start + 1] += 1;
			vals[start] -= 10;
		}
		if(start+1 < findLen())
			upShift(start + 1);
	}
	void add(int toAdd) {
		vals[0] += toAdd;
		upShift(0);
	}
	void add(){
		vals[0]+=1;
		upShift(0);
	}
	int mod(int toMod){
		int rem = 0;
		for(int x = findLen(); x >= 0; x--){
			int toDiv = rem*10+vals[x];
			rem=toDiv%toMod;
		}
		return rem;
	}
	void set(col b){
		for(int x = 0; x < b.findLen(); x++){
			vals[x] = b.vals[x];
		}
	}
	void add(col b){
		for(int x = 0; x < b.findLen(); x++){
			vals[x] += b.vals[x];
		}
		upShift(0);
	}
};
//end the creation of my horrendous, 1024 digit integer.


int main() {
	int sizeToGet = 100;
	int num = 1;
	col counter(1), tracker(1);
	while (num <= sizeToGet) {
		if (counter.mod(num) == 0) {
			cout << "For values 1 -> " << num << endl;
			cout << counter.toString() << endl;
			tracker.set(counter);
			num += 1;
		} else {
			counter.add(tracker);
		}
	}
	return 0;
}

