---
title: " USTH Smart Garden "
author: \textbf{Member} \newline
        HOANG Duc Minh \newline 
        DO Duy Huy Hoang \newline
        \newline
        \textit{University of Science and Technology Hanoi} \newline 
        \textit{ICT Department}
date: {today}
logo-width: 200
titlepage: true
...

\newpage{}
\tableofcontents
\newpage{}

# KHẢO SÁT - PHÂN TÍCH – THIẾT KẾ HỆ THỐNG THÔNG TIN QUẢN LÝ THỊ TRƯỜNG KHCN

## Bài toán thị trường KHCN của dự án Vườn thông minh USTH

Làm vườn rất thú vị, vì vậy chúng tôi nghĩ về việc thực hiện một dự án làm vườn. 
Ngày nay hệ thống vườn thông minh rất phổ biến vì mọi người thích chúng. 
Tuy nhiên, thách thức của chúng tôi là làm cho dự án rất đơn giản để bất cứ ai cũng có thể thực hiện điều này.
Hóa ra, các dự án dựa trên bảng phát triển phần cứng mở Arduino là một nơi tuyệt vời để bắt đầu.
Một cảm biến độ ẩm đất có thể đọc được độ ẩm có trong đất xung quanh nó. 
Đó là một lý tưởng để theo dõi một khu vườn đô thị, hoặc mực nước của nhà máy vật nuôi của bạn. 
Đây là một thành phần phải có cho một khu vườn / Nông nghiệp IOT!

## Phân tích yêu cầu
### Các yêu cầu đối với hệ thống

### Mô hình các use cases đặc tả cảc yêu cầu chức năng của hệ thống

### Biểu đồ lớp thể hiện cấu trúc bên trong của hệ thống


## THIẾT KẾ HTTT QUẢN LÝ THỊ TRƯỜNG KHCN

### Kiến trúc hệ thống

### Phân tích các gói thành phần trong kiến trúc của hệ thống

Hiện tại hệ thống của chúng tôi đang dựa trên hai cảm biến sau: 
* Cảm biến độ ẩm đất điện dung
* Cảm biến độ ẩm đất điện trở 

#### Cảm biến độ ẩm đất điện dung

![Cảm biến độ ẩm đất điện dung](image1.png)

Cảm biến này đo độ ẩm của đất bằng cảm biến điện dung, thay vì cảm biến điện trở như các loại cảm biến độ ẩm khác. 
Nó được làm bằng vật liệu chống ăn mòn mang lại tuổi thọ cao. 
Đồng thời dữ liệu được trả về với thời gian thực.

Sản phẩm bao gồm một bộ điều chỉnh điện áp trên bo mạch cho nó một phạm vi điện áp hoạt động từ 3,3 ~ 5,5V. 
Nó tương thích với MCU điện áp thấp (cả mức 3,3V và 5V). 
Để làm cho nó tương thích với Raspberry Pi, cần có bộ chuyển đổi ADC.

Ví dụ, chúng ta có thể sử dụng Arduino để đọc giá trị trực tiếp từ cảm biến.

**TÍNH NĂNG, ĐẶC ĐIỂM**

* Hỗ trợ kết nối tốt với arduino
* Đầu ra analog

**CÁC ỨNG DỤNG**

* Làm vườn & canh tác
* Phát hiện độ ẩm
* Nông nghiệp thông minh

**Thông số kỹ thuật**

* Điện áp hoạt động: 3,3 ~ 5,5 VDC
* Điện áp đầu ra: 0 ~ 3.0VDC
* Hiệu điện thế: 5mA
* Giao tiếp: PH2.0-3P
* Kích thước: 3,86 x 0,90 inch (L x W)
* Trọng lượng: 15g

**Sơ đồ mạch**

![Sơ đồ mạch](schematic.png)

**Kết nối**

![Mạch kết nối giữa cảm biến và Arduino Uno](capa.png)

| Aduino Uno    | Cảm biến độ ẩm đất điện dung   |
|---------------|---------------------------------|
| GND           | GND ( Black wire )              |
| 5V            | Red Wire                        |
| Analog output | Blue Wire                       |

**Phạm vi hiệu chuẩn**
\
Các thành phần trên bảng này KHÔNG thấm nước, không được để mạch điện tiếp xúc với độ ẩm quá vạch màu đỏ. 
(Nếu bạn muốn bảo vệ các thành phần khỏi các yếu tố, hãy thử sử dụng ống co nhiệt bao quanh chiều dài của cảm biến) 
Có một tỷ lệ nghịch giữa đầu ra cảm biến giá trị và độ ẩm của đất.

