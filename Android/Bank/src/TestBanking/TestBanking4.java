package TestBanking;
import Banking4.*;

public class TestBanking4 {
	public static void main(String[] args) {
		Bank bank = new Bank();
		
		// Add Customer Jane, Simms
		bank.addCustomer("Jane", "Simms");
		
		// Add Customer Owen, Bryant
		bank.addCustomer("Owen", "Bryant");
		
		// Add Customer Tim, Soley
		bank.addCustomer("Tim", "Soley");
		
		// Add Customer Maria, Soley
		bank.addCustomer("Maria", "Soley");
		
		for (int i = 0; i < bank.getNumOfCustomer(); i++) {
			Customer customer = bank.getCustomer(i);
			
			System.out.println("Customer [" + (i+1) + "] is "
							+ customer.getLastName() + ", "
							+ customer.getFirstName());
		}
	}
}
