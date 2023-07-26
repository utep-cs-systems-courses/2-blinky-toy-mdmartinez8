	.arch msp430g2553
	.p2align 1,0
	.text

	.global no_led
no_led:
	mov #0, r12
	pop r0

	.global red_led
red_led:
	mov #1, r12
	pop r0
	
	.global green_led
green_led:
	mov #64, r12
	pop r0

	.global both_led
both_led:
	mov #65, r12
	pop r0
