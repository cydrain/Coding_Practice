package TestBanking;

import Banking7.domain.*;
import Banking7.report.*;
import Banking7.domain.OverdraftException;

public class TestBanking7 {
	public static void main(String[] args) {
		Bank bank = Bank.getBanking();
		Customer customer;
		Account account;
		
		// Create several customers and their accounts
		bank.addCustomer("Jane", "Simms");
		customer = bank.getCustomer(0);
		customer.addAccount(new SavingAccount(500.0, 0.05));
		customer.addAccount(new CheckingAccount(200.00, 500.00));
		
		// Add Customer Owen, Bryant
		bank.addCustomer("Owen", "Bryant");
		customer = bank.getCustomer(1);
		customer.addAccount(new CheckingAccount(200.00));

		// Test the checking account of Jane Simms (with overdraft protection)
		customer = bank.getCustomer(0);
		account = customer.getAccount(1);
		System.out.println("Customer [" + customer.getLastName()
					+ ", " + customer.getFirstName() + "]"
					+ " has a checking balance of " 
					+ account.getBalance()
					+ " with a 500.00 overdraft protection.");		
		try {
			System.out.println("Checking acct [Jane Simms] : withdraw 150.00");
			account.withdraw(150.00);
			System.out.println("Checking acct [Jane Simms] : deposit 22.50");
			account.deposit(22.50);
			System.out.println("Checking acct [Jane Simms] : withdraw 147.62");
			account.withdraw(147.62);
			System.out.println("Checking acct [Jane Simms] : withdraw 470.00");
			account.withdraw(470.00);
		} catch (OverdraftException e) {
			System.out.println("Exception: " + e.getMessage()
						+ "   Deficit: " + e.getDeficit());
		} finally {
			System.out.println("Customer [" + customer.getLastName() 
						+ ", " + customer.getFirstName() + "]"
						+ " has a checking balance of " 
						+ account.getBalance());
		}
		
		// Test the checking account of Owen Bryant (without overdraft protection)
		customer = bank.getCustomer(1);
		account = customer.getAccount(0);
		System.out.println("Customer [" + customer.getLastName()
					+ ", " + customer.getFirstName() + "]"
					+ " has a checking balance of " 
					+ account.getBalance()
					+ " without overdraft protection.");
		
		try {
			System.out.println("Checking acct [Jane Simms] : withdraw 100.00");
			account.withdraw(100.00);
			System.out.println("Checking acct [Jane Simms] : deposit 25.00");
			account.deposit(25.00);
			System.out.println("Checking acct [Jane Simms] : withdraw 175.00");
			account.withdraw(175.00);
		} catch (OverdraftException e) {
			System.out.println("Exception: " + e.getMessage()
						+ "   Deficit: " + e.getDeficit());
		} finally {
			System.out.println("Customer [" + customer.getLastName() 
						+ ", " + customer.getFirstName() + "]"
						+ " has a checking balance of " 
						+ account.getBalance());
		}
	}
}
