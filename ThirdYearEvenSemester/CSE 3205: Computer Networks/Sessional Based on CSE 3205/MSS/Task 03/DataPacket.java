import java.io.Serializable;

public class DataPacket implements Serializable{
	private static final long serialVersionUID = 123456L;
	// members
	private int 		Header;
	private String 		Message;
	private int 		ProtocolID;
	private boolean 	Parity;

	// methods
	// constructor
	DataPacket(){
		setHeader(0);
		setMessage("");
		setProtocolID(0);
		setParity();
	}

	// setters and getters
	public void 	setHeader(int Header)			{this.Header = Header;}
	public int 		getHeader()						{return this.Header;}

	public void 	setMessage(String Message)		{this.Message = Message;}
	public String 	getMessage()					{return this.Message;}

	public void 	setProtocolID(int ProtocolID)	{this.ProtocolID = ProtocolID;}

	public void setParity(){
		this.Parity = true;

		if(CalculateParity(this.Header))		this.Parity = !this.Parity;
		if(CalculateParity(this.Message))		this.Parity = !this.Parity;
		if(CalculateParity(this.ProtocolID))	this.Parity = !this.Parity;
	}
	public boolean 	getParity()						{return this.Parity;}

	// check the received message
	public boolean CheckParity(){
		boolean parity = true;

		if(CalculateParity(this.Header))		parity = !parity;
		if(CalculateParity(this.Message))		parity = !parity;
		if(CalculateParity(this.ProtocolID))	parity = !parity;

		return parity;
	}

	//parity checking functions
	public boolean CalculateParity(int n){
		boolean parity = true;
		while(n != 0){ 
        	parity = !parity;
        	n = n & (n-1);
		}

		return parity;
	}

	public boolean CalculateParity(String str){
		boolean parity = true;
		byte[] byteArray = str.getBytes();
		int iter;

		for(iter=0; iter<byteArray.length; iter++){
			if(byteArray[iter] == 1)	parity = !parity;
		}

		return parity;
	}
}