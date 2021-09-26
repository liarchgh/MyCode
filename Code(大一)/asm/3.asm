DATA    SEGMENT
s       db 30 dup(?)
MUX1    DB ?                                     ;存放最大数s
MUX2    DB ?									 ;存放最大数ns
MIN1	DB ?									 ;存放最小数s
MIN2    DB ?                                     ;存放最小数ns
x       dw ?
i		db ?
j		db ?
re      db ?
DATA    ENDS
CODE    SEGMENT
        ASSUME  CS:CODE,DS:DATA
 START: MOV AX,DATA
        MOV DS,AX
        
        
        CALL scan
        mov i,bl
        mov j,bl
        
        dec i 
        
        MOV SI,OFFSET s
 lu:    
        mov re,0   
        CALL scan
        cmp re,0
        jz ns
        xor bl,255
        add bl,1
        ns:
        mov [SI],bl
        inc SI
        dec j
        jnz lu
        
        
        ;mov al,re
 		;mov ah,0
 		;call PRINTAX
 		;mov dl,' '    测试记录负号
 		;MOV  AH, 2
 		;INT  21H
 		
 
		
 
 		
        
        
        mov cx,word ptr i
        MOV SI,OFFSET s                          ;首地址
        MOV AH,[SI]                              ;假定第一个数为最大数
        MOV AL,[SI]                              ;假定第一个数为最小数
 LOOP1: INC SI                                   ;指向下一个数
        CMP AH,[SI]                              ;比较
        JGE NEXT1                                ;AH中数大
        MOV AH,[SI]                              ;AH中数小，替换
        JMP NEXT2
 NEXT1: CMP AL,[SI]                              ;比较
        JNGE NEXT2
        MOV AL,[SI]                              ;AL中数大，替换 
 NEXT2: DEC CX
        JNZ LOOP1                                ;循环
        MOV MUX2,AH
        MOV MIN2,AL                              ;存储最大数
        MOV AH,4CH
        
        MOV CX,word ptr i
        MOV SI,OFFSET s
        MOV AH,[SI]                             ;假定第一个数为最大数
        MOV AL,[SI]                             ;假定第一个数为最小数
 LOOP2: INC SI                                   ;指向下一个数
        CMP AH,[SI]                              ;比较
        JNB NEXT3                                ;AH中数大
        MOV AH,[SI]                              ;AH中数小，替换
        JMP NEXT4
 NEXT3: CMP AL,[SI]                              ;比较
        JB NEXT4
        MOV AL,[SI]                              ;AL中数大，替换 
 NEXT4: DEC CX
        JNZ LOOP2                                ;循环
        MOV MUX1,AH
        MOV MIN1,AL                              ;存储最大数
        

		mov si,offset MUX1
		mov i,4       
 l:		mov al,[SI]                              ; 循环输出
 		mov ah,0
 		call PRINTAX
 		
 		mov dl,' '
 		MOV  AH, 2
	    INT  21H
	   
 		inc si
 		dec i
 		jnz l
        
        
        
       ;最大为255
  scan proc  
  mov bl,0
    
  lop1: mov ah,01  
  int 21h
  
  cmp al,'-'
  jz fushu
     
  cmp al,20h  
  jz exit  
  cmp al,0dh  
  jz exit  
  sub al,30h ;必须注意当你在调用1号中断后存放在al寄存器的是输入字符的ASCSII,  
             ;必须减去30H或37H（十六进制中ABCDEF等字符）才是你想要的数值。  
  xchg al,bl  
  mov bh,10  
  mul bh  
  add bl,al  
  jmp lop1  
  exit: ret
  
  fushu: mov re,1
  jmp lop1
    
  scan endp




PRINTAX PROC          ;以10进制输出AX中的无符号整数.
	  mov  cx,0
	  MOV  BX, 10     ;按10进制输出.
      OR   AX, AX
      JZ   _0_
LOOP_P:
      XOR  DX, DX
      DIV  BX
      MOV  x, AX     ;商.
      OR   x, DX
      JZ   _E_        ;若商与余数都为0则结束循环.
      PUSH DX
      inc  cx         ;保存DX中的余数.
      jmp  LOOP_P     ;循环.
_E_:
LOOP_2:
      POP  DX         ;恢复余数.
      ADD  DL, '0'    ;变成ASCII码.
      JMP  _1_
_0_:  MOV  DL, '0'    ;是0则直接输出.
_1_:  MOV  AH, 2
	  
      INT  21H
      dec cx
      jnz LOOP_2
 RET
PRINTAX ENDP


        MOV AH,4CH
        INT 21H
CODE    ENDS
        END START







