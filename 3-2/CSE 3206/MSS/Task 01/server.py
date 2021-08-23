import socket

ServerSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ServerSocket.bind((socket.gethostname(), 1345))
ServerSocket.listen(4)

while True:
	ClientSocket, Address = ServerSocket.accept()
	Message.recv(1024)
	print(Message.decode("utf-8"))