# Bài toán Tháp Hà Nội
## Luật chơi
Có ba cột A, B, C. Ban đầu n đĩa xếp trên cột A, đĩa to nằm dưới, đĩa nhỏ nằm trên. Mỗi lần chỉ được chuyển một đĩa, lấy từ đỉnh một cột và đặt lên đỉnh cột khác. Không được đặt đĩa to lên đĩa nhỏ. Mục tiêu là đưa toàn bộ đĩa sang cột C.

Số bước tối thiểu:
S(n) = 2^n - 1
## 1. Hanoi_tower_recursive.cpp
### Các bước:

1. Nếu n = 1: chuyển đĩa 1 từ dau sang cuoi, tăng biến đếm, kết thúc.
2. Nếu n > 1: chuyển n - 1 đĩa phía trên từ dau sang giua, lấy cuoi làm trung gian.
3. Chuyển đĩa n từ dau sang cuoi.
4. Chuyển n - 1 đĩa đang ở giua sang cuoi, lấy dau làm trung gian.
### Độ phức tạp thời gian

Gọi T(n) là số phép chuyển đĩa khi giải n đĩa.

```
T(1) = 1
T(n) = 2T(n-1) + 1   với n >= 2
```
Suy ra

```
T(n) + 1 = 2(T(n-1) + 1)
```

Đặt U(n) = T(n) + 1 thì U(n) = 2U(n-1) và U(1) = 2, suy ra U(n) = 2^n. Vậy:

```
T(n) = 2^n - 1
```

Suy ra thời gian chạy là O(2^n).

### Độ phức tạp không gian

Độ sâu đệ quy là n nên ngăn xếp gọi hàm dùng O(n) bộ nhớ.

## 2. Hanoi_tower.cpp

### Ý tưởng

Ở các bước lẻ luôn di chuyển đĩa 1, ở các bước chẵn chỉ có đúng một nước đi hợp lệ không dùng đĩa 1 và ta thực hiện nước đó.
### Các bước
 
1. Đặt n đĩa lên cột đầu theo thứ tự từ n xuống 1 để đĩa 1 nằm trên cùng.
2. Sắp thứ tự ba cột trong mảng coc theo tính chẵn lẻ của n. Nếu n chẵn thì thứ tự là A, B, C. Nếu n lẻ thì thứ tự là A, C, B.
3. Lặp từ bước 1 đến bước cuối. Ở bước lẻ, chuyển đĩa 1 sang cột kế tiếp trong vòng, với vị trí mới tính bằng (vị trí cũ + 1) chia lấy dư cho 3.
4. Ở bước chẵn, lấy hai cột không chứa đĩa 1 rồi gọi hàm Move. Nếu một cột rỗng thì chuyển đĩa từ cột kia sang cột rỗng. Nếu cả hai cột đều có đĩa thì chuyển đĩa nhỏ hơn sang cột có đĩa lớn hơn.

### Độ phức tạp thời gian
```
số bước lẻ   = 2^(n-1)
số bước chẵn = 2^(n-1) - 1
tổng         = 2^(n-1) + 2^(n-1) - 1 = 2^n - 1
```
Khởi tạo đặt n đĩa lên cột đầu mất O(n). Vậy:

```
T(n) = (2^n - 1) + n = O(2^n)
```
### Độ phức tạp không gian

Ba vector chứa tổng cộng n đĩa tại mọi thời điểm => bộ nhớ dùng là O(n).
## 3. Test cases

### Test case 1

Input: n = 1

Output đệ quy:

```
Nhap so dia: 1
Buoc 1: Chuyen dia 1 tu cotA sang cot C
So buoc: 1
```

Output khử đệ quy:

```
Nhap so dia: 1
Tong so buoc can thuc hien: 1
Buoc 1: Chuyen dia 1 tu cot A sang cot C
```


### Test case 2
Input: n = 2
Output đệ quy:

