import socket

udp_ip = "192.168.4.2"  # IP address of ESP32 in AP mode
udp_port = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
sock.bind((udp_ip, udp_port))

print("UDP server started")

while True:
    data, addr = sock.recvfrom(1024)  # buffer size is 1024 bytes
    print("ADC Voltage:", data.decode())
