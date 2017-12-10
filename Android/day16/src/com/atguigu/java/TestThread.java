package com.atguigu.java;

public class TestThread {
	public static void main(String[] args) {
		Thread.currentThread().setName("========MainThread");
		
		SubThread st1 = new SubThread();
		st1.setName("SubThread");
		st1.start();

		for (int i = 1; i <= 100; i++) {
			System.out.println(Thread.currentThread().getName() + ":" + i);
			if (i == 30) {
				try {
					st1.join();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}

class SubThread extends Thread {
	public void run() {
		for (int i = 1; i <= 100; i++) {
			System.out.println(Thread.currentThread().getName() + ":" + i);
		}
	}
}
