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

**Tính năng, hỗ trợ**

* Hỗ trợ kết nối tốt với arduino
* Đầu ra analog

**Các ứng dụng**

* Làm vườn & canh tác
* Phát hiện độ ẩm
* Nông nghiệp thông minh

**Thông số kỹ thuật**

* Điện áp hoạt động: 3,3 ~ 5,5 VDC
* Điện áp đầu ra: 0 ~ 3.0VDC
* Cường độ dòng điện: 5mA
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
* Cường độ dòng điện: 35mA
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

| Aduino Uno    | Cảm biến độ ẩm đất điện trở     |
|---------------|---------------------------------|
| GND           | GND ( Dây đen )                 |
| 5V            | Dây Đỏ                          |
| Tín hiệu ra   | Dây xanh                        |

**Phạm vi hiệu chuẩn**

* Phạm vi sẽ được chia thành ba phần: đất khô, đất ướt, trong nước. Giá trị liên quan của chúng là:
  * 0 ~ 300 - đất khô
  * 300 ~ 700 - đất ẩm
  * 700 ~ 950 - trong nước

**Chương trình mẫu**
\
Chương trình mẫu có thể tìm thấy tại [**đây**](https://github.com/huyhoang8398/SmartGarden/blob/master/Analog_Soil_Moisture_Sensor_SKU_SEN0114/SampleCode/SampleCode.ino)


#### Mạch LoRa

Công nghệ LoRa , được phát triển bởi Semtech , là một giao thức không dây mới được thiết kế để truyền thông tầm xa, năng lượng thấp. 
Giao thức cung cấp loại khả năng liên lạc mà các thiết bị thông minh cần có, và Liên minh LoRa đang hoạt động để đảm bảo khả năng tương tác giữa nhiều mạng trên toàn quốc.

Một phần của phổ LoRa sử dụng thể hiện ít nhiễu điện từ, do đó tín hiệu có thể kéo dài một khoảng cách xa, thậm chí đi qua các tòa nhà, với rất ít năng lượng. 
Điều này phù hợp với các thiết bị IoT với dung lượng pin hạn chế. 
Điều đó cũng có nghĩa là các tinh thể chi phí thấp hơn có thể được sử dụng, do đó, việc xây dựng LoRa thành các thiết bị rẻ hơn.

Mỗi gateway LoRa có thể xử lý hàng triệu node. 
Điều đó, cộng với thực tế là các tín hiệu có thể kéo dài khoảng cách đáng kể, có nghĩa là cần ít cơ sở hạ tầng mạng hơn, do đó làm cho việc xây dựng mạng LoRa rẻ hơn. 
Các mạng LoRa có thể được đặt cùng với các thiết bị liên lạc khác, như các tháp điện thoại di động, làm giảm đáng kể các hạn chế xây dựng.

Các tính năng khác của LoRa cũng khiến nó trở nên lý tưởng cho IoT. 
LoRa sử dụng thuật toán tốc độ dữ liệu thích ứng để giúp tối đa hóa tuổi thọ pin và dung lượng mạng của thiết bị. 
Các giao thức của nó bao gồm nhiều lớp mã hóa, ở cấp độ mạng, ứng dụng và thiết bị, cho phép liên lạc an toàn. 
Tính hai chiều của giao thức hỗ trợ các thông điệp quảng bá, cho phép chức năng cập nhật phần mềm.

Sự phát triển của Internet of Things bị giới hạn bởi dung lượng của mạng, bởi khả năng hoạt động của thiết bị mà không cần thay pin và bởi khả năng mã hóa truyền dẫn bí mật.
Các tính năng được tích hợp trong LoRa cung cấp tất cả các khả năng này và sẽ cho phép sự phát triển rộng rãi của IoT. 
Với công nghệ Lora, chúng ta có thể truyền dữ liệu với khoảng cách lên hàng km mà không cần các mạch khuếch đại công suất; từ đó giúp tiết kiệm năng lượng tiêu thụ khi truyền/nhận dữ liệu. 
Do đó, LoRa có thể được áp dụng rộng rãi trong các ứng dụng thu thập dữ liệu như sensor network trong đó các sensor node có thể gửi giá trị đo đạc về trung tâm cách xa hàng km và có thể hoạt động với pin trong thời gian dài trước khi cần thay pin.

**So sánh Lora cùng các công nghệ khác**
Vì sao cần phải sử dụng công nghệ Lora ?
Hiện nay, mọi người rất hào hứng với tất cả các khả năng do các cảm biến và thiết bị mới mang lại cho khối lượng dữ liệu hữu ích. 
Nhưng chuyện gì sẽ xảy ra nếu những cảm biến này dừng đột ngột việc phát dữ liệu do hết pin ? 
Pin sẽ cần phải được thay đổi cứ sau vài ngày hoặc vài tuần? Và 1 mạng sẽ xử lý lưu lượng dữ liệu lớn như thế nào?
Rõ ràng, một trong những thách thức chính trong việc xây dựng Internet vạn vật là đảm bảo rằng tất cả những thứ đó trên thực tế có thể giao tiếp qua Internet. 
Số lượng thiết bị IoT là số lượng lớn 25 tỷ thiết bị vào năm 2020, theo một ước tính, và bất kỳ mạng nào hỗ trợ giao tiếp đó phải mở rộng để xử lý lưu lượng. 
Vì vậy, có những vấn đề đối với mạng và cũng có vấn đề với chính các thiết bị IoT: chúng chạy bằng nguồn pin, có sóng yếu và có bộ nhớ và khả năng xử lý hạn chế.
Các thiết bị IoT ngày nay chọn từ một số công nghệ để hỗ trợ liên lạc của họ, nhưng không có thiết bị nào là lý tưởng. Wi-Fi có ở khắp mọi nơi, nhưng nó sử dụng nhiều năng lượng và truyền nhiều dữ liệu. 
Đây không phải là một kết hợp hoàn hảo cho các thiết bị IoT không có năng lượng dự phòng và thường gửi dữ liệu hạn chế với số lượng nhỏ. 
Và cũng có những hạn chế về số lượng thiết bị mà một bộ định tuyến Wi-Fi có thể xử lý và chúng có thể hết dung lượng khi số lượng thiết bị IoT trong nhà tăng lên.

**Băng tần làm việc của LoRa từ 430MHz đến 915MHz cho từng khu vực khác nhau trên thế giới:**
* 430MHz cho châu Á
* 780MHz cho Trung Quốc
* 433MHz hoặc 866MHz cho châu Âu
* 915MHz cho USA

**Giao tiếp Raspberry Pi với LoRa**
\
Mô-đun Lora giao tiếp bằng SPI trên Logic 3.3V. 
Raspberry pi cũng hoạt động ở mức logic 3,3V và cũng có cổng SPI tích hợp và bộ điều chỉnh 3,3V. 
Vì vậy, chúng ta có thể kết nối trực tiếp mô-đun LoRa với Raspberry Pi. Bảng kết nối được hiển thị dưới đây

| Raspberry Pi | Lora Module  |
|--------------|--------------|
| 3.3V         | 3.3V         |
| Ground       | Ground       |
| GPIO 10      | MOSI         |
| GPIO 9       | MISO         |
| GPIO 11      | SCK          |
| GPIO 8       | Nss / Enable |
| GPIO 4       | DIO 0        |
| GPIO 17      | DIO 1        |
| GPIO 18      | DIO 2        |
| GPIO 27      | DIO 3        |
| GPIO 22      | RST          |

Bạn cũng có thể sử dụng sơ đồ mạch dưới đây để tham khảo.

![Sơ đồ mạch kết nối giữa LoRa và Rasp Pi]('./../Circuit-Diagram-for-Connecting-Raspberry-Pi-with-LoRa.png')

**Kết nối Arduino với mạch LoRa**

Bên truyền - Kết nối LoRa với Arduino UNO
Đối với phía truyền phát, chúng tôi sẽ sử dụng Arduino UNO với mô-đun LoRa của chúng tôi. 
Sơ đồ mạch để kết nối Arduino UNO với LoRa được hiển thị bên dưới. 
Mô-đun hoạt động trong 3,3V và do đó chân 3,3V trên LoRa được kết nối với chân 3,3v trên bo mạch Arduino UNO.

![Sơ đồ mạch kết nối giữa LoRa và Arduino Uno]('./../Circuit-Diagram-for-Connect-Arduino-Lora.png')

| LoRa SX1278 Module | Arduino UNO Board |
|--------------------|-------------------|
| 3.3V               | 3.3V              |
| Gnd                | Gnd               |
| En/Nss             | D10               |
| G0/DIO0            | D2                |
| SCK                | D13               |
| MISO               | D12               |
| MOSI               | D11               |
| RST                | D9                |

### Thiết kế cơ sở dữ liệu

![Cơ sở dữ liệu](db.png)

**Ghi chú** 


## XÂY DỰNG - CÀI ĐẶT HTTT QUẢN LÝ THỊ TRƯỜNG KHCN

### MÔI TRƯỜNG VÀ CÁC CÔNG CỤ PHÁT TRIỂN

### XÂY DỰNG HỆ THỐNG

## MỘT SỐ KẾT QUẢ CHÍNH














