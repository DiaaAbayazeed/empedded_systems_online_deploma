
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0010 	ldr	r0, [pc, #16]	; 20 <main+0x20>
   c:	ebfffffe 	bl	0 <uart_send>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e24bd004 	sub	sp, fp, #4
  18:	e8bd4800 	pop	{fp, lr}
  1c:	e12fff1e 	bx	lr
  20:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <arr>:
   0:	5241454c 	subpl	r4, r1, #76, 10	; 0x13000000
   4:	4e495f4e 	cdpmi	15, 4, cr5, cr9, cr14, {2}
   8:	5045445f 	subpl	r4, r5, pc, asr r4
   c:	3c3a4854 	ldccc	8, cr4, [sl], #-336	; 0xfffffeb0
  10:	41414944 	cmpmi	r1, r4, asr #18
  14:	0000003e 	andeq	r0, r0, lr, lsr r0
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000062 	andeq	r0, r0, r2, rrx
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000000 	andeq	r0, r0, r0
  10:	00006c0c 	andeq	r6, r0, ip, lsl #24
  14:	00007200 	andeq	r7, r0, r0, lsl #4
  18:	00000000 	andeq	r0, r0, r0
  1c:	00002400 	andeq	r2, r0, r0, lsl #8
  20:	00000000 	andeq	r0, r0, r0
  24:	003c0200 	eorseq	r0, ip, r0, lsl #4
  28:	00350000 	eorseq	r0, r5, r0
  2c:	35030000 	strcc	r0, [r3, #-0]
  30:	63000000 	movwvs	r0, #0
  34:	07040400 	streq	r0, [r4, -r0, lsl #8]
  38:	0000004c 	andeq	r0, r0, ip, asr #32
  3c:	5e080104 	adfple	f0, f0, f4
  40:	05000000 	streq	r0, [r0, #-0]
  44:	00727261 	rsbseq	r7, r2, r1, ror #4
  48:	00250301 	eoreq	r0, r5, r1, lsl #6
  4c:	03050000 	movweq	r0, #20480	; 0x5000
  50:	00000000 	andeq	r0, r0, r0
  54:	00005906 	andeq	r5, r0, r6, lsl #18
  58:	00040100 	andeq	r0, r4, r0, lsl #2
  5c:	24000000 	strcs	r0, [r0], #-0
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	Address 0x00000064 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	13490101 	movtne	r0, #37121	; 0x9101
  18:	00001301 	andeq	r1, r0, r1, lsl #6
  1c:	49002103 	stmdbmi	r0, {r0, r1, r8, sp}
  20:	000b2f13 	andeq	r2, fp, r3, lsl pc
  24:	00240400 	eoreq	r0, r4, r0, lsl #8
  28:	0b3e0b0b 	bleq	f82c5c <main+0xf82c5c>
  2c:	00000e03 	andeq	r0, r0, r3, lsl #28
  30:	03003405 	movweq	r3, #1029	; 0x405
  34:	3b0b3a08 	blcc	2ce85c <main+0x2ce85c>
  38:	3f13490b 	svccc	0x0013490b
  3c:	00180219 	andseq	r0, r8, r9, lsl r2
  40:	002e0600 	eoreq	r0, lr, r0, lsl #12
  44:	0e03193f 			; <UNDEFINED> instruction: 0x0e03193f
  48:	0b3b0b3a 	bleq	ec2d38 <main+0xec2d38>
  4c:	01111927 	tsteq	r1, r7, lsr #18
  50:	18400612 	stmdane	r0, {r1, r4, r9, sl}^
  54:	00194296 	mulseq	r9, r6, r2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000024 	andeq	r0, r0, r4, lsr #32
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4c4b1500 	cfstr64mi	mvdx1, [fp], {-0}
  30:	01000a02 	tsteq	r0, r2, lsl #20
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	20554e47 	subscs	r4, r5, r7, asr #28
   4:	20313143 	eorscs	r3, r1, r3, asr #2
   8:	2e322e37 	mrccs	14, 1, r2, cr2, cr7, {1}
   c:	30322031 	eorscc	r2, r2, r1, lsr r0
  10:	39303731 	ldmdbcc	r0!, {r0, r4, r5, r8, r9, sl, ip, sp}
  14:	28203430 	stmdacs	r0!, {r4, r5, sl, ip, sp}
  18:	656c6572 	strbvs	r6, [ip, #-1394]!	; 0xfffffa8e
  1c:	29657361 	stmdbcs	r5!, {r0, r5, r6, r8, r9, ip, sp, lr}^
  20:	52415b20 	subpl	r5, r1, #32, 22	; 0x8000
  24:	6d652f4d 	stclvs	15, cr2, [r5, #-308]!	; 0xfffffecc
  28:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  2c:	372d6465 	strcc	r6, [sp, -r5, ror #8]!
  30:	6172622d 	cmnvs	r2, sp, lsr #4
  34:	2068636e 	rsbcs	r6, r8, lr, ror #6
  38:	69766572 	ldmdbvs	r6!, {r1, r4, r5, r6, r8, sl, sp, lr}^
  3c:	6e6f6973 			; <UNDEFINED> instruction: 0x6e6f6973
  40:	35353220 	ldrcc	r3, [r5, #-544]!	; 0xfffffde0
  44:	5d343032 	ldcpl	0, cr3, [r4, #-200]!	; 0xffffff38
  48:	00672d20 	rsbeq	r2, r7, r0, lsr #26
  4c:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  50:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  54:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  58:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  5c:	6e75006e 	cdpvs	0, 7, cr0, cr5, cr14, {3}
  60:	6e676973 			; <UNDEFINED> instruction: 0x6e676973
  64:	63206465 			; <UNDEFINED> instruction: 0x63206465
  68:	00726168 	rsbseq	r6, r2, r8, ror #2
  6c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  70:	3a480063 	bcc	1200204 <main+0x1200204>
  74:	706d655c 	rsbvc	r6, sp, ip, asr r5
  78:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  7c:	20632064 	rsbcs	r2, r3, r4, rrx
  80:	Address 0x00000080 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	5420554e 	strtpl	r5, [r0], #-1358	; 0xfffffab2
   c:	736c6f6f 	cmnvc	ip, #444	; 0x1bc
  10:	726f6620 	rsbvc	r6, pc, #32, 12	; 0x2000000
  14:	6d724120 	ldfvse	f4, [r2, #-128]!	; 0xffffff80
  18:	626d4520 	rsbvs	r4, sp, #32, 10	; 0x8000000
  1c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  20:	72502064 	subsvc	r2, r0, #100	; 0x64
  24:	7365636f 	cmnvc	r5, #-1140850687	; 0xbc000001
  28:	73726f73 	cmnvc	r2, #460	; 0x1cc
  2c:	322d3720 	eorcc	r3, sp, #32, 14	; 0x800000
  30:	2d373130 	ldfcss	f3, [r7, #-192]!	; 0xffffff40
  34:	6d2d3471 	cfstrsvs	mvf3, [sp, #-452]!	; 0xfffffe3c
  38:	726f6a61 	rsbvc	r6, pc, #397312	; 0x61000
  3c:	2e372029 	cdpcs	0, 3, cr2, cr7, cr9, {1}
  40:	20312e32 	eorscs	r2, r1, r2, lsr lr
  44:	37313032 			; <UNDEFINED> instruction: 0x37313032
  48:	34303930 	ldrtcc	r3, [r0], #-2352	; 0xfffff6d0
  4c:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  50:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  54:	5b202965 	blpl	80a5f0 <main+0x80a5f0>
  58:	2f4d5241 	svccs	0x004d5241
  5c:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  60:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  64:	622d372d 	eorvs	r3, sp, #11796480	; 0xb40000
  68:	636e6172 	cmnvs	lr, #-2147483620	; 0x8000001c
  6c:	65722068 	ldrbvs	r2, [r2, #-104]!	; 0xffffff98
  70:	69736976 	ldmdbvs	r3!, {r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  74:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  78:	30323535 	eorscc	r3, r2, r5, lsr r5
  7c:	Address 0x0000007c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000020 	andeq	r0, r0, r0, lsr #32
	...
  1c:	00000024 	andeq	r0, r0, r4, lsr #32
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	48040b0c 	stmdami	r4, {r2, r3, r8, r9, fp}
  2c:	42080d0c 	andmi	r0, r8, #12, 26	; 0x300
  30:	000ecbce 	andeq	ip, lr, lr, asr #23

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002f41 	andeq	r2, r0, r1, asr #30
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000025 	andeq	r0, r0, r5, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	4d445437 	cfstrdmi	mvd5, [r4, #-220]	; 0xffffff24
  18:	02060049 	andeq	r0, r6, #73	; 0x49
  1c:	01090108 	tsteq	r9, r8, lsl #2
  20:	01140412 	tsteq	r4, r2, lsl r4
  24:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  28:	01190118 	tsteq	r9, r8, lsl r1
  2c:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
