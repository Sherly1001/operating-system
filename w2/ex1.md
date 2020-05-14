# API
---
### API = Application Programming Interface = giao diện lập trình ứng dụng.

Mỗi hệ điều hành hay phần mềm đều cung cấp cho người lập trình các hàm tương tác với CSDL, lập trình thực hiện các thao tác với hệ điều hành hay phần mềm đó.

Các hàm trong thư viện API của hệ điều hành Windows cho phép chúng ta lập trình ứng dụng thay đổi icon màn hình, xem thông tin máy tình,…

---
### Win api

Các thư viện API phổ biến trên Windows (hầu hết các hàm API được chứa trong các file \*.DLL(Dynamic Link Library) chứa trong thư mục hệ thống của Windows thường là C:\Windows\System\\)

* Advapi32.dll : Thư viện dịch vụ cao cấp API hỗ trợ rất nhiều các API bao gồm bảo mật và các lời gọi Registry.

* Comdlg32.dll: Các thư viện API Dialog phổ biến

* Gdi32.dll: Các hàm giao tiếp thiết bị đồ họa, cung cấp các chức năng đồ họa cần thiết.

* Kernel32.dll: Xử lý quản lý bộ nhớ, xử lý đa nhiệm các chương trình đang chạy.

* Shell32.dll: Các hàm hệ vỏ của Windows

* Ntdll.dll : Thư viện đa phương tiện của Windows, cung cấp các hàm nội bộ

* User32.dll: chứa các hàm liên quan đến việc quản lý cửa sổ, cho người dùng nhập dữ liệu. Là một trong những thư viện quan trọng nhất đối với các hoạt động của Windows. Nếu tập tin này bị xóa hoặc loại bỏ, hệ thống sẽ không làm việc.

Một số hàm tiêu biểu trong User32.dll : CreateWindow, MoveWindow, BringWindowtoTop, CloseWindow, DestroyWindow, GetGUIThreadInfo,EnableWindow.

---
### Linux
Trong linux không có các thư viện API tương tự như Windows, nhưng thay vào đó nó sử dụng các syscall (system call).

Có thể tham khảo các syscall của linux ở [đây](https://syscalls.kernelgrok.com/)

---
### Mac
Mac os cũng tương tự với linux