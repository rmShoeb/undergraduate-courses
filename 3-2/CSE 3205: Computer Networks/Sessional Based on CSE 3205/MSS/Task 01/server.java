import java.net.*;
import java.io.*;

public class server{
	public static void main(String[] args){
		try{
            ServerSocket  SerSock     = new ServerSocket(1234);
            Socket        Sock        = SerSock.accept();

            System.out.println("Client Connected");

            InputStreamReader     RecieveFromClient     = new InputStreamReader(Sock.getInputStream());
            BufferedReader        ReadBuffer            = new BufferedReader(RecieveFromClient);
            String                ClientInput           = ReadBuffer.readLine();

            System.out.println("Client says: " + ClientInput);
            RecieveFromClient.close();
            Sock.close();
        }
        catch(IOException e){
            System.out.println(e.toString());
        }
	}
}