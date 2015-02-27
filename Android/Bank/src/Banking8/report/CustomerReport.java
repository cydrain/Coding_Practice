package Banking8.report;

import java.text.NumberFormat;
import java.util.Iterator;

import Banking8.domain.*;

public class CustomerReport {
	public void generateReport() {
		Bank bank = Bank.getBanking();
		Customer customer;
		NumberFormat currency_format = NumberFormat.getCurrencyInstance();
		Iterator<Customer> cust_it;
		Iterator<Account> acct_it;
		
		System.out.println("\t\tCUSTOMERS REPORT");
		System.out.println("\t\t\t==============");
		
		cust_it = bank.getCustomers(); 
		while (cust_it.hasNext()) {
			customer = cust_it.next();
			
			System.out.println();
			System.out.println("Customer: " + customer.getLastName() + ", "
							+ customer.getFirstName());
			
			acct_it = customer.getAccounts();
			while (acct_it.hasNext()) {
				Account account = acct_it.next();
				String account_type = "";
				if (account instanceof SavingAccount) {
					account_type = "SavingAccount";
				}
				if (account instanceof CheckingAccount) {
					account_type = "CheckingAccount";
				}
				System.out.println(account_type + ": current balance is "
						+ currency_format.format(account.getBalance()));
			}
		}
	}

}
