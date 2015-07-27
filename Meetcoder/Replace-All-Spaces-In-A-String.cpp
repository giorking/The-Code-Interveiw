class Solution {
public:
    void replaceSpaces(char str[], int length){
        int num = 0;
        if (length == 0) return;
        for (int i = 0; i < length; i ++) {
            if (str[i] == ' ') num ++;
        }
        int pos1 = length + 2 * num, pos2 = length;
        while (pos2 >= 0) {
            if (str[pos2] == ' ') {
                str[pos1--] = '0';
                str[pos1--] = '2';
                str[pos1--] = '%';
                pos2 --;
            } else {
                str[pos1--] = str[pos2--];
            }
        }
    }
};