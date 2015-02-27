package com.atguigu.java;

public class TestAbstract {
	public static void main(String[] args) {
		Student s = new Student();
		s.eat();
		s.walk();
	}
}

abstract class Person {
	public Person() {
	}
	public abstract void eat();
	public abstract void walk();
}

class Student extends Person {
	public void eat() {
		System.out.println("student eat");
	}
	public void walk() {
		System.out.println("student walk");
	}
}
