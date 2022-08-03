import java.util.*;

public class Account {
    static final double balance = 500;
    static double currentBalance = balance;
    Account(int accountNo) {
        
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean option = true;
        User obj[] = new User[2];
        for (int i = 0; i < obj.length; i++) {
            System.out.println("Enter UserName\nEnter AccountNumber\nEnter secondAccountNumber");
            obj[i] = new User(scanner.next(), scanner.nextInt(), scanner.nextInt());
        }
        try {
        while (option) {
            System.out.println("--------Menu-------");
            System.out.println("0.AccountNumber\n1.Deposit\n2.Withdraw\n3.Display");
            int choice = scanner.nextInt();
            switch(choice) {
                case 0 :
                    System.out.println("Enter account number:");
                    int acno = scanner.nextInt();
                if (obj[0].accountNo == acno || obj[0].accountNo2 == acno || obj[1].accountNo == acno || obj[1].accountNo2 == acno) {
                case 1 :
                    System.out.println("Enter the amount to be deposited");
                    currentBalance += scanner.nextDouble();
                    //deposit(currentBalance);
                    break;
                case 2 :
                    System.out.println("Enter the amount to withdraw");
                    double moneyLost = scanner.nextDouble();
                    withdraw(currentBalance, moneyLost);
                    break;
                case 3 :
                    display(currentBalance);
                    break;
                    
            }
            System.out.println("Thank You, Do you want menu back press 1 for exit press 0");
            int select = scanner.nextInt();
            option = select == 1 ? true : false;   
        }
        } catch (LessBalanceException e) {

        }
        scanner.close();
    }
    static void deposit(double balance) {

    }
    static void display(double balance) {
        System.out.println("Balance is:" + balance);
    }
    static void withdraw(double currentBalance, double moneyLost) throws LessBalanceException {
        System.out.println(currentBalance);
        double value = currentBalance - moneyLost;
        if (value < 500 || moneyLost > currentBalance) {
            throw new LessBalanceException(moneyLost);
        } else {
            currentBalance -= moneyLost;
            //1System.out.println(balance);
        }
        //currentBalance = balance;
    }
}

class LessBalanceException extends Exception {
    LessBalanceException(double currentBalance) {
        System.out.println("Withdraw amount" + currentBalance + "is not valid");
    }
}

class User {
    String name;
    int accountNo;
    int accountNo2;
    User(String name, int accountNo, int accountNo1) {
        this.name = name;
        this.accountNo = accountNo;
        this.accountNo2 = accountNo1;
    }
}