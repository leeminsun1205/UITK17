.data
	S1: .asciiz "Nhap so nguyen thu nhat: "
	S2: .asciiz "Nhap so nguyen thu hai: "
	S3: .asciiz "So nguyen lon hon la: "
.text
main:
	#xu?t chu?i S1
	li $v0, 4
	la $a0, S1
	syscall
	#nh?p s? nguy�n th? nh?t
	li $v0, 5
	syscall
	move $t0 , $v0 # chuy?n gi� tr? c?a $v0 ??n $t0
	#xu?t chu?i S2
	li $v0, 4
	la $a0, S2
	syscall
	#nh?p s? nguy�n th? hai
	li $v0, 5
	syscall
	move $t1, $v0
	# n?u gi� tr? c?a $t0 < $t1 th� gi� tr? c?a $t3 = 1, ng??c l?i gi� tr? c?a $t3 = 0
	slt $t3, $t0, $t1
	#so s�nh gi� tr? $t3 v?i 0 
	beq $t3, $zero, ELSE
IF: #n?u gi� tr? c?a $t3 != 0 th� th?c thi
	#xu?t chu?i S3
	li $v0, 4
	la $a0, S3
	syscall
	#xu?t gi� tr? l?n h?n l� gi� tr? c?a $t1
	li $v0, 1
	la $a0, ($t1)
	syscall

	j EXIT
ELSE: #n?u gi� tr? c?a $t3 == 0 th� th?c thi
	#xu?t chu?i S3
	li $v0, 4
	la $a0, S3
	syscall
	#xu?t gi� tr? l?n h?n l� gi� tr? c?a $t0
	li $v0, 1
	la $a0, ($t0)
	syscall
EXIT:
