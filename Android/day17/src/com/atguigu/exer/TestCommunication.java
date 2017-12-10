package com.atguigu.exer;

public class TestCommunication {

	public static void main(String[] args) {
		Print p = new Print();
		
		Thread t1 = new Thread(p, "Thread1");
		Thread t2 = new Thread(p, "Thread2");
		
		t1.start();
		t2.start();
	}

}

class Print implements Runnable {
	int num = 1;
	
	public void run() {
		while (true) {
			synchronized(this) {
				notify();
				if (num <= 100) {
					try {
						Thread.currentThread().sleep(10);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					System.out.println(Thread.currentThread().getName() + ": " + (num++));
				} else {
					break;
				}
				try {
					wait();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}