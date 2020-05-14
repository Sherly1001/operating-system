# ex2

## File .com

Là file thực thi trên Windows hoặc Mac Os được xây dựng trên cấu trúc PE và COFF.

### Ví dụ file .com
```asm
.MODEL Tiny
.CODE
    Org 100h
    Jmp Start
    ;Các khai báo biến
Start:
    ;Thân chương trình
    Int 20h
    ;Nếu chương trình con có thì viết ở đây
End Start
```

---
## File .exe

Là file thực thi chương trình trên Windows, khác với file .com, file .exe có thêm phần khai báo dành riêng cho data.

### Ví dụ file .exe
```asm
MODEL Small
.STACK 100h
.DATA
    ;Khai báo biến ở đây
.CODE
Start:
    ;Để nạp data vào dx
    Mov ax,@DATA
    Mov ds,ax
    ;Phần thân chương trình
    ;Trả quyền lại cho hệ điều hành
    Mov ah,4ch
    inh 21h
End Start
```

---
### Độ ưu tiên giữa file .exe và file .com
Nếu trong cùng một folder mà có 2 file .exe và file .com cùng tên.
Chạy file đó với tên (không có extension) thì chương trình sẽ ưu tiên file .com hơn.

Nếu muốn chạy file .exe thì phải gõ cả extension .exe sau tên file.