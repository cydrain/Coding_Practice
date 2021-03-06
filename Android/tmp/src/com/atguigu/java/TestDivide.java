package com.atguigu.java;

public class TestDivide {
	public static void main(String[] args) {
		int a = Integer.MIN_VALUE, b = -1;
		int c = divide(a, b);
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
	}
    public static int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        boolean neg = ((dividend > 0 && divisor < 0) ||
                       (dividend < 0 && divisor > 0));
        long m = Math.abs((long)dividend);
        long n = Math.abs((long)divisor);
        long r = 0;
        long i = 0;
        
        while (m >= (n<<i)) {
            i++;
        }
        while (m >= n && --i >= 0) {
            if (m >= (n<<i)) {
                m -= (n<<i);
                r |= (1L<<i);
            }
            System.out.println(i + " " + m + " " + n + " " + r);
        }
        if (neg) {
            r = -r;
        }
        if (r >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (r <= Integer.MIN_VALUE) return Integer.MIN_VALUE;
        return (int)r;

	}
}
