package Banking8.domain;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Customer {
	private String firstName;
	private String lastName;
	private List<Account> accounts;
	
	public Customer(String f, String l) {
		firstName = f;
		lastName = l;
		accounts = new ArrayList<Account>();
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}

	public Account getAccount(int acct_idx) {
		return accounts.get(acct_idx);
	}

	public void addAccount(Account acct) {
		this.accounts.add(acct);
	}

	public int getNumOfAccounts() {
		return accounts.size();
	}
	
	public Iterator<Account> getAccounts() {
		return accounts.iterator();
	}
}
