# UDP_server_reusable
Reusable multi-threaded UDP server/client in C++ built by me containing a Modular interface + heritages that can be adapted to any new implementations and even new protocols like TCP.
In this implementations i adapted the software to be a FTP (File Transfer Protocol) that can sends and receives audio files between clients. The server is in charge of redistributions, processing of messages (serializations) and handling new requests.

USAGE :

LOCAL :

From one terminal :
a) ./server

From another terminal :
b) ./client
  Enter an inetAddr: 127.0.0.1
  
LAN :

From one computer :
a) ./server

From another computer :
b) ./client
  Enter an inetAddr: [addr of the server].
