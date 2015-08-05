public class CareerUp {
    public int countCompression(String str) {
        if (str == null || str.isEmpty()) return 0;
        char last = str.charAt(0);
        int size = 0;
        int count = 1;
        for (int i = 1; i < str.length(); i ++) {
            if (str.charAt(i) == last) {
                count ++;
            } else {
                last = str.charAt(i);
                size += 1 + String.valueOf(count).length();
                count = 1;
            }
        }
        size += 1 + String.valueOf(count).length();
        return size;
    }
    public String compress(String str) {
        int size = countCompression(str);
        if (size >= str.length()) return str;
        StringBuffer sb = new StringBuffer();
        if (str.length() <= 0) return str;
        char ch = str.charAt(0);
        int cur = 1;
        for (int i = 1; i < str.length(); i ++) {
            if (str.charAt(i) != ch) {
                sb.append(ch);
                sb.append(String.valueOf(cur));
                cur = 1;
                ch = str.charAt(i);
            } else {
                cur ++;
            }
        }
        sb.append(ch);
        sb.append(String.valueOf(cur));
        if (sb.length() == str.length()) return str;
        return sb.toString();
    }
}
