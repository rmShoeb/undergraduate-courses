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
		int 				iter 				= 0;

		while(iter<10){
			DataPacket 			SendToServer 		= new DataPacket();
			DataPacket 			RecievedFromServer 	= new DataPacket();
			
			SendToServer.CreatePacket(iter, UserInput.nextLine(), 100);
			WriteStream.writeObject(SendToServer);
			
			RecievedFromServer = (DataPacket)ReadStream.readObject();
			if(RecievedFromServer.CheckParity() == RecievedFromServer.getParity()){
				System.out.println("Acknowledgement recieved correctly.");
				if(RecievedFromServer.getAcknowledgement() == SendToServer.getHeader()){
					System.out.println("Server recieved correct frame.");
				}
				else{
					System.out.println("Server recieved wrong frame.");
				}
			}
			else{
				System.out.println("Message is broken.");
			}

			SendToServer = null;
			RecievedFromServer = null;
			iter++;
		}

		UserInput.close();
		CliSock.close();
	}
}
