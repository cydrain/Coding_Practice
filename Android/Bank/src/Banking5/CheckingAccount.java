package Banking5;

public class CheckingAccount extends Account {
	private double overdraftProtection;
	
	public CheckingAccount(double init_balance) {
		super(init_balance);
		// TODO Auto-generated constructor stub
	}

	public CheckingAccount(double init_balance, double overdraftProtection) {
		super(init_balance);
		this.overdraftProtection = overdraftProtection;
	}

	public double getOverdraftProtection() {
		return overdraftProtection;
	}

	public void setOverdraftProtection(double overdraftProtection) {
		this.overdraftProtection = overdraftProtection;
	}
	
	public boolean withdraw(double amt) {
		if (balance >= amt) {
			balance -= amt;
			return true;
		}
		else if (overdraftProtection >= amt - balance) {
			overdraftProtection -= (amt - balance);
			balance = 0;
			return true;
		}
		else {
			System.out.println("No enough money !");
			return false;
		}
	}
}
