package Banking6.domain;

public class SavingAccount extends Account {
	private double interestRate;
	
	public SavingAccount(double init_balance, double init_rate) {
		super(init_balance);
		this.interestRate = init_rate;
	}

	public double getInterestRate() {
		return interestRate;
	}

	public void setInterestRate(double interestRate) {
		this.interestRate = interestRate;
	}

	
}
