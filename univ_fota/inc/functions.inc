;some functions written by Rebellos, mijoma and b.kubica
;if adding new please make them model-independent
macro FUNCTIONS
{
align 4
;crc32 by mijoma
;int calc_crc32(void* data, int length)
calc_crc32:
   STMFD SP!, {R2-R6,LR\}
   adr   r6, crc_table
   mvn   r5, #0
   mov   r2, #0

crc_loop:
   and   r4, r5,#0xFF
   ldrb  r3, [r0, r2]
   eor   r4, r4, r3
   ldr   r4, [r6, r4, lsl 2]
   eor   r5, r4, r5,lsr 8
   add   r2, r2, #1
   cmp   r2, r1
   bcc   crc_loop
   mvn   r0, r5
   LDMFD SP!, {R2-R6,PC\}
   
   crc_table            dw 0x00000000, 0x77073096, 0xee0e612c, 0x990951ba
                        dw 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3
                        dw 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988
                        dw 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91
                        dw 0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de
                        dw 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7
                        dw 0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec
                        dw 0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5
                        dw 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172
                        dw 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b
                        dw 0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940
                        dw 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59
                        dw 0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116
                        dw 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f
                        dw 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924
                        dw 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d
                        dw 0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a
                        dw 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433
                        dw 0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818
                        dw 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01
                        dw 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e
                        dw 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457
                        dw 0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c
                        dw 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65
                        dw 0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2
                        dw 0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb
                        dw 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0
                        dw 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9
                        dw 0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086
                        dw 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f
                        dw 0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4
                        dw 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad
                        dw 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a
                        dw 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683
                        dw 0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8
                        dw 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1
                        dw 0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe
                        dw 0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7
                        dw 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc
                        dw 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5
                        dw 0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252
                        dw 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b
                        dw 0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60
                        dw 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79
                        dw 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236
                        dw 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f
                        dw 0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04
                        dw 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d
                        dw 0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a
                        dw 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713
                        dw 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38
                        dw 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21
                        dw 0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e
                        dw 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777
                        dw 0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c
                        dw 0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45
                        dw 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2
                        dw 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db
                        dw 0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0
                        dw 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9
                        dw 0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6
                        dw 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf
                        dw 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94
                        dw 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d

;int rebell_strlen(char* str)
rebell_strlen:
   STMFD SP!, {R1-R4,LR\}
   MOV   R1, 0
rebell_strlen_loop:
   LDRB  R2, [R0], 1
   CMP   R2, 0x0
   BEQ   rebell_strlen_ret
   ADD   R1, R1, 1
   B     rebell_strlen_loop
rebell_strlen_ret:
   MOV   R0, R1
   LDMFD SP!, {R1-R4,PC\}

;void rebell_fillmem(R0 void* ptr, R1 byte fillbyte, R2 int length)
rebell_fillmem:
   STMFD SP!, {R3,LR\}
   MOV   R3, 0
rebell_fillmem_loop:
   CMP   R3, R2
   BGE   rebell_fillmem_ret
   STRB  R1, [R0, R3]
   ADD   R3, R3, 1
   B     rebell_fillmem_loop
rebell_fillmem_ret:
   LDMFD SP!, {R3,PC\}
;be aware of code below, need someone to check and fix it
;it is 100% copy->paste from PBL with commented out 0x40 mapping
configure_ram:
   STMFD SP!, {R0-R5,LR\}
   LDR   R0, [APLL_LOCK]
   ORR   R0, R0, #0x6200
   ORR   R0, R0, #8
   MOV   R1, #0
   STR   R1, [R0]
   LDR   R0, [RST_STAT]
   LDR   R3, [R0]
   AND   R3, R3, #0x10000
   LDR   R0, [ASYNC_MSYS_DMC0]
   MOV   R1, #0
   STR   R1, [R0]
   MOV   R1, #0
   STR   R1, [R0,#0xC]
   LDR   R0, [DMC0_REG]
   LDR   R1, [conf_0x101000]
   STR   R1, [R0,#0x18]
   MOV   R1, #0x84
   STR   R1, [R0,#0x1C]
   LDR   R1, [conf_0x101000]
   ADD   R1, R1, 2
   STR   R1, [R0,#0x18]
   LDR   R1, [conf_0x101000]
   ADD   R1, R1, 3
   STR   R1, [R0,#0x18]
   MOV   R2, #0x4000
loopconfram:
   SUBS  R2, R2, #1
   CMP   R2, #0
   BNE   loopconfram
   LDR   R1, [conf_0x60101003]
   STR   R1, [R0,#0x18]
   CMP   R3, #0x10000
   BNE   configram2
   LDR   R1, [conf_0x60101001]
   STR   R1, [R0,#0x18]
configram2:
   LDR   R1, [conf_0xFFF1010]
   STR   R1, [R0]
   LDR   R1, [conf_0x212100]
   STR   R1, [R0,#4]
   LDR   R1, [conf_0x30F82222]
   STR   R1, [R0,#8]
   LDR   R1, [conf_0x40F02222]
   STR   R1, [R0,#0xC]
   MOV   R1, #0xFF000000
   STR   R1, [R0,#0x14]
   MOV   R1, 0x50E
   STR   R1, [R0,#0x30]
   LDR   R1, [conf_0x14233287]
   STR   R1, [R0,#0x34]
   LDR   R1, [conf_0x12130005]
   STR   R1, [R0,#0x38]
   LDR   R1, [conf_0xE140222]
   STR   R1, [R0,#0x3C]
   MOV   R1, #0x7000000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x1000000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x5000000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x5000000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x32
   STR   R1, [R0,#0x10]
   LDR   R1, [conf_0x20020]
   STR   R1, [R0,#0x10]
   MOV   R1, #0x7100000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x1100000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x5100000
   STR   R1, [R0,#0x10]
   MOV   R1, #0x5100000
   STR   R1, [R0,#0x10]
   LDR   R1, [conf_0x100032]
   STR   R1, [R0,#0x10]
   LDR   R1, [conf_0x120020]
   STR   R1, [R0,#0x10]
   LDR   R1, [conf_0xFFF10B0]
   STR   R1, [R0]
   MOV   R1, 0xFFFF00FF
   STR   R1, [R0,#0x28]
   LDR   R1, [conf_0x212113]
   STR   R1, [R0,#4]
   LDR   R0, [DMC1_REG] ; DMC1_config
   LDR   R1, [conf_0x101000]
   STR   R1, [R0,#0x18]
   MOV   R1, #0x84
   STR   R1, [R0,#0x1C]
   LDR   R1, [conf_0x101000]
   ADD   R1, R1, 2
   STR   R1, [R0,#0x18]
   LDR   R1, [conf_0x101000]
   ADD   R1, R1, 3
   STR   R1, [R0,#0x18]
   MOV   R2, #0x4000
loopconfram2:
   SUBS  R2, R2, #1
   CMP   R2, #0
   BNE   loopconfram2
   LDR   R1, [conf_0x50101003]
   STR   R1, [R0,#0x18]
   CMP   R3, #0x10000
   BNE   configram3
   LDR   R1, [conf_0x50101001]
   STR   R1, [R0,#0x18]
configram3:
;LDR     R0, [DMC1_REG]
;LDR     R1, [conf_0xFFF1010]
;STR     R1, [R0]
;LDR     R1, [conf_0x212100]
   ;MOV     R5, R0
   ;MOV     R0, 9999
   ;BL      int_debugprint
       ; MOV     R0, R5
;STR     R1, [R0,#4]

   ;MOV     R0, 9999
   ;BL      int_debugprint
   LDMFD   SP!, {R0-R5,PC\}
;endproc

   conf_0xE2700000      dw 0xE2700000
   conf_0xE2900C00      dw 0xE2900C00
   conf_0x120020        dw 0x120020
   conf_0xFFF10B0       dw 0xFFF10B0
   conf_0x212113        dw 0x212113
   conf_0x50101003      dw 0x50101003
   conf_0x50101001      dw 0x50101001
   conf_0xFFF1010       dw 0xFFF1010
   APLL_LOCK            dw 0xE0100000
   RST_STAT             dw 0xE010A000
   ASYNC_MSYS_DMC0      dw 0xF1E00000
   DMC0_REG             dw 0xF0000000
   conf_0x60101003      dw 0x60101003
   conf_0x60101001      dw 0x60101001
   conf_0x101000        dw 0x101000
   DMC1_REG             dw 0xF1400000
   conf_0x40F02222      dw 0x40F02222
   conf_0x212100        dw 0x212100
   conf_0x30F82222      dw 0x30F82222
   conf_0x14233287      dw 0x14233287
   conf_0x12130005      dw 0x12130005
   conf_0xE140222       dw 0xE140222
   conf_0x20020         dw 0x20020
   conf_0x100032        dw 0x100032

;void rebell_memcpy(int source(r0), int target(r1), int size(r2))
;returns num of bytes copied (always equal to size or just hangs on mem access violation)
rebell_memcpy:
   STMFD SP!, {R3-R6,LR\}

   MOV   R3, R2
   MOV   R2, R1
   MOV   R1, R0
   LDR   R0, [s_memcpy_a]
   bl    debug_print

   MOV   R0, R1
   MOV   R1, R2
   MOV   R2, R3

   MOV   R3, 0
rebell_memcpy_copyloop:
   ldrb  r4, [r0,r3] ;src
   strb  r4, [r1,r3] ;dst
   add   r3, r3, 1
   cmp   r3, r2
   BLT   rebell_memcpy_copyloop
   MOV   R0, R2
   LDMFD SP!, {R3-R6,PC\}

;void debug_print(char* fmt, ...)
debug_print:
   STMFD SP!, {R0-R11,LR\} ;make sure no registers change
   LDR   R10, [output_switch]
   CMP   R10, 2
   BEQ   debug_print_uart
   B     debug_print_ret

debug_print_uart:
   BL    EdbgOutputDebugString
   LDR   r0, [s_uart_newline_a]
   BL    EdbgOutputDebugString
   B     debug_print_ret
debug_print_ret:
   LDMFD SP!, {R0-R11,PC\}

;void enable_uart_output()
enable_uart_output:
   STMFD SP!, {R0-R1,LR\}
   LDR   r1, [output_switch_a]
   MOV   r0, 2
   STR   R0, [r1]
   ldr   r0, [s_uartoutput_a]
   bl    debug_print
   LDMFD SP!, {R0-R1,PC\}

;void int_debugprint(int num)
int_debugprint:
   STMFD SP!, {R0-R1,LR\}
   mov   r1, r0
   ldr   r0, [s_debug_fmt_int_a]
   bl    debug_print
   LDMFD SP!, {R0-R1,PC\}

;void hex_debugprint(int num)
hex_debugprint:
   STMFD SP!, {R0-R1,LR\}
   mov   r1, r0
   ldr   r0, [s_debug_fmt_hex_a]
   bl    debug_print
   LDMFD SP!, {R0-R1,PC\}

;int loadfile(wchar* filepath, ulong target_addr, ulong size)
;loads file to RAM under specific address
;returns bytes read or 0 if error
loadfile:
   STMFD SP!,{R3-R6,LR\}
   mov   r4, r1
   mov   r5, r2
   mov   r6, r0

   mov   r1, r4
   ldr   r0, [s_fileload_a]
   bl    debug_print

   mov   r0, r6

   mov   r1, 4 ;flag, probably READ or READWRITE
   mov   r6, r0   ;path
   bl    tfs4_open
   mov   r6, r0
   cmp   r0, 0   ;is it FILE index or -1?
   blt   loadfile_notfound

   mov   r0, 1

   mov   r0, r6

   mov   r2, r5    ;len
   mov   r1, r4    ;buffer
   mov   r0, r6    ;FILE index
   bl    tfs4_read
   mov   r4, r0
   
   mov   r1, r0
   ldr   r0, [s_filesize_a]
   bl    debug_print
   
   mov   r0, r6
   bl    tfs4_close
   mov   r0, r4
loadfile_ret:
   LDMFD SP!, {R3-R6,PC\}
loadfile_notfound:
   ldr   r0, [s_loadfile_error_a]
   bl    debug_print
   mov   r0, 0
   b     loadfile_ret

;;Rewritten SBL functions to configure platform and CPU like SBL does
configure_uart:
   LDR   R4, [UART2_PTR]
   MOV   R3, #0x23
   STRH  R3, [SP,#8]
   MOV   R3, #0x80
   STRH  R3, [SP,#6]
   LDR   R3, [R4, #4]
   BIC   R3, R3, #0xF
   STR   R3, [R4, #4]
   MOV   R3, #0
   STR   R3, [R4, #8]
   MOV   R3, #0
   STR   R3, [R4, #0xC]
   MOV   R3, #3
   STR   R3, [R4]
   MOV   R3, #0x240
   STR   R3, [R4, 4]
   LDRH  R3, [SP,#8]
   STR   R3, [R4, 0x28]
   LDRH  R3, [SP,#6]
   STR   R3, [R4, 0x2C]
   LDR   R3, [R4, 4]
   ORR   R3, R3, #5
   STR   R3, [R4, 4]
   BX    LR
configure_clocks:
   LDR   R3, [CLK_DIV1]
   LDR   R3, [R3]
   BIC   R3, R3, #0xF00000
   ORR   R3, R3, #0x300000
   LDR   R2, [CLK_DIV1]
   STR   R3, [R2]
   LDR   R3, [CLK_DIV0]
   LDR   R3, [R3]
   AND   R3, R3, #0x80000000
   MOV   R2, R3
   LDR   R3, [clk_div_mask]
   ORR   R3, R2, R3
   LDR   R2, [CLK_DIV0]
   STR   R3, [R2]

   wait_for_stable_div:
   LDR   R3, [CLK_DIV_STAT0]
   LDR   R3, [R3]
   AND   R3, R3, #1
   CMP   R3, #0
   BNE   wait_for_stable_div

   LDR   R3, [DMC0_REG]
   LDR   R3, [R3, 0x18]
   BIC   R3, R3, #2
   LDR   R2, [DMC0_REG]
   STR   R3, [R2, 0x18]
   LDR   R3, [DMC1_REG]
   LDR   R3, [R3, 0x18]
   BIC   R3, R3, #2
   LDR   R2, [DMC1_REG]
   STR   R3, [R2, 0x18]


   LDR   R2, [CLK_GATE_IP0]
   LDR   R3, [CLK_GATE_IP0]
   LDR   R3, [R3]
   BIC   R3, R3, #0x80000000
   STR   R3, [R2]
   LDR   R2, [CLK_GATE_IP1]
   LDR   R3, [CLK_GATE_IP1]
   LDR   R3, [R3]
   BIC   R3, R3, #0x10000000
   STR   R3, [R2]
   LDR   R2, [CLK_GATE_IP2]
   LDR   R3, [CLK_GATE_IP2]
   LDR   R3, [R3]
   BIC   R3, R3, #0x200
   BIC   R3, R3, #2
   STR   R3, [R2]
   LDR   R2, [CLK_GATE_IP3]
   LDR   R3, [CLK_GATE_IP3]
   LDR   R3, [R3]
   BIC   R3, R3, #3
   STR   R3, [R2]
   LDR   R2, [CLK_GATE_IP4]
   LDR   R3, [CLK_GATE_IP4]
   LDR   R3, [R3]
   BIC   R3, R3, #6
   STR   R3, [R2]
   BX    LR

   UART2_PTR            dw 0xE2900800
   clk_div_mask         dw 0x14131330
   CLK_DIV0             dw 0xE0100300
   CLK_DIV1             dw 0xE0100304
   CLK_DIV2             dw 0xE0100308
   CLK_DIV3             dw 0xE010030C
   CLK_DIV4             dw 0xE0100310
   CLK_DIV5             dw 0xE0100314
   CLK_DIV6             dw 0xE0100318
   CLK_DIV7             dw 0xE010031C
   CLK_GATE_IP0         dw 0xE0100460
   CLK_GATE_IP1         dw 0xE0100464
   CLK_GATE_IP2         dw 0xE0100468
   CLK_GATE_IP3         dw 0xE010046C
   CLK_GATE_IP4         dw 0xE0100470
   CLK_DIV_STAT0        dw 0xE0101000

timer_driver:
   var_18= -0x18
   var_4= -4
   STR   R11, [SP,#var_4]!
   ADD   R11, SP, #4+var_4
   SUB   SP, SP, #0xC
   LDR   R2, [TCFG0]
   MOV   R3, #0xF00
   STR   R3, [R2]
   LDR   R3, [TCFG1]
   LDR   R3, [R3]
   BIC   R3, R3, #0xF0000
   STR   R3, [R11,#0x10+var_18]
   LDR   R2, [TCFG1]
   LDR   R3, [R11,#0x10+var_18]
   ORR   R3, R3, #0x10000
   STR   R3, [R2]
   LDR   R2, [TCNTB4]
   MOV   R3, 0xFFFFFFFF
   STR   R3, [R2]
   LDR   R2, [TCON]
   LDR   R3, [TCON]
   LDR   R3, [R3]
   BIC   R3, R3, #0x700000
   ORR   R3, R3, #0x600000
   STR   R3, [R2]
   LDR   R2, [TCON]
   LDR   R3, [TCON]
   LDR   R3, [R3]
   BIC   R3, R3, #0x700000
   ORR   R3, R3, #0x500000
   STR   R3, [R2]
   MOV   SP, R11
   LDMFD SP!, {R11\}
   BX    LR

   TCFG0                dw 0xE2500000
   TCFG1                dw 0xE2500004
   TCON                 dw 0xE2500008
         
   TCNTB4               dw 0xE250003C
   
CoDisableMmu:
   MRC   p15, 0, R0,c1,c0   
   BIC   R0, R0, #1
   MCR   p15, 0, R0,c1,c0
   MOV   PC, LR   
   
CoDisableDCache:
   MRC   p15, 0, R0,c1,c0   
   BIC   R0, R0, #4   
   MCR   p15, 0, R0,c1,c0   
   MOV   PC, LR   

System_DisableVIC:
   MRC   p15, 0, R0,c1,c0
   BIC   R0, R0, #0x1000000
   MCR   p15, 0, R0,c1,c0
   BX    LR

System_DisableIRQ:
   MRS   R0, CPSR
   ORR   R0, R0, #0x80
   MSR   CPSR_cxsf, R0
   BX    LR

System_DisableFIQ:
   MRS   R0, CPSR
   ORR   R0, R0, #0x40
   MSR   CPSR_cxsf, R0
   BX    LR
   
}
