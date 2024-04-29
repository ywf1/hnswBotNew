import socket

host = "192.168.4.1" # IP address of the ESP32 access point
port = 80            # Port on which the ESP32 server is listening

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        print("Connected to ESP32 Access Point")

        while True:
            data = s.recv(1024)
            if not data:
                break
            print("Received:", data.decode())

if __name__ == "__main__":
    main()
