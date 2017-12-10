package com.atguigu.exer;

public class TestWindow {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Window w1 = new Window();
		Window w2 = new Window();
		Window w3 = new Window();
		
		w1.setName("Window1");
		w2.setName("Window2");
		w3.setName("Window3");
		
		w1.start();
		w2.start();
		w3.start();
	}
}

class Window extends Thread {
	static int tickets = 100;
	
	public void run() {
		while (tickets > 0) {
			System.out.println(Thread.currentThread().getName() + " sold ticket No." + tickets--);
		}
	}
}