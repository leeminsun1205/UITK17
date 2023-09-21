.data
	sizeA: .word 10
	arrA: .word 7,8,1,2,-3,5,3,4,0,-100
	sizeB: .word 12
	arrB: .word 1,2,3,4,5,6,7,8,9,10,11,12
.text
	la $s2, arrA
	lw $s0, sizeA
	la $s3, arrB
	lw $s1, sizeB
	li $t0, 0
LOOP:
	bge $t0, $s0, EXIT
	sll $t1, $t0, 2
	add $t2, $s2, $t1
	add $t3, $s3, $t1
	lw $t4, ($t2)
	sw $t4, ($t3)
	addi $t0, $t0, 1
	j LOOP
EXIT:
	li $t0, 0
LOOP1:
	bge $t0, $s1, EXIT1
	sll $t1, $t0, 2
	add $t2, $s3, $t1
	lw $t3, ($t2)
	
	li $v0, 1
	move $a0, $t3
	syscall
	
	li $v0, 11
	li $a0, 0x20
	syscall
	
	addi $t0, $t0, 1
	j LOOP1
EXIT1: