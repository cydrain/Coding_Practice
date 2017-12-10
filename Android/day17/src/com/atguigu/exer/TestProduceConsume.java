package com.atguigu.exer;

public class TestProduceConsume {
	public static void main(String[] args) {
		Clerk clerk = new Clerk();
		Producer p = new Producer(clerk);
		Consumer c = new Consumer(clerk);
		
		Thread t1 = new Thread(p, "Producer1");
		Thread t2 = new Thread(p, "Producer2");
		Thread t3 = new Thread(c, "=======> Consumer1");
		
		t1.start();
		t2.start();
		t3.start();
	}
}

class Clerk {
	private int product;
	
	public synchronized void addProduct() {
		if (product >= 10) {
			try {
				 System.out.println(Thread.currentThread().getName() + " need wait...");
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} else {
			product++;
			System.out.println(Thread.currentThread().getName() + " produce No." + product);
			notifyAll();
		}
	}
	
	public synchronized void consumeProduct() {
		if (product <= 0) {
			try {
				System.out.println(Thread.currentThread().getName() + " need wait...");
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} else {
			System.out.println(Thread.currentThread().getName() + " consume No." + product);
			product--;
			notifyAll();
		}
	}
}

class Producer implements Runnable {
	private Clerk clerk;

	public Producer(Clerk clerk) {
		super();
		this.clerk = clerk;
	}
	
	public void run() {
		while (true) {
			try {
				Thread.currentThread().sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			clerk.addProduct();
		}
	}
}

class Consumer implements Runnable {
	private Clerk clerk;

	public Consumer(Clerk clerk) {
		super();
		this.clerk = clerk;
	}
	
	public void run() {
		while (true) {
			try {
				Thread.currentThread().sleep(300);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			clerk.consumeProduct();
		}
	}
}