```
Nhap so dia: 2
Buoc 1: Chuyen dia 1 tu cotA sang cot B
Buoc 2: Chuyen dia 2tu cotA sang cot C
Buoc 3: Chuyen dia 1 tu cotB sang cot C
So buoc: 3
```
output khử đệ quy:
```
Nhap so dia: 2
Tong so buoc can thuc hien: 3
Buoc 1: Chuyen dia 1 tu cot A sang cot B
Buoc 2: Chuyen dia 2 tu cot A sang cot C
Buoc 3: Chuyen dia 1 tu cot B sang cot C
```
### Test case 3
Input: n = 3
Output đệ quy:

```
Nhap so dia: 3
Buoc 1: Chuyen dia 1 tu cotA sang cot C
Buoc 2: Chuyen dia 2tu cotA sang cot B
Buoc 3: Chuyen dia 1 tu cotC sang cot B
Buoc 4: Chuyen dia 3tu cotA sang cot C
Buoc 5: Chuyen dia 1 tu cotB sang cot A
Buoc 6: Chuyen dia 2tu cotB sang cot C
Buoc 7: Chuyen dia 1 tu cotA sang cot C
So buoc: 7
```

Output khử đệ quy:

```
Nhap so dia: 3
Tong so buoc can thuc hien: 7
Buoc 1: Chuyen dia 1 tu cot A sang cot C
Buoc 2: Chuyen dia 2 tu cot A sang cot B
Buoc 3: Chuyen dia 1 tu cot C sang cot B
Buoc 4: Chuyen dia 3 tu cot A sang cot C
Buoc 5: Chuyen dia 1 tu cot B sang cot A
Buoc 6: Chuyen dia 2 tu cot B sang cot C
Buoc 7: Chuyen dia 1 tu cot A sang cot C
```
### Test case 4
Input: n = 4
Output đệ quy:

```
Nhap so dia: 4
Buoc 1: Chuyen dia 1 tu cotA sang cot B
Buoc 2: Chuyen dia 2tu cotA sang cot C
Buoc 3: Chuyen dia 1 tu cotB sang cot C
Buoc 4: Chuyen dia 3tu cotA sang cot B
Buoc 5: Chuyen dia 1 tu cotC sang cot A
Buoc 6: Chuyen dia 2tu cotC sang cot B
Buoc 7: Chuyen dia 1 tu cotA sang cot B
Buoc 8: Chuyen dia 4tu cotA sang cot C
Buoc 9: Chuyen dia 1 tu cotB sang cot C
Buoc 10: Chuyen dia 2tu cotB sang cot A
Buoc 11: Chuyen dia 1 tu cotC sang cot A
Buoc 12: Chuyen dia 3tu cotB sang cot C
Buoc 13: Chuyen dia 1 tu cotA sang cot B
Buoc 14: Chuyen dia 2tu cotA sang cot C
Buoc 15: Chuyen dia 1 tu cotB sang cot C
So buoc: 15
```
Output khử đệ quy:
```
Nhap so dia: 4
Tong so buoc can thuc hien: 15
Buoc 1: Chuyen dia 1 tu cot A sang cot B
Buoc 2: Chuyen dia 2 tu cot A sang cot C
Buoc 3: Chuyen dia 1 tu cot B sang cot C
Buoc 4: Chuyen dia 3 tu cot A sang cot B
Buoc 5: Chuyen dia 1 tu cot C sang cot A
Buoc 6: Chuyen dia 2 tu cot C sang cot B
Buoc 7: Chuyen dia 1 tu cot A sang cot B
Buoc 8: Chuyen dia 4 tu cot A sang cot C
Buoc 9: Chuyen dia 1 tu cot B sang cot C
Buoc 10: Chuyen dia 2 tu cot B sang cot A
Buoc 11: Chuyen dia 1 tu cot C sang cot A
Buoc 12: Chuyen dia 3 tu cot B sang cot C
Buoc 13: Chuyen dia 1 tu cot A sang cot B
Buoc 14: Chuyen dia 2 tu cot A sang cot C
Buoc 15: Chuyen dia 1 tu cot B sang cot C
```