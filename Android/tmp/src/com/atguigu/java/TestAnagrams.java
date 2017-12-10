package com.atguigu.java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TestAnagrams {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] strs = {"12", "21"};
		System.out.println(anagrams(strs));
	}


    public static List<String> anagrams(String[] strs) {
        Map<String,List<String>> map = new HashMap<>();
        List<String> list = null;
        List<String> res = new ArrayList<>();
        String key = null;
        for (int i = 0; i < strs.length; i++) {
            key = String.sort(strs[i]);

            list = map.get(key);
            if (list == null) {
                list = new ArrayList<>();
                list.add(strs[i]);
                map.put(key, list);
            } else {
                list.add(strs[i]);
            }
            
            System.out.println(map);
        }
        
        for (List<String> list1: map.values()) {
            if (list1.size() > 1) {
                for (String s: list1) {
                    res.add(s);
                }
            }
        }
        return res;
    
	}
}
