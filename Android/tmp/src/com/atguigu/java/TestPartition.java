package com.atguigu.java;

import java.util.ArrayList;
import java.util.List;

public class TestPartition {
    public void partitionHelper(String s, boolean[][] isPalin, int start,
            List<String> p, List<List<String>> r) {
    	int n = s.length();
    	if (start == n) {
    		List<String> list = new ArrayList<>();
    		for (String ts: p) {
    			list.add(ts);
    		}
    		r.add(list);
    	} else {
    		for (int i = start; i < n; i++) {
    			if (isPalin[start][i]) {
    				p.add(s.substring(start, i+1));
    				partitionHelper(s, isPalin, i+1, p, r);
    				p.remove(p.size()-1);
    			}
    		}
    	}
    }
    public List<List<String>> partition(String s) {
    	List<List<String>> r = new ArrayList<>();
    	int n = s.length();
    	if (n == 0) return r;
    	List<String> p = new ArrayList<>();
    	boolean[][] isPalin = new boolean[n][n];
    	int i, j;

    	for (j = 0; j < n; j++) {
    		for (i = 0; i <= j; i++) {
    			if (s.charAt(i) == s.charAt(j) &&
    					(j-i < 2 || isPalin[i+1][j-1])) {
    				isPalin[i][j] = true;
    			}
    		}
    	}
    	partitionHelper(s, isPalin, 0, p, r);
    	return r;
    }
}
