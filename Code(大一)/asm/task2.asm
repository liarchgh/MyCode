DATA SEGMENT
  ;此处输入数据段代码
  TH DW ?;输入数字的个数 
  NUM DW ?;输入的数字
  MUX1 DW ?
  MUX2 DW ?
  MIN1 DW ?
  MIN2 DW ?
DATA ENDS

CODE SEGMENT
  ASSUME CS:CODE,DS:DATA
START:
  ;mov DL,'g'
  ;mov AH,2
  ;INT 21H
  MOV AX,DATA
  MOV DS,AX
  JMP RR

SCAN:;输入子程序
  ;mov DL,'0'
  ;mov AH,2
  ;INT 21H
  MOV BX,0;BX存放读入的数
RE_SCAN:;会使用AX AH存放输入号 AL存放输入的字符 BX存放中间数 CL符号 CH中间用来存AL的字符
  MOV AH,1
  INT 21H
  CMP AL,','
  JZ RE_SCAN
  CMP AL,' '
  JZ RE_SCAN
  CMP AL,13
  JZ RE_SCAN
CON_SCAN:;先判断是否读符号
  ;mov DL,'2'
  ;mov AH,2
  ;INT 21H
  MOV CL,0
  CMP AL,'-'
  JNZ S_F
  MOV CL,1
  mov ah,1
  int 21h
S_F:;读入符号后的数字
  ;mov DL,'3'
  MOV CH,AL
  ;mov AH,2
  ;INT 21H
  MOV AX,10
  MUL BX;DX has changed
  MOV BX,AX
  MOV AL,'0'
  SUB CH,AL;CH has a single origin number
  MOV AL,CH
  MOV AH,0
  ADD BX,AX
  MOV AH,1
  INT 21H;AL has a sign's ascii
  CMP AL,' '
  JZ SC_END
  CMP AL,','
  JZ SC_END
  CMP AL,13
  JZ SC_END
  JMP S_F
SC_END:
  CMP CL,0
  MOV NUM,BX
  JNZ BF
  RET
BF:;若是负数 转化为补码
  mov NUM,0
  sub num,bx
  RET

;printf_0 PROC
;  mov DL,'p'
;  mov AH,2
;  INT 21H
;  RET
;printf_0 ENDP

print:;print out  NUM's number
  ;mov DL,'4'
  ;mov AH,2
  ;INT 21H
  mov dx,22
  push dx
  CMP NUM,0
  mov ax,num
  JGE con_print
  mov dl,'-'
  mov ah,2
  int 21H
  mov ax,0
  sub ax,num
con_print:
  mov bx,10
  mov dx,0
  div bx;ax : ax / bx, dx : ax % bx
  add dl,30h
  push dx
  ;mov DL,'m'
  cmp ax,0
  jnz con_print
p_n:
  pop dx
  cmp dx,22
  jz p_end
  mov ah,2
  int 21h
  jmp p_n
p_end:
  ;mov DL,'x'
  ;mov AH,2
  ;INT 21H
  RET

print_k:
  mov ah,2
  mov dl,' '
  int 21H
  RET

print_h:
  mov ah,02H
  mov dl,13
  int 21H
  mov dl,10
  int 21H
  RET 

R1:
  MOV MUX1,BX
  JMP CON1
R2:
  MOV MUX2,BX
  JMP CON2
R3:
  MOV MIN1,BX
  JMP CON3
R4:
  MOV MIN2,BX
  JMP CON4
RR:
  ;call printf_0
  ;mov DL,'8'
  ;mov AH,2
  ;INT 21H
  CALL SCAN
  ;mov DL,'8'
  ;mov AH,2
  ;INT 21H
  ;call print
  MOV DX,NUM
  MOV TH,DX
  CALL SCAN
  MOV DX,NUM
  MOV MUX1,DX
  MOV MUX2,DX
  MOV MIN1,DX
  MOV MIN2,DX
  dec TH
CSTART:
  ;mov dx,th
  ;mov num,dx
  ;call print
  CMP TH,0
  JZ CEND
  CALL SCAN
  ;call print
  MOV BX,NUM
  CMP BX,MUX1
  JA R1
CON1:
  ;mov DL,'a'
  ;mov AH,2
  ;INT 21H
  CMP BX,MUX2
  JG R2
CON2:
  ;mov DL,'b'
  ;mov AH,2
  ;INT 21H
  CMP MIN1,BX
  JA R3
CON3:
  CMP MIN2,BX
  JG R4
CON4:
  dec TH
  JMP CSTART
CEND:
  ;mov DL,'c'
  ;mov AH,2
  ;INT 21H
  MOV AX,MUX1
  MOV NUM,AX
  ;mov DL,'d'
  ;mov AH,2
  ;INT 21H
  ;call print_k
  ;mov DL,'e'
  ;mov AH,2
  ;INT 21H
  call print
  MOV AX,MUX2
  MOV NUM,AX
  call print_k
  call print
  MOV AX,MIN1
  MOV NUM,AX
  call print_k
  call print
  MOV AX,MIN2
  MOV NUM,AX
  call print_k
  call print
  call print_h
  ;mov DL,'f'
  ;mov AH,2
  ;INT 21H
  mov ah,4ch
  int 21H
CODE ENDS
  END START
