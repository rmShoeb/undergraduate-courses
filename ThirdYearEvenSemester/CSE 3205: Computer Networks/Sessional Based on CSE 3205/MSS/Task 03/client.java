import java.net.*;
import java.io.*;
import java.util.Scanner;


public class client{
	public static void main(String[] args) throws IOException, UnknownHostException, ClassNotFoundException{
		Socket 				CliSock 			= new Socket("localhost", 1234);
		System.out.println("Connected to Server.");

		ObjectOutputStream 	WriteStream 		= new ObjectOutputStream(CliSock.getOutputStream());
		ObjectInputStream 	ReadStream 			= new ObjectInputStream(CliSock.getInputStream());
		Scanner 			UserInput 			= new Scanner(System.in);
		DataPacket 			SendToServer 		= new DataPacket();
		DataPacket 			RecieveFromServer 	= new DataPacket();
		String 				toEscape;

		System.out.print("Enter header: ");
		SendToServer.setHeader(UserInput.nextInt());

		toEscape = UserInput.nextLine();
		System.out.print("Enter message: ");
		SendToServer.setMessage(UserInput.nextLine());

		System.out.print("Enter Protocol ID: ");
		SendToServer.setProtocolID(UserInput.nextInt());

		SendToServer.setParity();

		WriteStream.writeObject(SendToServer);
		RecieveFromServer = (DataPacket)ReadStream.readObject();

		if(RecieveFromServer.CheckParity() == RecieveFromServer.getParity()){
			System.out.println("Message recieved correctly.");
			System.out.println(RecieveFromServer.getMessage());
		}
		else{
			System.out.println("Message is broken.");
		}

		UserInput.close();
		CliSock.close();
	}
}
