package Banking8.domain;

public class CheckingAccount extends Account {
	private Double overdraftProtection;
	
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
	
	public void withdraw(double amt) throws OverdraftException {
		if (balance >= amt) {
			balance -= amt;
		}
		else {
			if (overdraftProtection == null) {
				throw new OverdraftException("no overdraft exception", amt-balance);
			}
			else if (overdraftProtection >= amt - balance) {
				overdraftProtection -= (amt - balance);
				balance = 0;
			}
			else {
				throw new OverdraftException("Insufficient funds for over draft protection !", amt-balance-overdraftProtection);
			}
		}
	}
}
