import java.net.*;
import java.io.*;


public class server{
	public static void main(String[] args) throws IOException, ClassNotFoundException{
		ServerSocket 		SerSock 			= new ServerSocket(1234);
		Socket 				Sock 				= SerSock.accept();
		System.out.println("Client Connected.");

		ObjectOutputStream 	WriteStream 		= new ObjectOutputStream(Sock.getOutputStream());
		ObjectInputStream 	ReadStream 			= new ObjectInputStream(Sock.getInputStream());
		int 				iter 				= 0;


		while(iter<10){
			DataPacket 			SendToClient 		= new DataPacket();
			DataPacket 			RecieveFromClient 	= new DataPacket();
			
			RecieveFromClient = (DataPacket)ReadStream.readObject();
			if(RecieveFromClient.CheckParity() == RecieveFromClient.getParity()){
				System.out.println("Message recieved correctly.");
				System.out.println(RecieveFromClient.getMessage());
			}
			else{
				System.out.println("Message is broken.");
			}

			SendToClient.CreatePacket(RecieveFromClient.getHeader());

			WriteStream.writeObject(SendToClient);

			SendToClient = null;
			RecieveFromClient = null;
			iter++;
		}

		
		System.out.println("Connection Terminated");

		SerSock.close();
		Sock.close();
	}
}