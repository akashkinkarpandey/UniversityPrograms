import java.util.Scanner;

public class BankAccountTest{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		// System.out.print("Enter Account No : ");
		// int accNo = in.nextInt();
		
		// System.out.print("Enter Account Holder Name : ");
		// String name = in.nextLine();
		
		// System.out.print("Enter Account Type ( C:current, S:savings) : ");
		// String type = in.next();
		int accNo = Integer.parseInt(args[0]);
		String name = args[1];
		String type = args[2];


		BankAccount acc1 = new BankAccount(name, accNo, type);
		while(true){
			System.out.println("\n\n - - - - - WELCOME "+ name+" TO STCET BANK - - - - -\n");
			System.out.println("1. Balance Check");
			System.out.println("2. Cash Deposit");
			System.out.println("3. Cash Withdrawal");
			System.out.println("4. Exit");
			System.out.print("Enter Your Choice : ");
			int ch = in.nextInt();
			switch(ch){
				case 1: 
						System.out.println("Account Balance : "+acc1.checkBalance());
						break;
				case 2: 
					System.out.print("Enter amount to deposit: ");
					double m = in.nextDouble();
					acc1.deposit(m);
					break;
				case 3:
					System.out.print("Enter amount to withdraw: ");
					m = in.nextDouble();
					acc1.withdraw(m);
					break;
				case 4:
					System.exit(0);
			}	
		}
	}
}