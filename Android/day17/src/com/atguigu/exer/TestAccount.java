package com.atguigu.exer;

public class TestAccount {

	public static void main(String[] args) {
		Account acct = new Account();
		
		Customer c1 = new Customer(acct);
		Customer c2 = new Customer(acct);

		c1.setName("Customer1");
		c2.setName("Customer2");
		
		c1.start();
		c2.start();
	}
}

class Account {
	private double balance = 0.0;
	
	public synchronized void deposit(double amt) {
		notify();
		this.balance += amt;
		try {
			Thread.sleep(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(Thread.currentThread().getName() + " - Current balance: " + this.balance);
		try {
			wait();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class Customer extends Thread {
	Account account;
	
	public Customer(Account acct) {
		this.account = acct;
	}
	
	public void run() {
		for (int i = 0; i < 3; i++) {
			account.deposit(1000.00);
		}
	}
}