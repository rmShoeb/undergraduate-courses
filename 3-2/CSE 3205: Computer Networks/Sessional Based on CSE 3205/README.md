# **CSE3206_ComputerNetworks**
---
**MSS**
---
**Task 01**
create a server-client application (simple) where the server will response according to the client.

**Task 02**
create a server-client applicaton (chatbot)
* server and client both can send messages
* both can terminate connection anytime they want

**Task 03**

now send objects containing:
* header of any type
* data of int/float/string
* protocol id
* tailer to send parity - even (binary)

**Task 04**
* client will send an object
* server will send an acknowlwdement containing
	header = null;
	message = null;
	protocolID = null
	acknowldement = header of the recieved object
	parity
