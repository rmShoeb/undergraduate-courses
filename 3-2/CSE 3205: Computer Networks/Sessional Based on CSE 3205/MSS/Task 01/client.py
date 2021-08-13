import socket

ClientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ClientSocket.connect((socket.gethostname(), 1345))

Message = input()

ClientSocket.send(Message.encode("utf-8"))