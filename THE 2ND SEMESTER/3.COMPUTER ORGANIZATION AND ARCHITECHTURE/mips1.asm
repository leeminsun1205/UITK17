.data
	S1: .asciiz	"\nNhap 5 so nguyen can tinh toan: "
	S5: .asciiz	"\nSo le lon nhat la: "
	S4: .asciiz	"\nSo chan lon nhat la: "
	S3: .asciiz	"\nTong cac so le la: "
	S2: .asciiz	"\nTong cac so chan la: "
	Size: .word 5
	Arr: .space 5
.text
main:
	li $v0, 4
	la $a0, S1
	syscall
	
	lw $s0, Size
	la $s1, Arr
	sll $t0, $s0, 2
	add $t1, $s1, $t0
LOOP1:
	bge $s1, $t1, JUMP1
	
	li $v0, 5
	syscall
	sw $v0, ($s1)
	
	addi $s1, $s1, 4
	j LOOP1
JUMP1:
	la $s1, Arr
	sll $t0, $s0, 2
	add $t1, $s1, $t0
LOOP2:
	bge $s1, $t1, JUMP2
	
	li $v0, 1
	lw $a0, ($s1)
	syscall
	
	li $v0, 11
	li $a0, 0x20
	syscall
	
	addi $s1, $s1, 4
	j LOOP2
JUMP2:
	la $s1, Arr
	sll $t0, $s0, 2
	add $t1, $s1, $t0
	li $s2, 0
	li $s3, 0
	li $s4, -999999
	li $s5, -999999
LOOP3:
	bge $s1, $t1, JUMP3
	lw $t2, ($s1)
	andi $t3, $t2, 1
	beq $t3, $0, IFCHAN
	add $s3, $s3, $t2
	bgt $s5, $t2, JUMP4
	move $s5, $t2
	j JUMP4
IFCHAN:
	add $s2, $s2, $t2
	bgt $s4, $t2, JUMP4
	move $s4, $t2
JUMP4:
	addi $s1, $s1, 4
	j LOOP3
JUMP3:
	li $v0, 4
	la $a0, S2
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	li $v0, 4
	la $a0, S3
	syscall
	
	li $v0, 1
	move $a0, $s3
	syscall
	
	li $v0, 4
	la $a0, S4
	syscall
	
	li $v0, 1
	move $a0, $s4
	syscall
	
	li $v0, 4
	la $a0, S5
	syscall
	
	li $v0, 1
	move $a0, $s5
	syscall
	
	li $v0, 10
	syscall