![Phạm vi hiệu chuẩn](SEN0193-test.png)

* Giá trị đầu ra cuối cùng bị ảnh hưởng bởi độ sâu chèn đầu dò và độ chặt của đất xung quanh nó.
* Phạm vi sẽ được chia thành ba phần: khô, ướt, nước. Giá trị liên quan của chúng là:
   * Khô: (520 430]
   * Ướt: (430 350]
   * Nước: (350 260]

**Chương trình mẫu**
\
Chương trình mẫu của chúng tôi có thể được tìm thấy [**tại đây**](https://github.com/huyhoang8398/SmartGarden/blob/master/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193/ExampleCode/ExampleCode.c)

#### Cảm biến độ ẩm đất điện trở
![Cảm biến độ ẩm đất điện trở](IMGP5217.jpg)

Cảm biến này đối với Arduino có thể đọc lượng ẩm có trong đất xung quanh nó. Đó là một cảm biến công nghệ thấp, nhưng lý tưởng để theo dõi một khu vườn đô thị, hoặc mực nước của khu vườn tại nhà của bạn. 
Đây là một công cụ cần thiết cho một khu vườn thông minh!
Cảm biến độ ẩm đất mới sử dụng Vàng ngâm để bảo vệ niken khỏi quá trình oxy hóa. 
Vàng ngâm niken điện phân (ENIG) có một số lợi thế so với các bề mặt thông thường (và rẻ hơn) như HASL (hàn), bao gồm cả bề mặt phẳng tuyệt vời (đặc biệt hữu ích cho PCB với các gói BGA lớn), chống oxy hóa tốt và khả năng tiếp xúc không được xử lý các bề mặt như màng chuyển mạch và các điểm tiếp xúc.

Cảm biến arduino độ ẩm đất này sử dụng hai đầu dò để truyền dòng điện qua đất, và sau đó nó đọc điện trở đó để có được độ ẩm. 
Nhiều nước làm cho đất dẫn điện dễ dàng hơn (ít điện trở hơn), trong khi đất khô dẫn điện kém (điện trở nhiều hơn). 
Cảm biến này sẽ hữu ích để nhắc nhở bạn tưới nước cho cây trồng trong nhà hoặc theo dõi độ ẩm của đất trong khu vườn của bạn.

**Ghi chú**: Nếu bạn có ý định sử dụng cảm biến này trong điều kiện đất quá ẩm, nó rất có thể gây ra việc oxi hóa bề mặt của cảm biến chỉ trong vài ngày,
Vì vậy, chúng tôi khuyến nghị việc sử dụng cảm biến đổ ẩm đất điện trở tích hợp kháng ăn mòn.

**Thông số kĩ thuật**

* Nguồn điện: 3,3V ~ 5V
* Tín hiệu điện áp đầu ra: 0 ~ 4.2V
* Hiệu điện thế: 35mA
* Định nghĩa pin:
  * Màu xanh dương: đầu ra tương tự
  * Đen: GND
  * Đỏ: Nguồn vào
* Kích thước: 60x20x5mm
* Phạm vi giá trị:
  * 0 ~ 300: đất khô
  * 300 ~ 700: đất ẩm
  * 700 ~ 950: trong nước

**Sơ đồ mạch**

![Sơ đồ mạch của cảm biến với Arduino Uno](SEN0114_Dia.png) 

| Aduino Uno    | Cảm biến độ ẩm đất điện trở |
|---------------|---------------------------------|
| GND           | GND ( Dây đen )                 |
| 5V            | Dây Đỏ                          |
| Tín hiệu ra   | Dây xanh                        |

**Chương trình mẫu**
\
Chương trình mẫu có thể tìm thấy tại [**đây**](https://github.com/huyhoang8398/SmartGarden/blob/master/Analog_Soil_Moisture_Sensor_SKU_SEN0114/SampleCode/SampleCode.ino)

### Thiết kế cơ sở dữ liệu



## XÂY DỰNG - CÀI ĐẶT HTTT QUẢN LÝ THỊ TRƯỜNG KHCN

### MÔI TRƯỜNG VÀ CÁC CÔNG CỤ PHÁT TRIỂN

### XÂY DỰNG HỆ THỐNG

## MỘT SỐ KẾT QUẢ CHÍNH














