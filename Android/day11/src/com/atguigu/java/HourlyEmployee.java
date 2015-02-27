package com.atguigu.java;

public class HourlyEmployee extends Employee {
	private double wage;
	private double hour;
	
	public HourlyEmployee(String name, int number, MyDate birthday,
			double wage, double hour) {
		super(name, number, birthday);
		this.wage = wage;
		this.hour = hour;
	}

	public double earning() {
		return wage * hour;
	}

//	@Override
//	public String toString() {
//		return "HourlyEmployee [" + super.toString() + ", wage=" + wage + ", hour=" + hour + "]";
//	}
}
