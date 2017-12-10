package com.atguigu.exer;

public class TestThread {
	public static void main(String[] args) {
		Thread.currentThread().setName("========MainThread");
		OddThread ot = new OddThread();
		ot.setName("OddThread");
		EvenThread et = new EvenThread();
		et.setName("EvenThread");
		
		ot.start();
		et.start();
	}
}

class OddThread extends Thread {
	public void run() {
		for (int i = 1; i < 100; i+= 2) {
			System.out.println(Thread.currentThread().getName() + ":" + i);
		}
	}
}

class EvenThread extends Thread {
	public void run() {
		for (int i = 2; i <= 100; i+= 2) {
			System.out.println(Thread.currentThread().getName() + ":" + i);
		}
	}
}