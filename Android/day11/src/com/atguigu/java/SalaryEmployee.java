package com.atguigu.java;

public class SalaryEmployee extends Employee {
	private double monthlySalary;
	
	public SalaryEmployee(String name, int number, MyDate birthday, double monthlySalary) {
		super(name, number, birthday);
		this.monthlySalary = monthlySalary;
	}

	public double earning() {
		return monthlySalary;
	}

//	@Override
//	public String toString() {
//		return "SalaryEmployee [" + super.toString() + ", monthlySalary=" + monthlySalary + "]";
//	}
}
