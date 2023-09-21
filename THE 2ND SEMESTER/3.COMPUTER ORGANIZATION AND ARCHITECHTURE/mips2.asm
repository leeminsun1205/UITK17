.data
	S1: .asciiz "Cac phan thu cua mang array1 la: "
	array1: .word 5,6,7,8,1,2,3,9,10,4
	size1: .word 10
	
	S2: .asciiz "\nCac phan thu cua mang array2 la: "
	array2: .byte 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
	size2: .word 16
	
	S3: .asciiz "\nCac phan thu cua mang array3 la: "
	array3: .space 8
	size3: .word 8
	
	S4: .asciiz "\nNhap mang can tim (mang 1,2,3): "
	S5: .asciiz "Nhap chi so cua phan tu can tim trong mang: "
	S6: .asciiz "Phan tu can tim la: "
	Space: .asciiz " "
.text 
	li $v0, 4
	la $a0, S1
	syscall
	
	add $t0, $0, $0
	lw $s0, size1
	la $s1, array1
LOOP1:
	bge $t0, $s0, JUMP1
	sll $t1, $t0, 2
	add $t2, $s1, $t1
	lw $t3, ($t2)
	
	li $v0, 1
	move $a0, $t3
	syscall
	
	li $v0, 11
	li $a0, 0x20
	syscall
	
	addi $t0, $t0, 1
	j LOOP1
JUMP1:
	li $v0, 4
	la $a0, S2
	syscall
	
	add $t0, $0, $0
	lw $s0, size2
	la $s1, array2
LOOP2:
	bge $t0, $s0, JUMP2
	add $t1, $s1, $t0
	lb $t2, ($t1)
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 11
	li $a0, 0x20
	syscall
	
	addi $t0, $t0, 1
	
	j LOOP2
JUMP2:
	add $t0, $0, $0
	lw $s0, size3
	la $s1, array3
	
	add $t1, $0, $0
	lw $s2, size2
	la $s3, array2
	
	addi $t2, $s2, -1
LOOP3:
	bge $t0, $s0, JUMP3
	add $t5, $s1, $t0
	add $t6, $s3, $t1
	add $t7, $s3, $t2
	
	lb $s4, ($t6)
	lb $s5, ($t7)
	add $s6, $s4, $s5
	sb $s6, ($t5)
	
	addi $t0, $t0, 1
	addi $t1, $t1, 1
	addi $t2, $t2, -1
	j LOOP3
JUMP3:
	li $v0, 4
	la $a0, S3
	syscall
	
	addi $t0, $0, 0
	la $s0, array3
	lw $s1, size3
LOOP4:
	bge $t0, $s1, JUMP4
	add $t1, $s0, $t0
	lb $t2, ($t1)
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 11
	li $a0, 0x20
	syscall
	
	addi $t0, $t0, 1
	j LOOP4
JUMP4:
	li $v0, 4
	la $a0, S4
	syscall 
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	la $a0, S5
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	li $v0, 4
	la $a0, S6
	syscall
	
	bne $t0, 1, ELSEIF
	add $t2, $0, $0
	lw $s0, size1
	la $s1, array1
LOOP5:
	bge $t2, $s0, EXIT
	sll $t3, $t2, 2
	add $t4, $s1, $t3
	lw $t5, ($t4)
	
	bne $t1, $t2, NEXT1
	li $v0, 1
	move $a0, $t5
	syscall
	j EXIT
NEXT1:
	addi $t2, $t2, 1
	j LOOP5
ELSEIF:
	bne $t0, 2, ELSE
	addi $t2, $0, 0
	lw $s0, size2
	la $s1, array2
LOOP6:
	bge $t2, $s0, EXIT
	add $t3, $s1, $t2
	lb $t4, ($t3)
	bne $t1, $t2, NEXT2
	li $v0, 1
	move $a0, $t4
	syscall
NEXT2:
	addi $t2, $t2, 1
	j LOOP6
ELSE:
	bne $t0, 3, EXIT
	addi $t2, $0, 0
	lw $s0, size3
	la $s1, array3
LOOP7:
	bge $t2, $s0, EXIT
	add $t3, $s1, $t2
	lb $t4, ($t3)
	bne $t1, $t2, NEXT3
	li $v0, 1
	move $a0, $t4
	syscall
NEXT3:
	addi $t2, $t2, 1
	j LOOP7
EXIT:
	li $v0, 10
	syscall
	
	
	