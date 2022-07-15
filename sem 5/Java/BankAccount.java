public class BankAccount{
	String holderName;
	String accountType;
	int accountNo;
	double accBal;
	boolean overDraft;

	public BankAccount(String name, int accNo, String type){
		holderName = name;
		accountType = type;
		accountNo = accNo;
		accBal=1000;
		overDraft = (type.equals("C")) ? true:false;
	}

	public double checkBalance(){
		return this.accBal;
	}

	public void printBalance(){
		System.out.println("Updated Account Balance : "+checkBalance());
	}

	public void deposit(double money){
		this.accBal += money;
		printBalance();
	}

	public void withdraw(double money){
		if(accBal>money){
			accBal-=money;	
		}
		else if(this.overDraft==true)  accBal-=money;
		else System.out.println("Not Enough Money!");

		printBalance();
	}
}

