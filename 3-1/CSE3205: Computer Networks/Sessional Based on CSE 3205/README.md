# CSE3206_ComputerNetworks
#1
create a server-client applicaton (chatbot)
* server and client both can send messages
* both can terminate connection anytime they want

#2
now send objects containing:
* header of any type
* data of int/float/string
* protocol id
* tailer to send parity - even (binary)

#3
* client will send an object
* server will send an acknowlwdement containing
	header = null;
	message = null;
	protocolID = null
	acknowldement = header of the recieved object
	parity
