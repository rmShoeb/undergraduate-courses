import java.io.Serializable;

public class DataPacket implements Serializable{
	private static final long serialVersionUID = 123456L;
	// members
	private int 		Header;
	private String 		Message;
	private int 		ProtocolID;
	private boolean 	Parity;
	private int 		Acknowledgement;

	// methods
	// constructor
	DataPacket(){
		setHeader(0);
		setMessage("");
		setProtocolID(0);
		setAcknowledgement(0);
		setParity();
	}

	// setters and getters
	public void 	setHeader(int Header)			{this.Header = Header;}
	public int 		getHeader()						{return this.Header;}

	public void 	setMessage(String Message)		{this.Message = Message;}
	public String 	getMessage()					{return this.Message;}

	public void 	setProtocolID(int ProtocolID)	{this.ProtocolID = ProtocolID;}

	public void setParity(){
		this.Parity = false;

		if(CalculateParity(this.Header))			this.Parity = !this.Parity;
		if(CalculateParity(this.Message))			this.Parity = !this.Parity;
		if(CalculateParity(this.ProtocolID))		this.Parity = !this.Parity;
		if(CalculateParity(this.Acknowledgement))	this.Parity = !this.Parity;
	}
	public boolean 	getParity()						{return this.Parity;}

	public void 	setAcknowledgement(int Header)	{this.Acknowledgement = Header;}
	public int 		getAcknowledgement()			{return this.Acknowledgement;}

	// check the received message
	public boolean CheckParity(){
		boolean parity = false;

		if(CalculateParity(this.Header))			parity = !parity;
		if(CalculateParity(this.Message))			parity = !parity;
		if(CalculateParity(this.ProtocolID))		parity = !parity;
		if(CalculateParity(this.Acknowledgement))	parity = !parity;

		return parity;
	}

	//parity checking methods
	public boolean CalculateParity(int n){
		boolean parity = false;
		while(n != 0){ 
        	parity = !parity;
        	n = n & (n-1);
		}

		return parity;
	}

	public boolean CalculateParity(String str){
		boolean parity = false;
		byte[] byteArray = str.getBytes();
		int iter;

		for(iter=0; iter<byteArray.length; iter++){
			if(byteArray[iter] == 1)	parity = !parity;
		}

		return parity;
	}

	// Methods to create the packets
	public void CreatePacket(int Header, String Message, int ProtoclID){
		setHeader(Header);
		setMessage(Message);
		setProtocolID(ProtocolID);
		setAcknowledgement(0);
		setParity();
	}

	public void CreatePacket(int Acknowledgement){
		setHeader(0);
		setMessage("");
		setProtocolID(0);
		setAcknowledgement(Acknowledgement);
		setParity();
	}
}