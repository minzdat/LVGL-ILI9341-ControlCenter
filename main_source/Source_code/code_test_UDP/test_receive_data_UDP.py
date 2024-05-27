import socket
import time

# Địa chỉ IP và cổng của máy tính (host) hiện đang chạy chương trình
host_ip = '192.168.1.10'
host_port = 1234

# Tạo socket UDP
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    # Liên kết socket với địa chỉ IP và cổng của máy tính
    s.bind((host_ip, host_port))
    
    print("UDP server is running...")
    
    last_print_time = time.time()

    while True:
        # Nhận dữ liệu từ client
        data, addr = s.recvfrom(1024)  
        
        # Giải mã dữ liệu nhận được từ JSON
        received_data = data.decode('utf-8')
        
        # Kiểm tra xem đã đến thời điểm in dữ liệu hay chưa
        current_time = time.time()
        if current_time - last_print_time >= 1:  
            print("Received data from {}:{}".format(addr[0], addr[1]))
            print("Received data:", received_data)
            last_print_time = current_time 