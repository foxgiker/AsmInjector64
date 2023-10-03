includelib legacy_stdio_definitions.lib
option casemap:none

printf proto

_TEXT SEGMENT  ; read only
    format db "汇编输出: %d ",10,0
_TEXT ENDS


.code codeSegment


; 首先说明一下,在X64下,是寄存器传参. 前4个参数分别是 rcx rdx r8 r9进行传参.多余的通过栈传参.从右向左入栈.
asmTest proc
    mov eax , ecx
    add eax, edx
    add eax, r8d
    ret
asmTest ENDP;

; 测试调用c运行时库printf
; 需要注意的是visual studio 2015后msvc下的C运行时库把这个函数调整为内联函数了。
; 所以必须要 includelib legacy_stdio_definitions.lib

; 一定要执行 sub rsp,80h,来给子函数分配默认的栈空间
; 因为子函数中也可能使用局部变量，如果栈空间不够，就会异常
; 调用完子函数subroutine以后，记得要通过 add rsp,80h 清理堆栈空间。
callPrint proc
    sub rsp, 80h
    mov rcx, offset format
    mov rdx,2
    call printf
    add rsp, 80h
    ret
callPrint endp

;反转字符串,讲反转后的字符串写回原来的位置
reverseStr proc
; 定义一个64位的缓冲区，这个缓存区是分配在栈上的。
; 这也意味着这个函数只能处理长度不超过64字节的字符
; 如果需要处理足够长的字符串，需要在堆上分配空间
; 注意这里用到了rsi 非易失寄存器，在使用前要保存这个值，使用后要恢复
; 这里通过两次循环+字符缓冲区实现，逻辑比较简单。
; 也可以通过字符交换的方式来实现，逻辑复杂一点，但是就不需要缓冲区了
    local buf[64]:byte
    push rsi;
    mov rsi, rcx;
    xor rcx,rcx;
    xor rax,rax;
    lea rdx,buf;

lp:
    mov al,byte ptr [rsi];
    mov [rdx],al
    inc rsi;
    inc rdx;
    inc rcx;
    cmp byte ptr [rsi],0
    jne lp

    sub rsi,rcx; rsi指向初始的位置
    dec rdx    ; 排除末尾的0，否则字符串没有0结尾，会乱码
re:
    mov al,[rdx]
    mov [rsi],al
    inc rsi;
    dec rdx;
    dec rcx;
    cmp rcx,0
    jne re

    pop rsi;
    ret
reverseStr endp

end


