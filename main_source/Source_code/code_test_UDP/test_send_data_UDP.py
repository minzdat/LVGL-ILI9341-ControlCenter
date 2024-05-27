import socket
import json

# Địa chỉ IP và cổng của ESP32
esp32_ip = '192.168.1.8'  
esp32_port = 1234  

# Tạo socket UDP
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    # Tạo dữ liệu nhiệt độ và độ ẩm giả định
    data = {
        "temperature": 25.5,  
        "humidity": 70.0       
    }
    
    # Chuyển đổi dữ liệu thành chuỗi JSON
    message = json.dumps(data)
    
    # Gửi dữ liệu tới ESP32
    s.sendto(message.encode('utf-8'), (esp32_ip, esp32_port))

print("Data sent to ESP32.")
