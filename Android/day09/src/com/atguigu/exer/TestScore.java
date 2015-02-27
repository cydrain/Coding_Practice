package com.atguigu.exer;

import java.util.Scanner;
import java.util.Vector;

public class TestScore {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Vector scores = new Vector();
		int i;
		
		System.out.println("Please input student's score: ");		
		while (true) {
			i = s.nextInt();
			if (i >= 0) {
				scores.addElement(i);
			} else {
				break;
			}
		}
		
		System.out.println("Scores: ");
		for (i = 0; i < scores.size(); i++) {
			System.out.print(scores.elementAt(i).toString() + ", ");
		}
	}

}
