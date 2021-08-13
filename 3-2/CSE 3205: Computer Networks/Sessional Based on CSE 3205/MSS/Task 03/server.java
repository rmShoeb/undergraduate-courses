import java.net.*;
import java.io.*;
import java.util.Scanner;


public class server{
	public static void main(String[] args) throws IOException, ClassNotFoundException{
		ServerSocket 		SerSock 			= new ServerSocket(1234);
		Socket 				Sock 				= SerSock.accept();
		System.out.println("Client Connected.");

		ObjectOutputStream 	WriteStream 		= new ObjectOutputStream(Sock.getOutputStream());
		ObjectInputStream 	ReadStream 			= new ObjectInputStream(Sock.getInputStream());
		Scanner 			UserInput 			= new Scanner(System.in);
		DataPacket 			SendToClient 		= new DataPacket();
		DataPacket 			RecieveFromClient 	= new DataPacket();
		String toEscape;

		RecieveFromClient = (DataPacket)ReadStream.readObject();
		if(RecieveFromClient.CheckParity() == RecieveFromClient.getParity()){
			System.out.println("Message recieved correctly.");
			System.out.println(RecieveFromClient.getMessage());
		}
		else{
			System.out.println("Message is broken.");
		}

		System.out.print("Enter header: ");
		SendToClient.setHeader(UserInput.nextInt());

		toEscape = UserInput.nextLine();
		System.out.print("Enter message: ");
		SendToClient.setMessage(UserInput.nextLine());

		System.out.print("Enter Protocol ID: ");
		SendToClient.setProtocolID(UserInput.nextInt());

		SendToClient.setParity();

		WriteStream.writeObject(SendToClient);
		System.out.println("Connection Terminated");

		UserInput.close();
		SerSock.close();
		Sock.close();
	}
}