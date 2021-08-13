import java.net.*;
import java.io.*;
import java.util.Scanner;


public class client{
	public static void main(String[] args){
		try{
			Socket 				CliSock 			= new Socket("localhost", 1234);
			System.out.println("Connected to Server. Enter 'Exit/exit' to disconnect.");

			InputStreamReader 	RecieveFromServer 	= new InputStreamReader(CliSock.getInputStream());
			BufferedReader 		ReadBuffer 			= new BufferedReader(RecieveFromServer);
			String 				ServerInput;
			String 				SendToServer;
			Scanner 			UserInput 			= new Scanner(System.in);
			PrintWriter 		WriteToServer 		= new PrintWriter(CliSock.getOutputStream(), true);

			System.out.print("Client: ");
			SendToServer = UserInput.nextLine();
			WriteToServer.println(SendToServer);
			while(!SendToServer.equalsIgnoreCase("Exit")){
				ServerInput = ReadBuffer.readLine();
				System.out.println("Server: " + ServerInput);
				if(ServerInput.equalsIgnoreCase("Exit"))
					break;

				System.out.print("Client: ");
				SendToServer = UserInput.nextLine();
				WriteToServer.println(SendToServer);
			}
			System.out.println("Connection Terminated");

			RecieveFromServer.close();
			WriteToServer.close();
			CliSock.close();
		}
		catch(IOException e){
			System.out.println(e.toString());
		}
	}
}
