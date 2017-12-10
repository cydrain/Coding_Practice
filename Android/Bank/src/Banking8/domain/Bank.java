package Banking8.domain;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Bank {
	private static Bank bank = new Bank();
	private List<Customer> customers;
	
	private Bank() {
		customers = new ArrayList<Customer>();
	}
	
	public static Bank getBanking() {
		return bank;
	}
	
	public void addCustomer(String f, String l) {
		Customer cust = new Customer(f, l);
		customers.add(cust);
	}
	
	public int getNumOfCustomer() {
		return customers.size();
	}
	
	public Customer getCustomer(int index) {
		return customers.get(index);
	}
	
	public Iterator<Customer> getCustomers() {
		return customers.iterator();
	}
}
