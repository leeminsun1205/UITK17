.data
	in1: .space 80
	in2: .space 80
	S1: .asciiz "Nhap so nguyen thu nhat: "
	S2: .asciiz "Nhap so nguyen thu hai: "
	S3: .asciiz "Tong hai so nguyen la: "
	S4: .asciiz "\nHieu hai so nguyen la: "
.text
main:
	#xu?t chu?i S1
	li $v0, 4
	la $a0, S1
	syscall
	#nh?p s? nguy�n th? nh?t
	li $v0, 5
	la $a0, in1
	syscall
	move $t0, $v0
	#xu?t chu?i S2
	li $v0, 4
	la $a0, S2
	syscall
	#nh?p s? nguy�n th? 2
	li $v0, 5
	la $a0, in2
	syscall
	move $t1, $v0
	#xu?t chu?i S3
	li $v0, 4
	la $a0, S3
	syscall
	
	add $t2, $t0, $t1 #gi� tr? $t2= gi� tr? $t0+gi� tr? $t1
	li $v0, 1
	la $a0, ($t2) #xu?t gi� tr? $t2
	syscall
	#xu?t chu?i S4
	li $v0, 4
	la $a0, S4
	syscall

	sub $t3, $t0, $t1 #gi� tr? $t2= gi� tr? $t0-gi� tr? $t1
	li $v0, 1
	la $a0, ($t3) #xu?t gi� tr? $t3
	syscall
