package com.atguigu.java;

public class TestInterface {
	public static void main(String[] args) {
		ComparableCircle c1 = new ComparableCircle(1.0);
		ComparableCircle c2 = new ComparableCircle(2.0);
		System.out.println(c1.compareTo(c2));
		System.out.println(c1.compareTo(1));
	}
}

interface CompareObject {
	int compareTo(Object o);
}

class Circle {
	private double radius;

	public Circle() {
		super();
	}

	public Circle(double radius) {
		super();
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
}

class ComparableCircle extends Circle implements CompareObject {
	public ComparableCircle(double radius) {
		super(radius);
	}
	public int compareTo(Object o) {
		if (this == o) {
			return 0;
		} else if (o instanceof ComparableCircle) {
			ComparableCircle c = (ComparableCircle)o;
			if (this.getRadius() > c.getRadius()) {
				return 1;
			} else if (this.getRadius() == c.getRadius()) {
				return 0;
			} else {
				return -1;
			}
		}
		throw new RuntimeException("Unknown reference type");
	}
}