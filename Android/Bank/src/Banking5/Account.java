package Banking5;

public class Account {
	protected double balance;
	
	public Account(double init_balance) {
		balance = init_balance;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public boolean deposit(double amt) {
		balance += amt;
		return true;
	}
	
	public boolean withdraw(double amt) {
		if (balance >= amt) {
			balance -= amt;
			return true;
		} else {
			System.out.println("No enough money !");
			return false;
		}
	}
}
