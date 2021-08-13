import java.net.*;
import java.io.*;
import java.util.Scanner;


public class server{
	public static void main(String[] args){
		try{
            ServerSocket  			SerSock     		= new ServerSocket(1234);
            Socket        			Sock        		= SerSock.accept();
            System.out.println("Client Connected. Enter 'Exit/exit' to disconnect.");

            InputStreamReader     	RecieveFromClient   = new InputStreamReader(Sock.getInputStream());
            BufferedReader        	ReadBuffer          = new BufferedReader(RecieveFromClient);
            String                	ClientInput;
            String 					SendToClient;
            Scanner 				UserInput 			= new Scanner(System.in);
			PrintWriter 			WriteToClient 		= new PrintWriter(Sock.getOutputStream(), true);


            ClientInput = ReadBuffer.readLine();
            while(!ClientInput.equalsIgnoreCase("Exit")){
	            System.out.println("Client: " + ClientInput);

	            System.out.print("Server: ");
	            SendToClient = UserInput.nextLine();
	            WriteToClient.println(SendToClient);
	            if(SendToClient.equalsIgnoreCase("Exit"))
	            	break;
	            ClientInput = ReadBuffer.readLine();
            }
            System.out.println("Connection Terminated");

            RecieveFromClient.close();
            WriteToClient.close();
            Sock.close();
        }
        catch(IOException e){
            System.out.println(e.toString());
        }
	}
}