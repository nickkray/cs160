.globl _Main
.globl Main
#### function Main
#### size locals is 12
_Main:
Main:
    push %ebp
    mov %esp, %ebp
    sub $12, %esp
           #### number of args for this func is 0
#### ASSIGN
### found int literal
  pushl $999 #Int
### var lhs called for x
### providing memory address for lhs assign
popl %eax
mov $-4, %ecx
add %ebp, %ecx
### back to assigner to fix for call to var
movl %eax, (%ecx)
#### ASSIGN
### found int literal
  pushl $900 #Int
### var lhs called for y
### providing memory address for lhs assign
popl %eax
mov $-8, %ecx
add %ebp, %ecx
### back to assigner to fix for call to var
movl %eax, (%ecx)
#### ASSIGN
# UnaryMinus
### found int literal
  pushl $1 #Int
  popl %eax
  negl %eax
  pushl %eax
# //UnaryMinus
### var lhs called for z
### providing memory address for lhs assign
popl %eax
mov $-12, %ecx
add %ebp, %ecx
### back to assigner to fix for call to var
movl %eax, (%ecx)
#### ASSIGN
# Times
# Minus
### getting IDENT (retrieving val for) x
pushl -4(%ebp)
### getting IDENT (retrieving val for) y
pushl -8(%ebp)
  popl %ecx
  popl %eax
  subl %ecx, %eax
  pushl %eax
# //Minus
### getting IDENT (retrieving val for) z
pushl -12(%ebp)
  popl %ecx
  popl %eax
  imull %ecx, %eax
  pushl %eax
# //Times
### var lhs called for x
### providing memory address for lhs assign
popl %eax
mov $-4, %ecx
add %ebp, %ecx
### back to assigner to fix for call to var
movl %eax, (%ecx)
### getting IDENT (retrieving val for) x
pushl -4(%ebp)
#### RETURN
popl %eax
    add $12, %esp
    leave
    ret
