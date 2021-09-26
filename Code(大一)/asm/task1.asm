DATA SEGMENT
  ;此处输入数据段代码
  NUM_list db 55,-23,82,5,-66,27,-3,74,51,42
  num db ? 
  MUX1 db ?
  MUX2 db ?
  MIN1 db ?
  MIN2 db ?
DATA ENDS

CODE SEGMENT
  ASSUME CS:CODE,DS:DATA
START:
  MOV AX,DATA
  MOV DS,AX
  JMP RR
print:;print out  NUM's number
  ;mov DL,'4'
  ;mov AH,2
  ;INT 21H
  mov dx,22
  push dx
  CMP NUM,0
  mov al,num
  JGE con_print
  mov dl,'-'
  mov ah,2
  int 21H
  mov al,0
  sub al,num
con_print:
  mov ah,0
  mov bl,10
  div bl;ax : ax / bx, dx : ax % bx
  mov cl,al
  add ah,30h
  mov al,ah
  mov ah,0
  push ax
  ;mov DL,'m'
  mov al,cl
  cmp al,0
  jnz con_print
p_n:
  pop dx
  cmp dl,22
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
  MOV MUX1,BL
  JMP CON1
R2:
  MOV MUX2,BL
  JMP CON2
R3:
  MOV MIN1,BL
  JMP CON3
R4:
  MOV MIN2,BL
  JMP CON4
RR:
  mov si,0
  ;mov dl,[NUM_list + 0]
  MOV Dl,[NUM_list + si]
  inc si
  MOV MUX1,DL
  MOV MUX2,DL
  MOV MIN1,DL
  MOV MIN2,DL
CSTART:
  ;mov dx,th
  ;mov num,dx
  ;call print
  cmp si,10
  JZ CEND
  ;call print
  MOV bl,[NUM_list + si]
  inc si
  cmp bl,MUX1
  ja R1
CON1:
  ;mov DL,'a'
  ;mov AH,2
  ;INT 21H
  CMP bl,MUX2
  JG R2
CON2:
  ;mov DL,'b'
  ;mov AH,2
  ;INT 21H
  CMP MIN1,BL
  JA R3
CON3:
  CMP MIN2,BL
  JG R4
CON4:
  JMP CSTART
CEND:
  ;mov DL,'c'
  ;mov AH,2
  ;INT 21H
  MOV Al,MUX1
  MOV NUM,Al
  ;mov DL,'d'
  ;mov AH,2
  ;INT 21H
  ;call print_k
  ;mov DL,'e'
  ;mov AH,2
  ;INT 21H
  call print
  MOV AL,MUX2
  MOV NUM,AL
  call print_k
  call print
  MOV AL,MIN1
  MOV NUM,AL
  call print_k
  call print
  MOV AL,MIN2
  MOV NUM,AL
  call print_k
  call print
  call print_h  
  ;mov DL,'f'
  mov AH,4Ch
  INT 21H
CODE ENDS
  END START
