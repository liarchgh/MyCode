DATA    SEGMENT
s       db 30 dup(?)
MUX1    DB ?                                     ;��������s
MUX2    DB ?									 ;��������ns
MIN1	DB ?									 ;�����С��s
MIN2    DB ?                                     ;�����С��ns
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
 		;mov dl,' '    ���Լ�¼����
 		;MOV  AH, 2
 		;INT  21H
 		
 
		
 
 		
        
        
        mov cx,word ptr i
        MOV SI,OFFSET s                          ;�׵�ַ
        MOV AH,[SI]                              ;�ٶ���һ����Ϊ�����
        MOV AL,[SI]                              ;�ٶ���һ����Ϊ��С��
 LOOP1: INC SI                                   ;ָ����һ����
        CMP AH,[SI]                              ;�Ƚ�
        JGE NEXT1                                ;AH������
        MOV AH,[SI]                              ;AH����С���滻
        JMP NEXT2
 NEXT1: CMP AL,[SI]                              ;�Ƚ�
        JNGE NEXT2
        MOV AL,[SI]                              ;AL�������滻 
 NEXT2: DEC CX
        JNZ LOOP1                                ;ѭ��
        MOV MUX2,AH
        MOV MIN2,AL                              ;�洢�����
        MOV AH,4CH
        
        MOV CX,word ptr i
        MOV SI,OFFSET s
        MOV AH,[SI]                             ;�ٶ���һ����Ϊ�����
        MOV AL,[SI]                             ;�ٶ���һ����Ϊ��С��
 LOOP2: INC SI                                   ;ָ����һ����
        CMP AH,[SI]                              ;�Ƚ�
        JNB NEXT3                                ;AH������
        MOV AH,[SI]                              ;AH����С���滻
        JMP NEXT4
 NEXT3: CMP AL,[SI]                              ;�Ƚ�
        JB NEXT4
        MOV AL,[SI]                              ;AL�������滻 
 NEXT4: DEC CX
        JNZ LOOP2                                ;ѭ��
        MOV MUX1,AH
        MOV MIN1,AL                              ;�洢�����
        

		mov si,offset MUX1
		mov i,4       
 l:		mov al,[SI]                              ; ѭ�����
 		mov ah,0
 		call PRINTAX
 		
 		mov dl,' '
 		MOV  AH, 2
	    INT  21H
	   
 		inc si
 		dec i
 		jnz l
        
        
        
       ;���Ϊ255
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
  sub al,30h ;����ע�⵱���ڵ���1���жϺ�����al�Ĵ������������ַ���ASCSII,  
             ;�����ȥ30H��37H��ʮ��������ABCDEF���ַ�����������Ҫ����ֵ��  
  xchg al,bl  
  mov bh,10  
  mul bh  
  add bl,al  
  jmp lop1  
  exit: ret
  
  fushu: mov re,1
  jmp lop1
    
  scan endp




PRINTAX PROC          ;��10�������AX�е��޷�������.
	  mov  cx,0
	  MOV  BX, 10     ;��10�������.
      OR   AX, AX
      JZ   _0_
LOOP_P:
      XOR  DX, DX
      DIV  BX
      MOV  x, AX     ;��.
      OR   x, DX
      JZ   _E_        ;������������Ϊ0�����ѭ��.
      PUSH DX
      inc  cx         ;����DX�е�����.
      jmp  LOOP_P     ;ѭ��.
_E_:
LOOP_2:
      POP  DX         ;�ָ�����.
      ADD  DL, '0'    ;���ASCII��.
      JMP  _1_
_0_:  MOV  DL, '0'    ;��0��ֱ�����.
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







