
# Maze Runner

Đồ án: Phát triển robot di động (ballbot, Maze runner, mobile bot,...) cho môi trường thông minh


## Linh kiện sử dụng
- Vi điều khiển 8051 (AT89S52)
- Cảm biến siêu âm (HC-SR04) x3
- Module điều khiển động cơ (L298N)
- Động cơ DC x4
- Các linh kiện khác (Trở, tụ, thạch anh,...)
## Nguyên lí hoạt động
- Sử dụng 3 cảm biến siêu âm để phát hiện vật cảm
- Xe chuyển động theo thứ tự ưu tiên: Xe luôn rẽ phải nếu không có vật cản sau đó là đi thẳng cuối cùng là rẽ trái, nếu cả 3 hướng đều có vật cản thì rẽ trái hoặc phải
