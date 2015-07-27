class Solution {
public:
    void reverse(char* s){
        int left = 0, right = strlen(s) - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++;
            right --;
        }
    }
};