package TestBanking;

import Banking8.domain.*;
import Banking8.report.*;

public class TestBanking8 {
	public static void main(String[] args) {
		Bank bank = Bank.getBanking();
		Customer customer;
		CustomerReport report = new CustomerReport();
		
		// Create several customers and their accounts
		System.out.println("Creating the customer Jane Smith.");
		bank.addCustomer("Jane", "Simms");
		customer = bank.getCustomer(0);
		customer.addAccount(new SavingAccount(500.0, 0.05));
		customer.addAccount(new CheckingAccount(200.00, 400.00));
		
		// Add Customer Owen, Bryant
		System.out.println("Creating the customer Owen Bryant.");
		bank.addCustomer("Owen", "Bryant");
		customer = bank.getCustomer(1);
		customer.addAccount(new CheckingAccount(200.00));
		
		// Add Customer Tim, Soley
		System.out.println("Creating the customer Tim Soley.");
		bank.addCustomer("Tim", "Soley");
		customer = bank.getCustomer(2);
		customer.addAccount(new SavingAccount(1500.00, 0.05));
		customer.addAccount(new CheckingAccount(200.00));
	
		// Add Customer Maria, Soley
		System.out.println("Creating the customer Maria Soley.");
		bank.addCustomer("Maria", "Soley");
		customer = bank.getCustomer(3);
		// Maria shares her Checking Account with her husband Tim
		customer.addAccount(bank.getCustomer(2).getAccount(1));
		customer.addAccount(new SavingAccount(150.00, 0.05));
		
		System.out.println();
		
		// Generate a report
		report.generateReport();
	}
}
