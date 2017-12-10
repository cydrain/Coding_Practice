package Banking7.domain;

public class Bank {
	private static Bank bank = new Bank();
	private Customer[] customers;
	private int numberOfCustomer;
	
	private Bank() {
		customers = new Customer[5];
	}
	
	public static Bank getBanking() {
		return bank;
	}
	
	public void addCustomer(String f, String l) {
		Customer cust = new Customer(f, l);
		customers[numberOfCustomer++] = cust;
	}
	
	public int getNumOfCustomer() {
		return numberOfCustomer;
	}
	
	public Customer getCustomer(int index) {
		return customers[index];
	}
}
