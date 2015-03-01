package com.atguigu.exer;

public class TestWindow1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Window1 w = new Window1();
		
		Thread t1 = new Thread(w, "Window1");
		Thread t2 = new Thread(w, "Window2");
		Thread t3 = new Thread(w, "Window3");
		
		t1.start();
		t2.start();
		t3.start();
	}
}

class Window1 implements Runnable {
	int tickets = 100;
	Object obj = new Object();
	
	public void run() {
		while (true) {
			synchronized(this) {
				if (tickets > 0) {
					try {
						Thread.currentThread().sleep(10);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					System.out.println(Thread.currentThread().getName() + " sold ticket No." + tickets--);
				} else {
					break;
				}
			}
		}
	}
}