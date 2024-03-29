section .data
    window_size db 7
    sum dq 0.0

section .text
    bits 64
    default rel

global stencil1DComputation

stencil1DComputation:
    push rsi
    push rcx ; offset
    push rdx ; X
    mov r8, [window_size]
    add r8, rcx
    push r8 ; window_size+offset
    mov r9, rcx
    push r9 ; iterator
    movss xmm0, [sum]
    call LOOP
    pop rsi
    ret


LOOP:
    movss xmm1, [rdx + r9*4] ; access element in X using offset * 4 for float
    addss xmm0, xmm1 ; add current sum + current element
    inc r9     ; offset++

    ; offset < window_size + offset
    cmp r9, r8 
    jl LOOP

    ret 32


    



