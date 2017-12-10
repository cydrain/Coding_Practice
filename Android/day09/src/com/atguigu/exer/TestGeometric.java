package com.atguigu.exer;

import org.junit.Test;

public class TestGeometric {

	public static void main(String[] args) {
		TestGeometric t = new TestGeometric();
		
		Circle c1 = new Circle(2.3, "Green", 1.0);
		Circle c2 = new Circle(2.3, "Red", 1.0);
		
		MyRectangle m1 = new MyRectangle(2.3, 3.0, "Blue", 2.0);
		t.displayGeometricObject(c2);
		
		boolean b = t.equalsArea(c1, m1);
		System.out.println(b);
	}
	
	public boolean equalsArea(GeometricObject g1, GeometricObject g2) {
		return (g1.findArea() == g2.findArea());
	}

	void displayGeometricObject(GeometricObject g) {
		double area = g.findArea();
		System.out.println("Area is " + area);
	}
	
	@Test
	public void cyd() {		
		Circle c1 = new Circle(2.3, "Green", 1.0);
		Circle c2 = new Circle(2.3, "Red", 1.0);
		
		MyRectangle m1 = new MyRectangle(2.3, 3.0, "Blue", 2.0);
		displayGeometricObject(c2);
		
		boolean b = equalsArea(c1, m1);
		System.out.println(b);
	}
}
