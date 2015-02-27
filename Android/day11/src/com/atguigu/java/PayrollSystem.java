package com.atguigu.java;

import java.util.Scanner;

public class PayrollSystem {
	public static void main(String[] args) {
		Employee[] employee = new Employee[2];
		employee[0] = new SalaryEmployee("LiLei", 1001, new MyDate(1998, 12, 9), 8800);
		employee[1] = new HourlyEmployee("HanMeimei", 1002, new MyDate(1987, 4,30), 100, 6);
		
		Scanner s = new Scanner(System.in);
		System.out.println("Please input the month:");
		int month = s.nextInt();
		
		for (int i = 0; i < employee.length; i++) {
			if (month == employee[i].getBirthday().getMonth()) {
				System.out.println("Add salary 100");
			}
			System.out.println(employee[i]);
		}
	}
}
