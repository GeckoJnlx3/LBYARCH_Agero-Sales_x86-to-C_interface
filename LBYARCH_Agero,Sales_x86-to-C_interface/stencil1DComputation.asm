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
    push r8 ; window_size
    movss xmm0, [sum]
    call LOOP
    pop rsi
    ret


LOOP:
    movss xmm1, [rdx + rcx*4] ; access element in X using offset * 4 for float

    addss xmm0, xmm1 ; add current sum + current element

    ; compute for window_size + offset
    add r8, rcx

    ; offset++
    inc rcx
    mov r8, [window_size]

    ; below this sets off the error when put pero pwede ring nasa taas ung error
    ; offset < window_size + offset
    cmp rcx, r8
    jl LOOP

    ret 24


    

