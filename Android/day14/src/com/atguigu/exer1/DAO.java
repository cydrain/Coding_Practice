package com.atguigu.exer1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DAO<T> {
	private Map<String,T> map = new HashMap<>();
	
	public void save(String id, T entity) {
		map.put(id, entity);
	}
	public T get(String id) {
		return map.get(id);
	}
	public void update(String id, T entity) {
		map.put(id, entity);
	}
	public List<T> list() {
		List<T> list = new ArrayList<T>();
		for (String s: map.keySet()) {
			list.add(map.get(s));
		}
		return list;
	}
	public void delete(String id) {
		map.remove(id);
	}
}
