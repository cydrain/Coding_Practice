package com.atguigu.exer;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

import org.junit.Test;

public class TestEmployee {
	@Test
	public void test1() {
		TreeSet set = new TreeSet();
		set.add(new Employee("CaiYudong", 36, new MyDate(1979,6,2)));
		set.add(new Employee("ChaiLei", 33, new MyDate(1982,2,11)));
		set.add(new Employee("CaiYijun", 71, new MyDate(1944,6,2)));
		set.add(new Employee("ChaiFuyou", 59, new MyDate(1956,10,12)));
		set.add(new Employee("ZhuLianfeng", 59, new MyDate(1956,12,10)));
		//System.out.println(set);
		Iterator it = set.iterator();
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
	
	@Test
	public void test2() {
		Comparator comp = new Comparator() {

			@Override
			public int compare(Object o1, Object o2) {
				if (o1 instanceof Employee1 && o2 instanceof Employee1) {
					Employee1 e1 = (Employee1)o1;
					Employee1 e2 = (Employee1)o2;
					return e1.getBirthday().compareTo(e2.getBirthday());
				}
				return 0;
			}
		};
		
		TreeSet set = new TreeSet(comp);
		set.add(new Employee1("CaiYudong", 36, new MyDate(1979,6,2)));
		set.add(new Employee1("ChaiLei", 33, new MyDate(1982,2,11)));
		set.add(new Employee1("CaiYijun", 71, new MyDate(1944,6,2)));
		set.add(new Employee1("ChaiFuyou", 59, new MyDate(1956,10,12)));
		set.add(new Employee1("ZhuLianfeng", 59, new MyDate(1956,12,10)));
		//System.out.println(set);
		/*Iterator it = set.iterator();
		while (it.hasNext()) {
			System.out.println(it.next());
		}*/
		for (Object e: set) {
			System.out.println(e);
		}
	}
}
