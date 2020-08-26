import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client{
	public static void main(String[] args) throws IOException {
		String 		str;
		Scanner 	UserInput 		= new Scanner(System.in);
		Socket 		CliSock 		= new Socket("localhost", 1234);				// Socket class is for connection between client and server
		PrintWriter WriteToServer 	= new PrintWriter(CliSock.getOutputStream());

		System.out.print("Enter message to be sent to server: ");
		str = UserInput.nextLine();
		WriteToServer.println(str);
		WriteToServer.close();
	}
}
