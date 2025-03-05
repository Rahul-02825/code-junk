import java.io.*;

class Account implements Serializable {
    private String accountNumber;
    private int balance;

    public Account(String accountNumber, int balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "Account [accountNumber=" + accountNumber + ", balance=" + balance + "]";
    }
}

public class ObjectStreamExample {
    public static void main(String[] args) {
        Account acc1 = new Account("123456", 1000);
        Account acc2 = new Account("654321", 2000);

        // Store objects to a file
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("accounts.obj"))) {
            out.writeObject(acc1);
            out.writeObject(acc2);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Read objects from the file
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream("accounts.obj"))) {
            Account account1 = (Account) in.readObject();
            Account account2 = (Account) in.readObject();
            System.out.println("Read from file: " + account1);
            System.out.println("Read from file: " + account2);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}