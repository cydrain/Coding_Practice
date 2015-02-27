package Banking7.domain;

public class Customer {
	private String firstName;
	private String lastName;
	private Account[] accounts;
	private int numOfAccounts;
	
	public Customer(String f, String l) {
		firstName = f;
		lastName = l;
		accounts = new Account[5];
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}

	public Account getAccount(int acct_idx) {
		return accounts[acct_idx];
	}

	public void addAccount(Account acct) {
		this.accounts[numOfAccounts++] = acct;
	}

	public int getNumOfAccounts() {
		return numOfAccounts;
	}
}
