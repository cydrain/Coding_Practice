package com.atguigu.exer;

import java.util.Arrays;

public class TestString {
	public static void main(String[] args) {
		String s = "    ab* cd ef  ";
		System.out.println(s);
		System.out.println("---"+myTrim(s)+"---");
		System.out.println("---"+myTrim("   ")+"---");
		System.out.println("---"+reversePartialStr(s, 4, 10)+"---");
		
		System.out.println(getTimes("babababa", "ab"));
		System.out.println(getMaxSubStr("abcdadahellodiok", "daehellopk"));
	}
	
	public static String getMaxSubStr(String s, String p) {
		int p_len = p.length();
		int len, i;
		String tmp;
		for (len = p_len; len > 0; len--) {
			for (i = 0; i+len <= p_len; i++) {
				tmp = p.substring(i, i+len);
				if (s.contains(tmp)) {
					return tmp;
				}
			}
		}
		return null;
	}
	public static int getTimes(String s, String p) {
		int cnt = 0;
		int p_len = p.length();
		int start = 0;
		int index;
		
		while ((index = s.indexOf(p, start)) != -1) {
			cnt++;
			start = index + p_len;
		}
		return cnt;
	}
	
	public static String reversePartialStr(String s, int start, int end) {
		char[] str = s.toCharArray();
		char c;
		while (start < end) {
			 c = str[start];
			 str[start] = str[end];
			 str[end] = c;
			 start++;
			 end--;
		}
		return new String(str);
		//return String.valueOf(str);
	}
	
	public static String myTrim(String s) {
		if (s == null) return null;
		int start = 0, end = s.length();
		while ((start < end) && (s.charAt(start) == ' ')) {
			start++;
		}
		while ((end > start) && (s.charAt(end-1) == ' ')) {
			end--;
		}
		if (start < end) {
			return s.substring(start, end);
		}
		return null;
	}
}