/**************************************************************
    Problem: 15
    User: iFighting
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:1692 kb
****************************************************************/

class Solution {
public:
	int aPlusb(int a,int b) {
        while(b != 0){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
	}
};